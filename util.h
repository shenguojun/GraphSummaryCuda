#ifndef UTIL_H
#define UTIL_H

#include "graph.h"

class Util{
public:
	static void initializeIntArray(int* anArray, int nSize, int nInitValue, int nStep);
	static int calculateBlockPerGrid(int nDataSize, int nThreadPerBlock, int& nPart);
};
#endif