#ifndef INIT_CUH
#define INIT_CUH

#include "graph.h"
#include "gputimer.h"

void cudaMemoryHostToDeviceMalloc(Graph* pDevicGraph, Graph* pHostGraph);
#endif