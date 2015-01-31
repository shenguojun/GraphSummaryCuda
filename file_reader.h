#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include "graph.h"

using std::ifstream;

class FileReader{
public:
	void ReadGraph(Graph *graph);

private:
	ifstream m_inf;
};
#endif