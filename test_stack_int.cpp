//  Tests stack template for String
//
//  Jake Stocker
//  Kent State University
//


#include "stack.hpp"

int main(){

	{

	// create stack
	Stack<int> stack_single;
	
	// push 1 onto stack
	stack_single.push(1);

	// verify results by popping 1 off stack
	std::cout << "TESTING STACK FUNCTIONALITY FOR INT" <<std::endl;
	std::cout << "Running Single item push(1) Test" << std::endl;
	std::cout<< "POPPING 1 OFF STACK" <<std::endl;
	std::cout <<"EXPECTED RESULT = 1" <<std::endl;
	std::cout<< "RESULT = ";
	std::cout<<stack_single.pop();
	std::cout<<std::endl;


	}

	{
	// create stack
	Stack<int> stack_multiple;
	
	// push 123 onto stack
	stack_multiple.push(1);
	stack_multiple.push(2);
	stack_multiple.push(3);

	// verify by popping 123 off stack

	std::cout<< "Running multiple item push() Test" <<std::endl;
	std::cout<< "EXPECTED RESULT = 321"<<std::endl;
	std::cout<< "RESULT = ";
	std::cout<<stack_multiple.pop();
	std::cout<<stack_multiple.pop();
	std::cout<<stack_multiple.pop();
	
	}

}
