#include<stdio.h>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	/*定义各个变量*/
	char Sendbuf[100];
	char Receivebuf[100];
	int Sendlen;
	int Receivelen;
	SOCKET socket_send;
	SOCKADDR_IN Server_add;
	WORD wVersionRequested;
	WSADATA wsaData;
	int error;


	/*初始化套接字库*/
	wVersionRequested = MAKEWORD(2, 2);     /*MAKEWORD是将两个字节组合成一个字，前面是高字节，后面是低字节，表示2.2版本*/
	error = WSAStartup(wVersionRequested, &wsaData); /*加载套接字库，初始化Ws2——32.dll动态链接库*/
	if (error != 0)
	{
		printf("加载套接字失败！");
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 2 ||
		HIBYTE(wsaData.wVersion) != 2)         /*判断请求加载的版本号是否符合要求*/
	{
		WSACleanup();                /*不符合，关闭套接字库*/
		return 0;
	}


	/*设置服务器地址*/
	Server_add.sin_family = AF_INET;
	Server_add.sin_addr.S_un.S_addr = inet_addr("192.168.0.103");   /*将字符串表示的地址转成无符号长整型数据*/
	Server_add.sin_port = htons(5000);

	/*连接服务器*/
	socket_send = socket(AF_INET, SOCK_STREAM, 0);    /*客户端创建套接字，但不需要绑定，只需与服务器建立连接即可*/


	/*创建用于连接的套接字*/
	if (connect(socket_send,(SOCKADDR*)&Server_add,sizeof(SOCKADDR))==SOCKET_ERROR)
	{
		printf("连接失败！");
		return 0;
	}


	/*进行聊天*/
	while (1)
	{
		/*发送数据*/
		printf("please enter message:");
		scanf_s("%s", Sendbuf,100);
		Sendlen = send(socket_send, Sendbuf, 100, 0);
		if (Sendlen<0)
		{
			printf("发送失败！");
		}


		/*接收数据*/
		Receivelen = recv(socket_send, Receivebuf, 100, 0);
		if(Receivelen<0)
		{
			printf("接收失败！退出程序");
			break;
		}
		else
		{
			printf("Server say:%s\n", Receivebuf);
		}
	}

	/*释放套接字*/
	closesocket(socket_send);
	WSACleanup();
	return 0;
}