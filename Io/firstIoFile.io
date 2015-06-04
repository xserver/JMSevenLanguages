"Hello Io" println

Person := Object clone
Student := Person clone
boy := Student clone	//	小写和大写首字母的区别，小写是复制品，大写是类

/* 创建一个叫 name 槽 */
Person ID := method("My ID = ?" println)
Student name := method("I am a studen." println)
boy say := method("say..." println)

boy name
boy say
boy ID

Student name
Person ID
//	Person name	// Person 无 name 槽


boy getSlot("name") println

boy getSlot("xx") println

boy proto println	//	原型

Lobby println	//	主命名空间

Lobby slotNames println
Student slotNames println
