#include <iostream>
#include "queue.h"
using std::cout;
using std::endl;
//     node1-->node2-->node3-->null
// head--^                ^-----------tail

Queue::Queue()
{
	head = 0;
	tail = 0;
	full = false;
}

std::string Queue::print()
{
	std::string result = "";
//	cout << head << " " << tail << endl;
	for (int i = head; i < tail; i++)
	{
		result += std::to_string(arr[i%7]) + " ";
	}
	return result;
}
// 1 2 3 4 5
// null null 3 4 5 
void Queue::enqueue(int data)
{
	if (tail - head == 7 || head - tail == 7)
	{
		full = true;
		throw std::out_of_range("Full queue");
	}
	arr[tail%7] = data;
	tail++;
//	cout << "Tail: " << tail << " " << full <<  endl;
}
int Queue::dequeue()
{
	if (head == tail)
	{
		throw std::out_of_range("Cannot dequeue from empty queue");
	}
	int r = front();
	head++;
	full = false;
	return r;
}
int Queue::front()
{
//	cout << head << " " << tail << endl;
	if (head == tail)
	{
		throw std::out_of_range("Cannot get front of empty queue");
	}
	return arr[head % 7];
}
bool Queue::is_empty()
{
	return head == tail;
}
bool Queue::is_full()
{
	return full;
}
