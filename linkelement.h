#pragma once
class linkelement
{
public:
	int ox, oy, nx, ny, player;
	linkelement* next;
	linkelement();
	~linkelement();
	linkelement* get_next_element();
	void set_next_element(linkelement *el);
	void set_values(int orx, int ory, int nex, int ney, int player);
	void printlist(linkelement *first_element);
};

