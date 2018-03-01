#!/usr/bin/python
#coding=utf-8
import os
'''
	input 和 raw_input 区别：
	后者可以任意输入
'''

while True:
	word = raw_input("input word: ")
	if word == '--help' or word == '-help':
		print('input  \'--quite\'  stop me.')
		continue
	if word == '--quite':
		print('祝愿你武运隆昌！')
		break
	os.system('say ' + word)
