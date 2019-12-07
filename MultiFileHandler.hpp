#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class MultiFileHandler
{
	
	private:
		int numStrings;
		std::vector<std::string> sequences;
	public:
		MultiFileHandler();
		std::vector<std::string> getSequences();
		int getNumStrings();
};

#endif
