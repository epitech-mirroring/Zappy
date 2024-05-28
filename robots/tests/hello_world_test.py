try:
    import unittest2 as unittest
except ImportError:
    import unittest
import io
import contextlib
from robots import src as lib


class HelloWorldTests(unittest.TestCase):
    def test_example(self):
        with io.StringIO() as buf, contextlib.redirect_stdout(buf):
            lib.hello_world()
            self.assertEqual(buf.getvalue(), 'Hello, World!\n')


if __name__ == '__main__':
    unittest.main()
