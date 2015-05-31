sform# hash_table_array.rb

dictionary = {  1 => 'one', 
				2 => 'two'}

puts dictionary.class
puts dictionary

puts dictionary[0]
puts dictionary[1]
puts '----'
puts dictionary.to_a.class
puts dictionary.to_a

puts "----\n\n"

array = dictionary.to_a
dic = Hash[*array]	# 折成一半
puts dic.class
puts dic
puts
key = [1, "one"]
puts dic[key]

stuff = {:array => [1,2,3], :string => 'Hi, mom!'}
puts stuff[:string]