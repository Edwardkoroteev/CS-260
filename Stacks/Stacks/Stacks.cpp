/*
name: edward koroteev
assignment: stacks
class: cs-260
*/
#include<stack>
#include<iostream>
#include<string>

using namespace std;

//function prototypes
string promptUser(string userInput);
bool stringVarification(string input);
string erasingSpaces(string inputString);
string convertInfixToPostfix(string infixString);
bool compareOperator(char currentOperator, char topOfStack);

int main()
{
	string infixInput="";
	char yesOrno;

	do
	{
	infixInput= erasingSpaces(promptUser(infixInput));

	if(stringVarification(infixInput)==true)
	{
		cout << "Your in infix notation was " << infixInput << ".";
		cout << " You used proper notation" << endl;

	}
	else
	{
		cout << "Your input was " << infixInput << ".";
		cout << " You used improper notation" << endl;
		cout << "Try again";
	}
	infixInput= convertInfixToPostfix(infixInput);

	cout << "postfix notaion: "<<infixInput << endl;

	cout << "Do you want to enter another input? (y/n)";
	cin>> yesOrno;
	}
	while(yesOrno == 'y');
	cin.get();
	cin.ignore();

	return 0;
}


/*
Function name: promptUser
Purpose: prompts user for string notation
return: userInput
*/
string promptUser(string userInput)
{
	cout<<"Enter a infix expression: ";
	getline(cin,userInput);

	return userInput;
}


/*
Function name: stringVarification
Purpose:  varifies if user input is in proper notation
return: true or false
*/
bool stringVarification(string input)
{
	//set the parenthesis counter to 0
	int parenthesisCounter=0;

	//check if the first spot is a sybmol
	if(input.at(0) == '/' ||input.at(0) == '*' ||
		input.at(0) == '+' ||input.at(0) == '-'||input.at(0)==')')
	{
		return false;
	}

	//enter for loop the length-1 to check the string 
	// for certain cases and not run off the string 
	//while doing the checks
	for (int i = 0; i < input.length()-1; i++)
	{
		//checking the first number
		if(input.at(i) >= '0'  && input.at(i) <= '9')
		{
			//checking if there is a second number next to the first
			if(input.at(i+1) >='0' && input.at(i+1) <= '9')
			{
				return false;
			}
		}

		//checking for parenthesis
		if(input.at(i) == '(')
		{
			parenthesisCounter+=1;
		}

		if(input.at(i+1)==')')
		{
			parenthesisCounter+=1;
		}

		//checking for addition
		if(input.at(i) == '+')
		{
			//checkingt the last spot for an addition symbol
			if(input.at(i+1) == '+')
			{
				return false;
			}
		}

		//checking for the subtraction symbol
		if(input.at(i) == '-')
		{
			if(input.at(i+1) == '-')
			{
				return false;
			}
		}

		//checking for the multiplication symbole
		if(input.at(i) == '*')
		{
			if(input.at(i+1) == '*')
			{
				return false;
			}
		}

		//checking for the division symbol
		if(input.at(i) == '/')
		{
			if(input.at(i+1) == '/')
			{
				return false;
			}
		}
	}

	if(parenthesisCounter % 2 != 0)
	{
		return false;
	}

	return true;
}


/*
Function name: erasingSpaces
Purpose: erases spaces from the user input
return: inputstring
*/
string erasingSpaces(string inputString)
{
	for (int i = 0; i < inputString.length(); i++)
	{
		if(inputString.at(i) == ' ')
		{
			inputString.erase(i,1);
			i--;
		}
	}

	return inputString;
}


/*
Function name: convertinfixToPostFix
Purpose: converts the user input string into
post fix notation
return: postfixstring
*/
string convertInfixToPostfix(string infixString)
{
	string postFixString="";
	stack<char> myStack;

	//For each item in the infix expression
	for(int i = 0; i < infixString.length(); i++)
	{
		//If it is a number
		if(infixString.at(i) >= '0'  && infixString.at(i) <= '9')
		{
			//append it to postfix string.
			postFixString+=infixString.at(i);
		}
		//else If it is a left parenthesis
		else if(infixString.at(i) == '(')
		{
			//push it onto the stack
			myStack.push(infixString.at(i));
		}

		//else If it is an operator (+,-,*,/) 
		else if(infixString.at(i)=='/'||infixString.at(i)=='*'
			||infixString.at(i)=='-'||infixString.at(i)=='+')
		{
			if(myStack.empty())
			{
				myStack.push(infixString.at(i));
			}

			if(!myStack.empty() && infixString.at(i) == '/')
			{
				myStack.push(infixString.at(i));
			}
			if(!myStack.empty() && infixString.at(i) == '*')
			{
				myStack.push(infixString.at(i));
			}

			else if (!myStack.empty())
			{
				if(myStack.top()=='(')
					myStack.push(infixString.at(i));

				//while the operator on the top of the stack is >= precedence
				if(myStack.empty())
				{
					while( !myStack.empty() && compareOperator(infixString.at(i),myStack.top()))
					{
						//pop the operator and append it to postfix expression
						postFixString+=myStack.top();
						myStack.pop();
					}
				}
				//if the stack is empty
				if(myStack.empty())
				{
					//push operator onto the stack
					myStack.push(infixString.at(i));
				}
			}

			else
			{
				if(compareOperator(infixString.at(i), myStack.top()))
				{
					myStack.push(infixString.at(i));
				}
				else
				{
					postFixString += myStack.top();
					myStack.pop();
					myStack.push(infixString.at(i));
				}
			}
		}

		// 	If the stack is not empty 
		//else If it is right parenthesis then
		else if(infixString.at(i) == ')')
		{
			//while the stack is not empty and top not equal to left parenthesis
			while(!myStack.empty()&& myStack.top() != '(')
			{
				//Pop from stack and append to postfix expression
				postFixString+=myStack.top();
				myStack.pop();

			}
			//pop out the left parenthesis and discard it
			if(!myStack.empty() && myStack.top() == '(')
			{
				myStack.pop();
			}
		}
	}
	//While stack is not empty
	while(!myStack.empty())
	{
		//pop and append to the postfix string.
		postFixString+=myStack.top();
		myStack.pop();
	}
	return postFixString;
}


/*
Function name: compareOperator
Purpose: Compares the operators and determines
which operator is greater
return: true or false
*/
bool compareOperator(char currentOperator, char topOfStack)
{
	switch(currentOperator)
	{
	case '*':
	case '/':
		if(topOfStack == '*' || topOfStack == '/')
		{
			return true;
		}

		if(topOfStack == '+' || topOfStack == '-')
		{
			return false;
		}
	case'+':
	case'-':
		return true;
	}
}