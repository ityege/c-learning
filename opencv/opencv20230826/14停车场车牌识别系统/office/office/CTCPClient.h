#pragma once

#include <WinSock2.h>

#define			WM_RECVFILELIST		WM_USER + 1005		//�����ļ��б�
#define			WM_FILESTATUS		WM_USER + 1006		//��ӳ�ļ�����״̬
#define			WM_CONNECTERROR		WM_USER + 1007		//����ʧ��


#define			FILELIST		    1000				//�����ļ��б�
#define			FILEDATA			2000				//�����ļ�����

#define			RECVSIZE			1024*16		    	//һ���Է���/���յ����ݿ��С

//�������ͨ�����Խṹ
typedef struct
{
	int  iCommand;
	long lFileOffset;
	long lFileLength;
	char sClientPath[128];
	char sServerPath[128];
}MSGREQUEST;

//�����̲߳���
typedef struct
{
	char sIP[15];  //IP��ַ
	int  iPort;   //�˿�
	MSGREQUEST msgRequest; //ͨ�����Խṹ
	LPVOID ptr;  //ָ��
}PARAMREQUEST;

//�ļ��б�ṹ
typedef struct
{
	long lFileLength;
	char sServerPath[128];
}MSGFILELIST;

//��ӳ�ļ�״̬�Ľṹ
typedef struct
{
	long lFileOffset;//ƫ��
	char sServerPath[128];//·��
}MSGFILESTATUS;

class CTCPClient
{
public:
	CTCPClient();
	virtual ~CTCPClient();

	//���ع��캯�������ָ�򴰿�ָ��
	CTCPClient(LPVOID ptr);

	//���÷�����ip
	BOOL SetServerIP(char* sIP);

	//���÷������˿�
	void SetServerPort(int iPort);

	//���������߳�
	void RequestFile(MSGREQUEST msgRequest);

	//�������󲢽��շ�����Ϣ���߳�
	static DWORD WINAPI ThreadRequestFile(LPVOID lpParam);

	//ֹͣ���н����߳�
	static void StopAllRecvThread(void);

private:
	//��������ַ
	char m_sIP[15];

	//�������˿�
	int m_iServerPort;

	//ָ�򴰿ڵ�ָ��
	CWnd* m_pWnd;

	//�����߳̽�����
	static BOOL m_bEndRecvThread;
};
