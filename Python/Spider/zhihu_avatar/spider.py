#coding = utf-8
"""作者：挖数
链接：https://www.zhihu.com/question/20899988/answer/96904827"""

import requests
import urllib
import re
import random
from time import sleep

def main():
	url = 'https://www.zhihu.com/question/27032155/answer/151862277'
	headers = {}
	count = 1
	saveDir = '...'
	for x in range(20, 3600, 20):
		#知乎用offset控制加载的个数，每次响应加载20
		data = {'start':'0', 'offset':str(x), '_xsrf':'a128464ef225a69348cef94c38f4e428'}
	

	content = requests.post(url, headers = headers, data = data, timeout = 10).text
	#用post提交form data

	imgs = re.findall('<img src = \\\\\"(.*?)_m.jpg',content) 
	#在爬下来的 json 上用正则提取图片地址，去掉_m为大图 
	
	for img in imgs:
		try:
			img = img.replace('\\', '')
			#去掉\字符这个干扰成分
			pic = img + '.jpg'
			path = saveDir + str(count) + '.jpg'
			#声明存储地址及图片名称

			urllib.urlretrieve(pic, path)
			#下载图片
			# print u'下载了第' + str(count) + u'张图片'

			count += 1
			sleep(random.uniform(0.5,1))
			#睡眠函数用于防止爬取过快被封IP
		except:
			# print u'抓漏1张'
			pass
		sleep(random.uniform(0.5,1))

if __name__ == '__main__':
	print ('This is main of module')
	main()
