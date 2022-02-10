#pragma once

class Undo_Redo
{
	int* Arr;
	int Elements;
	int Capacity;

public:
	Undo_Redo(void);

	void PushMoves(int Value);
	void PopMoves();
	bool CheckEmpty();
	void Expand();
	int top();

	~Undo_Redo(void);

};
