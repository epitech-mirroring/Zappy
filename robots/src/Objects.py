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


class Food(AbstractObject):
    def __init__(self, count: int = 1):
        super().__init__(count)


class AbstractStones(AbstractObject):
    def __init__(self, count: int = 1):
        super().__init__(count)


class Linemate(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)


class Deraumere(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)


class Sibur(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)


class Mendiane(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)


class Phiras(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)


class Thystame(AbstractStones):
    def __init__(self, count: int = 1):
        super().__init__(count)


class Egg(AbstractObject):
    def __init__(self):
        super().__init__(0)
