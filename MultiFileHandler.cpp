#include "MultiFileHandler.hpp"

MultiFileHandler::MultiFileHandler()
{
	
	std::string fileName = "multiStrings.txt";
	std::ifstream inFile;
	
	
	inFile.open(fileName);

	if(!inFile)
	{

		std::cerr << fileName << " could not be opened\n";
		exit(1);
	
	}
	
	inFile >> numStrings;
	
	sequences.resize(numStrings);
	
	for(int i = 0; i < numStrings; i++)
	{
		inFile >> sequences[i];
	}
	
	inFile.close();
}

std::vector<std::string> MultiFileHandler::getSequences()
{
	return sequences;
}

int MultiFileHandler::getNumStrings()
{
	return numStrings;
}
