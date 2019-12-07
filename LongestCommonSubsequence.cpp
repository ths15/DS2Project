#include "LongestCommonSubsequence.hpp"

LongestCommonSubsequence::LongestCommonSubsequence()
{
	std::cout << "Part 1\n";
	FileHandler* newFileHandler = new FileHandler();
	
	firstSequenceString = newFileHandler->getFirstSequence();
	secondSequenceString = newFileHandler->getSecondSequence();
	
	int m = firstSequenceString.length();
	int n = secondSequenceString.length();
	
	setFirstSequence(firstSequenceString);
	setSecondSequence(secondSequenceString);
	
	LCSAlgorithm(m + 1, n + 1);
	
}

void LongestCommonSubsequence::LCSAlgorithm(int m, int n)
{
	table.resize(m);
	
	for(int i = 0; i < m; i++)
	{
		table[i].resize(n);
	}
	
	for(int i = 0; i < m; i++)
		table[i][0] = 0;
	for(int j = 1; j < n; j++)
		table[0][j] = 0;
	
	//Generates table
	for(int j = 1; j < n; j++)
	{
		
		for(int i = 1; i < m; i++)
		{
			if(firstSequence[i - 1] == secondSequence[j - 1])
			{
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else
			{
				if(table[i - 1][j] >= table[i][j - 1])
				{
					table[i][j] = table[i - 1][j];
				}
				else
				{
					table[i][j] = table[i][j - 1];
				}
			}
		}
		
	}

	//prints table
//	for(int j = 0; j < n; j++)
//	{
//		for(int i = 0; i < m; i++)
//		{
//			std::cout << table[i][j];
//		}
//		
//		std::cout << "\n";
//	}
	
	int j = n - 1;
	int i = m - 1;
	

	//creates lcs using table
	while(j != 0 || i != 0)
	{

			if(table[i][j] > table[i - 1][j] && table[i][j] > table[i][j - 1])
			{
				finalLCS.insert(finalLCS.begin(), firstSequence[i - 1]);
				i--;
				j--;
			}
			else if(table[i][j] == table[i - 1][j])
			{
				i--;
			}
			else
			{
				j--;
			}

	}
	
	//prints final lcs
	std::cout << "LCS: ";
	
	for(int i = 0; i < finalLCS.size(); i++)
		std::cout << finalLCS[i];
		
	std::cout << "\n";
}

void LongestCommonSubsequence::setFirstSequence(std::string firstSequenceString)
{
	
	int n = firstSequenceString.length();

	std::copy(firstSequenceString.begin(), firstSequenceString.end(), std::back_inserter(firstSequence));
	
	std::cout << "First sequence: ";
	
	for(int i = 0; i < n; i++)
		std::cout << firstSequence[i];
		
	std::cout << "\n";
	
}

void LongestCommonSubsequence::setSecondSequence(std::string secondSequenceString)
{
	
	int n = secondSequenceString.length();
	
	std::copy(secondSequenceString.begin(), secondSequenceString.end(), std::back_inserter(secondSequence));
	
	std::cout << "Second sequence: ";
	
	for(int i = 0; i < n; i++)
		std::cout << secondSequence[i];
		
	std::cout << "\n";
	
}
