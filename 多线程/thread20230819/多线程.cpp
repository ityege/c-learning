/**
该种多线程是c++的标准库，支持windows和linux，但是要求c++标准11以上
*/
#include<iostream>
#include<thread>
#include <mutex>
#include <future>
using namespace std;
auto test1() {
	/**
	https://blog.csdn.net/weixin_43971373/article/details/119678930
	*/
	/**
	*
	C++11 新标准中引入了四个头文件来支持多线程编程，他们分别是<atomic> ，<thread>，<mutex>，<condition_variable>和<future>。

	<atomic> ：该头文主要声明了两个类, std::atomic 和 std::atomic_flag，另外还声明了一套 C 风格的原子类型和与 C 兼容的原子操作的函数。
	<thread>：该头文件主要声明了 std::thread 类，另外 std::this_thread 命名空间也在该头文件中。
	<mutex>：该头文件主要声明了与互斥量(mutex)相关的类，包括 std::mutex 系列类，std::lock_guard, std::unique_lock, 以及其他的类型和函数。
	<condition_variable>：该头文件主要声明了与条件变量相关的类，包括 std::condition_variable 和 std::condition_variable_any。
	<future>：该头文件主要声明了 std::promise, std::package_task 两个 Provider 类，以及 std::future 和 std::shared_future 两个future 类，另外还有一些与之相关的类型和函数，std::async() 函数就声明在此头文件中。
	*/
}

auto test2() {
	auto thread_task = []() {cout << "线程执行" << endl; };
	thread t(thread_task);
	t.join();
}
/**
thread 构造函数
*/

auto test3() {
	auto func3_1 = [](int n) {
		for (auto i = 0; i < 5; i++)
		{
			cout << "线程: " << n << " 正在执行" << endl;
			this_thread::sleep_for(chrono::milliseconds(10));
		}};
	auto func3_2 = [](int& n) {
		for (auto i = 0; i < 5; i++)
		{
			cout << "线程 2 正在运行" << endl;
			++n;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		};
	int n = 0;
	thread t1;
	thread t2(func3_1, n + 1);
	thread t3(func3_2, ref(n));
	thread t4(move(t3));
	t2.join();
	t4.join();
	cout << "最后n的值是：" << n << endl;

}
/**
其他成员函数
*/

auto test4() {
	auto thread_task = [](int n) {
		this_thread::sleep_for(chrono::seconds(n));
		cout << "线程ID：" << this_thread::get_id() << "睡眠了：" << n << "秒" << endl;
		};
	thread threads[5];
	cout << "创建5个线程" << endl;
	for (auto i = 0; i < 5; i++)
	{
		threads[i] = thread(thread_task, i + 1);
	}
	cout << "5个线程进行阻塞" << endl;
	for (auto& t : threads) {
		t.join();
	}
	cout << "所有线程都执行完成" << endl;

}
/**
创建线程的几种方式
*/
/**
使用普通函数
*/

auto test5() {
	auto thread_task = [](int i) {cout << "线程传入的参数是：" << i << endl; };
	thread t(thread_task, 666);
	t.join();
}

/**
lambda 表达式
*/

auto test6() {
	auto thread_task = [](int i) {cout << "线程传入的参数是：" << i << endl; };

	thread t(thread_task, 5);

	t.join();
}
/**
类的成员函数
*/
auto test7() {
	struct MyClass {
		void thread_task(int i) {
			cout << "线程传入的参数是：" << i << endl;
		}
	};
	MyClass myclass;
	thread t(&MyClass::thread_task, &myclass, 666);
	t.join();
}
/**
可调用对象
*/



auto test8() {
	struct MyClass {
		void operator()(int i) {
			cout << "线程传入的参数是：" << i << endl;
		}
	};
	MyClass myclass;
	thread t(myclass, 5);
	t.join();
}

/**
std::mutex
*/

auto test9() {
	int a = 0;
	auto thread_task = [&]() {
		for (auto i = 0; i < 100000; i++)
		{
			++a;
		}};
	thread t1(thread_task);
	thread t2(thread_task);
	t1.join();
	t2.join();
	cout << a << endl;
}

/**
加了独占锁之后，值变成了2000000
*/
auto test10() {
	mutex mtx;
	int a = 0;
	auto thread_task = [&]() {
		for (auto i = 0; i < 100000; ++i)
		{
			mtx.lock();
			++a;
			mtx.unlock();
		}
		};

	thread t1(thread_task);
	thread t2(thread_task);
	t1.join();
	t2.join();
	cout << "a的最终解决是：" << a << endl;
}

/**
time_mutex案例演示
*/
auto test11() {
	timed_mutex mtx;
	auto fireworks = [&]() {
		// waiting to get a lock: each thread prints "-" every 200ms:
		while (!mtx.try_lock_for(chrono::milliseconds(200))) {
			std::cout << "-";
		}
		// got a lock! - wait for 1s, then this thread prints "*"
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "*" << endl;;
		mtx.unlock();
		};
	thread threads[10];
	for (auto i = 0; i < 10; i++)
	{
		threads[i] = thread(fireworks);
	}
	for (auto& th : threads) {
		th.join();
	}
}

/**
死锁演示
*/
auto test12() {
	auto a = 0;
	mutex mtx1;
	mutex mtx2;

	auto thread_task1 = [&]() {
		for (int i = 0; i < 100000; ++i)
		{
			mtx1.lock();
			mtx2.lock();
			++a;
			mtx2.unlock();
			mtx1.unlock();
		}
		};
	auto thread_task2 = [&]() {
		for (int i = 0; i < 100000; ++i)
		{
			mtx2.lock();
			mtx1.lock();
			++a;
			mtx1.unlock();
			mtx2.unlock();
		}
		};

	thread t1(thread_task1);
	thread t2(thread_task2);
	t1.join();
	t2.join();
	cout << a << endl;



}
/**
std::lock_guard
在定义时构造函数中会lock，析构函数会自动unlock。
*/
auto test13() {
	auto a = 0;
	mutex mtx;
	auto thread_task = [&]() {
		for (int i = 0; i < 100000; ++i)
		{
			lock_guard<std::mutex> lock(mtx);
			//mtx.lock();
			++a;
			//mtx.unlock();
		}
		};
	thread t1(thread_task);
	thread t2(thread_task);
	t1.join();
	t2.join();
	cout << a << endl;

}
/**
std::lock函数
可以同时对多个互斥量上锁如果互斥量中有一个没锁住，那么它会解锁已锁住的互斥量，不断尝试同时锁住所有的互斥量，所以这个函数的结果要么是所有互斥量都锁住了要么时所有互斥量一个都没锁住。
比如上面讲到的死锁问题，就可以用这个函数解决。
但是std::lock锁住的锁不会自动释放锁。
*/
auto test14() {
	auto a = 0;
	mutex mtx1;
	mutex mtx2;

	auto thread_task = [&]() {
		for (int i = 0; i < 100000; ++i)
		{
			std::lock(mtx1, mtx2);
			//mtx1.lock();
			//mtx2.lock();
			++a;
			mtx2.unlock();
			mtx1.unlock();
		}

		};

	thread t1(thread_task);
	thread t2(thread_task);
	t1.join();
	t2.join();
	cout << a << endl;
}

/**
std::adopt_lock参数
此参数作用就是让std::lock_guard在构造函数中不调用mutex的lock函数。
*/
auto test15() {
	auto a = 0;
	mutex mtx1;
	mutex mtx2;

	auto thread_task = [&]() {
		for (int i = 0; i < 100000; ++i)
		{
			lock(mtx1, mtx2);
			lock_guard<mutex> lock1(mtx1, adopt_lock);
			lock_guard<mutex> lock2(mtx2, adopt_lock);
			++a;
		}
		};
	thread t1(thread_task);
	thread t2(thread_task);
	t1.join();
	t2.join();
	cout << a << endl;
}

/*
std::unique_lock
与 Mutex RAII 相关，方便线程对互斥量上锁，但提供了更好的上锁和解锁控制，它的功能比std::lock_guard更多，摩尔嗯不带参数的std::unique_lock与默认不带参数的std::lock_guard功能基本一致。
std::unique_lock使用std::adopt_lock参数前，互斥锁必须是已经被本线程锁定的。
使用std::try_to_lock参数前，互斥锁必须没有被本线程锁定的，后续可以owns_lock()函数判断是否已经获取到了锁的所有权。
使用std::defer_lock参数前，互斥锁必须没有被本线程锁定的，同时也不在构造函数中对锁进行锁定，使用这个参数定义的std::unique_lock，后续可以使用std::unique_lock的成员函数lock、unlock、try_lock，最后可以不解锁也可以解锁，不解锁的话析构仍会自动解锁。
release()函数会释放锁的所有权，而不是解锁，返回指向锁的指针。
*/
auto test16() {
	int a = 0;
	mutex mtx;
	auto thread_task = [&]() {
		for (int i = 0; i < 100000; ++i)
		{
			unique_lock<mutex> lock(mtx);
			++a;
		}
		};

	thread t1(thread_task);
	thread t2(thread_task);
	t1.join();
	t2.join();
	cout << a << endl;

}

/*
std::try_lock函数
尝试同时对多个互斥量上锁，注意与std::unique_lock的std::try_to_lock参数区分。

###std::call_once函数
如果多个线程需要同时调用某个函数，call_once 可以保证多个线程对该函数只调用一次。需要配合std::one_flag类使用。

当有多个线程调用的某个函数中有func，可以采用上述方法让该函数中的func只被执行一次。
thread_task2函数虽然被执行了两次，但是thread_task1只被执行了一次。
*/
auto test17() {
	auto a = 0;
	once_flag g_flag;

	auto thread_task1 = [&]() {++a; };
	auto thread_task2 = [&]() {call_once(g_flag, thread_task1); };

	thread t1(thread_task2);
	thread t2(thread_task2);
	t1.join();
	t2.join();
	cout << a << endl;
}

/**
std::condition_variable
条件变量允许我们通过通知进而实现线程同步。
因此，您可以实现发送方/接收方或生产者/消费者之类的工作流。
在这样的工作流程中，接收者正在等待发送者的通知。如果接收者收到通知，它将继续工作。

如果wait没有第二个参数，那么wait会默认返回false，等待其它线程notify，一旦notify就会返回true继续向下执行。
wait时，第二个参数如果为false，则会对第一个参数提供的锁进行所有权释放，以便别的线程可以获取锁的所有权。

关于notify_one如果有多个线程在wait，那么notify_one将会随机的notify其中一个线程，如果调用notify_all，那么将会notify所有在wait的线程。
*/
auto test18() {
	int a = 0;
	mutex mtx;
	condition_variable cond;

	auto thread_task1 = [&]() {
		unique_lock<mutex> lock(mtx);
		cond.wait(lock, [&] {return !(a % 1000); });
		//cond.wait(lock);
		++a;
		};
	auto thread_task2 = [&]() {
		for (int i = 0; i < 100000; ++i)
		{
			unique_lock<mutex> lock(mtx);
			if (!(a % 1000))
				cond.notify_one();
			++a;
		}
		};

	thread t1(thread_task1);
	thread t2(thread_task2);
	t1.join();
	t2.join();
	cout << a << endl;

}

/**
std::atomic
std::atomic又称原子操作，是一种不需要用到互斥量（无锁）技术的多线程并发编程方式，执行过程中不会被打断、切换线程。
原子操作只能操作一些简单的数据类型，比如int、char、bool，只能进行最基本的++、++、+=、-=，涉及复杂运算操作的不是原子操作。


*/
auto test19() {
	atomic<int> a = 0;
	auto thread_task = [&]() {
		for (int i = 0; i < 100000; ++i)
		{
			++a;
		}
		};
	thread t1(thread_task);
	thread t2(thread_task);
	t1.join();
	t2.join();
	cout << a << endl;

}

/**
std::async用于创建异步任务，实际上就是创建一个线程执行相应任务，默认立即开始执行。
std::async就是异步编程的高级封装，std::async的操作，其实相当于封装了std::promise、std::packaged_task加上std::thread,基本上可以代替std::thread 的所有事情。
*/
void test20() {
	auto thread_task = []() {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread_task" << endl;
		};

	async(thread_task);

}

/**
std::launch::deferred参数
如果对std::async使用该参数，那么这个任务将变成同步任务，不会立即执行，直到std::future类对象调用get()或者wait()时才会开始执行，而且不会创建子线程，会直接在本线程执行。
*/
void test21() {
	auto thread_tesk = []() {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread_task" << endl;
		return 0;
		};

	future<int> result = async(launch::deferred, thread_tesk);
	cout << result.get() << endl;
}

/**
这是std::async的默认参数，即创建一个子线程并立即开始执行。
*/
auto test22() {
	auto thread_tesk = []() {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread_task" << endl;
		return 0;
		};

	future<int> result = async(launch::async, thread_tesk);
	//cout << result.get() << endl;
}
/**
std::async异步任务可以返回一个std::future对象，可用来保存子线程入口函数的返回值。
std::async、std::packaged_task 或 std::promise都能提供一个std::future对象给该异步操作的创建者。
使用std::future类的get()函数，可以阻塞等待子线程返回获取返回值.
std::future类的wait()函数，可以阻塞等待子线程执行结束，本身不返回结果。
get()函数职能调用一次，不可调用多次,调用多次会导致程序异常退出。

*/
auto test23() {
	auto thread_task = []() {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread_task" << endl;
		return 0;
		};
	future<int> result = async(thread_task);
	cout << result.get() << endl;

}
/*
std::packaged_task
std::packaged_task 包装一个可调用的对象，并且允许异步获取该可调用对象产生的结果，从包装可调用对象意义上来讲，std::packaged_task 与 std::function 类似，只不过 std::packaged_task 将其包装的可调用对象的执行结果传递给一个 std::future 对象（该对象通常在另外一个线程中获取 std::packaged_task 任务的执行结果）。
std::packaged_task 对象内部包含了两个最基本元素：一、被包装的任务(stored task)，任务(task)是一个可调用的对象，如函数指针、成员函数指针或者函数对象；二、共享状态(shared state)，用于保存任务的返回值，可以通过 std::future 对象来达到异步访问共享状态的效果。
std::packaged_task对象还可以直接调用，类似函数调用，如上例中使用pack(5)。
*/
auto test24() {
	auto thread_task = [](int i) {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread_task: " << i << endl;
		return 100;
		};
	std::packaged_task<int(int)> pack(thread_task);
	std::thread mythread(std::ref(pack), 5);
	mythread.join();
	std::future<int> result = pack.get_future();
	std::cout << result.get() << std::endl;
}
/**
std::promise
我们可以在某个线程中对该类对象进行赋值，然后可以在其它线程中取出其值。
set_value()只能被调用一次，多次调用会导致程序异常。
get()也只能被调用一次，多次调用会导致程序异常。
std::share_future()对象可以多次被get()。
*/
auto test25() {
	auto thread_task = [](promise<int>& pro, int i) {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread_task" << i << endl;
		pro.set_value(i);
		};
	promise<int> pro;
	thread mythread(thread_task, std::ref(pro), 5);
	mythread.join();
	future<int> result = pro.get_future();
	cout << result.get() << endl;
}


auto test26() {
	auto thread_task = [](promise<int>& pro, int i) {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread_task " << i << endl;
		pro.set_value(i);
		};

	std::promise<int> pro;
	std::thread mythread(thread_task, std::ref(pro), 5);
	mythread.join();
	std::future<int> result = pro.get_future();
	std::future_status status = result.wait_for(std::chrono::milliseconds(1000));
	if (std::future_status::ready == status)
	{
		cout << "线程已成功返回" << endl;
		//线程已成功返回
	}
	else if (std::future_status::timeout == status)
	{
		cout << "wait_for的时间已结束，线程仍未成功返回" << endl;
		//wait_for的时间已结束，线程仍未成功返回
	}
	else if (std::future_status::deferred == status)
	{
		cout << "如果std::async的第一个参数设置为std::launch::deferred" << endl;
		cout << "则该线程会直到std::future对象调用wait()或get()时才会执行" << endl;
		cout << "这种情况就会满足" << endl;
		//如果std::async的第一个参数设置为std::launch::deferred
		//则该线程会直到std::future对象调用wait()或get()时才会执行
		//这种情况就会满足
	}
	std::cout << result.get() << std::endl;
}
int main() {
	auto p = test26;
	p();
	return 0;
}