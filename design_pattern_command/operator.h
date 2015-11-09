#ifndef __OPERATOR_H__
#define __OPERATOR_H__

class OperationUpdate {
public:
	static OperationUpdate& getInstance();
	void action();
};

class OperationBuyTicket {
public:
	static OperationBuyTicket& getInstance();
	void action();
};

#endif //__OPERATOR_H__