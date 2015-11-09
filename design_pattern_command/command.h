#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "util.h"
#include "operator.h"
#include <string>
using namespace std;

class Command {
public:
	virtual ~Command() {}
	virtual void exec() = 0;
	static Command* createCmd(CommandType type);
};

class CmdUpdate : public Command{
public:
	CmdUpdate(OperationUpdate* oper = nullptr) : m_operUpdate(oper) {}
	virtual void exec();

private:
	OperationUpdate* m_operUpdate;
};

class CmdBuyTicket : public Command{
public:
	CmdBuyTicket(OperationBuyTicket* oper = nullptr) : m_operBuyTicket(oper) {}
	virtual void exec();

private:
	OperationBuyTicket* m_operBuyTicket;
};


#endif //__COMMAND_H__