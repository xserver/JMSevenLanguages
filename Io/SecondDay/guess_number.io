standardIO := File standardInput
guess := nil
answer := (Random value(9)) floor
count := 0

while( count < 10,
	"Guess a number 0~9:" println
	guess := standardIO readLine() asNumber()
	
	if(guess == answer,
		"You are right !" println; break,

		if(guess > answer,   # if-else 
			"Too Big" println,
			"Too Small" println
		)
	)
	count = count + 1
)
