#include <iostream>
#include "Notepad.h"
#include "Helpers.h"

//Notepad::~Notepad()
//{
//  for(Note note : notes)
//    note.~note();
//  notes.clear();
//}

void Notepad::show_all()
{
	set_color(6);
	if (notes.size() != 0)
	{
		for (int i = 0; i < notes.size(); i++)
		{
			std::cout << i + 1 << ".\n";
			std::cout << "-------------------\n";
			std::cout << "Pomieszczenie: " << notes[i].getRoom() << std::endl;
			std::cout << "Notatka: " << notes[i].getText() << std::endl;
		}
		std::cout << "-------------------\n";
	}
	else
		std::cout << "\nNie masz zadnych notatek jeszcze\n";
	getchar();
}

void Notepad::new_note()
{
	set_color(3);
	std::string rooms[10]{ "Lobby", "Biuro 1", "Biuro 2", "Serwerownia 1", "Serwerownia 2", "Kuchnia", "Lazienka", "Sala Konferencyjna", "Magazyn", "Kanciapa woznego" };
	std::string noteText;
	std::cout << "\nWbierz pomieszczenie\n";
	std::cout << "---------------------\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ". " << rooms[i] << std::endl;
	}
	std::cout << "---------------------\n";
	std::cout << "Odpowiedz: ";
	int choice = get_choice();
	if (choice < 1 || choice > 10)
	{
		std::cout << "Zly numer pomieszczenia\n";
		getchar();
		return;
	}
	std::cout << "Wprowadz tresc notatki: ";
	getline(std::cin, noteText);
	Note note(rooms[choice - 1], noteText);
	notes.push_back(note);
}

void Notepad::delete_note()
{
	set_color(4);
	if (notes.size() != 0)
	{
		for (int i = 0; i < notes.size(); i++)
		{
			std::cout << i + 1 << ".\n";
			std::cout << "-------------------\n";
			std::cout << "Pomieszczenie: " << notes[i].getRoom() << std::endl;
			std::cout << "Notatka: " << notes[i].getText() << std::endl;
		}
		std::cout << "-------------------\n";
		std::cout << "Numer notatki do usuniecia: ";
		int choice = get_choice();
		if (choice<1 || choice>notes.size())
		{
			std::cout << "Brak notatki o podanym numerze\n";
			getchar();
			return;
		}
		else
		{
			notes.erase(notes.begin() + choice-1);
		}
	}
	else
	{
		std::cout << "\nNie masz zadnych notatek jeszcze\n";
		getchar();
	}
}
