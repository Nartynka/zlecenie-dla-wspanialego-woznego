#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
inline void set_color(int color)
{
	//idk how this works but gives fancy colors :D
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

inline int get_choice()
{
	std::string userChoice;
	getline(std::cin, userChoice);
	if (userChoice.size() > sizeof(int) || userChoice[0] < 0) return 0;
	if (std::isdigit(userChoice[0])) {return stoi(userChoice); }
	return 0;
}

inline std::fstream open_file(std::string fileName = "notes.txt")
{
	std::fstream fout;
	fout.open(fileName, std::ios::in | std::ios::out | std::ios::app);
	if (fout.is_open()) return fout;

	std::cout << "\nBlad podczas otwierania pliku "<<fileName<<std::endl;
	fout.close();
	system("pause");
	exit(1);
}