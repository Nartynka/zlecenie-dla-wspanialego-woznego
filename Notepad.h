#pragma once
#include <vector>
#include <string>
#include "Note.h"
class Notepad
{
private:
	std::vector<Note> notes;
	std::vector<std::string> rooms { "Lobby", "Biuro 1", "Biuro 2", "Serwerownia 1", "Serwerownia 2", "Kuchnia", "Lazienka", "Sala Konferencyjna", "Magazyn", "Kanciapa woznego" };
public:
	Notepad() {};
	~Notepad() {};
	void show_all();
	void new_note();
	void delete_note();
};
