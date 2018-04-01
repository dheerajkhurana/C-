#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;                   
	node() {                           // constructor is automatically called just after making an object
		data = 0;
		next = NULL;
	}
};

class stack{                  // STACK IS LIFO: LAST IN FIRST OUT, so we will make the dummy head pointer at the top so printing and accessing is easy
public:
	node* head;
	stack() {
		head = new node();   // for initialisation using the basic constructor, can also choose to not use parenthesis but use is a good practice
	}
	void push(int a) {          
		node* n = new node();
		n->data = a;
		n->next = head->next;
		head->next = n;
	}
	int pop() {          //poping the top most data input in the stack 
		int a;
		node* n = n = head->next;
		a=n->data;
		head->next=n->next;
		delete n;       // we can delete the node pointer as its work is done and it is jsut wasting space in the heap
		return a;
	}
	void print() {
		node*n = head->next;
		while (n!=NULL) {
			cout <<"["<< n->data <<"]"<< endl;
			n = n->next;
		}
		cout << "---" << endl;
	}
};


int main() {
	stack* s = new stack();   //we are making a object pointer that is pointing towards the new object created from stack

	s->push(2);
	s->push(3);
	s->push(4);
	s->print();
	s->pop();
	s->print();
	s->pop();
	s->print();
	s->push(5);
	s->push(7);
	s->print();
	return 0;
}