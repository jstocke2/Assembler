// Jake Stocker
// Cs23001
// postfix.cpp
//
// This file reads in a file and converts the file from infix to postfix notation

#include "string.hpp"
#include <iostream>
#include "stack.hpp"
#include <fstream>

void infixtoPostfix(std::ifstream&, Stack <String>&);
void infixtoPostfix(std::ifstream&, Stack <String>&, std::ofstream&);


int main(int argc, char const *agrv[]){

	std::ifstream in;
	std::ofstream out;
	in.open(agrv[1]);
	out.open(agrv[2]);
	
	if (!in){

		std::cerr << "could not read file";

	}

	if (argc < 1) {

		std::cerr << "not a valid quantity of arguments in CLI";

	}
	
	if (out){
		Stack <String> converted;
		infixtoPostfix(in, converted, out);

	}
	else {

	Stack <String> converted;

	infixtoPostfix(in, converted);
	}
	

	
	in.close();
	out.close();
}

void infixtoPostfix(std::ifstream& in, Stack <String>& converted, std::ofstream& out){

	String token, right, oper, left, line, emptyLine;
	while (!in.eof()){
	
		while (!converted.isEmpty()){
			out <<"INFIX: ";
			out <<line<<std::endl;
			out <<"POSTFIX: ";
			out<<converted.pop();
			out<<std::endl;
			line = emptyLine;
		}
		in >>token;
		while (token != ";"){
			if (token == ")"){
				right =converted.pop();
				oper = converted.pop();
				left = converted.pop();
				converted.push(left+right+oper);
			}
			else if (token != "("){
				converted.push(token);
				line = line + token;
			}
		in >> token;
		}
	}
}

void infixtoPostfix(std::ifstream& in, Stack <String>& converted){
	String token, right, oper, left, line, emptyline;
	while (!in.eof()){
		
		while (!converted.isEmpty()){
			std::cout<<"INFIX: ";
			std::cout<<line<<std::endl;
			std::cout<<"POSTFIX: ";
			std::cout<<converted.pop();
			std::cout<<std::endl;
			line=emptyline;
		}
		in >>token;
		while	(token != ";"){         // while not semicolon 
			if (token == ")"){        // while not closing brace
				right = converted.pop();     // pop off first 3 chars
				oper = converted.pop();
				left = converted.pop();
				converted.push(left+right+oper);      // rearrange chars into reverse string
			}
			else if (token != "("){ 
				converted.push(token);
				line= line + token;
			}
		in >> token;	
	
		}
	}

}




