#include <iostream>
using namespace std;
#define size 10

class queue_array {
public:
	int arr[size];
	int front;
	int length;
	int pos;
	queue_array() {
		front = 0;
		length = 0;
	}

	void enqueue(int a) {
		pos = (front + length) % size;                  //this is the (actual length -1) which gives us the position/index of the box
		arr[pos] = a;
		length++;   // this is the actual length
	}

	int dequeue() {
		int a;
		a = arr[front];
		front++;
		length--;
		return a;
	}

	void print() {
		for (int i = front; i <= pos; i++) { //this pos is the position of the last box which is saved after the enqueue opertion,
											//so we print from front(which is the position of the first box) to pos(position/index of the last box filled)
			cout<<"\t" <<"["<< arr[i]<<"]" << endl;
		}
		cout<<"\t" << "---" << endl;
	}
};

class node{
public:
	int data=0;
	node* next;
	node* prev;
};

class queue_linkedlist {
public:
	node*head;

	queue_linkedlist() {
		head = new node();
		head->next = NULL;
		head->prev = head;  //circular linked list
	}

	void enqueue(int a) {
		node* nnode = new node();
		nnode->data = a;
		node* n = head->prev;  // n is the current position
		n->next = nnode;
		nnode->prev = n;
		nnode->next = NULL;
		head->prev = nnode;
	}

	int dequeue() {
		int a;
		node*n = head->next;
		a=n->data;
		head->next = n->next;
		n->next->prev = head;
		delete n;
		return a;
	}

	void print() {
		node*n = head->next;
		while (n!=NULL) {
			cout <<"\t"<< "[" << n->data << "]" << endl;
			n = n->next;
		}
		cout <<"\t" <<"---" << endl;
	}
};

int main() {
	queue_linkedlist* a = new queue_linkedlist();
	queue_array* b = new queue_array();

	cout << "Queue using Circular array implementation:	" << endl;
	b->enqueue(3);
	b->enqueue(5);
	b->print();
	b->enqueue(7);
	b->enqueue(9);
	b->print();
	b->dequeue();
	b->print();

	cout << endl;
	cout << "Queue using Circular Linked list implementation: " << endl;
	a->enqueue(3);
	a->enqueue(5);
	a->print();
	a->enqueue(7);
	a->enqueue(9);
	a->print();
	a->dequeue();
	a->print();
	return 0;
}