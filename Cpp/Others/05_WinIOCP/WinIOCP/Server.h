#pragma once

#ifndef WIN_IOCP_SERVER_H
#define WIN_IOCP_SERVER_H
#ifndef UNICODE
#define UNICODE
#endif // !UNICODE
#define WIN32_LEAN_AND_MEAN // ��MFC���򣬼������ɹ���

#include <iostream>
#include <cstdio>
#include <functional> // �ص�
#include <vector>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <MSWSock.h>


#include "ServerSocket.h"

class Server
{
public:
	Server(u_short port); // ���죺����˿ں�
	~Server(); // ����
	bool startAccept(); // 
	void waitingForAccept(); //
	void waitingForIO(); // 
	bool isRunning() const { return m_running; } // 
	void stop() { m_running = false; } // 

	// �ص���ʽ�������麯����
	typedef std::function<void(ServerSocket::pointer)> HandleNewConnect;
	HandleNewConnect newConn;
	ServerSocket::HandleRecvFunction socketRecv;
	ServerSocket::HandleClose socketClose;
	ServerSocket::HandleError socketError;

private:
	bool m_running;
	u_short m_port; // �˿ں�
	std::vector<char> m_acceptBuffer; // ���ջ�����
	SOCKET m_listenSocket; // ����Socket
	SOCKET m_currentAcceptSocket; // 
	HANDLE m_completePort; // 
	HANDLE m_ioCompletePort; // 
	LPFN_ACCEPTEX lpfnAcceptEx; // 
	WSAOVERLAPPED m_acceptUnit; // 
	bool tryNewConn(); // 
};

#endif // !WIN_IOCP_SERVER_H