// == 总是试图比较他们的值，如果类型不一样，总是试图作转化。
// === 比较同一性，不作转化就比较
// == 如果是基本类型 (string, number, boolean) ，比较他们的值，

console.log("a" == "b")


// typeof 返回的是 string
console.log("String " + 
	(typeof('x') == String) +" "+ 
	(typeof('x') == "string"))

if (typeof(1) === "number") {
	console.log('it is number')
}

//	instanceof 对象类型
if ([] instanceof Array) {
	console.log('it is Array')
}



