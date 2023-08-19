#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<pthread.h>
#include <semaphore.h>
/*
pthread多线程是linux上面，windows有对应的迁移版本
git clone git@github.com:GerHobbelt/pthread-win32.git
需要手动编译
*/

auto test1() {
	// 线程执行函数
	void* (*mythread) (void*) = [](void* arg) ->void* {
		printf("child thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), GetCurrentThreadId());
		return nullptr;
		};
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// 创建子线程
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		return -1;
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), GetCurrentThreadId());

	// 目的是为了让子线程能够执行起来
	Sleep(1000);
}

void test2() {
	struct Test
	{
		int data;
		char name[64];
	};
	//线程执行函数
	auto mythread = [](void* arg) ->void* {

		struct Test* p = (struct Test*)arg;

		printf("[%d][%s]\n", p->data, p->name);
		printf("child thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());
		return NULL;
		};

	struct Test t;
	memset(&t, 0x00, sizeof(struct Test));
	t.data = 88;
	strcpy(t.name, "xiaowen");
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// 创建子线程
	pthread_t thread;
	// int ret = pthread_create(&thread, NULL, mythread, &n);
	int ret = pthread_create(&thread, NULL, mythread, &t);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// 目的是为了让子线程能够执行起来
	Sleep(1);

}
/**
 循环创建子线程,并且打印是第几个子线程
*/
void test3() {
	auto mythread = [](void* arg)->void* {
		int i = *(int*)arg;
		printf("[%d]:child thread, pid==[%d], id==[%ld]\n", i, GetCurrentProcessId(), pthread_self());
		return nullptr;
		};
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// 创建子线程
	int n = 5;
	int arr[5] = { 0,1,2,3,4 };
	pthread_t thread[5];
	for (int i = 0; i < n; i++)
	{
		int ret = pthread_create(&thread[i], NULL, mythread, &arr[i]);
		if (ret != 0)
		{
			printf("pthread_create error, [%s]\n", strerror(ret));
			exit(-1);
		}
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// 目的是为了让子线程能够执行起来
	Sleep(1000);

}
/**
线程退出并将返回值带回
*/
void test4() {
	struct Test
	{
		int data;
		char name[64];
	};

	static struct Test t;
	auto mythread = [](void* arg)->void* {
		printf("child thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());
		memset(&t, 0x00, sizeof(t));
		t.data = 99;
		strcpy(t.name, "xiaowen");
		pthread_exit(&t);
		return nullptr;
		};

	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// 创建子线程
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// 回收子线程
	void* p = NULL;
	pthread_join(thread, &p);
	struct Test* pt = (struct Test*)p;
	printf("child exit status:[%d],[%s],[%p]\n", pt->data, pt->name, pt);

}
/**
比较线程id是否相等
*/
void test5() {
	if (pthread_equal(pthread_self(), pthread_self()) != 0)
	{
		printf("two thread id is same\n");
	}

}
/**
线程取消
*/
void test6() {
	auto mythread = [](void* arg)->void* {
		while (1)
		{
			Sleep(1000);
			// 设置取消点
			pthread_testcancel();

			printf("-----\n");
		}
		};
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// 创建子线程
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// 取消子线程,在windows上面好像取消不了
	pthread_cancel(thread);

	pthread_join(thread, NULL);

}
/**
线程属性设置
*/
void test7() {
	auto mythread = [](void* arg)->void* {
		printf("child thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());
		Sleep(2000);
		return nullptr;
		};

	// 定义pthread_attr_t类型的变量
	pthread_attr_t attr;

	// 初始化attr变量
	pthread_attr_init(&attr);

	// 设置attr为分离属性
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	// 创建子线程
	pthread_t thread;
	int ret = pthread_create(&thread, &attr, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// 释放线程属性
	pthread_attr_destroy(&attr);

	// 验证子线程是否为分离属性
	ret = pthread_join(thread, NULL);
	if (ret != 0)
	{
		printf("pthread_join error:[%s]\n", strerror(ret));
	}


}


void test8() {
	auto mythread = [](void* arg)->void* {
		printf("child thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());
		Sleep(10 * 1000);
		return nullptr;
		};

	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// 创建子线程
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// 设置线程为分离属性
	pthread_detach(thread);

	// 子线程设置分离属性,则pthread_join不再阻塞,立刻返回
	ret = pthread_join(thread, NULL);
	if (ret != 0)
	{
		printf("pthread_join error:[%s]\n", strerror(ret));
	}

}

/**
互斥锁
*/
void test9() {
	// 定义一把锁
	static pthread_mutex_t mutex;

	auto mythread1 = [](void* args) ->void* {
		while (1)
		{
			// 加锁
			pthread_mutex_lock(&mutex);

			printf("hello ");
			Sleep((rand() % 3) * 1000);
			printf("world\n");

			// 解锁
			pthread_mutex_unlock(&mutex);
			Sleep((rand() % 3) * 1000);
		}
		pthread_exit(NULL);
		};
	auto mythread2 = [](void* args) ->void* {
		while (1)
		{
			// 加锁
			pthread_mutex_lock(&mutex);

			printf("HELLO ");
			Sleep((rand() % 3) * 1000);
			printf("WORLD\n");

			// 解锁
			pthread_mutex_unlock(&mutex);
			Sleep((rand() % 3) * 1000);
		}

		pthread_exit(NULL);

		};
	int ret;
	pthread_t thread1;
	pthread_t thread2;

	// 随机数种子
	srand(time(NULL));

	// 互斥锁初始化
	pthread_mutex_init(&mutex, NULL);

	ret = pthread_create(&thread1, NULL, mythread1, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	ret = pthread_create(&thread2, NULL, mythread2, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	// 等待线程结束
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	// 释放互斥锁
	pthread_mutex_destroy(&mutex);

}
/**
读写锁
*/
void test10() {
	static int number = 0;
	// 定义一把读写锁
	static pthread_rwlock_t rwlock;
	// 写线程回调函数
	auto thread_write = [](void* arg)->void* {
		int i = *(int*)arg;

		int cur;

		while (1)
		{
			// 加写锁
			pthread_rwlock_wrlock(&rwlock);

			cur = number;
			cur++;
			number = cur;
			printf("[%d]-W:[%d]\n", i, cur);

			// 解锁
			pthread_rwlock_unlock(&rwlock);
			Sleep((rand() % 3) * 1000);
		}

		};
	//读线程回调函数
	auto thread_read = [](void* arg)->void* {
		int i = *(int*)arg;
		int cur;

		while (1)
		{
			// 加读锁
			pthread_rwlock_rdlock(&rwlock);

			cur = number;
			printf("[%d]-R:[%d]\n", i, cur);

			// 解锁
			pthread_rwlock_unlock(&rwlock);
			Sleep((rand() % 3) * 1000);
		}
		};

	int n = 8;
	int i = 0;
	int arr[8];
	pthread_t thread[8];

	// 读写锁初始化
	pthread_rwlock_init(&rwlock, NULL);

	// 创建3个写子线程
	for (i = 0; i < 3; i++)
	{
		arr[i] = i;
		pthread_create(&thread[i], NULL, thread_write, &arr[i]);
	}

	// 创建5个读子线程
	for (i = 3; i < n; i++)
	{
		arr[i] = i;
		pthread_create(&thread[i], NULL, thread_read, &arr[i]);
	}

	// 回收子线程
	int j = 0;
	for (j = 0; j < n; j++)
	{
		pthread_join(thread[j], NULL);
	}

	// 释放锁
	pthread_rwlock_destroy(&rwlock);

}

/**
* 条件变量生产者和消费者模式
*/
void test11() {
	typedef struct node
	{
		int data;
		struct node* next;
	}NODE;

	static NODE* head = NULL;

	//定义一把锁
	static pthread_mutex_t mutex;

	//定义条件变量
	static pthread_cond_t cond;

	//生产者线程
	auto producer = [](void* arg)->void* {
		NODE* pNode = NULL;
		while (1)
		{
			//生产一个节点
			pNode = (NODE*)malloc(sizeof(NODE));
			if (pNode == NULL)
			{
				perror("malloc error");
				exit(-1);
			}
			pNode->data = rand() % 1000;
			printf("P:[%d]\n", pNode->data);

			//加锁
			pthread_mutex_lock(&mutex);

			pNode->next = head;
			head = pNode;

			//解锁
			pthread_mutex_unlock(&mutex);

			//通知消费者线程解除阻塞
			pthread_cond_signal(&cond);

			Sleep((rand() % 3) * 1000);
		}

		};
	auto consumer = [](void* arg)->void* {

		NODE* pNode = NULL;
		while (1)
		{
			//加锁
			pthread_mutex_lock(&mutex);

			if (head == NULL)
			{
				//若条件不满足,需要阻塞等待
				//若条件不满足,则阻塞等待并解锁;
				//若条件满足(被生成者线程调用pthread_cond_signal函数通知),解除阻塞并加锁 
				pthread_cond_wait(&cond, &mutex);
			}

			printf("C:[%d]\n", head->data);
			pNode = head;
			head = head->next;

			//解锁
			pthread_mutex_unlock(&mutex);

			free(pNode);
			pNode = NULL;

			Sleep((rand() % 3) * 1000);
		}

		};

	int ret;
	pthread_t thread1;
	pthread_t thread2;

	//初始化互斥锁
	pthread_mutex_init(&mutex, NULL);

	//条件变量初始化
	pthread_cond_init(&cond, NULL);

	//创建生产者线程
	ret = pthread_create(&thread1, NULL, producer, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	//创建消费者线程
	ret = pthread_create(&thread2, NULL, consumer, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	//等待线程结束
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	//释放互斥锁
	pthread_mutex_destroy(&mutex);

	//释放条件变量
	pthread_cond_destroy(&cond);
}
/**
条件变量实现生产者消费者模式多线程版
*/
void test12() {
	typedef struct node
	{
		int data;
		struct node* next;
	} NODE;

	static NODE* head = NULL;

	// 定义一把锁
	static pthread_mutex_t mutex;

	// 定义条件变量
	static pthread_cond_t cond;

	auto producer = [](void* arg)->void* {
		NODE* pNode = NULL;
		int n = *(int*)arg;
		while (1)
		{
			// 生产一个节点
			pNode = (NODE*)malloc(sizeof(NODE));
			if (pNode == NULL)
			{
				perror("malloc error");
				exit(-1);
			}
			pNode->data = rand() % 1000;
			printf("P[%d]:[%d]\n", n, pNode->data);

			// 加锁
			pthread_mutex_lock(&mutex);

			pNode->next = head;
			head = pNode;

			// 解锁
			pthread_mutex_unlock(&mutex);

			// 通知消费者线程解除阻塞
			pthread_cond_signal(&cond);

			Sleep((rand() % 3) * 1000);
		}
		};
	auto consumer = [](void* arg)->void* {
		NODE* pNode = NULL;
		int n = *(int*)arg;
		while (1)
		{
			// 加锁
			pthread_mutex_lock(&mutex);

			if (head == NULL)
			{
				// 若条件不满足,需要阻塞等待
				// 若条件不满足,则阻塞等待并解锁;
				// 若条件满足(被生成者线程调用pthread_cond_signal函数通知),解除阻塞并加锁
				pthread_cond_wait(&cond, &mutex);
			}

			if (head == NULL)
			{
				// 解锁
				pthread_mutex_unlock(&mutex);
				continue;
			}

			printf("C[%d]:[%d]\n", n, head->data);
			pNode = head;
			head = head->next;

			// 解锁
			pthread_mutex_unlock(&mutex);

			free(pNode);
			pNode = NULL;

			Sleep((rand() % 3) * 1000);
		}

		};

	int ret;
	int i = 0;
	pthread_t thread1[5];
	pthread_t thread2[5];

	// 初始化互斥锁
	pthread_mutex_init(&mutex, NULL);

	// 条件变量初始化
	pthread_cond_init(&cond, NULL);

	int arr[5];
	for (i = 0; i < 5; i++)
	{
		arr[i] = i;
		// 创建生产者线程
		ret = pthread_create(&thread1[i], NULL, producer, &arr[i]);
		if (ret != 0)
		{
			printf("pthread_create error, [%s]\n", strerror(ret));
			exit(-1);
		}

		// 创建消费者线程
		ret = pthread_create(&thread2[i], NULL, consumer, &arr[i]);
		if (ret != 0)
		{
			printf("pthread_create error, [%s]\n", strerror(ret));
			exit(-1);
		}
	}

	// 等待线程结束
	for (i = 0; i < 5; i++)
	{
		pthread_join(thread1[i], NULL);
		pthread_join(thread2[i], NULL);
	}

	// 释放互斥锁
	pthread_mutex_destroy(&mutex);

	// 释放条件变量
	pthread_cond_destroy(&cond);

}

/**
信号量实现生产者消费者模式
*/
void test13() {
	typedef struct node
	{
		int data;
		struct node* next;
	} NODE;

	static NODE* head = NULL;

	// 定义信号量
	static	sem_t sem_producer;
	static sem_t sem_consumer;

	auto producer = [](void* arg)->void* {
		NODE* pNode = NULL;
		while (1)
		{
			// 生产一个节点
			pNode = (NODE*)malloc(sizeof(NODE));
			if (pNode == NULL)
			{
				perror("malloc error");
				exit(-1);
			}
			pNode->data = rand() % 1000;
			printf("P:[%d]\n", pNode->data);

			// 加锁
			sem_wait(&sem_producer); //--

			pNode->next = head;
			head = pNode;

			// 解锁
			sem_post(&sem_consumer); // 相当于++

			Sleep((rand() % 3) * 1000);
		}
		};
	auto consumer = [](void* arg)->void* {
		NODE* pNode = NULL;
		while (1)
		{
			// 加锁
			sem_wait(&sem_consumer); // 相当于--

			printf("C:[%d]\n", head->data);
			pNode = head;
			head = head->next;

			// 解锁
			sem_post(&sem_producer); // 相当于++

			free(pNode);
			pNode = NULL;

			Sleep((rand() % 3) * 1000);
		}
		};

	int ret;
	pthread_t thread1;
	pthread_t thread2;

	// 初始化信号量
	sem_init(&sem_producer, 0, 5);
	sem_init(&sem_consumer, 0, 0);

	// 创建生产者线程
	ret = pthread_create(&thread1, NULL, producer, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	// 创建消费者线程
	ret = pthread_create(&thread2, NULL, consumer, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	// 等待线程结束
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	// 释放信号量资源
	sem_destroy(&sem_producer);
	sem_destroy(&sem_consumer);

}
int main(void) {
	auto p = test13;
	p();
	return 0;
}