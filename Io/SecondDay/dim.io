List2D := List clone

//	首字符 是数字，算是类，还是克隆？
// y 行，每行 x 列， (x,y)
List2D dim := method(x, y, 
	self setSize(y)

	for (j, 0, y-1,
		self atPut(j, (list() setSize(x)))
	)
	return self
)

List2D dim(2,2) println

List2D get := method(x, y,
	return self at(y) at(x)
)

List2D set := method(x, y, value,
	self at(y) atPut(x, value)
)

test := List2D clone dim(2, 2)
test set(0,0, "(0,0)")
test set(1,0, "(0,1)")
test set(0,1, "a")

"(0,1) = " print test get(0,1) println
test println



