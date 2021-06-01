#include <iostream>
#include<string>
#include "List.h"

using namespace std;

List::List()
{
	head = NULL;
	cursor = NULL;
	prev = NULL;
	tail = NULL;
	personal = NULL;
}

List::~List()
{
	makeListEmpty();
}

bool List::listIsEmpty() const
{
	return (head == NULL);
}

bool List::curIsEmpty() const
{
	return (cursor == NULL);
}

void List::toFirst()
{
	cursor = head;
	prev = NULL;
}

bool List::atFirst() const
{
	return (cursor == head);
}

void List::advance()
{
	prev = cursor;
	cursor = cursor->next;
}

void List::toEnd()
{
	if(!listIsEmpty())
	{
		toFirst();
		while(cursor->next != NULL)
		{
			advance();
		}
	}
}

bool List::atEnd() //need feedback
{
	return (cursor->next == NULL);
}

int List::listSize() const
{
	NodePointer counter;
	int size = 0;
	if(!listIsEmpty())
	{	
		counter = head;
		while(counter != NULL)
		{
			size++;
			counter = counter->next;			
		}
	}
	return size;
}

void List::updateData(const int &id,const string name,const float &grade)
{
	cursor->data.st_name = name;
	cursor->data.st_no = id;
	cursor->data.st_grade = grade;}

void List::retreiveData (student d) const
{
	d = cursor->data;
}
	
void List::insertFirst (const int &k,const int &id,const string name,const float &grade)
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k;
	pnew->data.st_name = name;
	pnew->data.st_no = id;
	pnew->data.st_grade = grade;
	pnew->next = head;
	head = pnew;
	cursor = head;
	prev = NULL;
}

void List::insertAfter (const int &k, const int &id,const string name,const float &grade)
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k;
	pnew->data.st_name = name;
	pnew->data.st_no = id;
	pnew->data.st_grade = grade;	
	pnew->next = cursor->next;
	cursor->next = pnew;
}

void List::insertBefore (const int &k, const int &id,const string name,const float &grade) //need feedback
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k;
	pnew->data.st_name = name;
	pnew->data.st_no = id;
	pnew->data.st_grade = grade;
	pnew->next = cursor;
	prev = pnew;	
}

void List::insertEnd (const int &k, const int &id,const string name,const float &grade)
{
	if(listIsEmpty())
	{
		insertFirst(k, id, name, grade);
	}
	else
	{
		toEnd();
		insertAfter(k, id, name, grade);
	}
//	NodePointer pnew;
//	pnew = new node;
//	pnew->key = k;
//	pnew->data = d;
//	toEnd();
//	cursor->next = pnew;
//	prev = cursor;
//	cursor = pnew;
}

void List::deleteNode()
{
	NodePointer ptemp;

	if (!curIsEmpty())
	{
		if (atFirst())
		{
			ptemp = cursor;
			cursor = cursor->next;
			head = cursor;
			delete ptemp;
		}
		else
		{
			ptemp = cursor;
			cursor = cursor->next;
			prev->next = cursor;
			delete ptemp;
		}
	}
}

void List::deleteFirst()
{
	if(!listIsEmpty())
	{
		toFirst();
		deleteNode();		
	}
}

void List::deleteEnd()
{
	if(!listIsEmpty())
	{
		toEnd();
		deleteNode();		
	}
}

void List::makeListEmpty() //need feedback
{
	while(!listIsEmpty())
	{
		deleteFirst();
	}
	
//	toFirst();
//	while(!listIsEmpty())
//	{
//		deleteNode();
//	}
	
}

bool List::search(const int &k) //need feedback
{	
	if(!listIsEmpty())
	{
		toFirst();
		while(cursor != NULL)
		{
			if(k == cursor->key)
				return true;
			else
				advance();
		}
		return false;
	}
}

void List::orderInsert(const int &k, const int &id,const string name,const float &grade) //need feedback
{	
	if(listIsEmpty())
	{
		insertFirst(k, id, name, grade);
	}
	else
	{
		toFirst();
		while((k > cursor->key) && (cursor->next != NULL))
			advance();
		insertBefore(k, id, name, grade);	
	}
}


void List::traverse()
{
	toFirst();
	while(!curIsEmpty())
	{
		cout << "key: " << cursor->key << " || " << "data: " << endl
		<< "id: " << cursor->data.st_no << endl
		<< "name: " << cursor->data.st_name << endl
		<< "grade: " << cursor->data.st_grade << endl
		<< "===================================" << endl;
		advance();
	}
}


//assignment requirements//

float List::gradesAverage()
{
	float sum = 0;

	if(!listIsEmpty())
	{
		toFirst();
		while(!curIsEmpty())
		{
			sum += cursor->data.st_grade;
			advance();	
		}
	}
	return sum/listSize();
}

void List::createStudent(const int &counter)
{
		int id;
		string name;
		float grade;
		
		cout << "Enter Student ID: ";
		cin >> id;
		
		cout << "Enter Student Name: ";
		cin >> name;
		
		cout << "Enter Student Grade: ";
		cin >> grade;
		
		insertEnd(counter, id, name, grade);
}


 

