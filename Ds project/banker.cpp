#include "banker.h"
#include <string>
#include "treenode.h"

banker::banker()
{

}

banker::banker(int ID, string NAME, int S)
{
	id = ID;
	name = NAME;
	salary = S;
}

banker::~banker()
{

}

void banker::setID(int a)
{
	id = a;
}

void banker::setName(string n)
{
	name = n;
}

void banker::setSalary(int s)
{
	salary = s;
}

int banker::getID()
{
	return id;
}

string banker::getName()
{
	return name;
}


int banker::getSalary()
{
	return salary;
}


void banker::addClient(client& a, tree& x)
{
	x.insert(a);
}

/* remove client function requires remove function from the tree */
bool banker::removeClient(int id, tree& x){
	return x.remove(id);
}

float banker::viewBalance(int a, tree& x)
{
	treenode* temp = x.search(a);
	if (temp == nullptr) 
	{
		cout << "No Such ID" << endl; return 0;
	}
	float balance = temp->getdata()->viewbalance();
	return balance;
}



void banker::getBankStatment(int a, tree& x)
{
	treenode* temp = x.search(a);
	if (temp == nullptr)
	{
		cout << "No Such ID" << endl; return ;
	}
	 temp->getdata()->getBankStatment();
}



void banker::balanceTrans(int id1, int id2, float amount, tree& clients)
{
	treenode* owner = clients.search(id1);
	treenode* target = clients.search(id2);
	if (owner == nullptr || target == nullptr)
	{
		cout << "Either Accounts Doesn't Exist!" << endl; return;
	}

	if (owner->getdata()->viewbalance() >= amount)
	{
		owner->getdata()->withdraw(amount);
		target->getdata()->deposit(amount);
		cout << "Transferred Successfully!" << endl;
		cout << "Transferer Balance: " << owner->getdata()->viewbalance() << "\t Transfered Balance: " << target->getdata()->viewbalance() << endl;
	}
	else
	{
		cout << "Owner Account Doesn't Have Enough Funds!" << endl;
	}
}

void banker::listClients(tree& clients)
{
	clients.printalltree();
}


void banker::printInfo()
{
	cout << "ID: " << this->id << "\t Name: " << this->name << "\t Salary: " << this->salary << endl;
}