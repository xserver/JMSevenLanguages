 /*
	ResourceMan.cpp
	T13：使用对象管理资源：文件、数据库连接、网络连接等，智能指针
		使用对象的构造和析构的方法，来获取和释放资源。当然你也可以自己 open|close
		RAII (Resource Acquisition Is Initialization)
		RCSP (Reference-counting smart pointer)

	T14：小心资源的 copy
	T15：提供 private 资源访问的 const get
	T16：new - delete, new [] - delete [], 对应。
	T17：使用单条的独立语句将资源放入队列，管理起来。
 */
