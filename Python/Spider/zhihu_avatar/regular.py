#coding = utf-8

import requests
import urllib
import re

# url = 'http://www.apple.com'
url = 'https://ke.qq.com'

content = requests.post(url).text
# print(content)

# <img src="//p.qpic.cn/qqconadmin/0/90af48836e3a46df9c67aeb6785bf5cf/0" width="90" height="90" alt="职坐标" title="职坐标">aaa
imgs = re.findall('<img src=\\"(.*?)\\"', content) 
print(imgs)

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
