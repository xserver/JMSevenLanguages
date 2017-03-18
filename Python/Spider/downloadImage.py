#coding = utf-8

import requests
import urllib
import re
import time
import random

saveDir = '/Users/macro/GitHub/JMSevenLanguages/Python/Spider/Regular/images/'
url = 'https://ke.qq.com'
count = 0
content = requests.post(url).text

## <img src="//p.qpic.cn/qqconadmin/0/90af48836e3a46df9c67aeb6785bf5cf/0" width="90"
imgs = re.findall('<img src=\\"(.*?)\\"', content) 
print(imgs.count)

opener = urllib.request.build_opener()

for img in imgs:
	try:
		count += 1
		imgUrl = 'http://' + img.replace('//', '')
		outPath = saveDir + str(count) + '.jpg'

		if 'p.qpic.cn' in imgUrl:
			print(imgUrl)
		else:
			print('Error : ' + imgUrl)
			continue

		with urllib.request.urlopen(imgUrl) as file:
		    with open(outPath, 'wb') as outfile:
		        outfile.write(file.read())

		print('下载了第' + str(count) + u'张图片')
		time.sleep(random.uniform(0.5,1))	#睡眠函数用于防止爬取过快被封IP
		
	except:
		pass
		print('Error : ' + imgUrl)
		time.sleep(random.uniform(0.5,1))


