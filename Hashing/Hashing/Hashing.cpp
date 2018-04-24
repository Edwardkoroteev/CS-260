/*=============================
name: Edward Koroteev
date: 6/4/2015
purpose: counts all the words
in the mother goose book.
class: cs-260
===============================*/
#include<map>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//function prototypes
void convertingToLower(string &theString);
void gettingRidOfCharacters(string &theString);


void main()
{
	//variables
	map<string,int> countingStrings;
	ifstream input;
	ofstream output;
	string workingString;
	int amountOfKeys;

	//loading data
	input.open("motherGoose.txt");
	while(!input.eof())
	{
		input >> workingString;

		//convering all the string to lowercase
		convertingToLower(workingString);
		//getting rid of all the unnecessary characters
		gettingRidOfCharacters(workingString);

		if(!workingString.empty())
		{
			//loading string into the map
			countingStrings[workingString]++;
		}
	}

	input.close();

	//creating an iterarot variable
	map<string,int>::iterator i = countingStrings.begin();

	//counting total number of words
	int counter=0;
	map<string,int>::iterator j = countingStrings.begin();
	while(j != countingStrings.end())
	{
		counter += j->second;
		j++;
	}

	//prompt user
	cout << "There are: "<< counter << " words total";

	//initializing an iterator
	map<string,int>::iterator loop = countingStrings.begin();

	//counting the elements
	amountOfKeys = countingStrings.size();

	cout << "\nThere are " << amountOfKeys << " unique words" << endl;

	//loading data into a txt file
	output.open("results.txt");
	output << "The total number of words is: " << counter << "\n";
	output << "There are " << amountOfKeys << " unique words" << "\n\n";

	while(loop != countingStrings.end())
	{
		output << loop->first << "(" << loop->second << ")" << endl;
		loop++;
	}
	output.close();

	cout << "Loading is done." << endl << "Open \"results.txt\" to view the loaded data" << endl;


	cin.get();
	cin.ignore();
}


/*========================================================
function name: gettingRidOfCharacters
parameters: (string) & theString
purpose: recieves a string and gets rid of ,?.!":;--()_
symbols and it is pass by reference and modifies
the original string sent in
return: void
=========================================================*/
void gettingRidOfCharacters(string &theString)
{
	for(int i = 0; i < theString.length(); i++)
	{
		// ,
		if(theString.at(i) == ',')
		{
			theString.erase(i,1);
			i--;
		}
		// ?
		else if(theString.at(i) == '?')
		{
			theString.erase(i,1);
			i--;
		}
		// .
		else if(theString.at(i) == '.')
		{
			theString.erase(i,1);
			i--;
		}
		// !
		else if(theString.at(i) == '!')
		{
			theString.erase(i,1);
			i--;
		}
		// "
		else if(theString.at(i) == '"')
		{
			theString.erase(i,1);
			i--;
		}
		// :
		else if(theString.at(i) == ':')
		{
			theString.erase(i,1);
			i--;
		}
		// ;
		else if(theString.at(i) == ';')
		{
			theString.erase(i,1);
			i--;
		}
		//--
		else if(i == theString.length()-1)
		{
			if(theString.at(i) == '-')
			{
				theString.erase(i,1);
				i--;

				if(theString.at(i) == '-')
				{
					theString.erase(i,1);
					i--;
				}
			}
		}
		// (
		else if(theString.at(i) == '(')
		{
			theString.erase(i,1);
			i--;
		}
		//)
		else if(theString.at(i) == ')')
		{
			theString.erase(i,1);
			i--;
		}
		//_
		else if(theString.at(i) == '_')
		{
			theString.erase(i,1);
			i--;

		}
		else if(theString.at(i) >= '0' && theString.at(i) <= '9')
		{
			theString.erase(i,1);
			i--;
		}
	}
}


/*=============================================
function name: convertingToLower
parameters: (string) & theString
purpose: recieves a string and modifies the 
original string sent in and converts all
the upper case letters to lowercase
return: void
===============================================*/
void convertingToLower(string &theString)
{
	for(int i = 0; i < theString.length(); i++)
	{
		theString.at(i) = tolower(theString.at(i));
	}
}