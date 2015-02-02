// Jake Stocker
// CS23001
// list.hpp


#ifndef CS23001_STACK_HPP
#define CS23001_STACK_HPP

#include "string.hpp"
#include <iostream>
#include <cassert>


template <typename T>

	class dnode {
	public:
	dnode(): next(0),prev(0),data(){};  //dnode constructor
	dnode (const T& item):next(0),prev(0),data(item){};  // constructor for node absorbs T
	dnode<T> *next, *prev;  // pointers to the next node and previous nodes
	
	T data;  // int, String, etc to be added to list
};
template <typename T>

	class List {
	public:
	List(): beginning (0), ending (0),nodeCount(0){};  // constructor for list
	List(const List<T>&);  // CC for list
	~List();  // List deconstructor
	//runList();        // will print all items in the list
	void enqueue(const T& item);  // pushes an element on list
	void swap (List<T>);     // swaps two Lists
	List <T>& operator= (const List<T>);  // assignment operator
	T dequeue(void);  // pops an element off the List and return the element
	bool isFull(void) const;  // tests to see if List is full
	bool isEmpty() const {return nodeCount==0;}  // tests to see if List is empty

	private:
	dnode <T> *beginning, *ending, *current;  // points to the node at the beginning and end
	int nodeCount;   // Keeps track of how many nodes are in the list
	};

//---------------------------------------------------------------------------------------------
//FUNCTION DEFINITIONS FOR TEMPLATE
//----------------------------------------------------------------------------------------------
//

template <typename T>
// creates a new node with items's data and inserts it at the end of the list

void List <T>::enqueue(const T& item) {
	assert(!isFull());
	++nodeCount;  // iterate count by one
	dnode <T> *tmp = new dnode<T>(item);  // create a new dnode with data in it
	if (beginning == 0) {     // if List is empty
		beginning =tmp;  // set the new node to the begining and ending of List
		ending = tmp;
	}
	else{ 
		tmp->prev=ending;
		ending-> next = tmp;  // If not empty put the new node at end of list 
		ending = tmp;        
		
		
	}	

}
/*
template <typename T>
//  Prints all items off the stack


void List<T>::runList(){

	while(!isEmpty){
		cout << this.dequeue();


}



}
*/
		
template <typename T>
// tests whether the list is full
bool List<T>::isFull() const{
	dnode<T> *temp = new(std::nothrow) dnode<T>();  

	if (temp == 0){
		return true;
	}
	delete temp;
	return false;
}



template <typename T>
//  removes an item from the top of the list
T List<T>::dequeue(){
	assert (!isEmpty());
	--nodeCount;
	T result = beginning -> data;
	dnode <T> *tmp= beginning;
	beginning = beginning -> next;
	if (beginning == 0) ending = 0;
	delete tmp;
	return result;
}

template <typename T>

List <T> :: ~List() {
	while (beginning != 0){
	dnode <T> *tmp= beginning;
	beginning = beginning -> next;
	delete tmp;
	}
	}

// Copy Constructor
template <typename T>
List <T>::List(const List <T>& actual){

	dnode<T> *tmp = actual.beginning;
	beginning=0;
	ending = 0;
	nodeCount = actual.nodeCount;
	while (tmp != 0){
		if (beginning == 0){
			beginning = new dnode<T> (tmp->data);
			ending=beginning;
		}
		
		else{
			ending->next = new dnode<T> (tmp->data);
			ending=ending->next;



		}

		tmp = tmp -> next;
}
}
template <typename T>

void List<T>::swap (List <T> rhs){

	dnode<T> *tmp = rhs.beginning;
	rhs.beginning = beginning;
	beginning = tmp;
	tmp = rhs.ending;
	rhs.ending = ending;
	ending = tmp;
}

template <typename T>

List<T>& List<T>::operator=(const List<T> rhs)
{
	swap(rhs);
	return *this;

}
#endif
