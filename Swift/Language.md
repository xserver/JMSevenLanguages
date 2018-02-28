### [The Swift Programming Language](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/index.html#//apple_ref/doc/uid/TP40014097-CH3-ID0)   ★

* [★ The Basics](#the-basics)
* [Basic Operators](#basic-operators)
* [Strings and Characters](#strings-and-characters)
* [Collection Types](#collection-types)
* [Control Flow](#control-flow)
* [Functions](#functions)
* [Closures](#closures)
* [Enumerations](#enumerations)
* [Classes and Structures](#classes-and-structures)
* [Properties](#properties)
* [Methods](#methods)
* [Subscripts 下标](#subscripts)
* [Inheritance 继承](#inheritance)
* [Initialization](#initialization)
* [Deinitialization](#deinitialization)
* [★ Automatic Reference Counting](#automatic-reference-counting)
* [★ Optional Chaining](#optional-chaining)
* [★ Type Casting](#type-casting)
* [★ Nested Types](#nested-types)
* [Extensions 类似 OC Categories](#extensions)
* [Protocols](#protocols)
* [Generics](#generics)
* [Access Control 访问控制](#access-control)
* [Advanced Operators](#advanced-operators)

#### The Basics
	Declaring Constants and Variables = 声明常量和变量, let & var
	Type Annotations = 类型标记 name: NSString
    Naming Constants and Variables = 变量名是 any character. emoji 都可以

	Printing Constants and Variables = 打印 println("my name is \(var).")
	
	Semicolons	= 分号的作用
	Type Safety and Type Inference = 类型推断

	Numeric Type Conversion = 数字类型转换（无符号，32 64bit）
	Integer and Floating-Point Conversion = 整形和浮点型转换

	Type Aliases = 类型别名
	Booleans = 严格的布尔
	Tuples = 元组集合类型

Optionals [Optionals 语法多糖难解释](http://joeyio.com/ios/2014/06/04/swift---/)

```swift
let possibleString: String? = "An optional string."
println(possibleString!) // 需要惊叹号来获取值
// 输出 "An optional string."

let assumedString: String! = "An implicitly unwrapped optional string."
println(assumedString)  // 不需要感叹号
// 输出 "An implicitly unwrapped optional string."
```
	★ Optionals = enum Optional<T> 泛型系统 ???
		?	value 可能为 nil，请求保护，停止执行余下语句。
		!	肯定有值，请拆包使用我！自动解释
		as? 

	nil
	If Statements and Forced Unwrapping = if 语句与强拆包

	★ Optional Binding = 
	★ Implicitly Unwrapped Optionals	 = 

	Assertions = 断言
	Debugging with Assertions
	When to Use Assertions

### Basic Operators
	Terminology
	Assignment Operator = 分配
	Arithmetic Operators = 算术
	Remainder Operator = 取余
	... 省略
	Explicit Parentheses = 括号
	
### Collection Types
	Mutability of Collections
	Arrays
	Sets = 无序 & 唯一
	Performing Set Operations = Set 的集合操作
	Dictionaries
```swift
//	Array
var someInts = [Int]()
println("someInts is of type [Int] with \(someInts.count) items.")
someInts.append(3)
someInts = []

var threeDoubles = [Double](count: 3, repeatedValue: 1.2)
var shoppingList: [String] = ["Eggs", "Milk"]
shoppingList += ["Chocolate Spread", "Cheese", "Butter"]
shoppingList[4...6] = ["Bananas", "Apples"] // ?

shoppingList.insert("Maple Syrup", atIndex: 0)
let mapleSyrup = shoppingList.removeAtIndex(0)
let apples = shoppingList.removeLast()

for item in shoppingList {
    println(item)
}

for (index, value) in enumerate(shoppingList) {
    println("Item \(index + 1): \(value)")
}
```

```swift
// Set
var letters = Set<Character>()
println("letters is of type Set<Character> with \(letters.count) items.")
```
略

### Properties
	Stored Properties = 存储
		Stored Properties of Constant Structure Instances
		★ Lazy Stored Properties = 使用时创建
		Stored Properties and Instance Variables
		
	Computed Properties = 计算
		Read-Only Computed Properties
		var obj: type { return }
		
	Property Observers = 观察 
		var obj: type {willSet, didSet}
	
	Global and Local Variables = 全局&局部
	
	Type Properties = 类型
		★ Type Property Syntax
		Querying and Setting Type Properties
		
``` swift
class SomeClass { // enum or struct or class
	//	static 作为类属性，共享一份
    static var storedTypeProperty = "Some value."
    static var computedTypeProperty: Int {
        // return an Int value here
    }
    class var overrideableComputedTypeProperty: Int {
        // return an Int value here
    }
```
### Initialization
	Setting Initial Values for Stored Properties = 初始化属性
		Initializers
		Default Property Values
		
	Customizing Initialization = 自定义初始化
		Initialization Parameters
		Local and External Parameter Names = 构造器和函数一样，参数有自己的名字
			类比 OC 的 [obj callPhone:186 personName:@"Peter"]
			
		Initializer Parameters Without External Names = 参数不使用名字，用 _
			init(_ celsius: Double) {...}
			
		★ Optional Property Types = 说明 ? 的用处
			var response: String?
			1、初始自动为 nil，2、未来可能有值，3、无值时自动避免执行
			
		Assigning Constant Properties During Initialization = init 常量可修改
			常量属性只能在定义它的类的构造器中修改，不能在子类中修改
		
	Default Initializers = 默认的初始化
		Memberwise Initializers for Structure Types
		
	Initializer Delegation for Value Types = 构造器叠加使用
	
	Class Inheritance and Initialization = 类继承和初始化
		Designated Initializers and Convenience Initializers 
			= 必有的构造器 与 便利的辅助构造器
		Syntax for Designated and Convenience Initializers
			convenience 是个关键字
		★ Initializer Delegation for Class Types
		★ Two-Phase Initialization
		★ Initializer Inheritance and Overriding = 构造器的继承和重载
			与方法、属性和下标不同，在重载构造器时你没有必要使用关键字override
		Automatic Initializer Inheritance
		Designated and Convenience Initializers in Action
		
	Failable Initializers = 失败
		! ? 赋值 optional 一脉相承的概念
		init?(species: String) { ... return nil}, ?表示可能失败，返回 nil。
		Failable Initializers for Enumerations
		Failable Initializers for Enumerations with Raw Values
		Failable Initializers for Classes
		Overriding a Failable Initializer
		The init! Failable Initializer
		
	Required Initializers
		required init() {...}
		
	★ Setting a Default Property Value with a Closure or Function
		闭包
	
(Designated 和 Convenience)[https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/Art/initializerDelegation01_2x.png]

```swift
//	_ 下划线替代参数名
struct Celsius {
    var temperatureInCelsius: Double
    init(fromKelvin kelvin: Double) {
        temperatureInCelsius = kelvin - 273.15
    }
    init(_ celsius: Double) {
        temperatureInCelsius = celsius
    }
}
let bodyTemperature = Celsius(37.0)

//	convenience
class RecipeIngredient: Food {
    var quantity: Int
    init(name: String, quantity: Int) {
        self.quantity = quantity
        super.init(name: name)
    }
    override convenience init(name: String) {
        self.init(name: name, quantity: 1)
    }
}
//	Failable Initializers for Enumerations
enum TemperatureUnit {
    case Kelvin, Celsius, Fahrenheit
    init?(symbol: Character) {
        switch symbol {
        case "K":
            self = .Kelvin
        case "C":
            self = .Celsius
        case "F":
            self = .Fahrenheit
        default:
            return nil
        }
    }
}
```
### Optional Chaining

### Type Casting

### Nested Types

### Access Control
	Modules and Source Files
	Access Levels
	Guiding Principle of Access Levels
	Default Access Levels












