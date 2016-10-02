/*
	*Implementing singly linked list
	*Still thinking of functions we'll require in linked list
*/

/*
	*********************Things to include in documentation***************************
	*Details about the return type of insertAt
	*************************************END******************************************
*/

/*
	********************************Possible Errors***********************************
	*Value change of size might have been missed.
	**********************************************************************************
*/

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

template <typename T>
class linkedList{
		struct node{				//Declares node which will keep the information of next node along with some value required by user
			T item; node *next;
			node (T val, node* Next){
				item = val;
				next = head;
			}
		};
		typedef node* link;
		typedef link Node;			//link effectively points to node.
		Node head, current;			//stores the address for first node
		int size;					//stores the current size of the list
	public:
		linkedList();				//Constructor to initialize linked list
		~linkedList();				//Destructor to prevent memory leak if list goes out of scope
		bool isEmpty() const;		//Checks and returns if list is empty
		int size() const;			//Returns current size of the list
		void push(T);				//Adds a node at the top
		int insertAt(T, int);		//Inserts a new node at the i th position from the top
		T pop ();					//Pops the last element and deletes the node
		T delete_at(int);			//Deletes value at certain place
		T returnValue();			//Returns value stored at current node 
};

linkedList::linkedList(){			//Initializes first node and size to 0
	head = 0;
	size = 0;
}

bool linkedList::isEmpty () const{
	head == 0;
}

int linkedList::size () const{
	return size;
}

int linkedList::push (T val){
	Node add (val, head);			//Creates a new node and links it to head
	head = add;						//Head now points to the new node
}

void linkedList::insertAt (T x){
}

#endif