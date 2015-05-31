 # each.rb
array = []
# puts array.methods.sort
8.times do 
	number = rand(20)
	array.push(number)
	array << number
end

puts array.length
puts

index = 0
array.each do
	|item|
	if index % 4 == 0
		print "\n"
	end
	index += 1
	print item, "\t"
end
puts
puts
array.each_slice(4) {|x| p x}
puts

# array.each_index {|index| puts array[index]}
