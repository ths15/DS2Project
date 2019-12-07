#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <iostream>
#include <fstream>
#include <string>

class FileHandler
{
	
	private:
		std::string firstSequence;
		std::string secondSequence;
	public:
		FileHandler();
		std::string getFirstSequence();
		std::string getSecondSequence();
		void setFirstSequence(std::string newSequence);
		void setSecondSequence(std::string newSequence);
	
};

#endif
