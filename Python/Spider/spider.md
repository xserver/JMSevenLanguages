## 思路
    下载 HTML 文件
    解释 HTML 文件
    找出想要的 URL （domain、image
    把这些 URL 存到集合中
    遍历这些 URL & 下载 => 完成

### 要点
    1、递归子页面，地址重复、环地址打破，外链
    2、数据解释，正则找出目标数据
    2、URL 合法性
    3、隐式加载的数据
    4、需要签名的数据
    5、下载队列
    6、大文件处理
    7、攻防事项（IP 被封处理）

### 其它
    1、编码问题


### lib
[requests](http://www.python-requests.org/en/master/)

--

以前写过一个爬虫入门的系列，[专栏：Python爬虫入门教程](http://blog.csdn.net/column/details/why-bug.html)
