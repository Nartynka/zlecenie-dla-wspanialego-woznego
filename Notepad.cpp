#include <iostream>
#include "Notepad.h"
#include "Helpers.h"
#include <iterator>
#include <fstream>

void save_in_file(Note& note);

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
	std::string aa = "aaaa";
	notesFile >> aa;
	notesFile.close();
}

void Notepad::show_all()
{
	set_color(6);
	if (notes.size() != 0)
	{
		int counter = 0;
		for (Note& n : notes)
		{
			std::cout << ++counter << ".\n";
			std::cout << "Miejsce: " << n.getRoom();
			std::cout << "\nNotatka: " << n.getText();
			std::cout << "\n-------------------\n";
		}
	}
	else
		std::cout << "\nNie masz zadnych notatek jeszcze\n";
	system("pause");
}

void Notepad::new_note()
{
	set_color(3);
	std::string noteRoom;
	std::string noteText;
	while (true)
	{
		std::cout << "\nWpisz pomieszczenie\n";
		std::cout << "---------------------\n";
		std::cout << "Odpowiedz: ";
		std::getline(std::cin, noteRoom);
		if (noteRoom.find_first_not_of(' ') == std::string::npos) continue;
		if (noteRoom.length() > 0) break;
	}
	while (true)
	{
		std::cout << "Wprowadz tresc notatki: ";
		getline(std::cin, noteText);
		if (noteText.find_first_not_of(' ') == std::string::npos) continue;
		if (noteText.length() > 0) break;
	}
	Note note(noteRoom, noteText);
	save_in_file(note);
	notes.push_back(note);
}

void save_in_file(Note& note)
{
	std::fstream file = open_file();
	std::string room = note.getRoom();
	std::string text = note.getText();
	file << room << ",";
	file << text << "\n";
	file.close();
}

void Notepad::delete_note()
{
	set_color(4);
	if (notes.size() != 0)
	{
		std::fstream file = open_file();
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
		else
		{
			std::ofstream temp;
			temp.open("temp.csv", std::ofstream::out);

			char c;
			int line_no = 1;
			while (file.get(c))
			{
				if (c == '\n')
					line_no++;
				if (line_no != choice)
					temp << c;
			}
			temp.close();
			file.close();
			remove("notes.csv");
			rename("temp.csv", "notes.csv");
		}
		//int curLine = 0;
		//std::string line;
		//while (std::getline(file, line)) {
		//	curLine++;
		//	if (line.find(notes[choice-1].getText(), 0) != std::string::npos) 
		//		line.replace(line.find(deleteline), deleteline.length(), "");
		//}
		notes.erase(notes.begin() + choice - 1);
	}
	else
	{
	std::cout << "\nNie masz zadnych notatek jeszcze\n";
	system("pause");
	}
}
