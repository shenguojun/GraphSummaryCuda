#include "file_reader.h"
#include "graph.h"
#include "gputimer.h"
#include "init.h"
#include "util.h"

#include <iostream>
#include <stdio.h>

#define NUM_THREAD_PER_BLOCK 192

__global__ void compute(Graph* pd_Graph, int nPart){
	printf("Hello world! I'm a thread in block %d\n", blockIdx.x * blockDim.x + threadIdx.x);
}

int main(int argc, char** argv){
	FileReader cFileReader;
	Graph* ph_Graph = new Graph();
	// copy data from file to CPU
	cFileReader.ReadGraph(ph_Graph);
	// copy data from CPU TO GPU
	Graph * pd_Graph = new Graph();
	cudaMemoryHostToDeviceMalloc(pd_Graph, ph_Graph);
	GpuTimer timer;
	timer.Start();
	// run GPU thread
	int nPart = 0;
	int nBlockPerGrid = Util::calculateBlockPerGrid(ph_Graph->m_nEdgeNum, NUM_THREAD_PER_BLOCK, nPart);
	compute<<<nBlockPerGrid, NUM_THREAD_PER_BLOCK>>>(pd_Graph, nPart);
	timer.Stop();
	// copy data from GPU to CPU
	// TODO
	printf("Time elapsed = %g ms\n", timer.Elapsed());
	// memory free
	cudaFree(pd_Graph->m_anBetweenConn);
	cudaFree(pd_Graph->m_anNeighborId);
	cudaFree(pd_Graph->m_anOwnerId);
	cudaFree(pd_Graph->m_anRowOffset);
	cudaFree(pd_Graph->m_anSelfConn);
	cudaFree(pd_Graph->m_anVrtexSize);

	return 0;
}