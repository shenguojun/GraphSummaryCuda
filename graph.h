#ifndef GRAPH_H
#define GRAPH_H

class Graph{
public:
	int nVerNum;
	int nEdgeNum;
	int* anVertexId;
	int* anVrtexSize;
	int* anSelfConn;
	int* anAdjSize;
	int* anRowOffset;
	int* anNeighborId;
	int* anNeighborSize;
	int* anBetweenConn;
};
#endif