#include "PriorityQueue.h"
#include <iostream>


PriorityQueue::PriorityQueue()
{
	heap.emplace_back();
	size = 0;
	currentTime = 0;
	totalOperations = 0;
}

PriorityQueue::PriorityQueue(std::vector<int> values)
{
	heap.emplace_back();
	size = 0;
	currentTime = 0;
	totalOperations = 0;

	BuildHeap(values);
}

PriorityQueue::~PriorityQueue()
= default;

void PriorityQueue::BuildHeap(std::vector<int> values)
{
	for (int value : values)
	{
		Insert(value);		
	}
}

void PriorityQueue::Insert(int value)
{
	// Add item to back of array
	heap.push_back(value);
	size++;

	// Reset operation count
	currentTime = 1;

	// Percolate up
	PercolateUp(heap.size() - 1);

	// Print that the operation happened
	if (print)
	{
		std::cout << "Inserted: " << value << " in: " << currentTime << " operations" << std::endl;
	}

	totalOperations += currentTime;
}

int PriorityQueue::SelectElementK(int k)
{
	for(int i = 0; i < k; i++)
	{
		if (i == k - 1)
		{
			return Extract();
		}
		Extract();
	}
	return 0;
}

int PriorityQueue::Extract()
{
	if(size == 0)
	{
		return -1;
	}

	// Take the root
	const int min = heap[1];
	// Replace the root with the last element
	heap[1] = heap[heap.size() - 1];
	// Remove the spot the last element took up
	heap.erase(heap.begin() + heap.size() - 1);

	// Reset operation counter
	currentTime = 0;

	// Rebuild the heap
	PercolateDown(1);

	// Change size of heap
	size--;

	// Print that the operation happened
	if (print)
	{
		std::cout << "Extracted: " << min << " and rebuilt in: " << currentTime << " operations" << std::endl;
	}

	totalOperations += currentTime;

	// Return min value
	return min;
}

int PriorityQueue::GetSize()
{
	return size;
}

int PriorityQueue::PeekMin()
{
	return size == 0 ? -1 : heap[1];
}

int PriorityQueue::PeekLast()
{
	return size == 0 ? -1 : heap[size];
}

int PriorityQueue::GetTotalOperations()
{
	return totalOperations;
}

void PriorityQueue::TogglePrint(bool val)
{
	print = val;
}

void PriorityQueue::ClearOpCount()
{
	totalOperations = 0;
}

void PriorityQueue::PercolateUp(int index)
{
	// Gets the index of this node's parent
	const int parentIndex = index / 2;

	// Return if the parent node has a lower or equal value to the child
	// Applies rule for minheap (Child must be <=  parent)
	if(heap[parentIndex] <= heap[index])
	{
		return;
	}

	// Swap the values of the parent and the child
	const int temp = heap[parentIndex];
	heap[parentIndex] = heap[index];
	heap[index] = temp;

	// Increment operation counter
	currentTime++;

	// Call again until structure is correct
	PercolateUp(parentIndex);	
}

void PriorityQueue::PercolateDown(int index)
{	
	// Get index of left child
	int childIndex = index * 2;

	// Return if left index is out of bounds
	if (childIndex >= size)
	{
		return;
	}

	// If right child is in bounds, set childIndex to node with lowest value
	if (childIndex + 1 < size )
	{
		childIndex = heap[childIndex] <= heap[childIndex + 1] ? childIndex : childIndex + 1;
	}

	// Return if child is already larger or same as parent value
	if(heap[childIndex] >= heap[index])
	{
		return;
	}

	// Swap values of child and parent
	const int temp = heap[childIndex];
	heap[childIndex] = heap[index];
	heap[index] = temp;

	// Increment operation counter
	currentTime++;

	// Call again until structure is correct
	PercolateDown(childIndex);	
}