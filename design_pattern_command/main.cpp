#include "util.h"
#include "server.h"
#include "client.h"

int main() {
	Server s;
	Client t1("001", &s), t2("002", &s);

	t1.buyTicket();
	t1.update();
	t2.buyTicket();
	t1.buyTicket();

	s.Notify();

	t1.buyTicket();
	t2.buyTicket();
	t2.update();
	t1.cancelTicket();
	t2.cancelUpdate();

	s.Notify();

	return 0;
}