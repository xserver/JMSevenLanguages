

target = rand(10)
puts "Guess a number, input 0~9, please."

while true
	puts("input:")
	txt = gets()
	num = txt.to_i

	if num > target
		puts("Too large, try again.\n")
	elsif num < target
		puts("Too small, try again.\n")
	else
		puts "bingo, the number is ".(target.to_int())
		break
	end
end
