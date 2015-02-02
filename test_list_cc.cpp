// Jake Stocker
//
//
//
//


#include "string.hpp"
#include "stack.hpp"


int main(){

List <int> test1;

test1.enqueue(1);
test1.enqueue(2);
test1.enqueue(3);
std:: cout<< "testing assignment operator "<<std::endl;

List <int> receiver = test1;

std::cout << "expected output 123" << std::endl;

std::cout << "OUTPUT = ";
std::cout << receiver.dequeue() << receiver.dequeue()<<receiver.dequeue();








}
