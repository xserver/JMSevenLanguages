#coding=utf

"""
	少点空格，导致无法运行
"""

# class MyClass(object):
# 	def showname(self):
# 		"""display instance attribute and class name""" 
# 		print 'My name is', self.__class__.__name__



class MyClass(object):
def showname(self):
	"""display instance attribute and class name""" 
	print 'My name is', self.__class__.__name__



foo1 = MyClass()
foo1.showname()


