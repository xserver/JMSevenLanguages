[IO Home](http://iolanguage.org/)
[IO GitHub](https://github.com/stevedekorte/io)
[Io 练习](http://blog.shaofantasy.cn/?tag=Io)
安装, 有 brew, Mac 才更好，要半个小时。。。去喝杯茶
```brew install io```
[Io Programming Guide](http://iolanguage.org/scm/io/docs/IoGuide.html)

## 吐槽
异常冷门的语言。
控制语句好挫。

if-else 好囧
if(<condition>, <do message>, <else do message>)

分号 和 逗号是什么意义？

## 赞
### 槽
Io 槽的概念太有趣了，这样就像小时候组装玩具一样，创建不同的『槽』，『镶嵌』一个又一个模块，组成你的机器人。
好了，问题来了：『槽』与『槽』之间是如何协调工作的？


### 原型
原型的概念，复制，复制。和其他语言模板 new 不同？

### 消息
"Hello Io." println
左接受		右指令消息，  右→左
有 Objective-C 背景，无压力。

### 运算符
打印运算符列表优先级
添加自定义运算符，赞，比C++优雅多了


### clone
这里的 clone 和别的语言 copy 是不一样的，这里是『去中心化的 clone』


--
## 第一天
[Assignment operator action](http://iolanguage.org/scm/io/docs/IoGuide.html#Syntax-Operators)

|operator|action|
-------------------
| ::= |	Creates slot, creates setter, assigns value
| :=  |	Creates slot, assigns value
| =	  | Assigns value to slot if it exists, otherwise raises exception


## 第二天
函数、逻辑控制，都是 括号+逗号

