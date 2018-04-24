/*=====================================================
Name: Edward Koroteev
Date: 4/13/2015
Teacher: Jen Miller
Purpose: Create a linked list that stores strings and 
prompts a user for input and a menu that can have the 
user add, remove, print, count, and remove the entire
list of list of strings
=======================================================*/
#include<iostream>
#include<string>
#include"LinkedListAssignment.h"


using namespace std;


/*======================================
Function Name: list	(list)
parameters: none
purpose: constructor. initializes all
the pointers to NULL
=======================================*/
template <class type>
list::list()
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
bool list::insert(type input)
{
	node<type>* currentNode;
	node<type>* currentTrail;

	currentTrail = NULL;

	newNode = new node;

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
		tail=newNode;
		newNode->prev = tail;
		newNode->next = NULL;
		newNode = tail;
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
bool list::removeAll()
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
void list::print()
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
bool list::remove(type input)
{
	node<type>* currentNode;
	node<type>* currentTrail;

	currentTrail = NULL;
	currentNode = head;

	//removing something that is in the beginning of the list
	if(currentNode->next != NULL && head->userInput == input)
	{
		head = head->next;
		head->prev = NULL;
		delete currentNode;
		return true;
	}

	//removing input only if one node
	if (head->userInput == input && currentNode->next == NULL)
	{
		head = head->next;
		delete currentNode;
		return true;
	}

	//finding the position throughout the nodes
	while(currentNode->userInput != input && currentNode->next != NULL)
	{
		currentTrail=currentNode;
		currentNode= currentNode->next;

		if(currentNode->userInput == input)
		{
			currentNode->next->prev= currentTrail;
			currentTrail->next = currentNode->next;
			delete currentNode;
			return true;
		}
	}
}


/*======================================
Function Name: count (INT)
parameters:None
purpose: Counts the amount of nodes in 
the list and returns a number
=======================================*/
template<class type>
int list::count()
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
list::~list()
{
	removeAll();
}
