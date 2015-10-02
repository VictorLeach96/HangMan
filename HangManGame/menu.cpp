#include "header.h"

int stage = 0;
int selected = 0;

int difficulty = -1;
int theme = -1;

void menu(){

	//Infinite loop game and menu
	while (1){
		print_menu();

		//Get the current key pressed and decide on action
		int key = _getch();
		if (key == 27){
			//Esc
			exit(0);
		}else if (key == 72 && selected > 0){
			//Up arrow key
			selected --;
		}else if (key == 80){
			//Down arrow key and check if selection is out of bounds
			if ((stage == 0 && selected < 2) || (stage == 1 && selected < 4)){
				selected ++;
			}
		}else if (key == 13){
			//Enter button and check stage and apply vars accordingly
			if (stage == 0){
				difficulty = selected;
				stage += 1;
				selected = 0;
			}else if (stage == 1){
				theme = selected;
				stage += 1;
				selected = 0;
			}	
		}

		//Check if all options have been selected and start game with config
		if (theme != -1 && difficulty != -1){
			print_load();
			Sleep(100);

			switch (difficulty){
				case 0:
					start_game(3,5,0,theme);
				break;
				case 1:
					start_game(6,8,1,theme);
				break;
				case 2:
					start_game(9,20,2,theme);
				break;
			}

			//Reset variables for new menu
			stage = 0;
			selected = 0;
			difficulty = -1;
			theme =-1;
		}
	}
}

void print_menu(){
	system("cls");

	//Print header
	cout << "-----------------------------Press Escape to quit-------------------------------"<<endl;
	cout << "   _   _                  ___  ___            " << endl;
	cout << "  | | | |                 |  \\/  |            " << endl;
	cout << "  | |_| | __ _ _ __   __ _| .  . | __ _ _ __  " << endl;
	cout << "  |  _  |/ _` | '_ \\ / _` | |\\/| |/ _` | '_ \\ " << endl;
	cout << "  | | | | (_| | | | | (_| | |  | | (_| | | | |" << endl;
	cout << "  \\_| |_/\\__,_|_| |_|\\__, \\_|  |_/\\__,_|_| |_|" << endl;
	cout << "                      __/ |                   " << endl;
	cout << "                     |___/                    " << endl;

	//Different output for each stage
	if (stage == 0){
		//Difficulty stage
		cout << endl << "--------------Please choose a difficulty using the arrow keys-------------------"<<endl<<endl;

		if (selected == 0){
			cout << "  [*]	Easy (3-5 letters)"<<endl;
		}else{
			cout << "  [ ]	Easy (3-5 letters)"<<endl;
		}
		if (selected == 1){
			cout << "  [*]	Medium (6-8 letters, 1 given)"<<endl;
		}else{
			cout << "  [ ]	Medium (6-8 letters, 1 given)"<<endl;
		}
		if (selected == 2){
			cout << "  [*]	Hard (8+ letters, 2 given)"<<endl;
		}else{
			cout << "  [ ]	Hard (8+ letters, 2 given)"<<endl;
		}
	}else if (stage == 1){
		//Difficulty stage
		cout << endl << "-----------------Please choose a theme using the arrow keys---------------------"<<endl<<endl;

		if (selected == 0){
			cout << "  [*]	Animals"<<endl;
		}else{
			cout << "  [ ]	Animals"<<endl;
		}
		if (selected == 1){
			cout << "  [*]	Countries"<<endl;
		}else{
			cout << "  [ ]	Countries"<<endl;
		}
		if (selected == 2){
			cout << "  [*]	Fruits"<<endl;
		}else{
			cout << "  [ ]	Fruits"<<endl;
		}
		if (selected == 3){
			cout << "  [*]	Periodic Elements"<<endl;
		}else{
			cout << "  [ ]	Periodic Elements"<<endl;
		}
		if (selected == 4){
			cout << "  [*]	US States"<<endl;
		}else{
			cout << "  [ ]	US States"<<endl;
		}
	}

	//Footer
	cout << endl << endl << "--------------------------------------------------------------------------------"<<endl;
}
void print_load(){
	system("cls");
	cout << "-----------------------------Press Escape to quit-------------------------------"<<endl;
	cout << "   _   _                  ___  ___            " << endl;
	cout << "  | | | |                 |  \\/  |            " << endl;
	cout << "  | |_| | __ _ _ __   __ _| .  . | __ _ _ __  " << endl;
	cout << "  |  _  |/ _` | '_ \\ / _` | |\\/| |/ _` | '_ \\ " << endl;
	cout << "  | | | | (_| | | | | (_| | |  | | (_| | | | |" << endl;
	cout << "  \\_| |_/\\__,_|_| |_|\\__, \\_|  |_/\\__,_|_| |_|" << endl;
	cout << "                      __/ |                   " << endl;
	cout << "                     |___/                    " << endl;
	cout << endl << "--------------------------Loading, please wait...-------------------------------"<<endl<<endl;
}