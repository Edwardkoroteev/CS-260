#ifndef LINKED_LIST
#define LINKED_LIST
#include"Employee.h"
#include<string>
using namespace std;

template<class type>
struct node
{
	type userInput;
	node<type>* prev;
	node<type>* next;
};

template<class type>
class list
{
private:
	node<type>* head;
	node<type>* tail;
	node<type>* newNode;

public:
	list();
	~list();
	bool insert(type input);
	bool remove(type input);
	void print();
	int count();
	bool removeAll();
};

/*======================================
Function Name: list	(list)
parameters: none
purpose: constructor. initializes all
the pointers to NULL
=======================================*/
template <class type>
list<type>::list()
{
	head = NULL;
	tail = NULL;
	newNode = NULL;
}


/*======================================
Function name: insert	(VOID)
parameters: None
Purpose:
All of the user inputs are being stored
========================================*/
template<class type>
bool list<type>::insert(type input)
{
	node<type>* currentNode;
	node<type>* currentTrail;

	currentTrail = NULL;

	newNode = new node<type>;

	newNode->userInput = input;

	//head is null
	if(head == NULL)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
		return true;
	}

	//inserting something at the end of the list
	if(tail->userInput < input)
	{
		newNode->userInput=input;
		tail->next = newNode;
		newNode->prev = tail;
		tail=newNode;
		newNode->next = NULL;
		return true;
	}

	//inserting something into the beginning of the list
	if(head->userInput > input)
	{
		newNode->userInput = input;
		newNode->next= head;
		newNode->prev = NULL;
		head = newNode;
		return true;
	}
	else
	{
		currentNode = head;

		//finding out where something goes in the list
		while(currentNode->userInput < input)
		{
			currentTrail= currentNode;
			currentNode = currentNode->next;
		}

		//return false if the user is inputing the same thing
		if(currentNode->userInput == input)
		{
			return false;
		}

		//placing the input into the list after while loop
		newNode->next = currentNode;
		currentTrail->next = newNode;
		currentNode->prev = newNode;
		newNode->prev=currentTrail;
		return true;
	}
}


/*======================================
Function Name: removeAll	(BOOL)
parameters: none
purpose: deletes all the strings in the
linked list and will return true or
false based on the success of the
delete
=======================================*/
template<class type>
bool list<type>::removeAll()
{
	if (head != NULL)
	{
		remove(head->userInput);
	}

	head = NULL;
	return true;
}


/*==============================================
Function Name: print	(VOID)
parameters: none
purpose: cout all the strings in the linked list
================================================*/
template <class type>
void list<type>::print()
{
	node<type>* currentNode;

	currentNode= head;
	

	while(currentNode != NULL)
	{
		cout << currentNode->userInput << endl; // print it
		currentNode = currentNode->next; // update to the next node
	}
}


/*=========================================================
Function Name: Remove	(BOOL)
parameters: none
purpose: removes the latest user input from the link list
===========================================================*/
template <class type>
bool list<type>::remove(type input)
{
	node<type>* currentNode;
	node<type>* currentTrail;

	currentTrail = NULL;
	currentNode = head;
	
	if(head == NULL)
	{
		return false;
	}
	//removing something that is in the beginning of the list
	// if currentNode == NULL then return false;
	if(currentNode->userInput == input && head->next != NULL)
	{
		head = currentNode->next;
		head->prev = NULL;
		delete currentNode;
		return true;
	}

	//removing input only if one node
	if (head->userInput == input && currentNode->next == NULL)
	{
		delete currentNode;
		head=NULL;
		tail=NULL;
		return true;
	}

	//removing the last thing in the list
	if(tail->userInput == input)
	{
		currentNode= tail;
		tail = tail->prev;
		tail->next=NULL;
		delete currentNode;
		return true;
	}

	//finding the position throughout the nodes
	while(currentNode->userInput !=	input && currentNode->next != NULL)
	{
		currentTrail=currentNode;
		currentNode= currentNode->next;
	}

	if(currentNode->userInput == input && currentNode->next != NULL)
	{
 		currentNode->next->prev= currentTrail;
		currentTrail->next = currentNode->next;
		delete currentNode;
		return true;
	}
	
	return false;
}


/*======================================
Function Name: count (INT)
parameters:None
purpose: Counts the amount of nodes in 
the list and returns a number
=======================================*/
template<class type>
int list<type>::count()
{
	node<type>* currentNode;
	currentNode= head;
	int counter = 0;
	while(currentNode!= NULL)
	{
		counter++;
		currentNode = currentNode->next;
	}
	return counter;
}


/*===========================================
Function Name: list	(list)
parameters:none
purpose: destructor. deletes all the nodes
=============================================*/
template<class type>
list<type>::~list()
{
	removeAll();
}
#endif
