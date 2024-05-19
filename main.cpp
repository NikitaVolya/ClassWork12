
#include <iostream>
#include "PriorityQueue.h"
#include "string"

struct Rectangle
{
	int width;
	int height;
	string toString()
	{
		string text = "(";
		text += std::to_string(width) + " X ";
		text += std::to_string(height) + ")";
		return text;
	}
};

bool greaterRectangle(Rectangle pA, Rectangle pB)
{
	return pA.width * pA.height > pB.width * pB.height;
}

int myRandomInt(int min, int max)
{
	return min + rand() % (max - min + 1);
}

int main()
{
	srand(time(NULL));

	PriorityQueue<Rectangle, greaterRectangle> queue;

	for (int i = 0; i < 10; i++)
		queue.push(Rectangle{ myRandomInt(1, 20), myRandomInt(1, 20) });
	queue.print();
	

	return 0;
}


