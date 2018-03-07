#pragma once
#include <iostream>
#include "client.h"
using namespace std;

class treenode
{
	client c;
	treenode* left;
	treenode* right;
public:
	treenode(client a);
	void setright(treenode* r);
	void setleft(treenode* l);
	treenode* getright();
	treenode* getleft();
	client* getdata();
	void setdata(client a);
	
	friend class tree;
	
};

