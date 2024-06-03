try:
    import unittest2 as unittest
except ImportError:
    import unittest
from robots import src as lib


class ObjectsTest(unittest.TestCase):
    def test_constructor(self):
        obj = lib.Food()
        self.assertEqual(obj.count, 1)
        obj = lib.Food(5)
        self.assertEqual(obj.count, 5)

    def test_take_one(self):
        obj = lib.Food(5)
        portion = obj.take_one()
        self.assertEqual(obj.count, 4)
        self.assertEqual(portion.count, 1)
        self.assertIsInstance(portion, lib.Food)

    def test_add_one(self):
        obj = lib.Food(5)
        obj.add_one()
        self.assertEqual(obj.count, 6)

    def test_add(self):
        obj1 = lib.Food(5)
        obj2 = lib.Food(3)
        obj1.add(obj2)
        self.assertEqual(obj1.count, 8)
        self.assertEqual(obj2.count, 0)


if __name__ == '__main__':
    unittest.main()
