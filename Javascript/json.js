//	string to json
var text = '{ "name":"Google" , "url":"www.google.com" }';
console.log(text)

// JavaScript 内置函数 JSON.parse() 将字符串转换为 JavaScript 对象:
var obj = JSON.parse(text);
console.log(obj)

console.log(obj.name)

// string to json
text = '["array first obj", "222"]'
obj = JSON.parse(text);
console.log(obj[0])

console.log('----------------------------')


// json to string
var str =JSON.stringify(obj);
console.log(str)