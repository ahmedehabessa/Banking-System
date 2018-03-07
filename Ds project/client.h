#pragma once
#include <iostream>
#include "list.h"
#include "time.h"
using namespace std;
class client
{
	int id;
	string name;
	float balance;
	int age;
	int contactnumber;
	list l;
public:
	client();
	client(string N, int ag, int contactno, float bal);//constructor when make a new client (ba3mlo account gded y3ny)
	client(int id,string N, int ag, int contactno, float bal, list ll);//constructor when make a new client (ba3mlo account gded y3ny)
	client::client(string N, int ag, int contactno, float bal, list ll);
	
	//deh l functions law 7ad e7tag 7aga fl mosta2bl nb2a nezawed bs dah mabda2y
	void setid(int i);
	void setname(string n);
	void setage(int a);
	void setbalance(float bal);
	void setcontactnumber(int contactno);
	int getid();
	void setlist(list tt) { l.plus(tt); }
	list getlist() { return l; }
	string getname();
	int getage();
	float viewbalance();
	int getcontactnumber();
    void deposit(float money);
	void withdraw(float money);
	void printallclientinfo();
	string parseclient(); 
	string  client::parseclient2();
	void getBankStatment() { l.print(); }
};

