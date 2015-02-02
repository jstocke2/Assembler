// Jake Stocker
// Cs23001
// postfix.cpp
//
// This file reads in a file and converts the file from infix to postfix notation

#include "string.hpp"
#include <iostream>
#include "stack.hpp"
#include <fstream>

String infixtoPostfix(std::ifstream&, Stack <String>&);
String infixtoPostfix(std::ifstream&, Stack <String>&, std::ofstream&);
void postfixtoAssembly(std::ifstream&, Stack <String>&);
void postfixtoAssembly(std::ifstream&, Stack <String>&, std::ofstream&);


void infixtoPostfixFile(std::ifstream&,Stack<String>&, std::ofstream&);

String evaluate(String,String,String,int&);
String evaluate(String,String,String,int&,std::ofstream&);


int main(int argc, char const *agrv[]){

	std::ifstream in, in2;
	std::ofstream out;
	in.open(agrv[1]);
	//in2.open(agrv[1]);
	out.open(agrv[2]);
	if (!in){

		std::cerr << "could not read file";

	}

	if (argc < 1) {

		std::cerr << "not a valid quantity of arguments in CLI";

	}
	
	if (out){
		Stack <String> converted;
		postfixtoAssembly(in, converted, out);

	}
	else {

	Stack <String> converted;
	postfixtoAssembly(in,converted);


	in.close();
	out.close();
	}
}

// Stack is empty a file is passed for output and an input file is provided
// Writes to file Infix notation to ; and then Postfix notation to semicolon

String infixtoPostfix(std::ifstream& in, Stack <String>& converted, std::ofstream& out){
	String token, right, oper, left, line, postfix;
	in >> token;

	while (token != ";"&&!in.eof()){
		if (token == ")"){
			right =converted.pop()+ " ";
			oper = converted.pop();
			left = converted.pop()+" ";
			converted.push(left+right+oper);
		}
		else if (token != "("){
			converted.push(token);
			line = line + token+ " ";
		}
		in >> token;
	
	}
	while (!converted.isEmpty()){
		out<<"INFIX: ";
		out<<line<<std::endl;
		out<<"POSTFIX: ";
		postfix=converted.pop();
		out<<postfix;
		out<<std::endl;
	}

	return postfix;
}





String infixtoPostfix(std::ifstream& in, Stack <String>& converted){
	String token, right, oper, left, line, postfix;
	in >>token;
	
	while	(token != ";"&&!in.eof()){         // while not semicolon 
		if (token == ")"){        // while not closing brace
			right = converted.pop()+ " ";     // pop off first 3 chars
			oper = converted.pop();
			left = converted.pop()+" ";
			converted.push(left+right+oper);      // rearrange chars into reverse string
		}
		else if (token != "("){ 
			converted.push(token);
			line= line + token+ " ";
		}
		in >> token;	
	
		}
	
	while (!converted.isEmpty()){
		std::cout<<"INFIX: ";
		std::cout<<line<<std::endl;
		std::cout<<"POSTFIX: ";
		postfix=converted.pop();
		std::cout<<postfix;
		std::cout<<std::endl;
		
	}


	return postfix;

}
// Stack is empty input file and output file is provided
// Writes only postfix to a file up to semicolon per line
void infixtoPostfixFile(std::ifstream& in, Stack<String>&converted, std::ofstream& out){
	String token, right, oper, left;
	while (!in.eof()){
		
		while (!converted.isEmpty()){
			out << converted.pop();
			out << " ;";
			out << std::endl;
			
		}
		in >> token;
		while (token != ";"){
			if (token == ")"){
				right = converted.pop()+" ";
				oper = converted.pop();
				left = converted.pop()+" ";
				converted.push(left+right+oper);
			}
			else if(token != "("){
				converted.push(token);;
			}
		in >>token;
		}	
	}
}

// Stack is empty input file and output file are both provided
// outputs to console infix then postfix then assembler language up to the semicolon and repeats to end of file
void postfixtoAssembly(std::ifstream& in, Stack <String>& converted){
	Stack <String> assembly;  // STACK FOR ASSEMBLY OUTPUT
	String right,left,postfix;  // RIGHT AND LEFT OPERATORS ON THE STACK AND THE TRANSLATED POSTFIX EXPRESSION
	  //current memory registera
	  // current evaluated index of String
	 // index of beginning of current word
	 // index of end of current word
       while (!in.eof()){
		while (!assembly.isEmpty()){  //ensure assembly is empty stack
			assembly.pop();
		}
		int $tmp=0;
		int i =0;
		int begWord=0;
		int endWord=0;
		postfix=infixtoPostfix(in,converted);  // prints POSTFIX AND PREFIX AS TRANSLATED FROM FIRST LINE AND SAVES POSTFIX VALUE
		while (postfix[i] != '\0'){           // TAKES THE POSTFIX EXPRESION AND EVALUATES TO NULL
			begWord=postfix.findNonBlank(i);  
			endWord=postfix.findBlank(i) - 1;
			i=begWord;
			if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '/' && postfix[i] != '*'){  // IF NOT AN OPERATOR AT CURRENT BEGWORD
				assembly.push(postfix.substr(i,endWord));  // PUSH THE WORD UP TO BEFORE THE BLANK
				i=endWord+1;  // ITERATE THE CURRENT INDEX OF POSTFIX EXPRESSION BY ONE
				
			}
			else{
				right = assembly.pop();  
				left = assembly.pop();
				assembly.push(evaluate(left,postfix[i],right,$tmp));  // CALLS EVALUATE() FOR ASSEMBLY AND PUSHES THE RESULT ON THE STACK
				i = endWord+1;                  // ITERATES THE CURRENT INDEX OF POSTFIX EXPRESSION BY ONE
			}
 		}
	}
}

// Stack is empty input and output files are provided
// ouputs infix then postfix then assembly up to read file's semicolon ouput is to file
void postfixtoAssembly(std::ifstream& in, Stack <String>& converted, std::ofstream& out){
	Stack <String> assembly;
	String right,left,postfix;
	while (!in.eof()){
		while (!assembly.isEmpty()){
			assembly.pop();
		}
		int $tmp=0;
		int i = 0;
		int begWord=0;
		int endWord=0;
		postfix=infixtoPostfix(in,converted,out);
		while (postfix[i] != '\0'){
			begWord=postfix.findNonBlank(i);
			endWord=postfix.findBlank(i) - 1;
			i = begWord;
			if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '/' && postfix[i] != '*'){
				assembly.push(postfix.substr(i,endWord));
				i=endWord+1;
			}
			else{
				right = assembly.pop();
				left = assembly.pop();
				assembly.push(evaluate(left,postfix[i],right,$tmp,out));
				i = endWord+1;
			}
		}
	}
}

// stack is empty and two cString are provided along with current tmp count as an int
// converts infix expresion to assembly and ouputs to console then returns the reg key it is stored in
String evaluate(String left, String token, String right, int& numTMP){
		++numTMP;  // # of temporary memory locations stored
		
		std::cout << "LDR  " << left<<std::endl;


		if (token == "+") std::cout<< "ADD  ";
		if (token == "-") std::cout<< "SUB  ";
		if (token == "/") std::cout<< "DIV  ";
		if (token == "*") std::cout<< "MUL  ";

		std::cout<<right<<std::endl;
		std::cout <<"STR  "<<"TMP"<<numTMP;
		std::cout<<std::endl;
		String tmp = "TMP";
		char str[100];
		String $reg=itoa(numTMP,str,10);
		return tmp + $reg;

}
//stack is empty and two strings are provided along with the current tmp memory storages used as an int along with file to output to
// converts infix expresion to assembly and output to file then return the reg key expresiion is stored in
String evaluate(String left, String token, String right, int& numTMP, std::ofstream& out){

	++numTMP;

	out << "LDR  " << left<<std::endl;

	if (token == "+") out<<"ADD  ";
	if (token == "-") out<<"SUB  ";
	if (token == "/") out<<"DIV  ";
	if (token == "*") out << "MUL  ";

	out<<right<<std::endl;
	out<<"STR  "<<"TMP"<<numTMP;
	out<<std::endl;
	char* str1=0;
	char str[100];
	str1=itoa(numTMP,str,10);
	String $reg=str;
	String tmp="TMP";

	return tmp + $reg;

}






