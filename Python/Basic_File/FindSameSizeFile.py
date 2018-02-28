#coding=utf8
import sys
import os
import codecs
import shutil

# 不准确的做法

dir = os.getcwd()  
syscoding = sys.getfilesystemencoding()

filedic = {}
repeatlist = set()

# 根目录、所有目录、目录下的文件  
for root, dirs, files in os.walk(dir):  
	for name in files:  
		path = os.path.join(root, name) 
		# key=size
		# value=path
		print(name)

		size = os.path.getsize(path)

		if size in filedic:
			#可能重复
			repeatlist.add(path)
			repeatlist.add(filedic[size])
		else:
			filedic[size] = path


newdir = os.getcwd() + '/repeatdir'

for path in repeatlist:
	name = os.path.basename(path)
	newpath = newdir + '/' + name
	shutil.move(path, newpath)

	