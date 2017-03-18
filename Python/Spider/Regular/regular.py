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
	print(img)