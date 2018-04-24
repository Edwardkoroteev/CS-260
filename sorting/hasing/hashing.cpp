/*
Example Code using Hash Maps
We are going to use the map library, which is part of
the STL (standard template library)
*/

// the library for ordered hash maps
#include<map>
#include<iostream>

using namespace std;

void main(){
	// create a hash map to store the number of occurences
	// of unique characters entered by the user
	// the key is the character (char)
	// the value is just a count -- the number of times
	// I've seen that character (int)
	map<char,int> charCounts;

	// char variable to store input from the user
	char userInput;

	// prompt the user to start entering characters
	cout << "Start entering letters on new lines. Enter 0 when done." << endl;

	// loop to allow the user to enter characters
	while(cin >> userInput && userInput != '0'){
		// update the value for this key in the hash map
		// if this key already exists, it will be incremented
		// if this key does not exist yet, it will be added
		// to the hash map AND incremented (ints are initialized to 0)
		charCounts[userInput]++; // increment this value
	}

	// Get the size of the hash map
	// How many (key,value) pairs in the map
	cout << "The size of the hash map is: " << charCounts.size() << endl;

	// create an iterator to step through the hash map
	// starting at the beginning (first key)
	map<char,int>::iterator i = charCounts.begin();

	// loop through the hash map and print every (key,value) pair
	while(i != charCounts.end()){

		// print the key/value pair
		cout << "They key is: " << i->first << endl; // first is always the KEY 
		cout << "The value is: " << i->second << endl; // second is always the VALUE
	
		// update i
		i++;
	}

	// Clear the hash map
	charCounts.clear(); // all (key,value) pairs are erased

	// manually insert a key/value pair
	charCounts.insert(pair<char,int>('d',1));
	charCounts['d']++; // increment the value for key 'd' to 2

	// manually erase a key/value pair
	charCounts.erase('d');

	cin.get();
	cin.ignore();
}