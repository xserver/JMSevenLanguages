#coding=utf-8

"""

python 没有数组的说法


序列		sequence
	字符串	string
	列表	list
	元组	tuple
"""

aList = [1, 2, 3, 4]

print aList[0]
print aList
print

aTuple = ('robots', 77, 93, 'try')
print aTuple[0]
print aTuple
print

aDict = {'host': 'earth'} # create dict
print aDict.keys()
print aDict['host']

for key in aDict:
	print key, aDict[key]