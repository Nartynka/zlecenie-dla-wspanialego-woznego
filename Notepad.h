#pragma once
#include <vector>
#include <string>
#include "Note.h"
class Notepad
{
private:
	std::vector<Note> notes;
	std::vector<std::string> rooms;
	const std::string roomsFileName = "rooms.txt";
public:
	Notepad();
	~Notepad() {};
	void show_all();
	void new_note();
	void display_delete();
	void delete_note(int index);
	void save_in_file(Note& note);
	void save_in_file(std::string room);
	void new_room();
	void delete_room();
};
