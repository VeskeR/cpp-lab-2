// Database.h

#include <iostream>
#include <vector>
#include "railroadticket.h"

using namespace std;

namespace Records {
	class Database
	{
	public:
		Database();
		~Database();

        RailroadTicket& addTicket(string passengerName, string from, string to, string type,
                                  int trainNumber, int coachNumber, int seatNumber);
        RailroadTicket& getTicket(int ticketId);
        RailroadTicket& getTicket(string passengerName);
        void displayAll();
        void displayCurrent();
        void displayFormer();
	protected:
        vector<RailroadTicket> _tickets;
        int _nextTicketNumber;
	};
}
