#include "linkelement.h"
#include <iostream>

using namespace std;

linkelement::linkelement() {
	this->ox = 0;
	this->oy = 0;
	this->nx = 0;
	this->ny = 0;
	this->player = 0;
	this->next = nullptr;
}

linkelement::~linkelement() {
	//cout << "destructor called" << endl;
	delete next;
}

linkelement* linkelement::get_next_element() {
	return this->next;
}

void linkelement::set_next_element(linkelement *el) {
	this -> next = el;
}

void linkelement::set_values(int orx, int ory, int nex, int ney, int player) {
	this->ox = orx;
	this->oy = ory;
	this->nx = nex;
	this->ny = ney;
	this->player = player;
}

void linkelement::printlist(linkelement *first_element) {
	linkelement* t = first_element;

	while (t != nullptr) {
		if (t->player != 0) {
			cout << "Player " << t->player << ": " << t->ox << t->oy << " " << t->nx << t->ny << std::endl;
			
		}
		t = t->get_next_element();
	}

}