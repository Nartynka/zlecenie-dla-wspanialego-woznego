#include <iostream>
#include <string>
#include "Helpers.h"
#include "Notepad.h"

void display_menu();

int main()
{
  Notepad my_notes;
  while(true)
  {
    display_menu();
    int choice = get_choice();
    switch(choice)
    {
    case 1:
      my_notes.show_all();
      break;
    case 2:
      my_notes.new_note();
      break;
    case 3:
      my_notes.delete_note();
      break;
    case 4:
      return 0;
    default:
      std::cout<<"ERROR!!\n";
      return 0;
    }
  }
}

void display_menu()
{
  system("cls");
  set_color(2);
  std::cout<<".-------------------------------------------------------------------.\n";
  std::cout<<"                             MENU\n";
  std::cout<<".-------------------------------------------------------------------.\n";
  std::cout<<"  1. Wyswietl wszystkie notatki\n";
  std::cout<<"  2. Dodaj nowa\n";
  std::cout<<"  3. Usun notatke\n";
  std::cout<<"  4. Wyjdz z programu\n";
  std::cout<<"'-------------------------------------------------------------------'\n";
  std::cout<<"Odpowiedz: ";
}
