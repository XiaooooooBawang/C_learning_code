#include<stdio.h>
#include<winsock.h>

#pragma comment(lib,"ws2_32.lib")

int main()
{

	/*定义各个变量*/
	char Sendbuf[100];            /*发送数据的缓冲区*/
	char Receivebuf[100];         /*收*/
	int Sendlen;                  /*发送数据的长度*/
	int Receivelen;               /*收*/
	int Lenth;                    /*SOCKADDR的大小*/
	SOCKET socket_server;          /*定义服务器套接字*/
	SOCKET socket_receive;        /*定义用于连接套接字*/
	SOCKADDR_IN Server_add;       /*服务器地址信息结构（体）*/
	SOCKADDR_IN Client_add;       /*客户端地址信息结构（体）*/
	WORD wVersionRequested;       /*WORD代表 unsigned short   */
	WSADATA wsaData;              /*库版本信息结构(是结构体)*/
	int error;                    /*表示错误*/



	/*初始化套接字库*/
	wVersionRequested = MAKEWORD(2, 2);     /*MAKEWORD是将两个字节组合成一个字，前面是高字节，后面是低字节，表示2.2版本*/
	error = WSAStartup(wVersionRequested, &wsaData); /*加载套接字库，初始化Ws2——32.dll动态链接库*/
	if (error!=0)
	{
		printf("加载套接字失败！");
		return 0;
	}
	if (LOBYTE(wsaData.wVersion)!=2||
		HIBYTE(wsaData.wVersion)!=2)         /*判断请求加载的版本号是否符合要求*/
	{
		WSACleanup();                /*不符合，关闭套接字库*/
		return 0;
	}


	/*设置连接地址*/
	Server_add.sin_family = AF_INET;         /*家族地址必须是AF_INET，且只有他不是网络字节顺序*/
	Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);  /*主机地址，记得转换成网络字节顺序*/
	Server_add.sin_port = htons(5000);       /*端口号，记得转换成网络字节顺序*/


	/*创建套接字*/
	socket_server = socket(AF_INET, SOCK_STREAM, 0);   /*SOCK_STREAM表示流式套接字tcp*/


	/*绑定套接字到本地的某个地址和端口上*/
	if (bind(socket_server,(SOCKADDR*)&Server_add,sizeof(SOCKADDR))==SOCKET_ERROR)
	{
		printf("绑定失败！\n");                           /*实现绑定的同时进行判断*/
		return 0;
	}


	/*设置监听模式*/
	if (listen(socket_server,5)<0)
	{
		printf("监听失败！\n");
		return 0;
	}


	/*接受连接*/
	Lenth = sizeof(SOCKADDR);
	socket_receive = accept(socket_server, (SOCKADDR*)&Client_add, &Lenth);
	if (socket_receive == SOCKET_ERROR)
	{
		printf("连接失败！");
		return 0;
	}


	/*进行聊天*/
	while (1)                      /*无限循环*/
	{
		/*接收数据*/
		Receivelen = recv(socket_receive, Receivebuf, 100, 0);
		if (Receivelen < 0)
		{
			printf("接收数据失败！程序退出");
			break;
		}
		else
		{
			printf("Client say：%s\n", Receivebuf);
		}


		/*发送数据*/
		printf("please enter message:");
		scanf_s("%s", Sendbuf, 100);
		Sendlen = send(socket_receive, Sendbuf, 100, 0);
		if (Sendlen < 0)
		{
			printf("发送失败！退出程序");
			return 0;
		}
	}

	/*释放套接字，关闭动态库*/
	closesocket(socket_receive);
	closesocket(socket_server);
	WSACleanup();
	return 0;
}