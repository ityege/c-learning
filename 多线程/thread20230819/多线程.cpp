/**
���ֶ��߳���c++�ı�׼�⣬֧��windows��linux������Ҫ��c++��׼11����
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
	C++11 �±�׼���������ĸ�ͷ�ļ���֧�ֶ��̱߳�̣����Ƿֱ���<atomic> ��<thread>��<mutex>��<condition_variable>��<future>��

	<atomic> ����ͷ����Ҫ������������, std::atomic �� std::atomic_flag�����⻹������һ�� C ����ԭ�����ͺ��� C ���ݵ�ԭ�Ӳ����ĺ�����
	<thread>����ͷ�ļ���Ҫ������ std::thread �࣬���� std::this_thread �����ռ�Ҳ�ڸ�ͷ�ļ��С�
	<mutex>����ͷ�ļ���Ҫ�������뻥����(mutex)��ص��࣬���� std::mutex ϵ���࣬std::lock_guard, std::unique_lock, �Լ����������ͺͺ�����
	<condition_variable>����ͷ�ļ���Ҫ������������������ص��࣬���� std::condition_variable �� std::condition_variable_any��
	<future>����ͷ�ļ���Ҫ������ std::promise, std::package_task ���� Provider �࣬�Լ� std::future �� std::shared_future ����future �࣬���⻹��һЩ��֮��ص����ͺͺ�����std::async() �����������ڴ�ͷ�ļ��С�
	*/
}

auto test2() {
	auto thread_task = []() {cout << "�߳�ִ��" << endl; };
	thread t(thread_task);
	t.join();
}
/**
thread ���캯��
*/

auto test3() {
	auto func3_1 = [](int n) {
		for (auto i = 0; i < 5; i++)
		{
			cout << "�߳�: " << n << " ����ִ��" << endl;
			this_thread::sleep_for(chrono::milliseconds(10));
		}};
	auto func3_2 = [](int& n) {
		for (auto i = 0; i < 5; i++)
		{
			cout << "�߳� 2 ��������" << endl;
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
	cout << "���n��ֵ�ǣ�" << n << endl;

}
/**
������Ա����
*/

auto test4() {
	auto thread_task = [](int n) {
		this_thread::sleep_for(chrono::seconds(n));
		cout << "�߳�ID��" << this_thread::get_id() << "˯���ˣ�" << n << "��" << endl;
		};
	thread threads[5];
	cout << "����5���߳�" << endl;
	for (auto i = 0; i < 5; i++)
	{
		threads[i] = thread(thread_task, i + 1);
	}
	cout << "5���߳̽�������" << endl;
	for (auto& t : threads) {
		t.join();
	}
	cout << "�����̶߳�ִ�����" << endl;

}
/**
�����̵߳ļ��ַ�ʽ
*/
/**
ʹ����ͨ����
*/

auto test5() {
	auto thread_task = [](int i) {cout << "�̴߳���Ĳ����ǣ�" << i << endl; };
	thread t(thread_task, 666);
	t.join();
}

/**
lambda ���ʽ
*/

auto test6() {
	auto thread_task = [](int i) {cout << "�̴߳���Ĳ����ǣ�" << i << endl; };

	thread t(thread_task, 5);

	t.join();
}
/**
��ĳ�Ա����
*/
auto test7() {
	struct MyClass {
		void thread_task(int i) {
			cout << "�̴߳���Ĳ����ǣ�" << i << endl;
		}
	};
	MyClass myclass;
	thread t(&MyClass::thread_task, &myclass, 666);
	t.join();
}
/**
�ɵ��ö���
*/



auto test8() {
	struct MyClass {
		void operator()(int i) {
			cout << "�̴߳���Ĳ����ǣ�" << i << endl;
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
���˶�ռ��֮��ֵ�����2000000
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
	cout << "a�����ս���ǣ�" << a << endl;
}

/**
time_mutex������ʾ
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
������ʾ
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
�ڶ���ʱ���캯���л�lock�������������Զ�unlock��
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
std::lock����
����ͬʱ�Զ�������������������������һ��û��ס����ô�����������ס�Ļ����������ϳ���ͬʱ��ס���еĻ�������������������Ľ��Ҫô�����л���������ס��Ҫôʱ���л�����һ����û��ס��
�������潲�����������⣬�Ϳ�����������������
����std::lock��ס���������Զ��ͷ�����
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
std::adopt_lock����
�˲������þ�����std::lock_guard�ڹ��캯���в�����mutex��lock������
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
�� Mutex RAII ��أ������̶߳Ի��������������ṩ�˸��õ������ͽ������ƣ����Ĺ��ܱ�std::lock_guard���࣬Ħ���Ų���������std::unique_lock��Ĭ�ϲ���������std::lock_guard���ܻ���һ�¡�
std::unique_lockʹ��std::adopt_lock����ǰ���������������Ѿ������߳������ġ�
ʹ��std::try_to_lock����ǰ������������û�б����߳������ģ���������owns_lock()�����ж��Ƿ��Ѿ���ȡ������������Ȩ��
ʹ��std::defer_lock����ǰ������������û�б����߳������ģ�ͬʱҲ���ڹ��캯���ж�������������ʹ��������������std::unique_lock����������ʹ��std::unique_lock�ĳ�Ա����lock��unlock��try_lock�������Բ�����Ҳ���Խ������������Ļ������Ի��Զ�������
release()�������ͷ���������Ȩ�������ǽ���������ָ������ָ�롣
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
std::try_lock����
����ͬʱ�Զ��������������ע����std::unique_lock��std::try_to_lock�������֡�

###std::call_once����
�������߳���Ҫͬʱ����ĳ��������call_once ���Ա�֤����̶߳Ըú���ֻ����һ�Ρ���Ҫ���std::one_flag��ʹ�á�

���ж���̵߳��õ�ĳ����������func�����Բ������������øú����е�funcֻ��ִ��һ�Ρ�
thread_task2������Ȼ��ִ�������Σ�����thread_task1ֻ��ִ����һ�Ρ�
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
����������������ͨ��֪ͨ����ʵ���߳�ͬ����
��ˣ�������ʵ�ַ��ͷ�/���շ���������/������֮��Ĺ�������
�������Ĺ��������У����������ڵȴ������ߵ�֪ͨ������������յ�֪ͨ����������������

���waitû�еڶ�����������ôwait��Ĭ�Ϸ���false���ȴ������߳�notify��һ��notify�ͻ᷵��true��������ִ�С�
waitʱ���ڶ����������Ϊfalse�����Ե�һ�������ṩ������������Ȩ�ͷţ��Ա����߳̿��Ի�ȡ��������Ȩ��

����notify_one����ж���߳���wait����ônotify_one���������notify����һ���̣߳��������notify_all����ô����notify������wait���̡߳�
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
std::atomic�ֳ�ԭ�Ӳ�������һ�ֲ���Ҫ�õ��������������������Ķ��̲߳�����̷�ʽ��ִ�й����в��ᱻ��ϡ��л��̡߳�
ԭ�Ӳ���ֻ�ܲ���һЩ�򵥵��������ͣ�����int��char��bool��ֻ�ܽ����������++��++��+=��-=���漰������������Ĳ���ԭ�Ӳ�����


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
std::async���ڴ����첽����ʵ���Ͼ��Ǵ���һ���߳�ִ����Ӧ����Ĭ��������ʼִ�С�
std::async�����첽��̵ĸ߼���װ��std::async�Ĳ�������ʵ�൱�ڷ�װ��std::promise��std::packaged_task����std::thread,�����Ͽ��Դ���std::thread ���������顣
*/
void test20() {
	auto thread_task = []() {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread_task" << endl;
		};

	async(thread_task);

}

/**
std::launch::deferred����
�����std::asyncʹ�øò�������ô������񽫱��ͬ�����񣬲�������ִ�У�ֱ��std::future��������get()����wait()ʱ�ŻῪʼִ�У����Ҳ��ᴴ�����̣߳���ֱ���ڱ��߳�ִ�С�
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
����std::async��Ĭ�ϲ�����������һ�����̲߳�������ʼִ�С�
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
std::async�첽������Է���һ��std::future���󣬿������������߳���ں����ķ���ֵ��
std::async��std::packaged_task �� std::promise�����ṩһ��std::future��������첽�����Ĵ����ߡ�
ʹ��std::future���get()���������������ȴ����̷߳��ػ�ȡ����ֵ.
std::future���wait()���������������ȴ����߳�ִ�н������������ؽ����
get()����ְ�ܵ���һ�Σ����ɵ��ö��,���ö�λᵼ�³����쳣�˳���

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
std::packaged_task ��װһ���ɵ��õĶ��󣬲��������첽��ȡ�ÿɵ��ö�������Ľ�����Ӱ�װ�ɵ��ö���������������std::packaged_task �� std::function ���ƣ�ֻ���� std::packaged_task �����װ�Ŀɵ��ö����ִ�н�����ݸ�һ�� std::future ���󣨸ö���ͨ��������һ���߳��л�ȡ std::packaged_task �����ִ�н������
std::packaged_task �����ڲ����������������Ԫ�أ�һ������װ������(stored task)������(task)��һ���ɵ��õĶ����纯��ָ�롢��Ա����ָ����ߺ������󣻶�������״̬(shared state)�����ڱ�������ķ���ֵ������ͨ�� std::future �������ﵽ�첽���ʹ���״̬��Ч����
std::packaged_task���󻹿���ֱ�ӵ��ã����ƺ������ã���������ʹ��pack(5)��
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
���ǿ�����ĳ���߳��жԸ��������и�ֵ��Ȼ������������߳���ȡ����ֵ��
set_value()ֻ�ܱ�����һ�Σ���ε��ûᵼ�³����쳣��
get()Ҳֻ�ܱ�����һ�Σ���ε��ûᵼ�³����쳣��
std::share_future()������Զ�α�get()��
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
		cout << "�߳��ѳɹ�����" << endl;
		//�߳��ѳɹ�����
	}
	else if (std::future_status::timeout == status)
	{
		cout << "wait_for��ʱ���ѽ������߳���δ�ɹ�����" << endl;
		//wait_for��ʱ���ѽ������߳���δ�ɹ�����
	}
	else if (std::future_status::deferred == status)
	{
		cout << "���std::async�ĵ�һ����������Ϊstd::launch::deferred" << endl;
		cout << "����̻߳�ֱ��std::future�������wait()��get()ʱ�Ż�ִ��" << endl;
		cout << "��������ͻ�����" << endl;
		//���std::async�ĵ�һ����������Ϊstd::launch::deferred
		//����̻߳�ֱ��std::future�������wait()��get()ʱ�Ż�ִ��
		//��������ͻ�����
	}
	std::cout << result.get() << std::endl;
}
int main() {
	auto p = test26;
	p();
	return 0;
}