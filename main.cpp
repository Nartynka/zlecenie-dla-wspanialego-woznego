#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

std::vector <std::string> notes;

void set_color(int color)
{
  //idk how this works but gives fancy colors :D
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void wait()
{
  //ignore "\n" produced by cin
  std::cin.ignore();
  getchar();
}

void menu()
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

void show_all()
{
  set_color(6);
  if(notes.size()!=0)
  {
    int counter{};
    for(int i=0; i<notes.size(); i=i+2)
    {
      std::cout<<++counter<<".\n";
      std::cout<<"-------------------\n";
      std::cout<<"Pomieszczenie: "<<notes[i]<<std::endl;
      std::cout<<"Notatka: "<<notes[i+1]<<std::endl;
    }
    std::cout<<"-------------------\n";
  }
  else
    std::cout<<"\nNie masz zadnych notatek jeszcze\n";
  wait();
}

void new_note()
{
  set_color(3);
  std::string rooms[10] {"Lobby", "Biuro 1", "Biuro 2", "Serwerownia 1", "Serwerownia 2", "Kuchnia", "Lazienka", "Sala Konferencyjna", "Magazyn", "Kanciapa woznego"};
  int choice;
  std::string noteText;
  std::cout<<"\nWbierz pomieszczenie\n";
  std::cout<<"---------------------\n";
  for(int i=0; i<10; i++)
  {
    std::cout<<i+1<<". "<<rooms[i]<<std::endl;
  }
  std::cout<<"---------------------\n";
  std::cout<<"Odpowiedz: ";
  std::cin>>choice;
  if(choice < 1 || choice > 10)
  {
    std::cout<<"Zly numer pomieszczenia\n";
    new_note();
  }
  std::cout<<"Wprowadz tresc notatki: ";
  std::cin.ignore(); //ignore "\n" produced by cin
  getline(std::cin, noteText);
  notes.push_back(rooms[choice-1]);
  notes.push_back(noteText);
}

void delete_note()
{
  set_color(4);
  if(notes.size()!=0)
  {
    int counter{};
    for(int i=0; i<notes.size(); i=i+2)
    {
      std::cout<<++counter<<".\n";
      std::cout<<"-------------------\n";
      std::cout<<"Pomieszczenie: "<<notes[i]<<std::endl;
      std::cout<<"Notatka: "<<notes[i+1]<<std::endl;
    }
    std::cout<<"-------------------\n";
    std::cout<<"Numer notatki do usuniecia: ";
    int choice;
    std::cin>>choice;
    if(choice>1 || choice>notes.size())
    {
      std::cout<<"Brak notatki o podanym numerze\n";
      wait();
    }
    else
    {
      notes.erase(notes.begin()+choice-1);
      notes.erase(notes.begin()+choice);
    }
  }
  else
  {
    std::cout<<"\nNie masz zadnych notatek jeszcze\n";
    wait();
  }
}

int main()
{
  while(true)
  {
    menu();
    int choice;
    std::cin>>choice;
    switch(choice)
    {
    case 1:
      show_all();
      break;
    case 2:
      new_note();
      break;
    case 3:
      delete_note();
      break;
    case 4:
      return 0;
    default:
      std::cout<<"ERROR!!\n";
      return 0;
    }
  }
}
