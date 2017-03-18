#coding = utf-8

import requests
import urllib

outPath = '/Users/macro/GitHub/JMSevenLanguages/Python/Spider/Regular/2.jpg'
imgUrl = 'http://p.qpic.cn/qqconadmin/0/e82007362f0948b4a24adb5f86dab534/0'
with urllib.request.urlopen(imgUrl) as file:
    with open(outPath, 'wb') as outfile:
        outfile.write(file.read())

