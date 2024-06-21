class AbstractObject:
    count: int = 0

    def __init__(self, count: int = 1):
        self.count = count
        pass

    def take_one(self) -> 'AbstractObject':
        portion = self.__class__(1)
        self.count -= 1
        return portion

    def add_one(self):
        self.count += 1

    def add(self, other: 'AbstractObject'):
        if isinstance(other, self.__class__):
            self.count += other.count
        else:
            raise ValueError("Cannot add different objects")
        other.count = 0

    def set_count(self, count: int):
        self.count = count

    def get_name(self) -> str:
        pass


class Food(AbstractObject):
    def __init__(self, count: int = 1):
        super().__init__(count)

    def get_name(self) -> str:
        return "food"


class AbstractStones(AbstractObject):
    def __init__(self, count: int = 1):
        super().__init__(count)


class Linemate(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)

    def get_name(self) -> str:
        return "linemate"


class Deraumere(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)

    def get_name(self) -> str:
        return "deraumere"


class Sibur(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)

    def get_name(self) -> str:
        return "sibur"

class Mendiane(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)

    def get_name(self) -> str:
        return "mendiane"


class Phiras(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)

    def get_name(self) -> str:
        return "phiras"


class Thystame(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)

    def get_name(self) -> str:
        return "thystame"

class Egg(AbstractObject):
    def __init__(self):
        super().__init__(0)

    def get_name(self) -> str:
        return "egg"
