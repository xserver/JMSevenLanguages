//	数组内放数组
2d_array := list(
 list(1, 2, 3),
 list(4, 5, 6),
 list(7, 8, 9)
)

sum := 0
2d_array foreach(sub, sub foreach(item, (sum = sum + item)))
"The sum of this 2D array is: " print; sum println
