#include "server.h"

Server::~Server() {
	map<CommandType, CmdMap*>::iterator it = m_mpCmds.begin();
	for (; it != m_mpCmds.end(); ++it) {
		CmdMap* pCmdMap = it->second;
		CmdMap::iterator it2 = pCmdMap->begin();
		for (; it2 != pCmdMap->end(); ++it2) {
			delete it2->second;
		}
		delete pCmdMap;
	}
}

void Server::Notify() {
	map<CommandType, CmdMap*>::iterator it = m_mpCmds.begin();
	for (; it != m_mpCmds.end(); ++it) {
		CmdMap* pCmdMap = it->second;
		CmdMap::iterator it2 = pCmdMap->begin();
		for (; it2 != pCmdMap->end(); ++it2) {
			it2->second->exec();
			delete it2->second;
		}
		pCmdMap->clear();
	}
}

void Server::AddCommand(string id, CommandType cmdType) {
	if (m_mpCmds.end() == m_mpCmds.find(cmdType)) {
		Command* pCmd = Command::createCmd(cmdType);
		CmdMap* pCmdMap = new CmdMap;
		(*pCmdMap)[id] = pCmd;
		m_mpCmds[cmdType] = pCmdMap;
	} else {
		CmdMap* pCmdMap = m_mpCmds[cmdType];
		if (pCmdMap->end() == pCmdMap->find(id)) {
			Command* pCmd = Command::createCmd(cmdType);
			(*pCmdMap)[id] = pCmd;
		} else {
			printf("this command has been added already.\n");
		}
	}
}

void Server::cancelCommand(string id, CommandType cmdType) {
	if (m_mpCmds.end() == m_mpCmds.find(cmdType)) {
		return;
	}
	CmdMap* pCmdMap = m_mpCmds[cmdType];
	CmdMap::iterator it = pCmdMap->find(id);
	if (pCmdMap->end() != it) {
		delete it->second;
		pCmdMap->erase(it);
	}
}