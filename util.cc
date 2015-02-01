#include "util.h"

#include <iostream>

using std::cerr;
using std::endl;

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