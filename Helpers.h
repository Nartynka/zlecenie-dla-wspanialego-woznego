#pragma once
#include <windows.h>
#include <string>
#include <iostream>
inline void set_color(int color)
{
    //idk how this works but gives fancy colors :D
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

inline int get_choice()
{
    std::string userChoice;
    getline(std::cin, userChoice);
    if (userChoice.size() > sizeof(int)) return 0;
    if (std::isdigit(userChoice[0])) {return stoi(userChoice); }
    return 0;
}