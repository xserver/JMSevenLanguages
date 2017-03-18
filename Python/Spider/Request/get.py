# coding=utf-8
"""xx"""
import requests


# url = 'https://www.baidu.com'
url = 'https://www.zhihu.com/question/27032155/answer/151862277'
r = requests.get(url=url)

print(r.status_code, r.url)
print(r.headers['content-type'], r.encoding)
print(r.text)
