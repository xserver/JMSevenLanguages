=begin
	和 v1 版不同的地方是
	1、read 方法放入 self.acts_as_csv, 
	2、并用 define_method 标记了
	3、子类要显式 acts_as_csv
=end

class ActsAsCsv

	def self.acts_as_csv  # acts_as_csv =》ruby 称之为『宏』macro 
		define_method 'read' do
			# name = self.class.to_s.downcase + '.csv'
			name = 'file.csv'
			file = File.new(name)

			@headers = file.gets.chomp.split(', ')
			file.each do |row|
				puts row, '--------'
				@result << row.chomp.split(', ')
			end
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

class RubyCsv < ActsAsCsv
	acts_as_csv		# 相当于宏展开？
end

m = RubyCsv.new
puts m.headers.inspect
puts m.csv_contents.inspect

