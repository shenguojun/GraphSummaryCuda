#include <iostream>
#include "file_reader.h"
#include "graph.h"

int main(int argc, char** argv){
	FileReader cFileReader;
	Graph* pGraph = new Graph();
	cFileReader.ReadGraph(pGraph);

	return 0;
}