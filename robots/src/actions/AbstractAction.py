from .. import Bot


class AbstractAction:
    time_to_execute: int
    has_been_executed: bool = False
    requested_time: float

    def __init__(self, time_to_execute: int):
        self.time_to_execute = time_to_execute

    def execute(self, bot: Bot):
        self.has_been_executed = True

    def handle_response(self, response: str, bot: Bot):
        pass

    def set_requested_time(self, requested_time: float):
        self.requested_time = requested_time
