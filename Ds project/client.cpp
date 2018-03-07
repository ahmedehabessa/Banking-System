#include "client.h"
#include <string>
#include <sstream>
string NumericToString(int r)
{
	stringstream ss;
	ss << r;
	return ss.str();
}
client::client()
{
	
	
}

client::client( string N, int ag, int contactno, float bal) //constructor when make a new client (ba3mlo account gded y3ny)
{ 
	id=0;
	name = N;
	age = ag;
	balance = bal; //l client hayfta7 account be 7sab kam?akid mesh bey3ml account 3shan ysebo fady :D
	contactnumber = contactno;
	//l.plus(ll);
}

client::client(int id,string N, int ag, int contactno, float bal, list ll) //constructor when make a new client (ba3mlo account gded y3ny)
{
	id = id;
	name = N;
	age = ag;
	balance = bal; //l client hayfta7 account be 7sab kam?akid mesh bey3ml account 3shan ysebo fady :D
	contactnumber = contactno;
	l.plus(ll);
}
client::client( string N, int ag, int contactno, float bal, list ll) //constructor when make a new client (ba3mlo account gded y3ny)
{
	name = N;
	age = ag;
	balance = bal; //l client hayfta7 account be 7sab kam?akid mesh bey3ml account 3shan ysebo fady :D
	contactnumber = contactno;
	l.plus(ll);
}

void client::setname(string n)
{
	name = n;
}
void client::setage(int a)
{
	age = a;
}
void client::setid(int i)
{
	id = i;
}

int client::getid()
{ 
	return id; 
}
string client::getname() 
{
	return name;
}
int client::getage()
{
	return age;
}
float client::viewbalance()
{ 
	return balance; 
}
int client::getcontactnumber() 
{
	return contactnumber;
}


void client::setbalance(float bal)
{
	balance = bal;
}
void client::withdraw(float money)
{
	balance -= money;
	time_t rawtime;
	char s[26];
	time(&rawtime);
	ctime_s(s, 26, &rawtime);
	string s1 = "withdraw = " + to_string(money) + "\t @ time: " + s;
	l.addend(s1);
}

void client::deposit(float money)
{
	balance += money;
	time_t rawtime;
	char s[26];
	time(&rawtime);
	ctime_s(s, 26, &rawtime);
	string s1 = "deposit = " + to_string(money) + " \t @  time: " + s;
	l.addend(s1);
}
void client::setcontactnumber(int contactno)
{
	contactnumber = contactno;
}
void client::printallclientinfo()
{
	cout << "id:" << id;
	cout << "  name:";
	cout << name;
	cout << "  age:" << age;
	cout << "  balance:" << balance;
	cout << "  contact number:" << contactnumber << endl;
}
string  client::parseclient()
{
	string z;

	string ss = "";
	if (!l.isEmpty())
		for (int i = 0; i < l.getSize(); i++)
		{
			ss = ss + l.get(i);
			ss += " . ";
		}
	z =name+" "+ NumericToString(age) +" " + NumericToString(contactnumber) +" "+NumericToString(balance) + " " + ss + "\n" + " * ";
	return z; 

}
string  client::parseclient2()
{
	string z;

	string ss = "";
	if (!l.isEmpty())
		for (int i = 0; i < l.getSize(); i++)
		{
			ss = ss + l.get(i);
			ss += " . ";
		}
	z = NumericToString(id)+" "+name + " " + NumericToString(age) + " " + NumericToString(contactnumber) + " " + NumericToString(balance) + " " + ss + "\n" + " * ";
	return z;

}


/*client::~client()
{
}*/
