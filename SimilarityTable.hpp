#ifndef SIMILARITY_TABLE
#define SIMILARITY_TABLE

#include "MultiFileHandler.hpp"
#include <vector>
#include <cstring>

class SimilarityTable
{
	
	private:
		std::vector<std::string> tempSequences;
		std::vector<std::vector<char>> sequences;
		int numStrings;
		std::vector<std::vector<std::string>> simTable;
		std::vector<std::vector<int>> subsequenceTable;
	public:
		SimilarityTable();
		void generateSimTable();
		std::string createSubsequenceTable(int m, int n, int k, int l);
		void changeSimTable(int i, int j, std::string simLevel);
		void createCharVect();
		void printTable();
};

#endif
