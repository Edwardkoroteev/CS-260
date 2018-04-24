#include"Employee.h"

employee::employee()
{
	employeeName = "";
	workID = -5;
}


/*========================================
Function Name: setEmployeeName	(void)
parameters: name (STRING)
description: sets whatever was passed in to the 
	employee name
return: none
==========================================*/
void employee::setEmployeeName(string Name)
{
	employeeName = Name;
}


/*=========================================
Function Name: setEmployeeID	(VOID)
parameters: ID	(INT)
description: makes sure the ID is greater
	than 0
return: none
==========================================*/
void employee::setEmployeeID(int ID)
{
	if(ID>0)
	{
		workID = ID;
	}
}


/*=========================================
function name: getEmployeeName	(STRING)
parameters:	none
description: gets the string that was set
	and returns it
return: string
=========================================*/
string employee::getEmployeeName()
{
	 return employeeName;
}

/*===========================================
function name: getEmployeeID	(INT)
parameters: none
decription: gets the workId that was set
	and returns it
return: INT
===========================================*/
int employee::getEmployeeID()
{
	return workID;
}

//operator overloads
bool employee::operator <(const employee & employeeClass)
{
	if(employeeName<employeeClass.employeeName)
	{
		return true;
	}

	return false;
}

bool employee::operator >(const employee & employeeClass)
{
	if(employeeName>employeeClass.employeeName)
	{
		return true;
	}

	return false;
}

employee& employee::operator =(const employee & employeeClass)
{
	if (this!= &employeeClass)
	{
		employeeName= employeeClass.employeeName;
		workID= employeeClass.workID;
	}

	return *this;
}

ostream& operator <<(ostream& output, const employee& employeeClass)
{
	output << employeeClass.employeeName;
	output << " ";
	output << employeeClass.workID;
	return output;
}

bool employee::operator ==(const employee& employeeClass)
{
	if(employeeName == employeeClass.employeeName&& workID ==  employeeClass.workID)
	{
		return true;
	}
	return false;
}

bool employee::operator !=(const employee& employeeClass)
{
	if(employeeName != employeeClass.employeeName || workID !=  employeeClass.workID)
	{
		return true;
	}
	return false;
}