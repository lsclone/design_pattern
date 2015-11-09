#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "util.h"
#include "server.h"

#include <string>
using namespace std;

class Client {
public:
	Client(char* id, Server* server) 
		: m_strId(id), m_server(server) {}

	void buyTicket();
	void cancelTicket();

	void update();
	void cancelUpdate();

private:
	string m_strId;
	Server* m_server;
};

#endif //__CLIENT_H__