#include <iostream>
#include "PriorityQueue.h"
#include <ctime>

#define N_ELEMENTS 1000
#define K 1000

void main()
{
	srand(time(nullptr));

	int totalBuildOps = 0;
	int totalFindOps = 0;

	for (int i = 0; i < 1000; i++)
	{
		PriorityQueue b;

		for (int j = 0; j < N_ELEMENTS; j++)
		{
			b.Insert(rand() % 100 + 1);
		}

		std::cout << "Built queue with " << N_ELEMENTS << " elements in: " << b.GetTotalOperations() << " percolations" << std::endl;
		totalBuildOps += b.GetTotalOperations();
		b.ClearOpCount();

		std::cout << "Element " << K << " is " << b.SelectElementK(K) << std::endl;
		std::cout << "Total operations: " << b.GetTotalOperations() << std::endl;
		totalFindOps += b.GetTotalOperations();
	}

	std::cout << "Average percolations to build queue: " << totalBuildOps / 1000 << std::endl;
	std::cout << "Average percolations to find element K: " << totalFindOps / 1000 << std::endl;
}
