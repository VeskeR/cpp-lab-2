// Database.cpp

#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {

  Database::Database()
  {
    _nextEmployeeNumber = kFirstEmployeeNumber;
  }
  Database::~Database()
  {
  }
  Employee& Database::addEmployee(string inFirstName, string inLastName)
  {
    Employee theEmployee;
    theEmployee.setFirstName(inFirstName);
    theEmployee.setLastName(inLastName);
    theEmployee.setEmployeeNumber(_nextEmployeeNumber++);
    theEmployee.hire();
    _employees.push_back(theEmployee);

    return _employees[_employees.size()-1];
  }
  Employee& Database::getEmployee(int inEmployeeNumber)
  {
      for (auto iter = _employees.begin(); iter != _employees.end(); ++iter)
      {
          if (iter->getEmployeeNumber() == inEmployeeNumber)
              return *iter;
      }

      cerr << "No employee with employee number " << inEmployeeNumber << endl;
      throw exception();
  }

  Employee& Database::getEmployee(string inFirstName, string inLastName)
  {
      for (auto iter = _employees.begin(); iter != _employees.end(); ++iter)
      {
          if (iter->getFirstName() == inFirstName &&
              iter->getLastName() == inLastName) {
                  return *iter;
          }
      }

      cerr << "No match with name " << inFirstName << " " << inLastName << endl;
      throw exception();
  }
  void Database::displayAll() const
  {
      for (auto iter = _employees.begin(); iter != _employees.end(); ++iter) {
          iter->display();
      }
  }

  void Database::displayCurrent() const
  {
      for (auto iter = _employees.begin(); iter != _employees.end(); ++iter) {
          if (iter->getIsHired())
              iter->display();
      }
  }

  void Database::displayFormer() const
  {
      for (auto iter = _employees.begin(); iter != _employees.end(); ++iter) {
          if (!iter->getIsHired())
              iter->display();
      }
  }
}
