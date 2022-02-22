#include <iostream>
#include "Notepad.h"
#include "Helpers.h"
#include <iterator>
#include <fstream>

Notepad::Notepad()
{
	std::fstream notesFile = open_file();
	bool is_empty = notesFile.peek() == std::ifstream::traits_type::eof();
	if (!is_empty) {
		std::string line;
		while (std::getline(notesFile, line))
		{
			std::string noteRoom = line.substr(0, line.find(","));
			std::string noteText = line.substr(line.find(",") + 1, line.find("\n"));
			Note note(noteRoom, noteText);
			notes.push_back(note);
		}
	}
	notesFile.close();

	std::fstream roomsFile = open_file(roomsFileName);
	bool is_empty2 = roomsFile.peek() == std::ifstream::traits_type::eof();
	if (!is_empty2) {
		std::string line;
		while (std::getline(roomsFile, line))
		{
			rooms.push_back(line);
		}
	}
	roomsFile.close();
}

void Notepad::show_all()
{
	set_color(6);
	if (notes.size() != 0)
	{
		for (int i = 0; i < rooms.size(); i++)
		{
			std::cout << rooms[i] << ":\n";
			int counter = 0;
			for (Note& n : notes)
			{
				if (n.getRoom() == rooms[i]) {
					std::cout << "\t> " << ++counter << ". " << n.getText() << "\n";
				}
			}
		}
		std::cout << "\n-------------------\n";
	}
	else
		std::cout << "\nNie masz zadnych notatek jeszcze\n";
	system("pause");
}


void Notepad::new_note()
{
	set_color(3);

	if (rooms.size() == 0)
	{
		std::cout << "Nie masz zadnego pomieszczenia, stworz pomieszczenie aby dodac notatke\n";
		system("pause");
		return;
	}

	std::string noteText;
	std::cout << "\nWbierz pomieszczenie\n";
	std::cout << "---------------------\n";
	for (int i = 0; i < rooms.size(); i++)
	{
		std::cout << i + 1 << ". " << rooms[i] << std::endl;
	}
	std::cout << "---------------------\n";
	std::cout << "Odpowiedz: ";
	int choice = get_choice();
	if (choice < 1 || choice > rooms.size())
	{
		std::cout << "Zly numer pomieszczenia\n";
		system("pause");
		return;
	}
	while (true)
	{
		std::cout << "Wprowadz tresc notatki: ";
		getline(std::cin, noteText);
		if (noteText.find_first_not_of(' ') == std::string::npos) continue;
		if (noteText.length() > 0) break;
	}
	Note note(rooms[choice - 1], noteText);
	save_in_file(note);
	notes.push_back(note);
}

void Notepad::save_in_file(Note& note)
{
	std::fstream file = open_file();
	std::string room = note.getRoom();
	std::string text = note.getText();
	file << room << ",";
	file << text << "\n";
	file.close();
}

void Notepad::save_in_file(std::string room)
{
	std::fstream file = open_file(roomsFileName);
	file << room << "\n";
	file.close();
}

void Notepad::display_delete()
{
	set_color(4);
	if (notes.size() != 0)
	{
		for (int i = 0; i < notes.size(); i++)
		{
			std::cout << i + 1 << ".\n";
			std::cout << "-------------------\n";
			std::cout << "Miejsce: " << notes[i].getRoom() << std::endl;
			std::cout << "Notatka: " << notes[i].getText() << std::endl;
		}
		std::cout << "-------------------\n";
		std::cout << "Numer notatki do usuniecia: ";
		int choice = get_choice();
		if (choice<1 || choice>notes.size())
		{
			std::cout << "Brak notatki o podanym numerze\n";
			system("pause");
			return;
		}
		else delete_note(--choice);
	}
	else
	{
		std::cout << "\nNie masz zadnych notatek jeszcze\n";
		system("pause");
	}
}

void Notepad::delete_note(int index) 
{
	std::fstream file = open_file();
	std::ofstream temp;
	temp.open("temp.csv", std::ofstream::out);

	char c;
	int line_no = 1;
	while (file.get(c))
	{
		if (c == '\n')
			line_no++;
		if (line_no != (index+1) && c != '\n')
			temp << c;
	}
	temp.close();
	file.close();
	int b = remove("notes.csv");
	int a = rename("temp.csv", "notes.csv");
	notes.erase(notes.begin() + index);
}

//maybe in future i would make a class for rooms
//but for now rooms will be here, it's KISS.

void Notepad::new_room()
{
	set_color(3);
	std::string newRoom;
	while (true)
	{
		std::cout << "\nWpisz nazwe nowego pomieszczenie\n";
		std::cout << "---------------------\n";
		std::cout << "Odpowiedz: ";
		std::getline(std::cin, newRoom);
		if (newRoom.find_first_not_of(' ') == std::string::npos) continue;

		for (std::string room : rooms)
		{
			if (room == newRoom)
			{
				std::cout << "Pomieszczenie juz istnieje\n";
				system("pause");
				return;
			}
		}
		if (newRoom.length() > 0) break;
	}
	rooms.push_back(newRoom);
	save_in_file(newRoom);
}

void Notepad::delete_room()
{
	set_color(4);
	if (rooms.size() != 0)
	{
		std::fstream file = open_file(roomsFileName);
		std::cout << "-------------------\n";
		for (int i = 0; i < rooms.size(); i++)
		{
			std::cout << i + 1 << ". " << rooms[i] << std::endl;
		}
		std::cout << "-------------------\n";
		std::cout << "Numer pomieszczenia do usuniecia: ";
		int choice = get_choice();
		if (choice<1 || choice>rooms.size())
		{
			std::cout << "Brak pomieszczenia o podanym numerze\n";
			system("pause");
			return;
		}
		else
		{
			for (int i=0; i<notes.size(); i++)
			{
				if (notes[i].getRoom() == rooms[choice-1]) {
					delete_note(i);
				}
			}
			std::ofstream temp;
			temp.open("tempRoom.csv", std::ofstream::out);

			char c;
			int line_no = 1;
			while (file.get(c))
			{
				if (c == '\n')
					line_no++;
				if (line_no != choice && c!='\n')
					temp << c;
			}
			temp.close();
			file.close();
			int b = remove("rooms.csv");
			int a = rename("tempRoom.csv", "rooms.csv");
		}
		rooms.erase(rooms.begin() + choice - 1);
	}
	else
	{
		std::cout << "\nNie masz zadnych pokoi jeszcze\n";
		system("pause");
	}
}