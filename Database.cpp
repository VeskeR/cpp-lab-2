// Database.cpp

#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {

  Database::Database()
  {
    _nextTicketNumber = 0;
  }

  Database::~Database()
  {
  }

  RailroadTicket& Database::addTicket(string passengerName, string from, string to, string type,
                                      int trainNumber, int coachNumber, int seatNumber)
  {
    RailroadTicket ticket(passengerName, from, to, type, trainNumber, coachNumber, seatNumber);
    _tickets.push_back(ticket);
    return _tickets[_tickets.size()-1];
  }

  RailroadTicket& Database::getTicket(int ticketId)
  {
      for (auto iter = _tickets.begin(); iter != _tickets.end(); ++iter)
      {
          if (iter->getTicketId() == ticketId)
              return *iter;
      }

      cerr << "No ticket with ticket id " << ticketId << endl;
      throw exception();
  }

  RailroadTicket& Database::getTicket(string passengerName)
  {
      for (auto iter = _tickets.begin(); iter != _tickets.end(); ++iter)
      {
          if (iter->getPassengerName() == passengerName) {
                  return *iter;
          }
      }

      cerr << "No ticket with passenger name " << passengerName << endl;
      throw exception();
  }

  void Database::displayAll()
  {
      for (auto iter = _tickets.begin(); iter != _tickets.end(); ++iter) {
          cout << iter->toString() << endl;
      }
  }

  void Database::displayByType(string type)
  {
      for (auto iter = _tickets.begin(); iter != _tickets.end(); ++iter) {
          if (iter->getTicketType() == type)
              cout << iter->toString() << endl;
      }
  }

  void Database::displayByTrainNumber(int trainNumber)
  {
      for (auto iter = _tickets.begin(); iter != _tickets.end(); ++iter) {
          if (!iter->getTrainNumber() == trainNumber)
              cout << iter->toString() << endl;
      }
  }
}
