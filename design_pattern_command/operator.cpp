#include <stdio.h>
#include "operator.h"

OperationUpdate& OperationUpdate::getInstance() {
	static OperationUpdate instance;
	return instance;
}

void OperationUpdate::action() {
	printf("Update\n");
}

OperationBuyTicket& OperationBuyTicket::getInstance() {
	static OperationBuyTicket instance;
	return instance;
}

void OperationBuyTicket::action() {
	printf("Buy a ticket\n");
}