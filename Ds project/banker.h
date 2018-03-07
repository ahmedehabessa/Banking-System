#pragma once
#include <iostream>
#include "client.h"
#include "tree.h"
using namespace std;

class banker
{
	int id;
	string name;
	int salary;

public:
	banker();
	banker(int ID, string NAME, int S);
	~banker();

	void setID(int a);
	void setName(string n);
	void setSalary(int s);
	int getID();
	string getName();
	int getSalary();
	void addClient(client& a, tree& x);
	bool removeClient(int id, tree& x);
	void removeClient(client& a, tree& x);
	float viewBalance(int a, tree& x);
	void printInfo();
	void getBankStatment(int a, tree& x);
	void balanceTrans(int id1, int id2, float amount, tree& clients);
	void listClients(tree& clients);
};