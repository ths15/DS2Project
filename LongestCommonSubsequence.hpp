#ifndef LONGEST_COMMON_SUBSEQUENCE
#define LONGEST_COMMON_SUBSEQUENCE

#include "FileHandler.hpp"
#include <bits/stdc++.h> 
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

class LongestCommonSubsequence
{
	
	private:
		std::string firstSequenceString;
		std::string secondSequenceString;
		std::vector <char> firstSequence;
		std::vector <char> secondSequence;
		std::vector<std::vector<int>> table;
		std::vector <char> finalLCS;
	public:
		LongestCommonSubsequence();	
		void LCSAlgorithm(int m, int n);
		void setFirstSequence(std::string firstSequenceString);
		void setSecondSequence(std::string secondSequenceString);
	
};

#endif
