// UserInterface.cpp

#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void addTicket(Database& db);
void displayByType(Database& db);
void displayByTrainNumber(Database& db);

int start()
{
  Database ticketDB;
  bool done = false;

  while (!done) {
    int selection = displayMenu();

    switch (selection) {
    case 1:
      addTicket(ticketDB);
      break;
    case 2:
       ticketDB.displayAll();
    case 3:
      displayByType(ticketDB);
      break;
    case 4:
      displayByTrainNumber(ticketDB);
      break;
    case 0:
      done = true;
      break;
    default:
      cerr << "Unknown command." << endl;
    }
  }
  return 0;
}

int displayMenu()
{
  int selection;

  cout << endl;
  cout << "Tickets Database" << endl;
  cout << "-----------------" << endl;
  cout << "1) Add a new ticket" << endl;
  cout << "2) Display all tickets" << endl;
  cout << "3) Display all tickets with type" << endl;
  cout << "4) Display all tickets with train number" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "---> ";

  cin >> selection;

  return selection;
}

void addTicket(Database& inDB)
{
  string passengerName;
  string from;
  string to;
  string type;
  int trainNumber;
  int coachNumber;
  int seatNumber;

  cout << "Passenger name? ";
  cin >> passengerName;
  cout << "From location? ";
  cin >> from;
  cout << "To location? ";
  cin >> to;
  cout << "Ticket type? ";
  cin >> type;
  cout << "Train number? ";
  cin >> trainNumber;
  cout << "Coach number? ";
  cin >> coachNumber;
  cout << "Seat number? ";
  cin >> seatNumber;

  try {
    inDB.addTicket(passengerName, from, to, type, trainNumber, coachNumber, seatNumber);
  } catch (const std::exception&) { 
    cerr << "Unable to add new employee!" << endl;
  }
}

void displayByType(Database &db)
{
    string type;

    cout << "Type of tickets to show? ";
    cin >> type;

    db.displayByType(type);
}

void displayByTrainNumber(Database &db)
{
    int trainNumber;

    cout << "Train number of tickets to show? ";
    cin >> trainNumber;

    db.displayByTrainNumber(trainNumber);
}
