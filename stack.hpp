// Jake Stocker
// 10/30/2014
//
//  Stack header file for Stack linked list that uses custom built String library 




#ifndef CS23001_STACK_HPP_
#define CS23001_STACK_HPP_
#include <fstream>
#include <iostream>
#include <cassert>
#include "string.hpp"




template <typename T>

	class Node
	{	
	public:
		Node ():data(),next(0) {};
		Node (T item):data(item),next(0){};
	
		T data;
		Node<T> *next;

	};
template <typename T>
	class Stack
	{
	public:
		Stack(void):tos(0){};	// Constructor for Stack
		Stack(T *tos);
		~Stack();		// Stack destructor
		Stack(const Stack<T>&);// CC for Stack
		void swap(Stack<T>&);  // swaps stacks
		Stack <T>& operator = (Stack<T>);  // assignment operator
		bool isEmpty() const {return tos==0;} // returns true if stack is empty
		bool isFull(void) const;                 // returns true if stack is full
		T pop();			      // pops an element off the bottom of the stack
		void push(const T&);                  // pushes an element to the top of the stack
		void printAll() const;

	private:
		Node<T> *tos;
		    

	};


//-----------------------------------------------------------------------------
//
//  FUNCTION DEFINITIONS 
//
//  ---------------------------------------------------------------------------





//  Stack Copy Constructor def

template <typename T>
Stack<T>::Stack(const Stack<T>& actual)
{
	Node<T> *bottom=0;
	Node<T> *temp = actual.tos;
	tos = 0;

	while (temp != 0) {
		if (bottom == 0){
			tos = new Node <T> (temp -> data);
			bottom = tos;
		}
		else
			bottom ->next = new Node <T> (temp -> data);
			bottom = bottom -> next;
	
	}
	temp = temp -> next;

}

// Default destructor for stack

template <typename T>

Stack<T>::~Stack(){

	while (tos != 0){
		Node<T> *tmp = tos;
		tos = tos -> next;
		delete tmp;
	}
} 

// stack assignment operator

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> rhs)
{
	swap(rhs);
	return *this;

}


// returns true if stack is full

template <typename T>
bool Stack<T>::isFull() const
{
	Node <T> *temp = new(std::nothrow) Node<T>();

	if (temp == 0)
		return true;

	delete temp;
	return false;

}

//  prints to console all datavalues until stack isEmpty()
template <typename T>
void Stack <T>::printAll() const
{

	Stack <T> temp(*this);

	while (!(temp.isEmpty())) {
		std::cout << temp.pop() << " ";
	}

	std::cout <<std::endl;
}

// Pops the last element off the stack

template <typename T>
T Stack<T>::pop()
{
	assert(tos !=0);
	Node<T> *temp = tos;
	T result = tos->data;
	tos = tos -> next;
	delete temp;
	return result;
}

// Pushes item onto  the top of the stack

template <typename T>
void Stack <T>::push(const T& item)
{
	assert(!isFull());
	Node <T> *temp = new Node<T> (item);
	temp -> next = tos;
	tos = temp;
}

// swaps two stacks
//
template <typename T>
void Stack <T>::swap(Stack<T>& rhs){
	Node<T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}

 

/*
String infixtoPostfix(std::iostream in){

	if (!in)
	{
		cerr << "File could not be read" << endl;
	}
	String token;
	Stack <String> line;
	char right, oper, left;
	in >> token;
	while (token != ";") do{ 
		if (token == ")"){
			right = line.pop();
			oper = line.pop();
			left = line.pop();
			line.push(right+oper+left);
		}
		else{
			if (token != "(") line.push(token);
		}
		in >> token;
	}
*/
#endif
