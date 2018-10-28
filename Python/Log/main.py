import sys
import inspect

# 丑
def sayHello():
	print (__file__, sys._getframe().f_code.co_name, sys._getframe().f_lineno)
	print (sayHello.__name__)

def sayHello2():
	print (inspect.stack()[0][3])


if __name__ == "__main__":

	sayHello()
	print (inspect.stack()[0][3])
	sayHello2()
	