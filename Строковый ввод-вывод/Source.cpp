//"Строковый ввод-вывод"

/* 	Создать текстовый файл F1 не менее, чем из 10 строк и записать в него информацию
    Выполнить задание.*/

    //1) Скопировать из файла F1 в файл F2 все строки, которые не содержат слова, начинающиеся на одну букву.
      //2) Найти самое короткое слово в  файле F2.*/

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
int main()
{
    ofstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
    std::ifstream ifs("input.txt");
    if (!ifs)
        return 1;
    std::ofstream o("output.txt");
    for (std::string str; !ifs.eof() && std::getline(ifs, str); )
    {
        std::istringstream ist(str);
        std::set<char> s;
        bool flag = true;
        for (std::string word; flag && ist >> word; )
        {
            if (s.find(word[0]) == s.end())
                s.insert(word[0]);
            else
                flag = false;
        }
        if (flag)
            o << str << std::endl;
    }
    static std::size_t const max_line_size = 128;
    std::size_t min = std::numeric_limits<std::size_t>::max();
    char buffer[max_line_size];
    while (ifs.getline(buffer, max_line_size)) {
        min = std::min(min, std::strlen(buffer));
    }
    std::cout << min << std::endl;
}