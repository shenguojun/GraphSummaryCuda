#include "util.h"

#include <iostream>

using std::cerr;
using std::endl;
using std::min;

#define MAX_NUM_BLOCK 65535

void Util::initializeIntArray(int* anArray, int nSize, int nInitValue, int nStep){
	if (nSize < 0){
		cerr << "The size of array must bigger than zero!" << endl;
		exit(1);
	}
	anArray[0] = nInitValue;
	for (int i=1; i<nSize; i++){
		anArray[i] = anArray[i-1] + nStep;
	}
}

int Util::calculateBlockPerGrid(int nDataSize, int nThreadPerBlock, int& nPart){
	int nTotalBlock = (nDataSize + nThreadPerBlock -1) / nThreadPerBlock;
	int nBlock =  nTotalBlock > MAX_NUM_BLOCK ? MAX_NUM_BLOCK : nTotalBlock;
	nPart = (nTotalBlock + nBlock -1) / nBlock;
	return nBlock;
}