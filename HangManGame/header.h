#ifndef _HEADERS_
#define _HEADERS_

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <vector>

//Main Menu
void menu();
void print_menu();
void print_load();

//Words
enum { t_animals=0, t_countries=1, t_fruits=2, t_periodic=3, t_states=4 };

const int count_animals = 214;
const int count_countries = 174;
const int count_fruits = 73;
const int count_periodic = 118;
const int count_states = 39;

const char *words_animals[];
const char *words_countries[];
const char *words_fruits[];
const char *words_periodic[];
const char *words_states[];

//Game
enum { s_playing=0, s_won=1, s_lost=2, s_ended=3 };
enum { t_waiting=0, t_correct=1, t_incorrect=2, t_duplicate=3 };

void start_game(int min_letters, int max_letters, int given, int theme);
void load_words(int min_letters, int max_letters, int theme);
void pick_given_letters(int given);

void print_level();
void refresh_status();
void refresh_turn();
void guess_char(char key);

int guesses_incorrect();
int guesses_correct();

//Misc
void toggle_cursor(bool showFlag);
void console_size(int width, int height);

using namespace std;

#endif