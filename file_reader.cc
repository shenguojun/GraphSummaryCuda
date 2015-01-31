#include "file_reader.h"
#include "graph.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;

void FileReader::ReadGraph(Graph* pGraph){
	m_inf  = ifstream("../../dataset/rmat-100");
	if (!m_inf){
		cerr << "Dataset could not be opened for reading!" << endl;
		exit(1);
	}
	vector<set<int>> vecAdjaList;

	while (m_inf)
	{
		string strInput;
		m_inf >> pGraph->m_nVerNum >> pGraph->m_nEdgeNum;
		vecAdjaList.resize(pGraph->m_nVerNum, set<int>());
		int nVec, nNei, nWeight;
		m_inf >> nVec >> nNei >> nWeight;
		vecAdjaList[nVec].insert(nNei);
		vecAdjaList[nNei].insert(nVec);
	}
}