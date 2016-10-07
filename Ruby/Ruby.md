# Ruby

http://blog.shaofantasy.cn/?tag=Seven%20Languages%20In%20Seven%20Weeks

[Ruby 练习](http://blog.shaofantasy.cn/?tag=Ruby)

[w3c Ruby tutorial](http://www.w3cschool.cc/ruby/ruby-tutorial.html)

[Ruby 第三天 CSV](http://www.bennadel.com/blog/2063-seven-languages-in-seven-weeks-ruby-day-3.htm)

函数
数组，有序，
散列（哈希）- 字典，dictionary

## DSL(domain-specific language) 领域特定语言，元编程
自由地组合模块（类、方法、属性），产生出新的类
这个概念需要进一步学习

## 鸭子类型 ？

### 第一感觉

#### 无类型
视野开阔了，很多时候你无需关心类型是什么，参数命名好的话，秒懂。不懂也可以查看。

#### 全对象
3.class 

### 简洁、灵活
Block 比 C++，OC，Java 简洁太多了。
DSL

--
[ruby 加载资源](http://ruby-china.org/topics/25706)

``` ruby
load and require 是 Kernel 提供的类加载接口

load    'example.rb' # 加载多次，加载配置文件，在 irb 中使用，需要后缀名
require 'example'    # 加载一次，加载库文件，在脚本中使用

extend and include 是互相引用的接口
include
extend

autoload
```

引用
Math.sqrt


## main
ARGV 预置的参数
ARGV[0]
ARGV[1]


## variable
global variable `$开头`
local variable `abc or _ 开头`
class variable `@@ 开头`
instance variable `@ 开头`
pseudo variable	`Ruby 预置：nil、true、false、self`
Pre-defined variable `？？`
constant variable`ABC_XYZ`
保留字
    
## String
'不可变'
"可变，带解释功能，#{var name}"
'''string'''

#### symbol
to_s
to_sym


## output
print 'hello', "world"
puts 'hello', 'world'  # 每个都自带换行
p "100"  VS p 100  # 带类型提示，但不支持转义字符

## 编码问题
\# encoding: UTF-8  # ruby 2.0 默认 utf-8
\# encoding: GBK, GB 2312

执行时指定：ruby -E UTF-8 name.rb

## 注释
``` Ruby
# 单行
=begin
	多行 
	多行 
=end
Mach.sqrt(100)
```

## 控制语句

true, false = nil

#### 循环语句
``` ruby
while condition
end

# 10次循环，迭代器，iterator
10.times do
	p 'haha'
end

# each 处理数组
array.each do |item|
	p item
end

hash.each do |key, value|
	p key, value
end


```


## 数据
array = [" 小 林 ", " 林 ", " 高 野 ", " 森 冈 "]
#### hash
address = {:name => "高 桥", :pinyin => "gaoqiao", :postal => "1234567"}
address = {name: "高 桥", pinyin: "gaoqiao", postal: "1234567"}
address[name]


## regular expression, 正则
pattern
/content A/i = ~ "content BACD"
