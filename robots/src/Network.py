import socket
import select


class NetworkManager:
    serverIP: str = "127.0.0.1"
    serverPort: int
    socket = None
    sendQueue = []
    responseHandlers = []

    def __init__(self, server_port: int, server_ip: str = "127.0.0.1"):
        self.serverIP = server_ip
        self.serverPort = server_port

    def connect(self):
        print(f"Connecting to {self.serverIP}:{self.serverPort}")
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
        self.socket.setblocking(False)
        self.socket.connect((self.serverIP, self.serverPort))

    def __send(self, message: str):
        self.socket.sendall(message.encode())

    def send(self, message: str):
        self.sendQueue.append(message)

    def receive(self) -> str:
        return self.socket.recv(1024).decode()

    def start(self):
        self.connect()
        while True:
            write_list = []
            read_list = []
            if self.sendQueue:
                write_list.append(self.socket)
            else:
                read_list.append(self.socket)
            readable, writable, exceptional = select.select(read_list,
                                                            write_list,
                                                            [])
            if readable:
                response = self.receive()
                for line in response.split("\n"):
                    for handler in self.responseHandlers:
                        handler(line)
            if writable:
                self.__send(self.sendQueue.pop(0))

    def close(self):
        self.socket.close()
        print("Connection closed")

    def add_response_handler(self, handler: callable):
        self.responseHandlers.append(handler)

    def __del__(self):
        self.close()

    def __exit__(self, exc_type, exc_value, traceback):
        self.close()
