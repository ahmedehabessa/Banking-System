#pragma once
#include "treenode.h"
#include <iostream>
#include <vector>
using namespace std;
class tree
{
private:
	treenode* rootptr;
	vector<int> ids;
	void traverseinorder(treenode* p);
	
public:
	tree();
	bool isempty();
	treenode* getroot();
	void setroot(treenode* k);
	treenode* search(int ID);
	bool insert(client a);
	void printalltree();
	bool remove(int x);//x is id of client 
	string tree::parsetree(treenode* p);
	string tree::parsetree2(treenode* p);
	int heightplusone(treenode* t); //return height of the tree plus one
	bool isleaf(treenode* p);
	void generateID(client& a);
	void levelOrder(treenode* t);
	void givenlevel(treenode* t,int level);
	//bool Remove(int id);//is interfacing to remove fn to hide details about tree to another class

};

