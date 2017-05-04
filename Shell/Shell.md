## Shell 浅尝辄止系列


## ?
export 作用


## 天坑
空格



## 工具
#### Sublime Text Build Shell
{
	"cmd": ["sh","$file"],
	"selector": "source.shell"
}

## 语言

#### variable
```java
var=hello
echo ${var}
```


#### if

#### 数组
ARCHS=("arm64" "armv7s" "armv7" "i386" "x86_64")

#### for
```java
ARCHS=("arm64" "armv7s" "armv7" "i386" "x86_64")

for ((i=0; i < ${#ARCHS[@]}; i++))
do
	echo ${ARCHS[i]}
done

```

#### function
```java
myfunc()
{
	file_path=$0
	var1=$1

    echo ":" ${file_path} ${var1}
}

myfunc 11
```
