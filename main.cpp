#include <iostream>
#include <string>
#include "Helpers.h"
#include "Notepad.h"

void display_menu();

int main()
{
	//setlocale(LC_ALL, "pl_PL.UTF-8");
	//SetConsoleOutputCP(65001);
	Notepad my_notes;
	while (true)
	{
		display_menu();
		int choice = get_choice();
		switch (choice)
		{
		case 1:
			my_notes.show_all();
			break;
		case 2:
			my_notes.new_note();
			break;
		case 3:
			my_notes.display_delete();
			break;
		case 4:
			my_notes.new_room();
			break;
		case 5:
			my_notes.delete_room();
			break;
		case 6:
			return 0;
		default:
			std::cout << "Error! Podaj poprawny numer\n";
			system("pause");
		}
	}
}

void display_menu()
{
	system("cls");
	set_color(2);
	std::cout << ".-------------------------------------------------------------------.\n";
	std::cout << "                             MENU\n";
	std::cout << ".-------------------------------------------------------------------.\n";
	std::cout << "  1. Wyswietl wszystkie notatki\n";
	std::cout << "  2. Dodaj nowa notatke\n";
	std::cout << "  3. Usun notatke\n";
	std::cout << "  4. Dodaj nowe pomieszczenie\n";
	std::cout << "  5. Usun pomieszczenie\n";
	std::cout << "  6. Wyjdz z programu\n";
	std::cout << "'-------------------------------------------------------------------'\n";
	std::cout << "Odpowiedz: ";
}
