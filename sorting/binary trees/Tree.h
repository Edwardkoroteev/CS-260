/*

*/
#ifndef TREE
#define TREE
#include<iostream>
#include<string>
#include<functional>

using namespace std;

//struct
struct treeNode{
	string data;
	treeNode* left;
	treeNode* right;
};

//class
class treeClass{
private: 
	treeNode* root;
	void inOrderTraversal(const function<void(string,int)> &printingTree, treeNode* theRoot, int& counter);
	void postorderTraversal(const function<void(string,int)> &printingTree, treeNode* theRoot, int& counter);
	void preorderTraversal(const function<void(string,int)> &printingTree, treeNode* theRoot, int& counter);
public:
	//constructor
	treeClass();
	treeClass(treeClass &theCopy);

	//accessors
	treeNode* gettingTreePointer();

	//mutators
	bool insert(string word);
	//void settingTreePointer(treeNode* theRoot);
	bool deletingNode(string word);
	void deepCopy(treeNode* &theCopy, treeNode* theRoot);
	//other
	void inOrderTraversal(const function<void(string,int)> &printingTree);
	void postorderTraversal(const function<void(string,int)> &printingTree);
	void preorderTraversal(const function<void(string,int)> &printingTree);
};



#endif