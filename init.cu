#include "init.h"
#include "graph.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

void cudaMemoryHostToDeviceMalloc(Graph* pDevicGraph, Graph* pHostGraph){
	int nVerNum = pHostGraph->m_nVerNum;
	int nEdgeNum = pHostGraph->m_nEdgeNum;

	cudaError_t cudaStatus;

	// Choose which GPU to run on, change this on a multi-GPU system.
	cudaStatus = cudaSetDevice(0);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
	}
	size_t unVerSize = nVerNum * sizeof(int);
	size_t unVerSizePlus = (nVerNum + 1) * sizeof(int);
	size_t unEdgeSize = nEdgeNum * sizeof(int);
	// Allocate GPU buffers for graph vectors
	cudaMalloc((void**)&pDevicGraph->m_anOwnerId, unVerSize);
	cudaMalloc((void**)&pDevicGraph->m_anSelfConn, unVerSize);
	cudaMalloc((void**)&pDevicGraph->m_anVrtexSize, unVerSize);
	cudaMalloc((void**)&pDevicGraph->m_anRowOffset, unVerSizePlus);
	cudaMalloc((void**)&pDevicGraph->m_anNeighborId, unEdgeSize);
	cudaMalloc((void**)&pDevicGraph->m_anBetweenConn, unEdgeSize);


	// Copy input vectors from host memory to GPU buffers.
	cudaMemcpy(pDevicGraph->m_anOwnerId, pHostGraph->m_anOwnerId, nVerNum * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(pDevicGraph->m_anSelfConn, pHostGraph->m_anSelfConn, nVerNum * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(pDevicGraph->m_anVrtexSize, pHostGraph->m_anVrtexSize, nVerNum * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(pDevicGraph->m_anRowOffset, pHostGraph->m_anRowOffset, (nVerNum + 1) * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(pDevicGraph->m_anNeighborId, pHostGraph->m_anNeighborId, nEdgeNum * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(pDevicGraph->m_anBetweenConn, pHostGraph->m_anBetweenConn, nEdgeNum * sizeof(int), cudaMemcpyHostToDevice);

}