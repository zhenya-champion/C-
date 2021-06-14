 //Базы Данных

 /*Типизированный файл содержит данные о студентах, формируется список студентов, который включает ФИО студента, группу, 
средний балл, доход на члена семьи, место общежитии.
Вывести информацию о студентах, у которых доход на члена семьи менее двух минимальных зарплат.*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct stud {

    // ФИО
    string fio;
    // Средний балл
    double middleBall;
    // Доход
    double cash;
};

int main() {
    // Пусть это минимальная зарплата
    double min_cash = 5000;

    // Открываем поток чтения из файла
    ifstream in;
    in.open("data.txt");

    // Открываем поток записи в файл
    ofstream on;
    on.open("data.txt", ios::app);

    // Создаем массив студентов
    vector<stud> v;

    // Переменная, обеспечивающая работу с меню программы
    string answer = "";

    // До тех пор, пока переменная не напишем в командной строке exit
    while (answer != "exit") {

        // Выводим меню (1 - чтобы ввести новые данные (с записью в файл), 2 - чтобы считать данные из файла, 3 - вывод студентов, доход которых меньше двух минимальных зарплат, exit - чтобы выйти)
        cout << "Press 1 to enter new data" << endl;
        cout << "Press 2 to read data from file" << endl;
        cout << "Press 3 to print students with low cash" << endl;
        cout << "Write exit to exit programm" << endl;
        cin >> answer;

        // Обрабатываем соответствующие команды
        // Записываем в файл
        if (answer == "1") {

            // Осуществляем ввод имени, фамилии и отчества студента (вводим через пробел фамилия, имя и отчество), его среднего балла и дохода
            stud temp;
            cout << "Enter FIO" << endl;
            string f;
            string i;
            string o;
            cin >> f >> i >> o;
            temp.fio = f + " " + i + " " + o;
            cout << "Enter middleBall" << endl;
            cin >> temp.middleBall;
            cout << "Enter cash of student" << endl;
            cin >> temp.cash;
            on << temp.fio << " " << temp.middleBall << " " << temp.cash << "\n";

            // Переоткрываем и чистим поток (чтобы оставить возможность записи в файл в другой раз)
            on.close();
            on.clear();
            on.open("data.txt", ios::app);

            // Если же выбрали чтение из файла       
        }
        else if (answer == "2") {

            // Считываем всех студентов и выводим их на экран + записываем в массив студентов (если понадобятся дальнейшие вычисления)
            in.close();
            in.open("data.txt");
            in.clear();
            v.clear();
            stud temp;

            string f;
            string i;
            string o;
            cout << "---------List of students---------" << endl;
            while (in >> f >> i >> o >> temp.middleBall >> temp.cash) {
                temp.fio = f + " " + i + " " + o;
                cout << temp.fio << "; " << temp.middleBall << "; " << temp.cash << endl;
                v.push_back(temp);
            }
            cout << "----------------------------------" << endl;
        }
        else if (answer == "3") {

            // Если вектор пуст - считываем студентов
            if (v.empty()) {
                in.close();
                in.open("data.txt");
                in.clear();
                v.clear();
                stud temp;
                string f;
                string i;
                string o;
                while (in >> f >> i >> o >> temp.middleBall >> temp.cash)
                    temp.fio = f + " " + i + " " + o, v.push_back(temp);
            }
            cout << "---------List of poor students---------" << endl;
            for (int i = 0; i < v.size(); i++) {

                // Если доход студента меньше двух минимальных зарплат, то выводим его
                if (v[i].cash < 2 * min_cash) {
                    cout << v[i].fio << "; " << v[i].middleBall << "; " << v[i].cash << endl;
                }
            }
            cout << "---------------------------------------" << endl;
        }
        cout << endl << endl;
    }
    in.close();
    on.close();
    return 0;
}