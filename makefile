CXX = g++
CXXFLAGS = -std=c++11 -Wall
     
OBJS = main.o FileHandler.o LongestCommonSubsequence.o SimilarityTable.o MultiFileHandler.o

prog1 : ${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}

main.o : FileHandler.hpp LongestCommonSubsequence.hpp SimilarityTable.hpp MultiFileHandler.hpp
FileHandler.o : FileHandler.hpp
LongestCommonSubsequence.o : LongestCommonSubsequence.hpp
SimilarityTable.o : SimilarityTable.hpp
MultiFileHandler.o : MultiFileHandler.hpp

clean :
	rm ${OBJS}


