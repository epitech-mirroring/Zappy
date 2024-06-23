import socket
import select


class NetworkManager:
    serverIP: str = "127.0.0.1"
    serverPort: int
    socket = None
    sendQueue = []
    responseHandlers = []
    buffer = ""
    isRunning = False

    def __init__(self, server_port: int, server_ip: str = "127.0.0.1"):
        self.serverIP = server_ip
        self.serverPort = server_port

    def connect(self):
        print(f"Connecting to {self.serverIP}:{self.serverPort}")
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
        self.socket.setblocking(True)
        self.socket.connect((self.serverIP, self.serverPort))

    def __send(self, message: str):
        print(f"Sending: {message.strip()}")
        self.socket.sendall(message.encode())

    def send(self, message: str):
        print(f"Queuing: {message.strip()}")
        self.sendQueue.append(message)

    def receive(self) -> str:
        return self.socket.recv(1024).decode()

    def start(self):
        self.connect()
        self.isRunning = True
        while self.isRunning:
            write_list = []
            read_list = []
            if len(self.sendQueue) > 0:
                write_list.append(self.socket)
            else:
                read_list.append(self.socket)
            readable, writable, exceptional = select.select(read_list,
                                                            write_list,
                                                            [],
                                                            0.1)
            if self.socket in readable:
                response = self.receive()
                if len(response) == 0:
                    break
                if '\n' not in response:
                    self.buffer += response
                    continue
                if '\n' in response and len(self.buffer) > 0:
                    response = self.buffer + response
                    self.buffer = ""
                print(f"Received: '{response.strip()}'")
                for line in response.split("\n"):
                    for handler in self.responseHandlers:
                        handler(line)
            if self.socket in writable:
                self.__send(self.sendQueue.pop(0))
        self.close()

    def close(self):
        if self.socket is not None:
            self.socket.close()
        self.socket = None
        self.isRunning = False
        print("Connection closed")

    def add_response_handler(self, handler: callable):
        self.responseHandlers.append(handler)

    def __del__(self):
        self.close()

    def __exit__(self, exc_type, exc_value, traceback):
        self.close()
