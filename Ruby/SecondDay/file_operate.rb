# read_file_block.rb
path = "./test.txt"
f = File.open(path, "w")
f.puts "hello"
f.puts 'ruby'
f.puts 'Cool'
f.close

# puts f.methods

File.foreach(path) { |line|  puts line}

f = File.open(path, "w")
puts f.gets
f.close
