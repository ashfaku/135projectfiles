#include <iostream>
#include <unistd.h>
#include "stack.h"
#include "queue.h"
using std::cout;
using std::endl;
int main()
{
	Stack *l = new Stack();
	cout << "Empty stack? " << (l->is_empty() ? "Yes" : "No") << endl;
	l->push(3);
	cout << "Pushed this element as first one: " << l->top() << endl;
	cout<< "Empty stack? " << (l->is_empty() ? "Yes" : "No" )  << endl;
	cout << "Removed this element: " << l->pop() << endl;
	l->push(5);
	cout << "New top: " << l->top() << endl;
	l->push(10);
	cout << "New top: " << l->top() << endl;
	l->push(-2);
	cout << "New top: " << l->top() << endl;
	cout << "Empty stack? " << (l->is_empty() ? "Yes" : "No") << endl;
	cout << "Removed with pop(): " << l->pop() << endl;
	cout << "New top: " << l->top() << endl;
	cout << "Popped top element: " << l->pop() << endl;
	cout << "Popped top element: " << l->pop() << endl;
	cout << "Empty stack? " << (l->is_empty() ? "Yes" : "No") << endl;
	try
	{
		cout << "Trying to pop: " << l->pop() << endl;
	}
	catch (std::exception e)
	{
		cout << e.what() << endl;
	}
	delete l;

	Queue *q = new Queue();
	q->enqueue(1);
	q->enqueue(3);
	q->enqueue(7);
	cout << q->print() << endl;
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	cout << q->print() << endl;
	q->enqueue(9);
	q->enqueue(11);
	q->enqueue(12);
	q->enqueue(13);
	q->enqueue(14);
	q->enqueue(15);
	cout << q->print() << endl;
	cout << q->dequeue() << endl;
	cout << q->print() << endl;
	cout << q->dequeue() << endl;
	cout << q->print() << endl;
	return 0;
}
