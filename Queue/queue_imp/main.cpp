#include <iostream>
#include "queue.h"

int main() {
	queue queueobj(5);
	queueobj.Enqueue(5);
	queueobj.Enqueue(8);
	queueobj.Enqueue(7);
	queueobj.Enqueue(9);
	std::cout << "Front:"<< queueobj.Front()<<std::endl;
	std::cout << "Back:" << queueobj.Back();
}
