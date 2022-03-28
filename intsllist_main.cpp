//Daniel Farone 
//CSCI 3110-001 
//Project #2 
//Due: 02/10/22 
//This driver file creates an instance of the IntSLList class then reads input from "ints.txt"
//Each line of the read file contains a value and an operation instruction. Depending on the letter read,
//the integer value is either added or deleted from the list. For every line of the input file the printAll() function is called.
#include "intsllist.h"
#include <fstream> 

int main()
{
	IntSLList list;
	int val;
	char letter;
	std::ifstream infile;
	infile.open("ints.txt");
	
	while(infile >> val >> letter)
	{
		std::cout << "(" << letter << ")" << val;
		if(letter == 'a')
			list.insertInOrder(val);
		else if(letter == 'd')
			val = list.deleteVal(val);
		else
			list.deleteAllVal(val);
		list.printAll();
	}
	infile.close();
	return 0;
}
