import sys
import os
import subprocess

def sayHello():
	os.system('ls -al')

def fetchCommandResult():
	result = os.popen('ls -al')	# popen = pipeline open
	print (result, type(result))
	# print (result.read())
	print (result.readlines()[0].replace('\n', ''))

def sayHi():
	subprocess.call('say hi')
	# subprocess.popen

if __name__ == "__main__":
   # sayHello()
   #  fetchCommandResult()
	sayHi()