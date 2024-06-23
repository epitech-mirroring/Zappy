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
        obj_to_add: AbstractObject or None = None
        for o in self.cells[y][x]:
            if isinstance(o, obj.__class__):
                obj_to_add = o
                break
        if obj_to_add is not None:
            obj_to_add.add(obj)
        else:
            self.cells[y][x].append(obj)

    def remove_object(self, x: int, y: int, obj: AbstractObject):
        if y in self.cells and x in self.cells[y]:
            if obj in self.cells[y][x]:
                obj_to_remove: AbstractObject or None = None
                for o in self.cells[y][x]:
                    if isinstance(o, obj.__class__):
                        obj_to_remove = o
                        break
                if obj_to_remove is not None:
                    to_remove_count = obj.count
                    new_count = obj_to_remove.count - to_remove_count
                    obj_to_remove.set_count(new_count)
                    if new_count <= 0:
                        self.cells[y][x].remove(obj_to_remove)

    def remove_object_by_type(self, x: int, y: int, obj_type: AbstractObject.__class__, count: int = 1):
        if y in self.cells and x in self.cells[y]:
            obj_to_remove: AbstractObject or None = None
            for o in self.cells[y][x]:
                if isinstance(o, obj_type):
                    obj_to_remove = o
                    break
            if obj_to_remove is not None:
                to_remove_count = min(count, obj_to_remove.count)
                new_count = obj_to_remove.count - to_remove_count
                obj_to_remove.set_count(new_count)
                if new_count <= 0:
                    self.cells[y][x].remove(obj_to_remove)

    def get_objects(self, x: int, y: int) -> list[AbstractObject]:
        if y not in self.cells:
            return []
        if x not in self.cells[y]:
            return []
        return self.cells[y][x]

    def clear_cell(self, x: int, y: int):
        if y in self.cells and x in self.cells[y]:
            self.cells[y][x] = []

    def get_objects_by_type_on_cell(self, x: int, y: int, obj_type: AbstractObject.__class__) -> AbstractObject or None:
        objects = self.get_objects(x, y)
        for obj in objects:
            if isinstance(obj, obj_type):
                return obj
        return None

    def remove_all_of_type_on_cell(self, x: int, y: int, obj_type: AbstractObject.__class__):
        objects = self.get_objects(x, y)
        for obj in objects:
            if isinstance(obj, obj_type):
                self.cells[y][x].remove(obj)

    def __str__(self):
        result = ""
        for i in range(self.height):
            for j in range(self.width):
                result += f"{self.cells[i][j]} "
            result += "\n"
        return result

    def __repr__(self):
        return self.__str__()
