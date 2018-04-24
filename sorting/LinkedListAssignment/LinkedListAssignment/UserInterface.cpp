/*===================================================
Name: Edward Koroteev
Date: 4/28/2015
purpose: use templates and overload sign operators 
and I created a entry for employee name and work ID
====================================================*/
#include<iostream>
#include<string>
#include"LinkedListAssignment.h"

using namespace std;

void main()
{
	string stringInputFromUser;
	int userInputWorkID;

	list<employee> mylinkedlist;
	employee edward;
	employee james;
	employee bob;
	employee amy;
	int count;

	//setting edward as employee name
	edward.setEmployeeName("Edward");
	edward.setEmployeeID(1234);
	mylinkedlist.insert(edward);

	//setting james as employee name
	james.setEmployeeName("James");
	james.setEmployeeID(5678);
	mylinkedlist.insert(james);

	//setting bob up as an employee
	bob.setEmployeeName("Bob");
	bob.setEmployeeID(9101);
	mylinkedlist.insert(bob);

	//setting amy up as an employee
	amy.setEmployeeName("Amy");
	amy.setEmployeeID(1121);
	mylinkedlist.insert(amy);

	//printing the linked list
	cout << "===YOUR LIST===" << endl;
	mylinkedlist.print();

	//counting the amount of employees in the list
	cout << endl << "you have " << mylinkedlist.count() << " employee(s) in your  list" << endl;

	//removing amy from the employee list
	cout << endl << "===DELETING AMY===" << endl;
	if(mylinkedlist.remove(amy)==true)
	{
		cout << "DELETE SUCCESSFULL"<< endl;
	}

	//printing the linked list
	cout << endl << "===YOUR LIST===" << endl;
	mylinkedlist.print();

	//counting the amount of employees in the list
	cout << endl << "you have " << mylinkedlist.count() << " employee(s) in your  list" << endl;

	//removing james from the employee list
	cout << endl << "===DELETING JAMES===" << endl;
	if(mylinkedlist.remove(james)==true)
	{
		cout << "DELETE SUCCESSFUL" << endl;
	}

	//printing the linked list
	cout << endl << "===YOUR LIST===" << endl;
	mylinkedlist.print();

	//counting the amount of employees in the list
	cout << endl << "you have " << mylinkedlist.count() << " employee(s) in your  list" << endl;

	//setting james as employee name
	james.setEmployeeName("James");
	james.setEmployeeID(5678);
	mylinkedlist.insert(james);

	//setting amy up as an employee
	amy.setEmployeeName("Amy");
	amy.setEmployeeID(1121);
	mylinkedlist.insert(amy);

	cout << endl << "ADDING AMY AND JAMES BACK TO THE LIST" << endl;

	//printing the linked list
	cout << endl << "===YOUR LIST===" << endl;
	mylinkedlist.print();

	//clearing the entire list
	cout << endl << "===CLEARING THE ENTIRE LIST===" << endl;

	if(mylinkedlist.removeAll()==true)
	{
		cout << "DELETE SUCCESSFUL" << endl;
	}

	//printing the linked list
	cout << endl << "===YOUR LIST===" << endl;
	mylinkedlist.print();

	cin.get();
	cin.ignore();
}
