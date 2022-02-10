#include "Undo_Redo.h"
#include <assert.h>
#include <iostream>
using namespace std;


Undo_Redo::Undo_Redo(void)
{
	Elements = 0;
	Capacity = 10;
	Arr = new int[Capacity];

}
Undo_Redo::~Undo_Redo(void)
{
	delete[]Arr;
}


bool Undo_Redo::CheckEmpty()
{
	return (Elements == 0);
}

void Undo_Redo::Expand()
{
	Capacity = Capacity * 2;
	int* Temp = new int[Capacity];
	for (int i = 0; i < Capacity; i++) {
		Temp[i] = Arr[i];
	}
	delete[]Arr;
	Arr = Temp;
}

void Undo_Redo::PushMoves(int Value)
{
	if (Elements == Capacity)
	{
		Expand();
	}
	Arr[Elements] = Value;
	Elements++;
}
void Undo_Redo::PopMoves()
{
	assert(Elements != 0);
	Elements--;
}

int Undo_Redo::top()
{
	assert(!CheckEmpty());
	return Arr[Elements - 1];

}
