/*Разработайте программу «Библиотека».Создайте структуру «Книга»(название, автор,
    издательство, жанр).Создайте массив из 10 книг.Реализуйте для него следующие возможности :
Редактировать книгу
Печать всех книг
Поиск книг по автору
Поиск книги по названию
Сортировка массива по названию книг
Сортировка массива по автору
Сортировка массива по издательству*/


#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

struct Book
{
    std::string name, author, publisher, genre;
};

void PrintByIndex(const std::vector<Book>& b, const size_t index);

int main()
{
    const unsigned int NumberOfElements = 10;
    const std::string items[] = {
      "1) Edit.",
      "2) Print all.",
      "3) Find by author.",
      "4) Find by name.",
      "5) Sort by name.",
      "6) Sort by author.",
      "7) Sort by publisher.",
    };

    unsigned int key, book_number;
    std::string author, name;

    std::vector<Book> books(NumberOfElements);

    for (auto& value : books) {
        std::cout << "Name, author, publisher, genre: ";
        std::cin >> value.name >> value.author >> value.publisher >> value.genre;
    }


    while (true) {
        for (const auto& value : items)
            std::cout << value << std::endl;

        std::cout << ">> ";
        std::cin >> key;

        switch (key) {
        case 1:
            std::cout << "Book number: ";
            std::cin >> book_number;
            std::cout << "New name, author, publisher, genre: ";
            std::cin >> books[book_number].name >> books[book_number].author
                >> books[book_number].publisher >> books[book_number].genre;
            break;
        case 2:
            for (size_t i = 0; i < NumberOfElements; ++i)
                PrintByIndex(books, i);
            break;
        case 3:
            std::cout << "Author: ";
            std::cin >> author;
            for (size_t i = 0; i < NumberOfElements; ++i)
                if (books[i].author == author)
                    PrintByIndex(books, i);
            break;
        case 4:
            std::cout << "Name: ";
            std::cin >> name;
            for (size_t i = 0; i < NumberOfElements; ++i)
                if (books[i].name == name)
                    PrintByIndex(books, i);
            break;
        case 5:
            std::sort(books.begin(), books.end(), [](const Book& b1, const Book& b2) { return b1.name < b2.name; });
            break;
        case 6:
            std::sort(books.begin(), books.end(), [](const Book& b1, const Book& b2) { return b1.author < b2.author; });
            break;
        case 7:
            std::sort(books.begin(), books.end(), [](const Book& b1, const Book& b2) { return b1.publisher < b2.publisher; });
            break;

        default:
            break;
        }
    }
}

void PrintByIndex(const std::vector<Book>& b, const size_t index)
{
    std::cout << "[" << index << "] "
        << b[index].name << " " << b[index].author << " "
        << b[index].publisher << " " << b[index].genre << std::endl;
}