// Jake Stocker
//
// Test file for postfix
//
//


#include "stack.hpp"
#include "string.hpp"
#include <fstream>

void infixtoPostfix(std::ifstream&, Stack <String>&);

int main(){

	std::ifstream in;

	in.open("make.txt");
	
	Stack <String> converted;

	infixtoPostfix(in, converted);


	in.close();



}


void infixtoPostfix(std::ifstream& in, Stack <String>& converted){
	String token;
	String right, oper, left;
	String LRO;

	do
	{
	in >> token;
			while (!converted.isEmpty()){
				std::cout << converted.pop();
				std::cout << std::endl;

			}


		while (token != ";"){
			if (token != ")") {
				right = converted.pop();
				oper = converted.pop();
				left = converted.pop();
				converted.push(left+right+oper);
			}
			else{
				if (token!= "("){
					converted.push(token);
	
				}
			}

		in >> token;
		}
	}while (!in.eof());
}
