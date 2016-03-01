#include <iostream>
#include "Database.h"

using namespace std;
using namespace Records;

int main()
{
  Database myDB;

  RailroadTicket& ticket1 = myDB.addTicket("Andrey Bulat", "Kiev",
                                             "chernivtsi", "Platzkart", 118, 1, 48);

  RailroadTicket& ticket2 = myDB.addTicket("Olexiy Miroshnik", "Kiev",
                                             "Lviv", "Platzkart", 404, 4, 2);

  RailroadTicket& ticket3 = myDB.addTicket("Billy Milligan", "Somewhere",
                                             "Nowhere", "Deluxe", 42, 42, 42);

  cout << "All tickets in database: " << endl;
  cout << endl;
  myDB.displayAll();

  cout << endl;
  cout << "All tickets with type 'Platzcart': " << endl;
  cout << endl;
  myDB.displayByType("Platzkart");

  cout << endl;
  cout << "All tickets with train number 42: " << endl;
  cout << endl;
  myDB.displayByTrainNumber(42);

  return 0;
}
