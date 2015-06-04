=begin
	v3 据说谢了一个 会写程序的程序...
	这里的 module 是关键点

	ActsAsCsv =》ClassMethods =》InstanceMethods.read

	include 相当于『注入』模块、类（类是特殊模块）、方法

	根据不同的 case，很方便『注入』不同的模块和方法，就具有不同的功能，也就是所谓的『会写程序的程序』。
	这个在其它语言难以想象，其它语言的类是封闭的（你难以添加新模块），
	而 Ruby 是开放的（容易添加新模块，Ruby 设计的理念本身如此）

=end

module ActsAsCsv

	def self.included(base)	# 这个 included，是过去式 ed
		base.extend ClassMethods
	end

	# ClassMethods 包含 InstanceMethods
	module ClassMethods
		def acts_as_csv
			include InstanceMethods	
		end
	end

	module InstanceMethods
		attr_accessor :headers, :csv_contents

		def read
			@csv_contents = []
			filename = 'file.csv'
			file = File.new(filename)

			@headers = file.gets.chomp.split(', ')
			
			file.each do |row|
				puts row, '--------'
				@csv_contents << row.chomp.split(', ')
			end
		end

		def initialize
			read
		end
	end

end

class RubyCsv  # 无继承
	include ActsAsCsv
	acts_as_csv
end

m = RubyCsv.new
puts m.headers.inspect
puts m.csv_contents.inspect

# undefined method `headers' for #<RubyCsv:0x007fbd298e1848> (NoMethodError)
