#ifndef GRAPH_H
#define GRAPH_H

class Graph{
public:
	int m_nVerNum;
	int m_nEdgeNum;
	int* m_anOwnerId;
	int* m_anNeighborId;
	int* m_anRowOffset;
	int* m_anVrtexSize;
	int* m_anSelfConn;
	int* m_anBetweenConn;
};
#endif