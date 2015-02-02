//  Tests stack template for String
//
//  Jake Stocker
//  Kent State University
//


#include "stack.hpp"

int main(){

	{

	// create stack
	List<int> List_single;
	
	// push 1 onto stack
	List_single.enqueue(1);

	// verify results by popping 1 off stack
	std::cout << "TESTING LIST FUNCTIONALITY FOR INT" <<std::endl;
	std::cout << "Running Single item enqueue(1) Test" << std::endl;
	std::cout<< "dequeue 1 OFF LIST" <<std::endl;
	std::cout <<"EXPECTED RESULT = 1" <<std::endl;
	std::cout<< "RESULT = ";
	std::cout<<List_single.dequeue();
	std::cout<<std::endl;


	}

	{
	// create stack
	List<int> List_multiple;
	
	// push 123 onto stack
	List_multiple.enqueue(1);
	List_multiple.enqueue(2);
	List_multiple.enqueue(3);

	// verify by popping 123 off stack

	std::cout<< "Running multiple item push() Test" <<std::endl;
	std::cout<< "EXPECTED RESULT = 123"<<std::endl;
	std::cout<< "RESULT = ";
	std::cout<<List_multiple.dequeue();
	std::cout<<List_multiple.dequeue();
	std::cout<<List_multiple.dequeue();
	std::cout<<std::endl;
	}

}
