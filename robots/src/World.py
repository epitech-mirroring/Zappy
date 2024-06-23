from .Objects import AbstractObject


class World:
    width: int
    height: int
    cells: dict[int, dict[int, list[AbstractObject]]]

    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height
        self.cells = {}
        for i in range(height):
            self.cells[i] = {}
            for j in range(width):
                self.cells[i][j] = []

    def add_object(self, x: int, y: int, obj: AbstractObject):
        if y not in self.cells:
            self.cells[y] = {}
        if x not in self.cells[y]:
            self.cells[y][x] = []
        self.cells[y][x].append(obj)

    def remove_object(self, x: int, y: int, obj: AbstractObject):
        if y in self.cells and x in self.cells[y]:
            self.cells[y][x].remove(obj)

    def get_objects(self, x: int, y: int) -> list[AbstractObject]:
        if y not in self.cells:
            return []
        if x not in self.cells[y]:
            return []
        return self.cells[y][x]
