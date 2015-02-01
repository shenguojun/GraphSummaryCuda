#include "file_reader.h"
#include "graph.h"
#include "util.h"

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
	m_inf  = ifstream("../../dataset/test");
	if (!m_inf){
		cerr << "Dataset could not be opened for reading!" << endl;
		exit(1);
	}
	vector<set<int>> vecAdjaList;
	string strInput;
	int nVerNum;
	// get how many vertexes and original edge number;
	m_inf >> nVerNum >> pGraph->m_nEdgeNum;
	pGraph->m_nVerNum = nVerNum;
	vecAdjaList.resize(pGraph->m_nVerNum + 1, set<int>());
	// translate directive graph to non-directive graph;
	while (m_inf){
		int nVec, nNei, nWeight;
		m_inf >> nVec >> nNei >> nWeight;
		vecAdjaList[nVec].insert(nNei);
		vecAdjaList[nNei].insert(nVec);
	}
	// calculate offset and total edge number;
	pGraph->m_anRowOffset = new int[nVerNum];
	pGraph->m_anRowOffset[0] = 0;
	int ntotalEdge = 0;
	for (int i=0; i<nVerNum + 1; i++){
		ntotalEdge += vecAdjaList[i].size();
		pGraph->m_anRowOffset[i+1] = pGraph->m_anRowOffset[i] + vecAdjaList[i].size();
	}
	// calculate neighbor id array;
	pGraph->m_nEdgeNum = ntotalEdge;
	pGraph->m_anNeighborId = new int[ntotalEdge];
	int j = 0;
	for(int i = 0; i < nVerNum; i++){
		set<int>::const_iterator it; 
		it = vecAdjaList[i].begin(); 
		while (it != vecAdjaList[i].end()) {
			pGraph->m_anNeighborId[j] = *it;
			it++;
			j++;
		}
	}
	// do some other initialzaions;
	pGraph->m_anOwnerId = new int[nVerNum];
	Util::initializeIntArray(pGraph->m_anOwnerId, nVerNum, 0, 1);
	pGraph->m_anBetweenConn = new int[ntotalEdge];
	Util::initializeIntArray(pGraph->m_anBetweenConn, ntotalEdge, 1, 0);
	pGraph->m_anSelfConn = new int[nVerNum];
	Util::initializeIntArray(pGraph->m_anSelfConn, nVerNum, 0, 0);
	pGraph->m_anVrtexSize = new int[nVerNum];
	Util::initializeIntArray(pGraph->m_anVrtexSize, nVerNum, 1, 0);

	/*
	cout<< pGraph->m_nVerNum << endl;
	cout<< pGraph->m_nEdgeNum << endl;
	for(int i = 0; i<nVerNum; i++){
		cout<< pGraph->m_anOwnerId[i]<< " ";
	}
	cout<< endl;
	for(int i = 0; i<ntotalEdge; i++){
		cout<< pGraph->m_anNeighborId[i]<< " ";
	}
	cout<< endl;
	for(int i = 0; i<nVerNum +1; i++){
		cout<< pGraph->m_anRowOffset[i]<< " ";
	}
	cout<< endl;
	for(int i = 0; i<nVerNum; i++){
		cout<< pGraph->m_anVrtexSize[i]<< " ";
	}
	cout<< endl;
	for(int i = 0; i<nVerNum; i++){
		cout<< pGraph->m_anSelfConn[i]<< " ";
	}
	cout<< endl;
	for(int i = 0; i<ntotalEdge; i++){
		cout<< pGraph->m_anBetweenConn[i]<< " ";
	}
	cout<< endl;
	*/

}