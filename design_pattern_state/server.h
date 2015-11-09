#ifndef __SERVER_H__
#define __SERVER_H__

#include <map>
#include "command.h"
using namespace std;

class Server {
public:
	~Server();
	void Notify();
	void AddCommand(string id, CommandType cmdType);
	void cancelCommand(string id, CommandType cmdType);

private:
	typedef map<string, Command*> CmdMap;
	map<CommandType, CmdMap*> m_mpCmds;
};

#endif //__SERVER_H__