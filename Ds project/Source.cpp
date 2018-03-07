#include <iostream>
#include <string>
#include "client.h"
 #include "tree.h"
#include "treenode.h"
#include "banker.h"
#include <vector>
#include <fstream>
#include <sstream >
using namespace std;

tree databaseClient;
vector<banker> databaseBanker;
// load the system status  from files // 
void loadsystem(void)
{
	fstream  file("clientes.txt", ios::in | ios::out | ios::app);
	if (!file.is_open())
		cout << "error in loading client " << endl;
	else
		cout << "loading clients " << endl;
	
	int age, phone, account;
	int id; 
	
	string s, sbs, sum;
	//client z; 
	while (!file.eof())
	{
		file >> s >> age>>phone>>account;
		list ll;
		file >> sbs;
		while (sbs != "*")
		{
			if (sbs == ".")
			{
				ll.addend(sum);
				sum = "";
			}
			sum += " ";
			sum += sbs;
			file >> sbs;
		}
		sum = "";
		client z(s, age, phone, account, ll);
		databaseClient.insert(z);

	}


	file.close(); 


	fstream  file1("bankers.txt", ios::in | ios::out | ios::app);
	if (!file.is_open())
		cout << "error  loading bankers " << endl;
	else
		cout << "loading bankers " << endl;

	while (file1 >> id >> s >> account)

	{
		banker y(id, s, account);
		databaseBanker.push_back(y);
	}



	file1.close();

	cout << "loading is done successfully " << endl; 
}


// saving all system status 
void save(void)
{
	
	fstream  file3("bankers.txt",  ios::out | std::ofstream::trunc);
	if (!file3.is_open())
		cout << "open failed  " << endl;
	else
		cout << "saving files  " << endl;


	vector<banker>::iterator it; 
	for (it= databaseBanker.begin(); it != databaseBanker.end(); ++it)
	{
		file3 << (*it).getName() << " " << (*it).getID() << " " << (*it).getSalary() << endl; 
     }
	file3.close();
	//saving clients //

	 //traverse the tree to strings 
	 // traverse the tree to vector of strings //
	
fstream  file2("clientes.txt",ios::out | std::ofstream::trunc);
	if (!file2.is_open())
		cout << "open failed  " << endl;
	else
		cout << "saving ....  " << endl;


	
	file2 << databaseClient.parsetree(databaseClient.getroot());

	file2.close();




} // saves 

int main()
{
	
loadsystem();
	list x; 
	
	databaseClient.printalltree(); 

	int ID;
	banker selectedBanker;
	client* selectedClient;
	bool found = false;
	treenode* temp;

	int temp_ID;
	string temp_Name;
	int temp_Age;
	int temp_Contact;
	float temp_Balance;
	client new_entry;

	float deposit_money;
	float withdraw_money;
	float curr_balance;

	int id1, id2;
	float transfer_amount;

	bool logout = false;
	char command;
	cout << "Welcome to KEA3 Banking Platform" << endl;

	do
	{
		cout << "Please choose from the menu below: " << endl;
		cout << "1- Banker Login (press 'b')" << endl;
		cout << "2- Client Login (press 'c')" << endl;
		cout << "3- Exit Platform (press 'x')" << endl;
		cin >> command;
		cout << "Command Entered: " << command << endl;

		found = false;
		switch (command)
		{
		case 'b'://here you are banker and enter information of the banker
			cout << "Enter Banker's ID To Login: ";
			cin >> ID;
			//cout << ID << endl;		
			for (int i = 0; i < databaseBanker.size(); i++)
			{
				if (ID == databaseBanker[i].getID())
				{
					selectedBanker = databaseBanker[i];
					found = true;
				}
			}
			if (!found)
			{
				cout << "This Banker's ID Doesn't Exist" << endl;
			}
			else
			{
				cout << "Hello, Banker " << selectedBanker.getName() << endl;

				char operation;
				do
				{
					logout = false;
					cout << "Please Select The Desired Operation: " << endl;
					cout << "1- Add New Client (press 'a')" << endl;
					cout << "2- Remove Client (press 'r')" << endl;
					cout << "3- View Client's Balance (press 'v')" << endl;
					cout << "4- Transfer Balance (press 't')" << endl;
					cout << "5- List All Clients (press 'c')" << endl;
					cout << "6- View Client's Bank Statment (press 's')" << endl;
					cout << "7- Log Out (press 'l')" << endl;
					cin >> operation;
					cout << "Selected Operation: " << operation << endl;

					switch (operation)
					{
					case 'a':
						cout <<" Name, Age, Contact Number and Starting Balance: " << endl;
						cin >> temp_Name;
						cin >> temp_Age;
						cin >> temp_Contact;
						cin >> temp_Balance;
                        new_entry.setname(temp_Name); new_entry.setage(temp_Age); new_entry.setcontactnumber(temp_Contact); new_entry.setbalance(temp_Balance);
						selectedBanker.addClient(new_entry, databaseClient);
						databaseClient.printalltree();
						break;

					case 'r':
						cout << "Enter The Desired Client's ID: ";
						cin >> temp_ID;
						databaseClient.remove(temp_ID); 
						break;

					case 'v':
						cout << "Enter The Desired Client's ID: ";
						cin >> temp_ID;
						temp_Balance = selectedBanker.viewBalance(temp_ID, databaseClient);
						cout << "Account's Balance = " << temp_Balance << endl;
						break;

					case 't':
						cout << "Enter Transferer ID, Transfered ID, and Transfered Amount: ";
						cin >> id1;
						cin >> id2;
						cin >> transfer_amount;
						selectedBanker.balanceTrans(id1, id2, transfer_amount, databaseClient);
						break;

					case 'c':
						selectedBanker.listClients(databaseClient);
						break;

					case 'l':
						cout << "Logging Out. Returning To Previous Menu." << endl;
					
						logout = true;
						break;
						
					case 's':
						cout << "Enter The Desired Client's ID: ";
						cin >> temp_ID;
						cout << "bank statment " << endl;
						selectedBanker.getBankStatment(temp_ID,databaseClient);
						break;
					
					default:
						cout << "Ivalid Operation" << endl;
						break;
					}
				} while (!logout);
			}

			break;

		case 'c':
			cout << "Enter Client's ID To Login: ";
			cin >> ID;
			//cout << ID << endl;
			temp = databaseClient.search(ID);
			if (temp == nullptr)
			{
				cout << "This Client's ID Doesn't Exist" << endl;
			}
			else
			{
				selectedClient = temp->getdata();
				cout << "Hello, Client " << selectedClient->getname() << endl;

				char operation;
				do
				{
					logout = false;
					cout << "Please Select The Desired Operation: " << endl;
					cout << "1- Deposit Money (press d)" << endl;
					cout << "2- Withdraw Money (press w)" << endl;
					cout << "3- View Balance (press v)" << endl;
					cout << "4- Get Bank Statment (press s)" << endl;
					cout << "5- Log Out (press 'l')" << endl;
					cin >> operation;
					cout << "Selected Operation: " << operation << endl;

					switch (operation)
					{
					case 'd':
						cout << "Enter Amount To Deposit: ";
						cin >> deposit_money;
						selectedClient->deposit(deposit_money);
						cout << "Current Balance = " << selectedClient->viewbalance() << endl;

						break;

					case 'w':
						cout << "Enter The Amount to Withdraw: ";
						cin >> withdraw_money;
						selectedClient->withdraw(withdraw_money);
						cout << "Current Balance = " << selectedClient->viewbalance() << endl;

						break;

					case 'v':
						curr_balance = selectedClient->viewbalance();
						cout << "Your Current Balance Is  " << curr_balance << endl;
						break;

					case 'l':
						cout << "Logging Out. Returning To Previous Menu." << endl;
						logout = true;
					
						break;

					case 's':
						cout << "bank statment " << endl;
						selectedClient->getBankStatment();
						break;

					default:
						cout << "Ivalid Operation" << endl;
						break;
					}
				} while (!logout);
			}
			break;

		case 'x':
			cout << "Thanks For Using KEA3 Platform!" << endl;
	  save();
			exit(EXIT_SUCCESS);
			break;

		default:
			cout << "Ivalid Command" << endl;
			break;
		}

	}while (1);

}