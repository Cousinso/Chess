#pragma once
#include "boardchesspiece.h"

class board
{
public:
	board();
	~board();
	void printboard();
	boardchesspiece cboard[8][8];
	void movepiece(int ox, int oy, int nx, int ny);
	bool moveislegal(int ox, int oy, int nx, int ny, int player);
	char kingnottaken(int nx, int ny);
	bool notobstructed(int ox, int oy, int nx, int ny);
	

};

