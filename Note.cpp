#include "Note.h"

Note::Note(std::string room, std::string text)
{
	noteRoom = room;
	noteText = text;
};

std::string Note::getText() { return noteText; };
std::string Note::getRoom() { return noteRoom; };