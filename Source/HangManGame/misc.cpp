#include "header.h"

//Turns on or off the blinking cursor
//Sourced from http://stackoverflow.com/questions/18028808/blinking-underscore-with-console
void toggle_cursor(bool showFlag){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

//Set the console width and height
void console_size(int width, int height){
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, 50, width, height, TRUE);
}