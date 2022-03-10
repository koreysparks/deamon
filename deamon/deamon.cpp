#include "deamon.hpp"
#include <bits/types.h>
#include <unistd.h>
#include <string.h>

void CCMDrecv::OnRecv(int len)
{
	m_data[len] = 0;
	if(0 != len)
	{
		printf("on recv: fd=%08x, data=%s\n", fd, m_data);
		if (m_data[0] == 'q')
		{
			printf("user exit command\n");
			close();
		}
		else
		{
			// 需要转发的数据
			//char pidStr[10];
			//sprintf(pid, "ps -C ees_bk -o pid=", g_demonExeName.c_str());
			//pid_t pidnum = (pid_t)atoi(pidStr);
			//m_data[len] = '\r\n';

		}
		recv(m_data, 255);
	}

}

void CCMDrecv::OnConnect()
{
	printf("on client connect, fd=%08x ip=%d port=%d\n", fd, ip, port);
	recv(m_data, 255);
}

void CCMDrecv::OnDisconnect()
{
	printf("on client disconnect, fd=%08x ip=%d port=%d\n", fd, ip, port);
}

void* cmdThread()
{
	// 等待120秒
	CLog::sleep(_TIME_S_ * 120);
	return NULL;
}

int  main(const int argc, const char* argv[])
{
	int runTimes = 10;
	int interval = 1;
	int deamonPort = 0;
	string startCMD;
	string stopCMD;

	string xml = argv[1];
	if (xml.empty())
	{
		xml = "deamon.xml";
	}

	CXmlClass xmlConf(xml);
	xmlConf.sub("deamon_conf");
	if(!xmlConf.getNode().is_good())
	{
		return -1;
	}
	else
	{
		xmlConf.sub();
	}

	while(xmlConf.getNode().is_good())
	{
		string name = xmlConf.getNode().get_element_name();
		string value = xmlConf.getNode().get_attribute("value");

		if("times" == name)				runTimes = atoi(value.c_str());
		if("time_interval" == name)		interval = atoi(value.c_str());
		if ("deamon_port" == name)		deamonPort = atoi(value.c_str());
		if ("start_cmd" == name)		startCMD = value;
		if ("stop_cmd" == name)		stopCMD = value;

		xmlConf.next();		
	}

	printf(" start cmd : %s stop cmd: %s\n", startCMD.c_str(), stopCMD.c_str());
	printf("\n");
	if(startCMD.empty() || stopCMD.empty())
	{
		printf("exe cmd error, exit\n");
		return -1;
	}

	//CLog::sleep(_TIME_S_);
	for(size_t i = 0; i < runTimes; ++i)
	{
		system(stopCMD.c_str());
		system(startCMD.c_str());

		usleep(interval);
	}

	return 0;
}




