#include "application.h"
#include <iostream>
#include "boardchesspiece.h"
#include "board.h"
#include "linkelement.h"

using namespace std;

application::application() {

}

application::~application() {

}

void application::run() {
	//initialization zone.
	int ox, oy, nx, ny;
	int player = 1;
	char gameon = 'y';
	char upforit = 'y';
	char print = 'y';
	
	while (upforit=='y') {
		//get going
		board nboard;
		nboard.printboard();
		char gameon = 'y';
		int player = 1;
		linkelement *first_element = new linkelement;
		linkelement *last_element = first_element;


		while (gameon == 'y') {
			
			//get coordinates from player.
			std::cout << "Player " << player << " enter coordinates of piece you want to move" << endl;
			std::cin >> ox >> oy;
			std::cout << "Now enter coordinates of where you want to move" << endl;
			std::cin >> nx >> ny;

			//linklist shtuff
			
			linkelement* nl = new linkelement;
			nl->set_values(ox, oy, nx, ny, player);
			last_element->set_next_element(nl);
			last_element = nl;

			//check if coordinates are within the plane
			if (ox > 8 || ox < 0) std::cout << "Thats not a square..." << endl;
			else if (oy > 8 || oy < 0) std::cout << "Thats not a square..." << endl;
			else if (nx > 8 || nx < 0) std::cout << "Thats not a square..." << endl;
			else if (ny > 8 || ny < 0) std::cout << "Thats not a square..." << endl;
			else {


				//convert coordinates to usable values
				ox = ox - 1;
				oy = oy - 1;
				nx = nx - 1;
				ny = ny - 1;

				//check move then move
				if (nboard.moveislegal(ox, oy, nx, ny, player)) {
					gameon = nboard.kingnottaken(nx, ny);
					nboard.movepiece(ox, oy, nx, ny);
					nboard.printboard();
					
					if (player == 1)
						player = 2;
					else player = 1;
				}
				else std::cout << "Try Again" << endl;
				if (gameon != 'y') {
					std::cout << "Player " << player << " loses and owes their oppenent a drink" << endl;
				}
				else {
					std::cout << "Does player " << player <<" want to continue?(y/n)" << endl;
					std::cin >> gameon;
					if(gameon != 'y')std::cout << "Player " << player << " loses and owes their oppenent a drink" << endl;
					std::cout << "Do you wish to print the list of attempted moves? (y/n)";
					std::cin >> print;
					if (print == 'y') last_element->printlist(first_element);
				}
			}
		}
		delete first_element;
		std::cout << "Do you want to play a game? (y/n)" << endl;
		std::cin >> upforit;
	}
	std::cout << "I didnt want to play with you anyway..." << endl;
}


void application::test() {
	board nboard;
	int ox, oy, nx, ny,player;
	bool gameon;
	
	gameon = true;
	// pawn check
	player = 1;
	ox = 1;
	oy = 2;
	nx = 1;
	ny = 3;

	ox = ox - 1;
	oy = oy - 1;
	nx = nx - 1;
	ny = ny - 1;

	//check move then move
	if (nboard.moveislegal(ox, oy, nx, ny, player)) {
		gameon = nboard.kingnottaken(nx, ny);
		nboard.movepiece(ox, oy, nx, ny);
		std::cout << "pawn passes test" << endl;;
	}
	else std::cout << "pawn fails test" << endl;;



	// rook check
	player = 1;
	ox = 1;
	oy = 1;
	nx = 1;
	ny = 2;

	ox = ox - 1;
	oy = oy - 1;
	nx = nx - 1;
	ny = ny - 1;

	//check move then move
	if (nboard.moveislegal(ox, oy, nx, ny, player)) {
		gameon = nboard.kingnottaken(nx, ny);
		nboard.movepiece(ox, oy, nx, ny);
		std::cout << "rook passes test" << endl;;
	}
	else std::cout << "rook fails test" << endl;;


	// knight check
	player = 1;
	ox = 2;
	oy = 1;
	nx = 3;
	ny = 3;

	ox = ox - 1;
	oy = oy - 1;
	nx = nx - 1;
	ny = ny - 1;

	//check move then move
	if (nboard.moveislegal(ox, oy, nx, ny, player)) {
		gameon = nboard.kingnottaken(nx, ny);
		nboard.movepiece(ox, oy, nx, ny);
		std::cout << "knight passes test" << endl;;
	}
	else std::cout << "knight fails test" << endl;;


	// bishop check
	player = 1;
	ox = 6;
	oy = 1;
	nx = 8;
	ny = 3;

	ox = ox - 1;
	oy = oy - 1;
	nx = nx - 1;
	ny = ny - 1;
	nboard.cboard[6][1].x = ' ';
	nboard.cboard[6][1].y = ' ';
	//check move then move
	if (nboard.moveislegal(ox, oy, nx, ny, player)) {
		gameon = nboard.kingnottaken(nx, ny);
		nboard.movepiece(ox, oy, nx, ny);
		std::cout << "bishop passes test" << endl;;
	}
	else std::cout << "bishop fails test" << endl;;


	// king check
	player = 1;
	ox = 5;
	oy = 1;
	nx = 5;
	ny = 2;

	ox = ox - 1;
	oy = oy - 1;
	nx = nx - 1;
	ny = ny - 1;
	nboard.cboard[4][1].x = ' ';
	nboard.cboard[4][1].y = ' ';
	//check move then move
	if (nboard.moveislegal(ox, oy, nx, ny, player)) {
		gameon = nboard.kingnottaken(nx, ny);
		nboard.movepiece(ox, oy, nx, ny);
		std::cout << "king passes test" << endl;;
	}
	else std::cout << "king fails test" << endl;;


	// queen check
	player = 1;
	ox = 4;
	oy = 1;
	nx = 2;
	ny = 3;

	ox = ox - 1;
	oy = oy - 1;
	nx = nx - 1;
	ny = ny - 1;
	nboard.cboard[2][1].x = ' ';
	nboard.cboard[2][1].y = ' ';
	//check move then move
	if (nboard.moveislegal(ox, oy, nx, ny, player)) {
		gameon = nboard.kingnottaken(nx, ny);
		nboard.movepiece(ox, oy, nx, ny);
		std::cout << "queen passes test" << endl;;
	}
	else std::cout << "queen fails test" << endl;;


}








