#include "SimilarityTable.hpp"

SimilarityTable::SimilarityTable()
{
	std::cout << "\nPart 2\n";
	MultiFileHandler* newFileHandler = new MultiFileHandler();
	tempSequences = newFileHandler->getSequences();
	numStrings = newFileHandler->getNumStrings();
	
	createCharVect();
	generateSimTable();
	
	for(int i = 0; i < numStrings; i++)
	{
		
		for(int j = 0; j < numStrings; j++)
		{
			
			if(i > j)
			{
				int m = sequences[i].size();
				int n = sequences[j].size();
				int k = i;
				int l = j;
				
				std::string simLevel = createSubsequenceTable(m, n, k, l);
				changeSimTable(i, j, simLevel);
				
			}
			
		}
		
	}
	
	printTable();
	
}

void SimilarityTable::generateSimTable()
{
	std::cout << "\n";
	simTable.resize(numStrings + 1);
	
	for(int i = 0; i < numStrings + 1; i++)
		simTable[i].resize(numStrings + 1);
		
	for(int i = 0; i < numStrings + 1; i++)
	{
		for(int j = 0; j < numStrings + 1; j++)
		{
			if(i == 0 && j == 0)
				simTable[i][j] = " ";
			else if(i == 0)
				simTable[i][j] = std::to_string(j);	
			else if(j == 0)
				simTable[i][j] = std::to_string(i);	
			else if(i >= j)
				simTable[i][j] = "-";
			else
				simTable[i][j] = "T";
		}
	}
	
//	for(int i = 0; i < numStrings + 1; i++)
//	{
//		for(int j = 0; j < numStrings + 1; j++)
//		{
//			std::cout << simTable[i][j];
//		}
//		
//		std::cout << "\n";
//	}
}

std::string SimilarityTable::createSubsequenceTable(int m, int n, int k, int l)
{
	
	double longestLength;
	double shortestLength;
	
	std::vector <char> firstSequence(sequences[k].begin(), sequences[k].end());
	std::vector <char> secondSequence(sequences[l].begin(), sequences[l].end());
	
	if(m > n)
	{
		longestLength = m;
		shortestLength = n;	
	}
	else
	{
		longestLength = n;
		shortestLength = m;	
	}
	
	m++;
	n++;
	
	subsequenceTable.resize(m);
	
	for(int i = 0; i < m; i++)
	{
		subsequenceTable[i].resize(n);
	}
	
	for(int i = 0; i < m; i++)
		subsequenceTable[i][0] = 0;
	for(int j = 1; j < n; j++)
		subsequenceTable[0][j] = 0;
	
	//Generates table
	for(int j = 1; j < n; j++)
	{
		
		for(int i = 1; i < m; i++)
		{
			if(firstSequence[i - 1] == secondSequence[j - 1])
			{
				subsequenceTable[i][j] = subsequenceTable[i - 1][j - 1] + 1;
			}
			else
			{
				if(subsequenceTable[i - 1][j] >= subsequenceTable[i][j - 1])
				{
					subsequenceTable[i][j] = subsequenceTable[i - 1][j];
				}
				else
				{
					subsequenceTable[i][j] = subsequenceTable[i][j - 1];
				}
			}
		}
		
	}
	
//	for(int j = 0; j < n; j++)
//	{
//		for(int i = 0; i < m; i++)
//		{
//			std::cout << table[i][j];
//		}
//		
//		std::cout << "\n";
//	}
	
	int longestSubLength = subsequenceTable[m - 1][n - 1];
	
	float wordLengths = shortestLength / longestLength;
	float LCSLength = longestSubLength / longestLength;
		
	if( wordLengths >= .1 && LCSLength >= .9)
		return "H";
	else if(wordLengths >= .2 && LCSLength >= .8)
		return "M";
	else if(wordLengths >= .4 && LCSLength >= .5)
		return "L";
	else
		return "D";	
	
}

void SimilarityTable::changeSimTable(int i, int j, std::string simLevel)
{
	
	simTable[j + 1][i + 1] = simLevel;
	
}

void SimilarityTable::createCharVect()
{
	sequences.resize(numStrings);
	
	for(int i = 0; i < numStrings; i++)
		sequences[i].resize(tempSequences[i].size());
	
	for(int i = 0; i < numStrings; i++)
	{
		std::copy(tempSequences[i].begin(), tempSequences[i].end(), std::back_inserter(sequences[i]));
		sequences[i].erase(sequences[i].begin(), sequences[i].begin() + sequences[i].size() / 2);
	}
	
//	for(int i = 0; i < numStrings; i++)
//	{
//		for(int j = 0; j < sequences[i].size(); j++)
//		{
//			std::cout << sequences[i][j];
//		}
//		std::cout << "\n";
//	}
}

void SimilarityTable::printTable()
{
	
	for(int i = 0; i < numStrings + 1; i++)
	{
		for(int j = 0; j < numStrings + 1; j++)
		{
			std::cout << simTable[i][j];
		}
		
		std::cout << "\n";
	}
	
}
