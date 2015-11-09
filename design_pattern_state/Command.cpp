#include "command.h"

Command* Command::createCmd(CommandType type) {
	switch (type)
	{
	case Cmd_Update:
		return new CmdUpdate(&OperationUpdate::getInstance());
	case Cmd_BuyTicket:
		return new CmdBuyTicket(&OperationBuyTicket::getInstance());
	default:
		return nullptr;
	}
}

void CmdUpdate::exec() {
	if (nullptr != m_operUpdate) {
		m_operUpdate->action();
	}
}

void CmdBuyTicket::exec() {
	if (nullptr != m_operBuyTicket) {
		m_operBuyTicket->action();
	}
}