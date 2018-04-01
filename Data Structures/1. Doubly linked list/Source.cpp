#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node* prev;
	node() {									// initialisation of head node
		data = 0;
		next = NULL;
		prev = NULL;
	}
	node(int d, node* nnode) {					//custom initialisation of new node made 
		data = d;
		next = nnode;
	}

	void add(node* nnode) {						//Very important element in doubly linked list this adds the newly created node to the previously created node
		next = nnode;
		prev = nnode->prev;
		nnode->prev = this;					//this is dat pointer that has called this function which keeps on changing
	} 
};

void print(node* head) {
	node* n=head->next;
	while (true) {
		cout <<"[" <<n->data<<"]" << endl;
		n = n->next;
		if (n==NULL) {
			break;
		}
	}
}


int main() {
	node* head = new node();
	node* n = head; 
	for (int i = 2; i < 6;i++) {
		node* nnode = new node(i,NULL);
		n->add(nnode);
		n = nnode;                    // n refers to the current pointer and it keeps on changing it is initially pointing towards the dummy head node
	}
	print(head);
	return 0;
}


/*-----------------------------------Note:---------------------------------------------

-What is the point of having a dummy head node ?

A dummy head node is only used to access the node after the linked list is completed.
so, it really depends from where you want to access your linked list. If you want to access your linked list from the first node then put the head
node in the starting of the first node.
Whereas if you want to access your linked list from the end, then put your dummy node that side.

NOTE:
-In making a stack using singly linked list implementation we need to access the stack from the top, So, we leave a dummy head node their so we can easily 
access and print out the stack from the top. Basically LIFO operates if you put the linked list at the top(near the last node)
- Here we have kept the dummy node in the starting of linked list, so we if want to access the linked list we can access the starting part by using the 
dummy head pointer. and so we can easily print from starting node to last node as the dummy head node is in starting.
In short, Dummy head node is only used for accessing a node and to print the linked list.
*/