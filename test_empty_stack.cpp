// Jake Stocker
//
// 10/30/2014
// Test file for Stack ADT





#include <iostream>
#include "stack.hpp"

int main(){
	{
	


	//Empty Stack Test
	Stack <int> empty_stack;

	std::cout << "Testing Stack when empty" <<std::endl;
	std::cout << "Expected Result is empty" <<std::endl;
	std::cout << "Result is: ";
	empty_stack.printAll();

	}





}
