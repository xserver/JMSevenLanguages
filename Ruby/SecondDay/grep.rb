def grepWord(filePath, word)
	lineNum = 1
	count = 0
	pattern = Regexp.new(word)
	File.foreach(filePath, 'r') { 
		|line|  
		if pattern =~ line
			puts "#{lineNum} : #{line}___"
			count += 1
		end
		lineNum += 1
	}

end

# 打印出多余的东西了，有个小 r
grepWord('./test.txt', 'Ruby')