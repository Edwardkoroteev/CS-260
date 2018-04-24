/*===========================================================
name: edward
date: 5/14/2015
class: cs-260
teacher: jen miller
purpose: sort through 5 different
array sizes 100,1,000,10,000,100,000, and 1,000,000
and populate them randomly, in order, backwards, and sort
them using sorting algotrithms
==========================================================*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

//constant
const int HUNDRED = 100;
const int THOUSAND = 1000;
const int TEN_THOUSAND = 10000;
const int HUNDRED_THOUSAND = 100000;
const int MILLION= 1000000;

struct arrayStorage{
	int hundredArray[HUNDRED];
	int thousandArray[THOUSAND];
	int tenThousandArray[TEN_THOUSAND];
	int hundredThousandArray[HUNDRED_THOUSAND];
	int millionArray[MILLION];
};

struct timeHolder{
	double hundredTime;
	double thousandTime;
	double tenThousandTime;
	double hundredThousandTime;
	double millionTime;
};

//function prototypes
void populatingArrayInOrder(int arrayType[], int size);
void populatingArrayBackwardsOrder(int arrayType[], int size);
void populatingArrayRandomOrder(int arrayType[], int size);
void printingArray(int arrayType[], int size);
void bubbleSortFunction(int arrayType[], int size, double& timeLength);
void selectionSortFunction(int arrayType[], int size, double& timeLength);
void quickSort(int arrayType[], int lowValue, int highValue);

void main()
{
	static arrayStorage inOrderArray;
	static arrayStorage backwardOrderArray;
	static arrayStorage randomOrderArray;
	ofstream outFile;

	//=======BUBBLE SORT TIMES==========
	timeHolder bubbleSortInOrderTime;
	timeHolder bubbleSortBackwardsTime;
	timeHolder bubbleSortRandomTime;

	//========SELECTION SORT TIMES==========
	timeHolder selectionSortInOrderTime;
	timeHolder selectionSortBackwardsTime;
	timeHolder selectionSortRandomTime;

	//========QUICK SORT TIME=============
	timeHolder quickSortInOrderTime;
	timeHolder quickSortBackwardsTime;
	timeHolder quickSortRandomTime;

	clock_t start;
	clock_t finish;

	//populating arrays IN ORDER
	populatingArrayInOrder(inOrderArray.hundredArray,HUNDRED); // 100
	populatingArrayInOrder(inOrderArray.thousandArray,THOUSAND); //1,000
	populatingArrayInOrder(inOrderArray.tenThousandArray,TEN_THOUSAND); //10,000
	populatingArrayInOrder(inOrderArray.hundredThousandArray,HUNDRED_THOUSAND); //100,000
	populatingArrayInOrder(inOrderArray.millionArray,MILLION);//1,000,000

	//bubble sort in order
	bubbleSortFunction(inOrderArray.hundredArray,HUNDRED,bubbleSortInOrderTime.hundredTime); //100
	bubbleSortFunction(inOrderArray.thousandArray,THOUSAND,bubbleSortInOrderTime.thousandTime); //1,000
	bubbleSortFunction(inOrderArray.tenThousandArray,TEN_THOUSAND,bubbleSortInOrderTime.tenThousandTime); //10,000
	bubbleSortFunction(inOrderArray.hundredThousandArray,HUNDRED_THOUSAND,bubbleSortInOrderTime.hundredThousandTime);//100,000
	bubbleSortFunction(inOrderArray.millionArray,MILLION,bubbleSortInOrderTime.millionTime);//1,000,000

	//selection sort in order
	selectionSortFunction(inOrderArray.hundredArray,HUNDRED,selectionSortInOrderTime.hundredTime); //100
	selectionSortFunction(inOrderArray.thousandArray,THOUSAND,selectionSortInOrderTime.thousandTime); //1,000
	selectionSortFunction(inOrderArray.tenThousandArray,TEN_THOUSAND,selectionSortInOrderTime.tenThousandTime); //10,000
	selectionSortFunction(inOrderArray.hundredThousandArray,HUNDRED_THOUSAND,selectionSortInOrderTime.hundredThousandTime);//100,000
	selectionSortFunction(inOrderArray.millionArray,MILLION,selectionSortInOrderTime.millionTime);//1,000,000

	//quick sort in order
	start = clock();
	quickSort(inOrderArray.hundredArray,0,HUNDRED-1);//100
	finish= clock();
	quickSortInOrderTime.hundredTime = (double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(inOrderArray.thousandArray,0,THOUSAND-1);//1,000
	finish=clock();
	quickSortInOrderTime.thousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(inOrderArray.tenThousandArray,0,TEN_THOUSAND-1);//10,000
	finish = clock();
	quickSortInOrderTime.tenThousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(inOrderArray.hundredArray,0,HUNDRED_THOUSAND-1);//100,000
	finish=clock();
	quickSortInOrderTime.hundredThousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start=clock();
	quickSort(inOrderArray.millionArray,0,MILLION-1);//1,000,000
	finish=clock();
	quickSortInOrderTime.millionTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	cout<< "===========IN ORDER============" << endl;
	cout << "BUBBLE SORT" << endl;
	cout << "hundred  " << bubbleSortInOrderTime.hundredTime << endl;
	cout << "thousand  " << bubbleSortInOrderTime.thousandTime << endl;
	cout << "ten thousand  " << bubbleSortInOrderTime.tenThousandTime << endl;
	cout << "hundred thousand  " << bubbleSortInOrderTime.hundredThousandTime << endl;
	cout << "million" << bubbleSortInOrderTime.millionTime << endl;

	cout << endl<< "SELECTION SORT " << endl;
	cout << "hundred  " << selectionSortInOrderTime.hundredTime << endl;
	cout << "thousand  " << selectionSortInOrderTime.thousandTime << endl;
	cout << "ten thousand  " << selectionSortInOrderTime.tenThousandTime << endl;
	cout << "hundred thousand  " << selectionSortInOrderTime.hundredThousandTime << endl;
	cout << "million" << selectionSortInOrderTime.millionTime << endl;

	cout << endl << "QUICK SORT" << endl;
	cout << "hundred  " << quickSortInOrderTime.hundredTime << endl;
	cout << "thousand  " << quickSortInOrderTime.thousandTime << endl;
	cout << "ten thousand  " << quickSortInOrderTime.tenThousandTime << endl;
	cout << "hundred thousand  " << quickSortInOrderTime.hundredThousandTime << endl;
	cout << "million" << quickSortInOrderTime.millionTime << endl;

	//populating in backwards order
	populatingArrayBackwardsOrder(backwardOrderArray.hundredArray,HUNDRED); // 100
	populatingArrayBackwardsOrder(backwardOrderArray.thousandArray,THOUSAND); //1,000
	populatingArrayBackwardsOrder(backwardOrderArray.tenThousandArray,TEN_THOUSAND); //10,000
	populatingArrayBackwardsOrder(backwardOrderArray.hundredThousandArray,HUNDRED_THOUSAND); //100,000
	populatingArrayBackwardsOrder(backwardOrderArray.millionArray,MILLION);//1,000,000

	//bubble sort in order
	bubbleSortFunction(backwardOrderArray.hundredArray,HUNDRED,bubbleSortBackwardsTime.hundredTime); //100
	bubbleSortFunction(backwardOrderArray.thousandArray,THOUSAND,bubbleSortBackwardsTime.thousandTime); //1,000
	bubbleSortFunction(backwardOrderArray.tenThousandArray,TEN_THOUSAND,bubbleSortBackwardsTime.tenThousandTime); //10,000
	bubbleSortFunction(backwardOrderArray.hundredThousandArray,HUNDRED_THOUSAND,bubbleSortBackwardsTime.hundredThousandTime);//100,000
	bubbleSortFunction(backwardOrderArray.millionArray,MILLION,bubbleSortBackwardsTime.millionTime);//1,000,000

	//selection sort in order
	selectionSortFunction(backwardOrderArray.hundredArray,HUNDRED,selectionSortBackwardsTime.hundredTime); //100
	selectionSortFunction(backwardOrderArray.thousandArray,THOUSAND,selectionSortBackwardsTime.thousandTime); //1,000
	selectionSortFunction(backwardOrderArray.tenThousandArray,TEN_THOUSAND,selectionSortBackwardsTime.tenThousandTime); //10,000
	selectionSortFunction(backwardOrderArray.hundredThousandArray,HUNDRED_THOUSAND,selectionSortBackwardsTime.hundredThousandTime);//100,000
	selectionSortFunction(backwardOrderArray.millionArray,MILLION,selectionSortBackwardsTime.millionTime);//1,000,000

	//quick sort in order
	start = clock();
	quickSort(backwardOrderArray.hundredArray,0,HUNDRED-1);//100
	finish= clock();
	quickSortBackwardsTime.hundredTime = (double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(backwardOrderArray.thousandArray,0,THOUSAND-1);//1,000
	finish=clock();
	quickSortBackwardsTime.thousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(backwardOrderArray.tenThousandArray,0,TEN_THOUSAND-1);//10,000
	finish = clock();
	quickSortBackwardsTime.tenThousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(backwardOrderArray.hundredArray,0,HUNDRED_THOUSAND-1);//100,000
	finish=clock();
	quickSortBackwardsTime.hundredThousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start=clock();
	quickSort(backwardOrderArray.millionArray,0,MILLION-1);//1,000,000
	finish=clock();
	quickSortBackwardsTime.millionTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	cout<< "===========BACKWARDS ORDER============" << endl;
	cout << "BUBBLE SORT" << endl;
	cout << "hundred  " << bubbleSortBackwardsTime.hundredTime << endl;
	cout << "thousand  " << bubbleSortBackwardsTime.thousandTime << endl;
	cout << "ten thousand  " << bubbleSortBackwardsTime.tenThousandTime << endl;
	cout << "hundred thousand  " << bubbleSortBackwardsTime.hundredThousandTime << endl;
	cout << "million" << bubbleSortBackwardsTime.millionTime << endl;

	cout << endl<< "SELECTION SORT " << endl;
	cout << "hundred  " << selectionSortBackwardsTime.hundredTime << endl;
	cout << "thousand  " << selectionSortBackwardsTime.thousandTime << endl;
	cout << "ten thousand  " << selectionSortBackwardsTime.tenThousandTime << endl;
	cout << "hundred thousand  " << selectionSortBackwardsTime.hundredThousandTime << endl;
	cout << "million" << selectionSortBackwardsTime.millionTime << endl;

	cout << endl << "QUICK SORT" << endl;
	cout << "hundred  " << quickSortBackwardsTime.hundredTime << endl;
	cout << "thousand  " << quickSortBackwardsTime.thousandTime << endl;
	cout << "ten thousand  " << quickSortBackwardsTime.tenThousandTime << endl;
	cout << "hundred thousand  " << quickSortBackwardsTime.hundredThousandTime << endl;
	cout << "million" << quickSortBackwardsTime.millionTime << endl;

	//random order
	populatingArrayRandomOrder(randomOrderArray.hundredArray,HUNDRED); // 100
	populatingArrayRandomOrder(randomOrderArray.thousandArray,THOUSAND); //1,000
	populatingArrayRandomOrder(randomOrderArray.tenThousandArray,TEN_THOUSAND); //10,000
	populatingArrayRandomOrder(randomOrderArray.hundredThousandArray,HUNDRED_THOUSAND); //100,000
	populatingArrayRandomOrder(randomOrderArray.millionArray,MILLION);//1,000,000

	//bubble sort in order
	bubbleSortFunction(randomOrderArray.hundredArray,HUNDRED,bubbleSortRandomTime.hundredTime); //100
	bubbleSortFunction(randomOrderArray.thousandArray,THOUSAND,bubbleSortRandomTime.thousandTime); //1,000
	bubbleSortFunction(randomOrderArray.tenThousandArray,TEN_THOUSAND,bubbleSortRandomTime.tenThousandTime); //10,000
	bubbleSortFunction(randomOrderArray.hundredThousandArray,HUNDRED_THOUSAND,bubbleSortRandomTime.hundredThousandTime);//100,000
	bubbleSortFunction(randomOrderArray.millionArray,MILLION,bubbleSortRandomTime.millionTime);//1,000,000

	//selection sort in order
	selectionSortFunction(randomOrderArray.hundredArray,HUNDRED,selectionSortRandomTime.hundredTime); //100
	selectionSortFunction(randomOrderArray.thousandArray,THOUSAND,selectionSortRandomTime.thousandTime); //1,000
	selectionSortFunction(randomOrderArray.tenThousandArray,TEN_THOUSAND,selectionSortRandomTime.tenThousandTime); //10,000
	selectionSortFunction(randomOrderArray.hundredThousandArray,HUNDRED_THOUSAND,selectionSortRandomTime.hundredThousandTime);//100,000
	selectionSortFunction(randomOrderArray.millionArray,MILLION,selectionSortRandomTime.millionTime);//1,000,000

	//quick sort in order
	start = clock();
	quickSort(randomOrderArray.hundredArray,0,HUNDRED-1);//100
	finish= clock();
	quickSortRandomTime.hundredTime = (double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(randomOrderArray.thousandArray,0,THOUSAND-1);//1,000
	finish=clock();
	quickSortRandomTime.thousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(randomOrderArray.tenThousandArray,0,TEN_THOUSAND-1);//10,000
	finish = clock();
	quickSortRandomTime.tenThousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start = clock();
	quickSort(randomOrderArray.hundredArray,0,HUNDRED_THOUSAND-1);//100,000
	finish=clock();
	quickSortRandomTime.hundredThousandTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	start=clock();
	quickSort(randomOrderArray.millionArray,0,MILLION-1);//1,000,000
	finish=clock();
	quickSortRandomTime.millionTime=(double)(finish-start)/ CLOCKS_PER_SEC;

	cout<< "===========RANDOM ORDER============" << endl;
	cout << "BUBBLE SORT" << endl;
	cout << "hundred  " << bubbleSortBackwardsTime.hundredTime << endl;
	cout << "thousand  " << bubbleSortBackwardsTime.thousandTime << endl;
	cout << "ten thousand  " << bubbleSortBackwardsTime.tenThousandTime << endl;
	cout << "hundred thousand  " << bubbleSortBackwardsTime.hundredThousandTime << endl;
	cout << "million" << bubbleSortBackwardsTime.millionTime << endl;

	cout << endl<< "SELECTION SORT " << endl;
	cout << "hundred  " << selectionSortBackwardsTime.hundredTime << endl;
	cout << "thousand  " << selectionSortBackwardsTime.thousandTime << endl;
	cout << "ten thousand  " << selectionSortBackwardsTime.tenThousandTime << endl;
	cout << "hundred thousand  " << selectionSortBackwardsTime.hundredThousandTime << endl;
	cout << "million" << selectionSortBackwardsTime.millionTime << endl;


	outFile.open("outFile.csv");
	//======================BUBBLESORT===================
	outFile << "BubbleSort,100,1000,10000,100000,1000000" << endl;
	//random
	outFile << "Random," << bubbleSortRandomTime.hundredTime << "," << bubbleSortRandomTime.thousandTime <<"," <<
		bubbleSortRandomTime.tenThousandTime << "," << bubbleSortRandomTime.hundredThousandTime<< "," <<
		bubbleSortRandomTime.millionTime << endl;

	//in order
	outFile << "In order," << bubbleSortInOrderTime.hundredTime << "," << bubbleSortInOrderTime.thousandTime <<"," <<
		bubbleSortInOrderTime.tenThousandTime << "," << bubbleSortInOrderTime.hundredThousandTime<< "," <<
		bubbleSortInOrderTime.millionTime << endl;

	// backwards order
	outFile << "Backwards," << bubbleSortBackwardsTime.hundredTime << "," << bubbleSortBackwardsTime.thousandTime <<"," <<
		bubbleSortBackwardsTime.tenThousandTime << "," << bubbleSortBackwardsTime.hundredThousandTime<< "," <<
		bubbleSortBackwardsTime.millionTime << endl;

	//==================SELECTION SORT ========================
	outFile << endl << endl;
	outFile << "Selection,100,1000,10000,100000,1000000" << endl;
	//random
	outFile << "Random," << selectionSortRandomTime.hundredTime << "," << selectionSortRandomTime.thousandTime <<"," <<
		selectionSortRandomTime.tenThousandTime << "," << selectionSortRandomTime.hundredThousandTime<< "," <<
		selectionSortRandomTime.millionTime << endl;
	
	//in order
	outFile << "In order," << selectionSortInOrderTime.hundredTime << "," << selectionSortInOrderTime.thousandTime <<"," <<
		selectionSortInOrderTime.tenThousandTime << "," << selectionSortInOrderTime.hundredThousandTime<< "," <<
		selectionSortInOrderTime.millionTime << endl;

	// backwards order
	outFile << "Backwards," << selectionSortBackwardsTime.hundredTime << "," << selectionSortBackwardsTime.thousandTime <<"," <<
		selectionSortBackwardsTime.tenThousandTime << "," << selectionSortBackwardsTime.hundredThousandTime<< "," <<
		selectionSortBackwardsTime.millionTime << endl;

		//=================Quick Sort================5
	outFile << endl << endl;
	outFile << "Quick,100,1000,10000,100000,1000000" << endl;
	
	//random
	outFile << "Random," << quickSortRandomTime.hundredTime << "," << quickSortRandomTime.thousandTime <<"," <<
		quickSortRandomTime.tenThousandTime << "," << quickSortRandomTime.hundredThousandTime<< "," <<
		quickSortRandomTime.millionTime << endl;
	
	//in order
	outFile << "In order," << quickSortInOrderTime.hundredTime << "," << quickSortInOrderTime.thousandTime <<"," <<
		quickSortInOrderTime.tenThousandTime << "," << quickSortInOrderTime.hundredThousandTime<< "," <<
		quickSortInOrderTime.millionTime << endl;

	// backwards order
	outFile << "Backwards," << quickSortBackwardsTime.hundredTime << "," << quickSortBackwardsTime.thousandTime <<"," <<
		quickSortBackwardsTime.tenThousandTime << "," << quickSortBackwardsTime.hundredThousandTime<< "," <<
		quickSortBackwardsTime.millionTime << endl;
	
	outFile.close();
	
	cin.get();
	cin.ignore();
}


/*============================================================
function name: quickSort
parameters: array type (INT), lowValue (INT), highValue (INT)
purpose: sorts any size of array using the quick
soft algorithm method
==============================================================*/
void quickSort(int arrayType[], int lowValue, int highValue)
{
	int h = highValue;
	int l = lowValue;
	int pivot = arrayType[(lowValue+highValue)/2];
	int tempVariable;

	while(l<=h)
	{
		while(arrayType[l]< pivot)
			l++;
		while(arrayType[h]>pivot)
			h--;
		if(l<=h)
		{
			tempVariable = arrayType[l];
			arrayType[l] = arrayType[h];
			arrayType[h] = tempVariable;
			l++;
			h--;
		}
	}

	if (lowValue < h)
		quickSort(arrayType,lowValue,h);
	if (l < highValue)
		quickSort(arrayType, l, highValue);
}


/*=============================================================
function name: bubbleSortFunction
parameters: arrayType (INT), size (INT), timeLength (DOUBLE)&
purpose: sorts any sized array using the bubble sort
algorithm method and times each sorting process
==============================================================*/
void bubbleSortFunction(int arrayType[], int size, double& timeLength)
{
	clock_t start;
	clock_t finish;

	start = clock();

	for(int i = 0; i < size; i++)
	{
		for(int k = 0; k < size; k++)
		{
			if( k<size-1 && arrayType[k]> arrayType[k+1])
			{
				int temp = arrayType[k];
				arrayType[k] = arrayType[k+1];
				arrayType[k+1] = temp;
			}
		}
	}

	finish= clock();
	timeLength = (double)(finish-start)/ CLOCKS_PER_SEC;
}


/*=====================================================================
function name: selectionSortFuntion
parameters: arrayType (INT) ARRAY, size (INT), timeLength (DOUBLE)&
purpose: sorts any size array using the selection sort algorithm
and it times each process and pass by reference time
=======================================================================*/
void selectionSortFunction(int arrayType[], int size, double& timeLength)
{
	clock_t start;
	clock_t finish;

	start = clock();

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(arrayType[j]>arrayType[i])
			{
				int temp = arrayType[i];
				arrayType[i] = arrayType[j];
				arrayType[j] = temp;
			}
		}
	}

	finish= clock();
	timeLength = (double)(finish-start)/ CLOCKS_PER_SEC;
}


/*==========================================
function name: populatingArrayInOrder
parameters: arrayType[]	(INT), size	(INT)
purpose: Populates the array with numbers
starting from 1 to the size of the array
============================================*/
void populatingArrayInOrder(int arrayType[], int size)
{
	for(int i = 0; i < size; i++)
	{
		arrayType[i] = i;
	}
}


/*====================================================
function name: populatingArrayBackwardsOrder
parameters: arrayType[]	(INT), size	(INT)
purpose: Populates the array with numbers
starting from the highest value of the array
size to 0
======================================================*/
void populatingArrayBackwardsOrder(int arrayType[], int size)
{
	for(int i = 1; i <= size; i++)
	{
		arrayType[i-1]= size-i;
	}
}


/*==========================================
function name: populatingArrayRandomOrder
parameters: arraytype[] (INT), size (INT)
purpose: populates any size of 
array in backwards order from the biggest
to smallest numbers in each index
===========================================*/
void populatingArrayRandomOrder(int arrayType[], int size)
{
	int integer;
	srand(42);
	for (int i = 0; i < size; i++)
	{
		integer= rand() % size;
		arrayType[i] = integer;
	}
}


/*=============================================
function name: printingArray
parameters: arrayType[] (INT), size (INT)
purpose: cout the array in the console window
=============================================*/
void printingArray(int arrayType[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arrayType[i] << endl;
	}
}