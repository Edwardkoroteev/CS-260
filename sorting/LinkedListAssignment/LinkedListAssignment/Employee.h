#ifndef EMPLOYEE_LIST
#define EMPLOYEE_LIST
#include<iostream>
#include<string>

using namespace std;

class employee
{
private: 
	string employeeName;
	int workID;

public:
	employee();
	void setEmployeeName(string Name);
	void setEmployeeID(int ID);
	string getEmployeeName();
	int getEmployeeID();

	//operator overloads
	bool operator <(const employee & employeeClass);
	bool operator >(const employee & employeeClass);
	employee& operator =(const employee & employeeClass);
	friend ostream& operator <<(ostream& output, const employee& employeeClass);
	bool operator ==(const employee& emploteeClass);
	bool operator !=(const employee& emploteeClass);
};
#endif