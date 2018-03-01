/*	cpp11_7_thread.cc
	原来C++没有一套自己的线程库，使用第三方例如 pthread。现在有了！
	提供同步异步，mutext、lock_guard unique_lock try_to_lock_t condition_variable

	http://www.cplusplus.com/reference/thread/thread/thread/
	http://www.cnblogs.com/haippy/p/3235560.html (有好几篇)

	thread 对象不能被 copy
	joinable 是否可以被 join
	detach thread 分离
	swap thread
	native_handle

互斥量
	http://blog.csdn.net/tujiaw/article/details/8245130
	http://www.cnblogs.com/haippy/p/3237213.html
	多线程访问共享资源的时用到互斥量，当互斥量被 lock，其他线程必须等待这个互斥量解锁后才能访问它。thread提供了四种不同的互斥量：
	独占式互斥量non-recursive (std::mutex)
	递归式互斥量recursive (std::recursive_mutex)
	允许超时的独占式互斥量non-recursive that allows timeouts on the lock functions(std::timed_mutex)
	允许超时的递归式互斥量recursive mutex that allows timeouts on the lock functions (std::recursive_timed_mutex)

Lock 类（两种）
	std::lock_guard，与 Mutex RAII 相关，方便线程对互斥量上锁。
	std::unique_lock，与 Mutex RAII 相关，方便线程对互斥量上锁，但提供了更好的上锁和解锁控制。

其他类型
	std::once_flag
	std::adopt_lock_t
	std::defer_lock_t
	std::try_to_lock_t

函数
	std::try_lock，尝试同时对多个互斥量上锁。
	std::lock，可以同时对多个互斥量上锁。
	std::call_once，如果多个线程需要同时调用某个函数，call_once 可以保证多个线程对该函数只调用一次。

*/
#include <iostream>
#include <atomic>	//
#include <thread>	//	std::thread 类，另外 std::this_thread 命名空间也在该头文件中
#include <mutex>	//	互斥，std::mutex, std::lock_guard, std::unique_lock
#include <condition_variable>	//	条件变量 std::condition_variable 和 std::condition_variable_any
#include <future>	//	std::promise, std::package_task 两个 Provider 类，
									//  以及 std::future 和 std::shared_future 两个 Future 类，另有 std::async() 函数
#include <functional>
#include <chrono>	//	计时
#include <string>

int asyncFunc() {
	//	dosomething
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 100;
}

// async 异步
void testAsync() {
	std::future <int> fu = std::async(asyncFunc);
	int n = fu.get();
	printf("%d\n", n);	
}

void thread_task(const std::string& name) {

	std::cout << "thread_task id = " << std::this_thread::get_id() << std::endl;

	printf("%s : \n", name.c_str());
	for (int i = 0; i < 10; ++i){
		printf("%d ", i);
		fflush(stdout);
		// std::chrono::seconds()
		std::this_thread::sleep_for(std::chrono::milliseconds(200));	//	毫秒
	}
	printf("%s\n", "");
}

void thread_task2(int& count) {
	printf("thread_task not name \n");
	for (int i = 0; i < count; ++i){
		printf("%d ", i);
		fflush(stdout);
		std::this_thread::sleep_for(std::chrono::milliseconds(200));	//	毫秒
	}
	printf("%s\n", "");
}

void testSync() {

	std::thread th(thread_task, "testSync");
	th.join();	//	等待线程结束，否则会立刻终止。

	int count  = 5;
	std::thread th2(thread_task2, std::ref(count));
	th2.join();
}

void thread_task3(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n + 5));
    std::cout << "hello thread "
        << std::this_thread::get_id()
        << " paused " << n << " seconds" << std::endl;
}
void test() {
	std::thread threads[5];
    std::cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; i++) {
        threads[i] = std::thread(thread_task3, i + 1);
    }
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (auto& t: threads) {
        t.join();
        printf("%s\n", "-----");
    }
    std::cout << "All threads joined.\n";
}
int main(int argc, char const *argv[])
{
	test();
	return 0 ;
	testAsync();
	testSync();
	return 0;
}