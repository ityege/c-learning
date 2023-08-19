#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<pthread.h>
#include <semaphore.h>
/*
pthread���߳���linux���棬windows�ж�Ӧ��Ǩ�ư汾
git clone git@github.com:GerHobbelt/pthread-win32.git
��Ҫ�ֶ�����
*/

auto test1() {
	// �߳�ִ�к���
	void* (*mythread) (void*) = [](void* arg) ->void* {
		printf("child thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), GetCurrentThreadId());
		return nullptr;
		};
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// �������߳�
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		return -1;
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), GetCurrentThreadId());

	// Ŀ����Ϊ�������߳��ܹ�ִ������
	Sleep(1000);
}

void test2() {
	struct Test
	{
		int data;
		char name[64];
	};
	//�߳�ִ�к���
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
	// �������߳�
	pthread_t thread;
	// int ret = pthread_create(&thread, NULL, mythread, &n);
	int ret = pthread_create(&thread, NULL, mythread, &t);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// Ŀ����Ϊ�������߳��ܹ�ִ������
	Sleep(1);

}
/**
 ѭ���������߳�,���Ҵ�ӡ�ǵڼ������߳�
*/
void test3() {
	auto mythread = [](void* arg)->void* {
		int i = *(int*)arg;
		printf("[%d]:child thread, pid==[%d], id==[%ld]\n", i, GetCurrentProcessId(), pthread_self());
		return nullptr;
		};
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// �������߳�
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

	// Ŀ����Ϊ�������߳��ܹ�ִ������
	Sleep(1000);

}
/**
�߳��˳���������ֵ����
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
	// �������߳�
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// �������߳�
	void* p = NULL;
	pthread_join(thread, &p);
	struct Test* pt = (struct Test*)p;
	printf("child exit status:[%d],[%s],[%p]\n", pt->data, pt->name, pt);

}
/**
�Ƚ��߳�id�Ƿ����
*/
void test5() {
	if (pthread_equal(pthread_self(), pthread_self()) != 0)
	{
		printf("two thread id is same\n");
	}

}
/**
�߳�ȡ��
*/
void test6() {
	auto mythread = [](void* arg)->void* {
		while (1)
		{
			Sleep(1000);
			// ����ȡ����
			pthread_testcancel();

			printf("-----\n");
		}
		};
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                       void *(*start_routine) (void *), void *arg);
	// �������߳�
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// ȡ�����߳�,��windows�������ȡ������
	pthread_cancel(thread);

	pthread_join(thread, NULL);

}
/**
�߳���������
*/
void test7() {
	auto mythread = [](void* arg)->void* {
		printf("child thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());
		Sleep(2000);
		return nullptr;
		};

	// ����pthread_attr_t���͵ı���
	pthread_attr_t attr;

	// ��ʼ��attr����
	pthread_attr_init(&attr);

	// ����attrΪ��������
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	// �������߳�
	pthread_t thread;
	int ret = pthread_create(&thread, &attr, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// �ͷ��߳�����
	pthread_attr_destroy(&attr);

	// ��֤���߳��Ƿ�Ϊ��������
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
	// �������߳�
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, mythread, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}
	printf("main thread, pid==[%d], id==[%ld]\n", GetCurrentProcessId(), pthread_self());

	// �����߳�Ϊ��������
	pthread_detach(thread);

	// ���߳����÷�������,��pthread_join��������,���̷���
	ret = pthread_join(thread, NULL);
	if (ret != 0)
	{
		printf("pthread_join error:[%s]\n", strerror(ret));
	}

}

/**
������
*/
void test9() {
	// ����һ����
	static pthread_mutex_t mutex;

	auto mythread1 = [](void* args) ->void* {
		while (1)
		{
			// ����
			pthread_mutex_lock(&mutex);

			printf("hello ");
			Sleep((rand() % 3) * 1000);
			printf("world\n");

			// ����
			pthread_mutex_unlock(&mutex);
			Sleep((rand() % 3) * 1000);
		}
		pthread_exit(NULL);
		};
	auto mythread2 = [](void* args) ->void* {
		while (1)
		{
			// ����
			pthread_mutex_lock(&mutex);

			printf("HELLO ");
			Sleep((rand() % 3) * 1000);
			printf("WORLD\n");

			// ����
			pthread_mutex_unlock(&mutex);
			Sleep((rand() % 3) * 1000);
		}

		pthread_exit(NULL);

		};
	int ret;
	pthread_t thread1;
	pthread_t thread2;

	// ���������
	srand(time(NULL));

	// ��������ʼ��
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

	// �ȴ��߳̽���
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	// �ͷŻ�����
	pthread_mutex_destroy(&mutex);

}
/**
��д��
*/
void test10() {
	static int number = 0;
	// ����һ�Ѷ�д��
	static pthread_rwlock_t rwlock;
	// д�̻߳ص�����
	auto thread_write = [](void* arg)->void* {
		int i = *(int*)arg;

		int cur;

		while (1)
		{
			// ��д��
			pthread_rwlock_wrlock(&rwlock);

			cur = number;
			cur++;
			number = cur;
			printf("[%d]-W:[%d]\n", i, cur);

			// ����
			pthread_rwlock_unlock(&rwlock);
			Sleep((rand() % 3) * 1000);
		}

		};
	//���̻߳ص�����
	auto thread_read = [](void* arg)->void* {
		int i = *(int*)arg;
		int cur;

		while (1)
		{
			// �Ӷ���
			pthread_rwlock_rdlock(&rwlock);

			cur = number;
			printf("[%d]-R:[%d]\n", i, cur);

			// ����
			pthread_rwlock_unlock(&rwlock);
			Sleep((rand() % 3) * 1000);
		}
		};

	int n = 8;
	int i = 0;
	int arr[8];
	pthread_t thread[8];

	// ��д����ʼ��
	pthread_rwlock_init(&rwlock, NULL);

	// ����3��д���߳�
	for (i = 0; i < 3; i++)
	{
		arr[i] = i;
		pthread_create(&thread[i], NULL, thread_write, &arr[i]);
	}

	// ����5�������߳�
	for (i = 3; i < n; i++)
	{
		arr[i] = i;
		pthread_create(&thread[i], NULL, thread_read, &arr[i]);
	}

	// �������߳�
	int j = 0;
	for (j = 0; j < n; j++)
	{
		pthread_join(thread[j], NULL);
	}

	// �ͷ���
	pthread_rwlock_destroy(&rwlock);

}

/**
* �������������ߺ�������ģʽ
*/
void test11() {
	typedef struct node
	{
		int data;
		struct node* next;
	}NODE;

	static NODE* head = NULL;

	//����һ����
	static pthread_mutex_t mutex;

	//������������
	static pthread_cond_t cond;

	//�������߳�
	auto producer = [](void* arg)->void* {
		NODE* pNode = NULL;
		while (1)
		{
			//����һ���ڵ�
			pNode = (NODE*)malloc(sizeof(NODE));
			if (pNode == NULL)
			{
				perror("malloc error");
				exit(-1);
			}
			pNode->data = rand() % 1000;
			printf("P:[%d]\n", pNode->data);

			//����
			pthread_mutex_lock(&mutex);

			pNode->next = head;
			head = pNode;

			//����
			pthread_mutex_unlock(&mutex);

			//֪ͨ�������߳̽������
			pthread_cond_signal(&cond);

			Sleep((rand() % 3) * 1000);
		}

		};
	auto consumer = [](void* arg)->void* {

		NODE* pNode = NULL;
		while (1)
		{
			//����
			pthread_mutex_lock(&mutex);

			if (head == NULL)
			{
				//������������,��Ҫ�����ȴ�
				//������������,�������ȴ�������;
				//����������(���������̵߳���pthread_cond_signal����֪ͨ),������������� 
				pthread_cond_wait(&cond, &mutex);
			}

			printf("C:[%d]\n", head->data);
			pNode = head;
			head = head->next;

			//����
			pthread_mutex_unlock(&mutex);

			free(pNode);
			pNode = NULL;

			Sleep((rand() % 3) * 1000);
		}

		};

	int ret;
	pthread_t thread1;
	pthread_t thread2;

	//��ʼ��������
	pthread_mutex_init(&mutex, NULL);

	//����������ʼ��
	pthread_cond_init(&cond, NULL);

	//�����������߳�
	ret = pthread_create(&thread1, NULL, producer, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	//�����������߳�
	ret = pthread_create(&thread2, NULL, consumer, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	//�ȴ��߳̽���
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	//�ͷŻ�����
	pthread_mutex_destroy(&mutex);

	//�ͷ���������
	pthread_cond_destroy(&cond);
}
/**
��������ʵ��������������ģʽ���̰߳�
*/
void test12() {
	typedef struct node
	{
		int data;
		struct node* next;
	} NODE;

	static NODE* head = NULL;

	// ����һ����
	static pthread_mutex_t mutex;

	// ������������
	static pthread_cond_t cond;

	auto producer = [](void* arg)->void* {
		NODE* pNode = NULL;
		int n = *(int*)arg;
		while (1)
		{
			// ����һ���ڵ�
			pNode = (NODE*)malloc(sizeof(NODE));
			if (pNode == NULL)
			{
				perror("malloc error");
				exit(-1);
			}
			pNode->data = rand() % 1000;
			printf("P[%d]:[%d]\n", n, pNode->data);

			// ����
			pthread_mutex_lock(&mutex);

			pNode->next = head;
			head = pNode;

			// ����
			pthread_mutex_unlock(&mutex);

			// ֪ͨ�������߳̽������
			pthread_cond_signal(&cond);

			Sleep((rand() % 3) * 1000);
		}
		};
	auto consumer = [](void* arg)->void* {
		NODE* pNode = NULL;
		int n = *(int*)arg;
		while (1)
		{
			// ����
			pthread_mutex_lock(&mutex);

			if (head == NULL)
			{
				// ������������,��Ҫ�����ȴ�
				// ������������,�������ȴ�������;
				// ����������(���������̵߳���pthread_cond_signal����֪ͨ),�������������
				pthread_cond_wait(&cond, &mutex);
			}

			if (head == NULL)
			{
				// ����
				pthread_mutex_unlock(&mutex);
				continue;
			}

			printf("C[%d]:[%d]\n", n, head->data);
			pNode = head;
			head = head->next;

			// ����
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

	// ��ʼ��������
	pthread_mutex_init(&mutex, NULL);

	// ����������ʼ��
	pthread_cond_init(&cond, NULL);

	int arr[5];
	for (i = 0; i < 5; i++)
	{
		arr[i] = i;
		// �����������߳�
		ret = pthread_create(&thread1[i], NULL, producer, &arr[i]);
		if (ret != 0)
		{
			printf("pthread_create error, [%s]\n", strerror(ret));
			exit(-1);
		}

		// �����������߳�
		ret = pthread_create(&thread2[i], NULL, consumer, &arr[i]);
		if (ret != 0)
		{
			printf("pthread_create error, [%s]\n", strerror(ret));
			exit(-1);
		}
	}

	// �ȴ��߳̽���
	for (i = 0; i < 5; i++)
	{
		pthread_join(thread1[i], NULL);
		pthread_join(thread2[i], NULL);
	}

	// �ͷŻ�����
	pthread_mutex_destroy(&mutex);

	// �ͷ���������
	pthread_cond_destroy(&cond);

}

/**
�ź���ʵ��������������ģʽ
*/
void test13() {
	typedef struct node
	{
		int data;
		struct node* next;
	} NODE;

	static NODE* head = NULL;

	// �����ź���
	static	sem_t sem_producer;
	static sem_t sem_consumer;

	auto producer = [](void* arg)->void* {
		NODE* pNode = NULL;
		while (1)
		{
			// ����һ���ڵ�
			pNode = (NODE*)malloc(sizeof(NODE));
			if (pNode == NULL)
			{
				perror("malloc error");
				exit(-1);
			}
			pNode->data = rand() % 1000;
			printf("P:[%d]\n", pNode->data);

			// ����
			sem_wait(&sem_producer); //--

			pNode->next = head;
			head = pNode;

			// ����
			sem_post(&sem_consumer); // �൱��++

			Sleep((rand() % 3) * 1000);
		}
		};
	auto consumer = [](void* arg)->void* {
		NODE* pNode = NULL;
		while (1)
		{
			// ����
			sem_wait(&sem_consumer); // �൱��--

			printf("C:[%d]\n", head->data);
			pNode = head;
			head = head->next;

			// ����
			sem_post(&sem_producer); // �൱��++

			free(pNode);
			pNode = NULL;

			Sleep((rand() % 3) * 1000);
		}
		};

	int ret;
	pthread_t thread1;
	pthread_t thread2;

	// ��ʼ���ź���
	sem_init(&sem_producer, 0, 5);
	sem_init(&sem_consumer, 0, 0);

	// �����������߳�
	ret = pthread_create(&thread1, NULL, producer, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	// �����������߳�
	ret = pthread_create(&thread2, NULL, consumer, NULL);
	if (ret != 0)
	{
		printf("pthread_create error, [%s]\n", strerror(ret));
		exit(-1);
	}

	// �ȴ��߳̽���
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	// �ͷ��ź�����Դ
	sem_destroy(&sem_producer);
	sem_destroy(&sem_consumer);

}
int main(void) {
	auto p = test13;
	p();
	return 0;
}