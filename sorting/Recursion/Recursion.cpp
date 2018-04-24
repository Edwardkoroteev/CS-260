/*============================================
Name: Edward Koroteev
Date: 4/6/2015
Purpose: Solve the Eight Queens Puzzle
============================================*/
#include<iostream>
#include<fstream>

using namespace std;

//Function Prototype
bool UnderAttack(char Array[][8], int Row, int Col);
void Search(char BoardArray[][8], int Row);

void main()
{
	char Board[8][8] ={

		{'-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-'}
	};

	Search(Board,0);

	cin.get();
	cin.ignore();
}


/*============================================
Function name: Under Attack
Arguements: char array[][8]
int row
int col
Purpose: checks to see if the current queen
that is being placed in a spot on the board
is safe or not
===============================================*/
bool UnderAttack(char Array[][8], int Row, int Col)
{
	int Left = Col;
	int Right = Col;
	int LocalRow = Row;

	//check for a queen above current position
	for(int R = Row; R >= 0; R--)
	{
		if (Array[R][Col] == 'Q')
		{
			return true;
		}
	}

	//check for a queen left of the current position
	while(Left >= 0 && LocalRow >= 0)
	{
		if (Array[LocalRow][Left] == 'Q')
		{
			return true;
		}

		Left--;
		LocalRow--;
	}

	LocalRow = Row;

	while(Right >= 0 && LocalRow >= 0)
	{
		if (Array[LocalRow][Right] == 'Q')
		{
			return true;
		}
		LocalRow--;
		Right++;
	}

	return false;
}


/*===========================================
Function Name: Search void
Arguements: char BoardArray[][8]
int Row
Purpose: Searches for all the possibilites
of the eight queens puzzle
=============================================*/
void Search(char BoardArray[][8], int Row)
{
	ofstream Output;

	for(int i = 0; i < 8; i++)
	{
		if(!UnderAttack(BoardArray, Row, i))
		{
			BoardArray[Row][i] = 'Q';

			if(Row < 7)
			{
				Search(BoardArray, Row+1);
				BoardArray[Row][i] = '-';
			}


			if(Row == 7)
			{
				//loop through and print
				for(int r = 0; r < 8; r++)
				{
					for(int c = 0; c < 8; c++)
					{
						cout << BoardArray[r][c];
					}
					cout << endl;
				}
				cout << "****************" << endl;

				Output.open("Recursion.txt", ofstream::out);
				for(int k = 0; k < 8; k++)
				{
					for(int l=0; l < 8; l++)
					{
						Output << BoardArray[k][l];
					}
				}
				Output.close();

				BoardArray[7][i] = '-';

			}
		}
	}

}