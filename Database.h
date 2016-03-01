// Database.h

#include <iostream>
#include <vector>
#include "Employee.h"

using namespace std;

namespace Records {
	const int kFirstEmployeeNumber = 1000;
	class Database
	{
	public:
		Database();
		~Database();

        Employee& addEmployee(string inFirstName, string inLastName);
		Employee& getEmployee(int inEmployeeNumber);
        Employee& getEmployee(string inFirstName, string inLastName);
        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;
	protected:
        vector<Employee> _employees;
        int _nextEmployeeNumber;
	};
}
