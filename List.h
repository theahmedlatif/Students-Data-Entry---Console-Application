#ifndef LIST_H
#define LIST_H
#include<string>
#include<cstring>
using namespace std;
class List
{
	private:
		//student data
		class student
		{
			public:
				string st_name;
				int st_no;
				float st_grade;
		};
		typedef student * StudentPointer;
		
		//node data
		class node
		{
			public:
				int key;
				student data;
				node* next;
		};
		
		typedef node * NodePointer;
		
		NodePointer head, cursor, prev, tail;
		StudentPointer personal;
		
	public:
		//construct empty list
		List();
		//list destructor
		~List();
		
		//functions prototype
		bool listIsEmpty() const;
		bool curIsEmpty() const;
		void toFirst();
		bool atFirst() const;
		void advance();
		void toEnd();
		bool atEnd();
		int listSize() const;
		void updateData(const int &,const string,const float &);
		void retreiveData (student) const;
		void insertFirst (const int &,const int &,const string,const float &);
		void insertAfter (const int &, const int &,const string,const float &);
		void insertBefore (const int &, const int &,const string,const float &);
		void insertEnd (const int &, const int &,const string,const float &);
		void deleteNode();
		void deleteFirst();
		void deleteEnd();
		void makeListEmpty();
		bool search(const int &);
		void orderInsert(const int &,const int &,const string,const float &);
		void traverse();
		
		//assignment requirements//
		float gradesAverage();
		void createStudent(const int &);
};

#endif


