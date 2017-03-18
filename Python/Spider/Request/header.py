# coding=utf-8
"""xx"""
import requests


url = 'https://api.github.com/some/endpoint'
headers = {'user-agent': 'my-app/0.0.1'}
r = requests.get(url=url, headers=headers)

print(r.status_code, r.url)
print(r.headers['content-type'], r.encoding)
print(r.text)
