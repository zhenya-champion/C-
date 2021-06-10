#pragma once
#include <iostream>

using namespace std;
class PRINT
{
public: struct PRINT_priority
{
public:  string name;
public:  string Autor;
public:  string cell;
public:  string table_of_contents;
}
      public PRINT() { }
      public:PRINT(string name, string autor, string cell, string table_of_contents)
      {
          name = name;
          autor = autor;
          cell = cell;
          table_of_contents = table_of_contents;
      }
public: string Display()
      {
          return (string.Format("Название книги: {0}" + Environment.NewLine + "Автор книги: {1}" + Environment.NewLine + "Цена: {2:F2}р." + Environment.NewLine + "Оглавление: {3}", book_properity.name, book_properity.Autor, book_properity.cell, book_properity.table_of_contents);
      }
};

void PRINT::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage)
    {
        Object** p = beg;
        for (int i = 0; i < cur; i++)
        {
            (*p)->HandleEvent(e);
        }
    }
}
