#include "board.h"
#include "boardchesspiece.h"
#include <iostream>

using namespace std;

board::board() {
	// set W values
	for (int h = 0; h <= 1; h++) {
		for (int w = 0; w <= 7; w++) {
			cboard[w][h].x = 'W';
			
		}
	}
	// set B values

	for (int h = 6; h <= 7; h++) {
		for (int w = 0; w <= 7; w++) {
			cboard[w][h].x = 'B';
			
		}
	}

	//set individual values;
		//rook
	cboard[0][0].y = 'R';
	cboard[7][0].y = 'R';
	cboard[0][7].y = 'R';
	cboard[7][7].y = 'R';

		//knight
	cboard[1][0].y = 'N';
	cboard[6][0].y = 'N';
	cboard[1][7].y = 'N';
	cboard[6][7].y = 'N';

		//bishop
	cboard[2][0].y = 'B';
	cboard[5][0].y = 'B';
	cboard[2][7].y = 'B';
	cboard[5][7].y = 'B';

		//queen
	cboard[3][0].y = 'Q';
	cboard[3][7].y = 'Q';

		//king
	cboard[4][0].y = 'K';
	cboard[4][7].y = 'K';

		//pawns
	for (int w = 0; w <= 7; w++) {
		cboard[w][1].y = 'P';
	}
	for (int w = 0; w <= 7; w++) {
		cboard[w][6].y = 'P';
	}



}

board::~board() {

}

void board::printboard() {
	for (int h = 0; h <= 7; h++) {
		cout << "-------------------------" << endl << "|";
		for (int w = 0; w <= 7; w++) {
			cout << cboard[w][h].x;
			cout << cboard[w][h].y << "|";
		}

		cout << " " << h+1 << endl;
	}
	cout << "-------------------------" << endl << " 1  2  3  4  5  6  7  8  " << endl;

}

void board::movepiece(int ox, int oy, int nx, int ny) {
	//assign new square
	cboard[nx][ny].x = cboard[ox][oy].x;
	cboard[nx][ny].y = cboard[ox][oy].y;

	//set original square to clear
	cboard[ox][oy].x = ' ';
	cboard[ox][oy].y = ' ';

}

bool board::moveislegal(int ox, int oy, int nx, int ny, int player) {
	if (cboard[ox][oy].x == ' ') {
		cout << "There's nothing there, silly goose." << endl;
		return false;
	}
	else if (cboard[ox][oy].x == 'W' && player == 2) {
		cout << "Thats not yours!!!" << endl;
		return false;
	}
	else if (cboard[ox][oy].x == 'B' && player == 1) {
		cout << "Thats not yours!!!" << endl;
		return false;
	}
		
	else if (ox - nx == 0 && oy - ny == 0) {
		cout << "You have to move." << endl;
		return false;
	}
	else if (cboard[ox][oy].x == cboard[nx][ny].x) {
		cout << "No friendly fire." << endl;
		return false;
	}
	else if (cboard[nx][ny].y == 'K') {
		cout << "The king cannot fall!" << endl;
		return false;
	}
	//rook rules
	else if (cboard[ox][oy].y == 'R') {
		if (ox - nx == 0 || oy - ny == 0) {
			if (notobstructed(ox, oy, nx, ny))
				return true;
			else {
				cout << "This piece is obstructed and connot move to selected square" << endl;
				return false;
			}
		}
		else {
			cout << "This piece cannot move to that square." << endl;
			return false;
		}
	}
	//pawn rules
	else if (cboard[ox][oy].y == 'P') {
		
		if (cboard[ox][oy].x == 'W') {
			if (ny - oy == 1 && ox - nx == 0) {
				if (notobstructed(ox, oy, nx, ny))
					return true;
				else {
					cout << "This piece is obstructed and connot move to selected square" << endl;
					return false;
				}

			}
		else if (ny - oy == 1 && abs(ox - nx) == 1) {
				if (cboard[nx][ny].x == 'B') {
					return true;
				}
				else return false;
			}

		}
		if (cboard[ox][oy].x == 'B') {
			
			if (oy - ny == 1 && ox - nx == 0) {

				if (notobstructed(ox, oy, nx, ny))
					return true;
				else {
					cout << "This piece is obstructed and connot move to selected square" << endl;
					return false;
				}

			}
			else if (oy - ny == 1 && abs(ox - nx) == 1) {

				if (cboard[nx][ny].x == 'W') {
					return true;
				}
				else return false;
			}
			else return false;

		}
		
		else { cout << "This piece cannot move to that square." << endl; return false; }
	}
	// knight rules
	else if (cboard[ox][oy].y == 'N') {
		if (abs(ox - nx) == 1 && abs(oy - ny) == 2)
			return true;
		else if (abs(ox - nx) == 2 && abs(oy - ny) == 1)
			return true;
		else return false;
	}
	
	//bishop rules
	else if (cboard[ox][oy].y == 'B') {
		if (abs(ox - nx) == abs(oy - ny)) {
			if (notobstructed(ox, oy, nx, ny))
				return true;

			else {
				cout << "This piece is obstructed and connot move to selected square" << endl;
				return false;
			}
		}
		else { cout << "This piece cannot move to that square." << endl; return false; }
	}
	//king rules
	if (cboard[ox][oy].y == 'K') {
		if (abs(ox - nx) <= 1 && abs(oy - ny) <= 1) {
			return true;
		}
		else return false;
	}
	//queen rules
	if (cboard[ox][oy].y == 'Q') {
		
		if (ox - nx == 0 || oy - ny == 0) {
			cboard[ox][oy].y = 'R';
			if (notobstructed(ox, oy, nx, ny)) {
				cboard[ox][oy].y = 'Q';
				return true;
			}
			else {
				cout << "This piece is obstructed and connot move to selected square" << endl;
				cboard[ox][oy].y = 'Q';
				return false;
			}
		}


		else if (abs(ox - nx) == abs(oy - ny)) {
			cboard[ox][oy].y = 'B';
			if (notobstructed(ox, oy, nx, ny)){ 
				cboard[ox][oy].y = 'Q';
				return true;
			}

			else {
				cout << "This piece is obstructed and connot move to selected square" << endl;
				cboard[ox][oy].y = 'Q';
				return false;
			}
		}
	
	else { cout << "This piece cannot move to that square." << endl; return false; }
	
	}
	
	
	
	//all checks complete.
	else return true;

	
}

bool board::notobstructed(int ox, int oy, int nx, int ny) {
	
	//rook rules
	if (cboard[ox][oy].y == 'R') {
		//cout << cboard[ox][oy].y;
		if (ox - nx == 0) {
			if (oy < ny) {
				for (int h = oy+1; h < ny; h++) {
					if (cboard[ox][h].y != ' ')
						return false;
				}
				return true;
			}
			else {
				for (int h = oy-1; h > ny; h--) {
					if (cboard[ox][h].y != ' ')
						return false;
				}
				return true;
			}

		}
		else if (oy - ny == 0) {
			if (ox < nx) {
				for (int w = ox+1; w < nx; w++) {
					if (cboard[w][oy].y != ' ')
						return false;
				}
				return true;
			}
			else {
				for (int w = ox-1; w > nx; w--) {
					if (cboard[w][oy].y != ' ')
						return false;
				}
				return true;
			}
		}
	}
	//pawn rules
	if (cboard[ox][oy].y == 'P') {
		if (cboard[nx][ny].y == ' ')
			return true;
		else return false;
	}

	//bishop rules
	if (cboard[ox][oy].y == 'B') {
		//cout << cboard[ox][oy].y;
		if (nx - ox > 0 && ny - oy > 0) {
			for (int h = 1; h < ny - oy; h++) {
				if (cboard[ox + h][oy + h].y != ' ')
					return false;
			}
		}

		else if (nx - ox > 0 && ny - oy < 0) {
			for (int h = 1; h < nx - ox; h++) {
				if (cboard[ox + h][oy - h].y != ' ')
					return false;
			}
		}

		else if (nx - ox < 0 && ny - oy > 0) {
			for (int h = 1; h < ny - oy; h++) {
				if (cboard[ox - h][oy + h].y != ' ')
					return false;
			}
		}

		else if (nx - ox < 0 && ny - oy < 0) {
			for (int h = 1; h < abs(ny - oy); h++) {
				if (cboard[ox - h][oy - h].y != ' ')
					return false;
			}
		}

		else return true;

	}


	

	//all checks complete.
	else {
		//cout << cboard[ox][oy].y;
		return true;
	}
};



char board::kingnottaken(int nx, int ny) {
	if (cboard[nx][ny].y == 'K')
		return 'n';
	else return 'y';
}
