/*=================================================
name: Edward
date: 6/1/2015
teacher:jen Miller
class: cs-260
purpose: implement a binary tree and delete
the nodes using funcion pointers
and traversing the tree in preorder,
post order, and in order
=================================================*/
#include"Tree.h"

//function prototype
void printingTree(string myData, int theCounter);


/*=================================================
Function Name: treeClass::treeClass()	Constructor
Parameters: none
purpose: initializes private variables
in the treeClass Class
=================================================*/
treeClass::treeClass()
{
	root=NULL;
}


/*=================================================
Function Name: treeClass()	Constructor
Parameters:	treeClass::treeClass &theCopy
purpose: constructor for the copy binary tree
and the function implements a deep copy of 
the binary tree
=================================================*/
treeClass::treeClass(treeClass &theCopy)
{
	if(theCopy.gettingTreePointer()==NULL)
	{
		root= NULL;
	}
	else
	{
		deepCopy(root,theCopy.root);
	}
}

/*=================================================
Function Name: treeClass::insert()
Parameters: word (string)
purpose: inserts the nodes into the correct
form that if a binary tree.
=================================================*/
bool treeClass::insert(string word)
{
	treeNode* newNode = NULL; // ptr to the new node
	treeNode* current = NULL; // keep track of current node
	treeNode* previous = NULL; // keep track of last node visited

	newNode = new treeNode; // allocates memory for the new node
	newNode->data = word;
	newNode->left = NULL;
	newNode->right = NULL;

	if(root == NULL) // check if first node in the tree
	{
		root = newNode; // the new node is the root
		return true;
	}
	else{ // if this isn't the first node in the tree
		current = root; // start traversing at the root

		// keep traversing until we reach a NULL node
		while(current != NULL)
		{
			if(newNode->data == current->data){
				// NO DUPLICATES ALLOWED
				return false;
			}
			else if(newNode->data < current->data){
				previous = current; // update previous node ptr
				// need to move left
				current = current->left;
			}
			else{ // newNode > current
				previous = current; // update previous node ptr
				// need to move right
				current = current->right;
			}
		} // end while loop

		// insert the new node into the tree
		if(newNode->data < previous->data){
			// insert the new node to the left of previous
			previous->left = newNode;
			return true;
		}
		else{ // newNode > previous
			// insert the new node to the right of previous
			previous->right = newNode;
			return true;
		}
	}
}


/*==========================================================
Function Name: treeClass::postorderTraversal()
Parameters: const function<void(string,int)>&printingTree,
			theRoot (treeNode*),
			counter	(int&)
purpose: traverses the binary tree in a 
post order recursive method by pointing left, then
pointing right, and finally visiting the node
============================================================*/
void treeClass::postorderTraversal(const function<void(string,int)> &printingTree, treeNode* theRoot, int& counter)
{
	if(theRoot!=NULL)
	{
		counter++;
		postorderTraversal(printingTree,theRoot->left,counter);
		postorderTraversal(printingTree,theRoot->right,counter);
		counter--;
		printingTree(theRoot->data,counter);
	}
}


/*=======================================================
Function Name: treeClass::postorderTraversal()
Parameters:	const function<void(string,int)>&printingTree
purpose: calls the postorderTraversal function
and sends it the root and the counter
========================================================*/
void treeClass::postorderTraversal(const function<void(string,int)> &printingTree)
{
	int counter=0;
	postorderTraversal(printingTree,root,counter);
}


/*=================================================
Function Name: treeClass::preorderTraversal()
Parameters: const function<void(string,int)>& printingTree
			theRoot	(treenode*),
			counter	(int&)
purpose: traverses the binary tree in a
preorder recursive method by visiting the node,
then moving left, then moving right
=================================================*/
void treeClass::preorderTraversal(const function<void(string,int)> &printingTree, treeNode* theRoot, int& counter)
{
	if(theRoot!=NULL)
	{
		printingTree(theRoot->data,counter);
		counter++;
		preorderTraversal(printingTree,theRoot->left,counter);
		preorderTraversal(printingTree,theRoot->right,counter);
		counter--;
	}
}


/*=========================================================
Function Name: treeClass::preorderTraversal()
Parameters: const function<void(string,int)>& printingTree
purpose: calls the preorderTraversal function
which then starts the recursion
=========================================================*/
void treeClass::preorderTraversal(const function<void(string,int)> &printingTree)
{
	int counter=0;
	preorderTraversal(printingTree,root,counter);
}


/*=================================================
Function Name: treeClass::inOrdertraversal()
Parameters: const function<void(string,int)>&printingTree
			theRoot	(treeNode*),
			counter	(int&)
purpose: traverses the binary tree in a
inorder recursive method by moving left,
visiting the node, then moving right
=================================================*/
void treeClass::inOrderTraversal(const function<void(string,int)> &printingTree, treeNode* theRoot, int& counter)
{
	if(theRoot!=NULL)
	{
		counter++;
		inOrderTraversal(printingTree,theRoot->left,counter);
		counter--;
		printingTree(theRoot->data,counter);
		counter++;
		inOrderTraversal(printingTree, theRoot->right,counter);
		counter--;
	}
}


/*==========================================================
Function Name: treeClass::inOrderTraversal(0
Parameters: const function<void(string,int)> & printingTree
purpose: calls the inOrderTraversal function which then
starts the recursion
==========================================================*/
void treeClass::inOrderTraversal(const function<void(string,int)> &printingTree)
{
	int counter = 0;
	inOrderTraversal(printingTree, root, counter);
}


/*=================================================
Function Name: void printingTree()
Parameters: myData	(string)
			theCounter	(int)
purpose: prints the string and the counter
in a nicely fromatted output
=================================================*/
void printingTree(string myData, int theCounter)
{
	cout << myData << "(" << theCounter << "), " << endl;
}


/*========================================================
Function Name: treenode* treeClass::gettingTreePointer()
Parameters: NONE
purpose: returns the root
=================================================*/
treeNode* treeClass::gettingTreePointer()
{
	return root;
}


/*=================================================
Function Name: void treeClass::deepCopy()
Parameters: theCopy	(treeNode*&)
			theRoot	(treeNode*)
purpose: does a deep copy of the original binary
tree which doesn't allow the user to modify the 
original but they have access to an exact copy
=================================================*/
void treeClass::deepCopy(treeNode* &theCopy, treeNode* theRoot)
{
	if(theRoot == NULL)
	{
		theCopy = NULL;
	}
	else
	{
		theCopy = new treeNode;
		theCopy->data = theRoot->data;
		deepCopy(theCopy->left, theRoot->left);
		deepCopy(theCopy->right, theRoot->right);
	}
}


/*=================================================
Function Name: bool treeClass::deletingNode()
Parameters: word (string)
purpose: deletes a node from the binary
tree that is being sent into the function
=================================================*/
bool treeClass::deletingNode(string word)
{
	treeNode* current = root;
	treeNode* currentTrail = current;
	treeNode* traversal=NULL;
	treeNode* nodeToSwap=NULL;
	treeNode* parentNodeToSwap=NULL;

	if(root == NULL)
	{
		return false;
	}
	else
	{
		while(current != NULL&& current->data != word)
		{
			currentTrail=current;

			if(current->data > word)
			{
				current = current->left;
			}
			else if(current->data < word)
			{
				current = current->right;
			}
		}

		if(current->data != word)
		{
			return false;
		}

		//if a leaf
		if(current->right == NULL && current->left == NULL)
		{
			if(current == root)
			{
				delete current;
				root = NULL;
				return true;
			}
			else if(currentTrail->left == current)
			{
				delete current;
				currentTrail->left = NULL;
				return true;
			}
			else if(currentTrail->right == current)
			{
				delete current;
				currentTrail->right = NULL;
				return true;
			}
		}

		else if(current->left != NULL && current->right == NULL)
		{
			if(currentTrail->left == current)
			{
				currentTrail->left = current->left;
				delete current;
				return true;
			}
			else if(currentTrail->right = current)
			{
				currentTrail->right = current->right;
				delete current;
				return true;
			}
		}

		else if(current->left == NULL && current->right != NULL)
		{
			if(currentTrail->left == current)
			{
				currentTrail->left = current->left;
				delete current;
				return true;
			}
			else if(currentTrail->right = current)
			{
				currentTrail->right = current->right;
				delete current;
				return true;
			}
		}

		else if(current->right != NULL & current->left != NULL)
		{
			traversal= current->left;
			nodeToSwap= current;
			parentNodeToSwap= currentTrail;

			while(traversal->right != NULL)
			{
				parentNodeToSwap= nodeToSwap;
				nodeToSwap= traversal;
				traversal= traversal->right;
			}

			if(nodeToSwap->left != NULL && nodeToSwap->right == NULL)
			{
				if(parentNodeToSwap->left == nodeToSwap)
				{
					parentNodeToSwap->left = nodeToSwap->left;
					current->data=nodeToSwap->data;
					delete nodeToSwap;
					return true;
				}
				else if(parentNodeToSwap->right == nodeToSwap)
				{
					parentNodeToSwap->right = nodeToSwap->left;
					current->data=nodeToSwap->data;
					delete nodeToSwap;
					return true;
				}
			}

			else if(nodeToSwap->left == NULL && nodeToSwap->right == NULL)
			{
				if(parentNodeToSwap->left == nodeToSwap)
				{
					parentNodeToSwap->left = NULL;
					current->data = nodeToSwap->data;
					delete nodeToSwap;
					return true;
				}
				else if(parentNodeToSwap->right == nodeToSwap)
				{
					parentNodeToSwap->right=NULL;
					current->data = nodeToSwap->data;
					delete nodeToSwap;
					return true;
				}
			}
			else if(nodeToSwap->left != NULL && nodeToSwap->right!= NULL)
			{
				if(parentNodeToSwap->left==nodeToSwap)
				{
					parentNodeToSwap->left= nodeToSwap->left;
					traversal->right = nodeToSwap->right;
					delete nodeToSwap;
					return true;
				}
			}
			else if(nodeToSwap->left == NULL && nodeToSwap->right != NULL)
			{
				current->data = traversal->data;
				nodeToSwap->right=NULL;
				delete traversal;
				return true;
			}
		}
	}
	return false;
}

void main()
{
	treeClass myClass;

	//populating the binary tree
	myClass.insert("Jinx");
	myClass.insert("Charmander");
	myClass.insert("Snorlax");
	myClass.insert("Clefairy");
	myClass.insert("Diglett");
	myClass.insert("Kakuna");
	myClass.insert("Meowth");
	myClass.insert("Nidorina");
	myClass.insert("Pikachu");
	myClass.insert("Blastoise");
	myClass.insert("Squirtle");
	myClass.insert("Ivysaur");
	myClass.insert("Bulbasaur");
	myClass.insert("Abra");

	//copying the tree class
	treeClass copiedClass(myClass);

	//printing the original tree in order
	cout<< "=========ORIGINAL TREE=========" << endl;
	cout<< "IN ORDER" << endl;
	myClass.inOrderTraversal(printingTree);

	//post order
	cout<< endl<< "POST ORDER" << endl;
	myClass.postorderTraversal(printingTree);

	//preorder
	cout<< endl << "PREORDER" << endl;
	myClass.preorderTraversal(printingTree);

	//deep tree copy
	cout << endl << "========DEEP==COPY==TREE========" << endl;
	cout << "IN ORDER" << endl;
	copiedClass.inOrderTraversal(printingTree);

	//
	//deleting blastoise
	cout << endl << "Deleting Blastoise" << endl;
	if(copiedClass.deletingNode("Blastoise")==true)
		cout << "DELETE SUCCESSFUL" << endl;
	else
		cout << "DELETE NOT SUCCESSFUL" << endl;

	copiedClass.inOrderTraversal(printingTree);

	//deleting squirtle
	cout <<  endl << "Deleting Squirtle" << endl;
	if(copiedClass.deletingNode("Squirtle")==true)
		cout << "DELETE SUCCESSFUL"<< endl;
	else
		cout << "DELETE NOT SUCCESSFUL" << endl;

	copiedClass.inOrderTraversal(printingTree);

	//deleting meowth
	cout << endl << "Deleting Meowth" << endl;
	if(copiedClass.deletingNode("Meowth") == true)
		cout << "DELETE SUCCESSFUL"<< endl;
	else
		cout << "DELETE NOT SUCCESSFUL" << endl;

	copiedClass.inOrderTraversal(printingTree);

	//deleting Jinx
	cout << endl << "Deleting Jinx" << endl;
	if(copiedClass.deletingNode("Jinx") == true)
		cout << "DELETE SUCCESSFUL"<< endl;
	else
		cout << "DELETE NOT SUCCESSFUL" << endl;

	copiedClass.inOrderTraversal(printingTree);
	
	//printing the copy tree
	cout << endl << "=======COPY==OF==THE==TREE=======" << endl;
	cout << "IN ORDER" << endl;
	copiedClass.inOrderTraversal(printingTree);

	//printing the tree in postorder
	cout << endl << "POST ORDER" << endl;
	copiedClass.postorderTraversal(printingTree);

	//printing the tree in preorder
	cout << endl << "PRE ORDER" << endl;
	copiedClass.preorderTraversal(printingTree);


	//deleting blastoise
	cout << "\nDELETING FROM ORIGINAL TREE\n";
	cout << endl << "Deleting Blastoise" << endl;
	if(myClass.deletingNode("Blastoise")==true)
		cout << "DELETE SUCCESSFUL" << endl;
	else
		cout << "DELETE NOT SUCCESSFUL" << endl;

	myClass.inOrderTraversal(printingTree);

	//deleting squirtle
	cout <<  endl << "Deleting Squirtle" << endl;
	if(myClass.deletingNode("Squirtle")==true)
		cout << "DELETE SUCCESSFUL"<< endl;
	else
		cout << "DELETE NOT SUCCESSFUL" << endl;

	myClass.inOrderTraversal(printingTree);

	//deleting meowth
	cout << endl << "Deleting Meowth" << endl;
	if(myClass.deletingNode("Meowth") == true)
		cout << "DELETE SUCCESSFUL"<< endl;
	else
		cout << "DELETE NOT SUCCESSFUL" << endl;

	myClass.inOrderTraversal(printingTree);

	//deleting Jinx
	cout << endl << "Deleting Jinx" << endl;
	if(myClass.deletingNode("Jinx") == true)
		cout << "DELETE SUCCESSFUL"<< endl;
	else
		cout << "DELETE NOT SUCCESSFUL" << endl;

	myClass.inOrderTraversal(printingTree);

	//printing the original tree in order
	cout<< "=========ORIGINAL TREE=========" << endl;
	cout<< "IN ORDER" << endl;
	myClass.inOrderTraversal(printingTree);

	//post order
	cout<< endl<< "POST ORDER" << endl;
	myClass.postorderTraversal(printingTree);

	//preorder
	cout<< endl << "PREORDER" << endl;
	myClass.preorderTraversal(printingTree);


	cin.get();
	cin.ignore();
}