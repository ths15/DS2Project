#include "FileHandler.hpp"

FileHandler::FileHandler()
{
	
	std::string fileName = "twoStrings.txt";
	std::ifstream inFile;
	
	
	inFile.open(fileName);

	if(!inFile)
	{

		std::cerr << fileName << " could not be opened\n";
		exit(1);
	
	}
		
	std::string sequence;
	
	inFile >> sequence;
	setFirstSequence(sequence);
	
	inFile >> sequence;
	setSecondSequence(sequence);
	
	inFile.close();
}

std::string FileHandler::getFirstSequence()
{
	
	return firstSequence;
	
}

std::string FileHandler::getSecondSequence()
{
	
	return secondSequence;
	
}

void FileHandler::setFirstSequence(std::string newSequence)
{
	
	firstSequence = newSequence;
	
}

void FileHandler::setSecondSequence(std::string newSequence)
{
	
	secondSequence = newSequence;
	
}

