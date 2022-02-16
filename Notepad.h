#pragma once
#include <vector>
#include <string>
#include "Note.h"
class Notepad
{
private:
	std::vector<Note> notes;
public:
	Notepad() {};
	~Notepad() {};
	void show_all();
	void new_note();
	void delete_note();
};
