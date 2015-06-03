class ActsAsCsv
	def read
		# name = self.class.to_s.downcase + '.csv'
		name = 'file.csv'
		file = File.new(name)

		@headers = file.gets.chomp.split(', ')
		file.each do |row|
			puts row, '--------'
			@result << row.chomp.split(', ')
		end
	end

	def headers		# 囧，get 方法
		@headers
	end

	def csv_contents
		@result
	end

	def initialize
		@result = []
		read
	end
end

# 不是一般的继承
class RubyCsv < ActsAsCsv
end

m = RubyCsv.new
puts m.headers.inspect
puts m.csv_contents.inspect

