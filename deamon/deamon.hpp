#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#include "../base/xml.hpp"
#include "../base/log.hpp"

#include "../base/thread.hpp"
#include "../tcp_iocp/src/lance/tcpsrv.hpp"
#include "../tcp_iocp/src/lance/ldebug.h"
#include "../tcp_iocp/src/lance/systm.h"



using namespace pp;
using namespace std;


string	g_demonExeName;
CThread g_cmdThread;


class CCMDrecv :  public lance::net::Client
{
public:

	void OnConnect();

	void OnDisconnect();

	void OnRecv(int len);


private:
	char m_data[128];
};

void* cmdThread(void *);


