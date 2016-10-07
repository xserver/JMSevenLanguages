# 替换
str = "World Hello World".sub('World', 'Ruby')
puts(str)

puts()

# 全部替换
str = '1 + 1 + 2 + 3 + 5 = ?'.gsub('+', '-')
puts(str)

puts()

# 查找
str = "Hello Ruby."
str.scan(/[Ruby\.]/) { |x| puts "Hello Ruby.".index(x)}

puts()

# 遍历
# http://www.yiibai.com/ruby/ruby_loops.html
3.times do puts "3 puts" end

puts()

n = 0
while (n < 3)
	n = n+1
	puts "This is sentence number" + n.to_s + "."
end

for i in 1..3
	puts "This is sentence number" + i.to_s + "."
end



# (The Pragmatic Programmer's Guide)[http://ruby-doc.com/docs/ProgrammingRuby/]
# (正则表达式)[http://ruby-doc.org/core-1.9.3/Regexp.html]
# (range)[http://ruby-doc.org/core-1.9.3/Range.html]