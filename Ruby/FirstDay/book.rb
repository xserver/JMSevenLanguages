# 参数
language = 'Ruby'
puts 'Ruby 总是在解释，因为它是解释型语言，伪强类型（运行时可以改变）'
puts "Ruby 总会返回一个值，void 也是一种返回\n\n"

x = 3
if x == 3
	puts 'if x = 3'
end
unless x != 3
	puts 'unlee 和 if 相反的关键字'
end

until x == 1	# 直到 x == 1 才跳出，和 while
	puts x
	x = x - 1 
end

# 字符串
puts 
puts 'Hello, #{language}, 单引号不解释'
puts "Hello, #{language}, 双引号代表可变，会解释\n\n"


puts 'Ruby 是纯面向对象语言，所以 Ruby 的世界：万物皆对象'
puts language.class
puts 3.class
puts 4.0.class
# puts 3.methods

