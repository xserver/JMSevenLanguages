/*	cpp11_3.cc
		
		智能指针 Smart Pointers, http://stackoverflow.com/questions/15648844/using-smart-pointers-for-class-members
		 * auto_ptr已经被废弃，不会再使用
	   * unique_ptr: unique_ptr的资源，只能由一个人占有！（它没有拷贝构造函数），它可以std::move转让给另一个unique_ptr（存在move构造函数）。
	   * shared_ptr: 如果内存资源需要共享，那么使用这个（所以叫这个名字）。
	   * weak_ptr: 持有被shared_ptr所管理对象的引用，但是不会改变引用计数值。
*/

#include <iostream>

void foo(int* p) {
	std::cout << *p << std::endl;
}

void test_unique_ptr() {
	// unique_ptr的资源，只能由一个人占有！
	std::unique_ptr<int> p1(new int(42));
	if(p1) {
		printf("A input p1 = %d\n", *p1.get());
		// foo(p1.get());
	}

	std::unique_ptr<int> p2 = std::move(p1); // transfer ownership
	if(p1) {
		printf("B input p1 = %d\n", *p1.get());
		foo(p1.get());
	}

	(*p2)++;
	if(p2) {
		printf("C input p2 = %d\n", *p2.get());	
	}
}

void test_shared_ptr() {
	
	std::shared_ptr<int> p1(new int(42));
	std::shared_ptr<int> p2 = p1;
	foo(p1.get());
	foo(p2.get());

	auto p0 = std::make_shared<int>(42);
	//	p0 和 p1 等价
	// make_shared<T>是一个非成员函数，使用它的好处是可以一次性分配共享对象和智能指针自身的内存。
	// 而显示地使用shared_ptr构造函数来构造则至少需要两次内存分配。
	// 除了会产生额外的开销，还可能会导致内存泄漏。
}

void test_weak_ptr() {

	auto shared = std::make_shared<int>(42);
	std::weak_ptr<int> wp = shared;
 
	{
		//	必须调用lock()来获得被引用对象的shared_ptr
		// 估计是害怕 shared 被释放？

		auto sp = wp.lock();
		std::cout << *sp << std::endl;
	}
	
	shared.reset();
 
	if(wp.expired()) {
		std::cout << "expired" << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	// test_shared_ptr();
	test_weak_ptr();
	return 0;
}