#coding=utf
"""os.walk(dir) 是三列的数组"""
  
import os  
dir = os.getcwd()  
  
for cons in os.walk(dir):  
    print cons  
  
# 根目录、所有目录、目录下的文件  
for root, dirs, files in os.walk(dir):  
    for name in files:  
        print os.path.join(root, name) 


############################################

def subString(str, sub):  
    return sub in str  
  
  
dir = '/Users/xserver/Desktop/new_res/'  
  
for root, dirs, files in os.walk(dir):    
    for name in files:  
        path = os.path.join(root, name)   
        if subString(path, '.jpg'):  
            path2 = path.replace('.jpg','.png')  
            print path  
            shutil.move(path, path2);  