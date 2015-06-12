//	获取 Number 的 "/" 槽，之后重命名
Number getSlot("/") println

Number setSlot("division", Number getSlot("/"))
  
//	把 "/" 槽的 method 替换掉
Number setSlot("/",
	method( denominator,
		if((denominator == 0),return (0))
		
		return(self division( denominator))
	)
)
  
(1 / 0) println
(2 / 1) println