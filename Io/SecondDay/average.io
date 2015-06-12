i := 8
i type println
if(i type == Number type, "OK" println)
str := "I'm String"
str type println

List myAverage := method(
	if(self size == 0, return 0) 
	sum := 0
	
	self foreach(item,
		item type println, 	// 不打印的？
		if(item type != Number type, // 无效？
			return 0
			Exception raise("Error! check your list.")
		),
		sum = sum + item
	),
	return sum/(self size)
)

list(0) myAverage println
list(1,2,3) myAverage println
list(1,"a",3) myAverage println