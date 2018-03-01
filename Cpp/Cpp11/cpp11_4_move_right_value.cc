/*	
	右值引用和 move 语义
	返回临时对象触发深拷贝，导致性能下降。
	move 和 T&& ，可以将const 对象的数据 copy 过来。
	Move语法改变了我们设计API的方式。我们可以更多地设计通过值传递。为你的类型启用move语法，使用时会比copy更有效。
*/

#include <iostream>

template <typename T>
class Buffer
{
   std::string          _name;
   size_t               _size;
   std::unique_ptr<T[]> _buffer;
 
public:
   // constructor
  Buffer(const std::string& name = "", size_t size = 16):
     _name(name),
     _size(size),
     _buffer(size? new T[size] : nullptr)
  {}
 
  // copy constructor
  Buffer(const Buffer& copy):
     	_name(copy._name),
     	_size(copy._size),
     	_buffer(copy._size? new T[copy._size] : nullptr)
  {
     T* source = copy._buffer.get();
     T* dest = _buffer.get();
     std::copy(source, source + copy._size, dest);
  }
 
  // copy assignment operator
  Buffer& operator=(Buffer temp) {
      swap(*this, temp);
      return *this;
  }
 
  // move constructor
  Buffer(Buffer&& temp):Buffer() {
     swap(*this, temp);
  }
 
	friend void swap(Buffer& first, Buffer& second) noexcept {
      using std::swap;
      swap(first._name  , second._name);
      swap(first._size  , second._size);
      swap(first._buffer, second._buffer);
   }
};

// bool is_r_value(int &&) { return true; }
// bool is_r_value(const int &) { return false; }
 
// void test(int && i)
// {
//     is_r_value(i); // i 為具名變數，即使被宣告成右值也不會被認定是右值。
//     is_r_value(std::move<int&>(i)); // 使用 std::move<T>() 取得右值。
// }


template <typename T>
Buffer<T> getBuffer(const std::string& name) {
	//	返回临时对象。
	Buffer<T> b(name, 128);
	return b;
}

int main(int argc, char const *argv[])
{

	Buffer<int> b1;
	Buffer<int> b2("buf2", 64);
	Buffer<int> b3 = b2;
	Buffer<int> b4 = getBuffer<int>("buf4");
	b1 = getBuffer<int>("buf5");

// 你运行这段代码，你就会发现b4构造时，move constructor会被调用。同样，对b1赋值时，move assignment operator会被调用。
// 原因就在于getBuffer()的返回值是一个临时对象——也就是右值。
// 右值引用允许开发者提供完美转发 (perfect function forwarding)
  return 0;
}