#pragma once
#include<string>
using namespace std;
class node {


private:
	string data;
	node* next;
public:
	node() { data = ""; next = nullptr; }
	node(string d) : data(d), next(nullptr) {}
	string getData() { return data; }
	void setData(string d) { data = d; }
	node* getNext() { return next; }
	void setNext(node* n) { next = n; }
	friend class list;


};

class list {
private:
	node* chain;
public:
	list() {
		chain = nullptr;
	}

	list(string d) {

		chain = new node(d);
	}
	void addfront(string d) {
		node* temp = new node(d);
		temp->setNext(chain);
		chain = temp;
	}
	void addend(string d) {

		node* temp = chain;
		if (chain == nullptr) chain = new node(d);
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new node(d);
		}


	}
	int getSize()
	{
		if (chain == nullptr)
			return 0;
		int i = 0;
		node* p = new node();
		p = chain;
		while (p->getNext() != nullptr)
		{
			i++;
			p = p->getNext();
		}

		return (i + 1);

}

void print()
	{
	if (chain == nullptr)
	{
		cout << "no history to show" << endl;
		return;
	}
		node*p = chain;

		while (p->next != nullptr)
		{
			cout << p->data << endl;
			p = p->next;
		}
		cout << p->data << endl;

	}
string get(int index)
{
	node* p = new node();
	p = chain;
	for (int i = 0; i < index; i++)
	{
		p = p->getNext();
	}
	return p->getData();

}

bool isEmpty() { return chain == nullptr; }

void plus(list ll)
{
	if (!ll.isEmpty()) {
		node* temp = chain;
		//	if (chain == nullptr) chain = new node(d);
		//else
		//{
		//		while (temp->next != nullptr)
		//	{
		//		temp = temp->next;
		//	}

		for (int i = 0; i < ll.getSize(); i++)
		{
			if (i == 0)
			{
				chain = new node(ll.get(0));
				temp = chain;
			}
			else
			{
				node* n = new node(ll.get(i));
				temp->setNext(n);
				temp = temp->next;
			}
		}
	}


}

};