#include "treenode.h"



treenode::treenode(client a)
{
	
	c.setage(a.getage());
	c.setbalance(a.viewbalance());
	c.setcontactnumber(a.getcontactnumber());
	c.setid(a.getid());
	c.setname(a.getname());	
	c.setlist(a.getlist());
		right = NULL;
		left = NULL;
	}
void treenode::setright(treenode* r)
{
	this->right = r;
}
void treenode::setleft(treenode* l)
{
	this->left = l;
}
treenode* treenode::getright()
{
	return right;
}
treenode* treenode::getleft()
{
	return left;
}
client* treenode::getdata()
{
	return &c;
}
void treenode::setdata(client a)
{
	c.setage(a.getage());
	c.setbalance(a.viewbalance());
	c.setcontactnumber(a.getcontactnumber());
	c.setid(a.getid());
	c.setname(a.getname());
}



