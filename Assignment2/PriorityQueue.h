#pragma once
#include <vector>

class PriorityQueue
{
public:
	PriorityQueue();
	explicit PriorityQueue(std::vector<int> values);
	~PriorityQueue();

	// Inserts values in O(n log n) time
	void BuildHeap(std::vector<int> values);

	// Inserts a value in O(1) average time, O(log n) worst case time
	void Insert(int value);

	// Returns the kth smallest element.
	int SelectElementK(int k);

	// Extracts the minimum element
	int Extract();

	// Gets the number of elements in the heap
	int GetSize();

	// Returns the minimum value without removing it
	int PeekMin();

	// Returns the last element without affecting it
	int PeekLast();

	// Get number of operations performed on heap
	int GetTotalOperations();

	// Set print status
	void TogglePrint(bool val);

	void ClearOpCount();

private:
	// The number of elements in the heap
	int size;

	// Percolates an element up
	void PercolateUp(int index);

	// Percolates an element down
	void PercolateDown(int index);

	// Operation counter
	int currentTime;

	// Total operation counter
	int totalOperations;

	// Should values be printed?
	bool print = false;

	// Heap vector
	std::vector<int> heap;
};