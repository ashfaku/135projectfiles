#pragma once
#include <iostream>
#include "Node.h"

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class Queue
{
	private:
//		Node *head, *tail;
		int arr[7];
		int head, tail;
		bool full;
	//     node1-->node2-->node3-->null
	// head--^                ^-----------tail

	public:
		Queue();
		void enqueue(int d);
		int dequeue();
		int front();
		bool is_empty();
		bool is_full();
		std::string print();

};



