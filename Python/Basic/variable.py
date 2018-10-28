# variable.py

print (type('aa'), type(123))


# 
GLOBALNumber = 1;

def temporary():
	GLOBALNumber = 2

def updateGlobalVariable():
	global GLOBALNumber
	GLOBALNumber = 3

if __name__ == "__main__":
	 
    print ('This is main of module "hello.py"')
    temporary()
    print (GLOBALNumber)
    
    updateGlobalVariable()
    print (GLOBALNumber)