#coding=utf8
import sys
import os
import codecs

# reload(sys)
# sys.setdefaultencoding('utf-8')

dir = os.getcwd()  
syscoding = sys.getfilesystemencoding()

# 根目录、所有目录、目录下的文件  
for root, dirs, files in os.walk(dir):  
	for name in files:  
		path = os.path.join(root, name) 
		print('path = ' + path)
		outfile = open(path+'.txt','w')
		
		with open(path, 'r', encoding='utf_16le') as file:
			lines = file.readlines()
			row = 0
			print(lines)
			for line in lines:
				print(line)
				row += 1
				if len(line) > len('Dialogue:'):
					index = line.find('shad1}')
					if index > 0:
						index += len('shad1}')
						outline = line[index:]
						outfile.write(outline + '\n')
		outfile.close()
		break