# foreach_hash.rb

dictionary = {  1 => 'one', 
				2 => 'two'}

# each 枚举
dictionary.each {|k, v| puts k => v}

puts dictionary.keys
puts dictionary.values

puts dictionary.keys.class
key = dictionary.keys[0]
puts key => dictionary[key]