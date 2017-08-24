var length = 16;                                  // Number 通过数字字面量赋值 
var points = length * 10;                         // Number 通过表达式字面量赋值
var lastName = "Johnson";                         // String 通过字符串字面量赋值
var cars = ["Saab", "Volvo", "BMW"];              // Array  通过数组字面量赋值
var person = {firstName:"John", lastName:"Doe"};  // Object 通过对象字面量赋值

console.log(length);

// typeof "John"                // 返回 string 
// typeof 3.14                  // 返回 number
// typeof false                 // 返回 boolean
// typeof [1,2,3,4]             // 返回 object
// typeof {name:'John', age:34} // 返回 object

console.log(typeof length);
console.log(typeof lastName);

console.log("-------------- null vs underfined");
console.log(typeof null);
console.log(typeof underfined);