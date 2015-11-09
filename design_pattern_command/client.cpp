#include "client.h"

void Client::buyTicket() {
	if (nullptr != m_server) {
		m_server->AddCommand(m_strId, CommandType::Cmd_BuyTicket);
	}
}

void Client::cancelTicket() {
	if (nullptr != m_server) {
		m_server->cancelCommand(m_strId, CommandType::Cmd_BuyTicket);
	}
}

void Client::update() {
	if (nullptr != m_server) {
		m_server->AddCommand(m_strId, CommandType::Cmd_Update);
	}
}

void Client::cancelUpdate() {
	if (nullptr != m_server) {
		m_server->cancelCommand(m_strId, CommandType::Cmd_Update);
	}
}