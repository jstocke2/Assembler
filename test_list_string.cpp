//  Tests stack template for int
//
//  Jake Stocker
//  Kent State University





#include "stack.hpp"

int main() 
{
	{
	
	// create stack and String
	List<String> List_single;
	String str1("abc");
	// push 1 string onto stack
	
	List_single.enqueue(str1);

	// verify results by popping 1 off stack
	std::cout << "TESTING PUSH() AND POP() FUNCTIONALITY FOR STRING"<<std::endl;
	std::cout<< "Running Single item push(str) Test" <<std::endl;
	std::cout<< "POPPING STR OFF THE STACK" <<std::endl;
	std::cout << "EXPECTED RESULT = abc" <<std::endl;
	std::cout <<"RESULT = ";
	std::cout<<List_single.dequeue();
	std::cout<<std::endl;

	}

	{
	// create stack and String
	List<String> List_multiple;
	String str1("ABC"),str2("DEF"),str3("GHIJK");
	// push "abc" "def" "ghijk" on to stack
	List_multiple.enqueue(str1);
	List_multiple.enqueue(str2);
	List_multiple.enqueue(str3);

	// verify results by popping expected values off stack
	std::cout << "Running multiple item push() Test" <<std::endl;
	std::cout << "EXPECTED RESULT = ABCDEFGHIJK" <<std::endl;
	std::cout << "RESULT = ";
	std::cout << List_multiple.dequeue();
	std::cout << List_multiple.dequeue();
	std::cout << List_multiple.dequeue();

	std::cout << std::endl;

	}

}



