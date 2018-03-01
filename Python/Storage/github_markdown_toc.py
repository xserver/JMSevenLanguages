#coding=utf8
import os
import urllib

'''
	github markdown 不支持 [TOC] 生成目录，此脚本自动生成3级目录的锚点代码。
	PS ：现在的判断条件不完善，误判 ####， 不支持层级
	if cmp(line[0:3], '###') == 0:
'''
# filepath = "github_markdown_toc.py"
filepath = "github.txt"
with open(filepath, 'r') as f:
	while 1:
		line = f.readline()
		if not line:
			break
		if len(line) > 3:
			if cmp(line[0:3], '###') == 0:
				title = line[3:].strip()
				anchor = urllib.quote(title.replace(' ', '-').lower())
				print '* [' + title + '](#' + anchor + ')'
		# print line.strip()

	f.close()


