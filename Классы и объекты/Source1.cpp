/*Создайте приложение «Телефонная книга». Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса.
Наполните класс переменными-членами, функциямичленами, конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память под
ФИО. Предоставьте пользователю возможность добавлять
новых абонентов, удалять абонентов, искать абонентов
по ФИО, показывать всех абонентов.*/

#include <iostream>
#include <string>

using namespace std;

class PhoneBook
{
    string FIO, HPhone, WPhone, MPhone, DopInfo;
    int data;
public:
    PhoneBook(int _data)
    {
        data = _data;
    }
    void setSubscriber(string _FIO, string _HPhone, string _WPhone, string _MPhone, string _DopInfo)
    {
        FIO = _FIO;
        HPhone = _HPhone;
        WPhone = _WPhone;
        MPhone = _MPhone;
        DopInfo = _DopInfo;
    }
    void CinSubscriber()
    {
        cout << "Введите имя абонента: ";
        getline(cin, FIO);
        cout << "Введите домашний телефон абонента: ";
        getline(cin, HPhone);
        cout << "Введите рабочий телефон абонента: ";
        getline(cin, WPhone);
        cout << "Введите мобильный телефон абонента: ";
        getline(cin, MPhone);
        cout << "Введите доп. информацию об абоненте: ";
        getline(cin, DopInfo);
        cout << endl;
    }
    int CoutSubscriber()
    {
        cout << "\nИмя абонента: ";
        cout << FIO << endl;
        cout << "Домашний телефон абонента: ";
        cout << HPhone << endl;
        cout << "Рабочий телефон абонента: ";
        cout << WPhone << endl;
        cout << "Мобильный телефон абонента: ";
        cout << MPhone << endl;
        cout << "Доп. информацию об абоненте: ";
        cout << DopInfo << endl;
    }
    bool SearchSubscriber()
    {
        string searchFullName;
        cout << "Введите имя абонента, которого желаете найти: ";
        cin >> searchFullName;
        if (searchFullName == FIO)
            return true;
    }
    void DeleteSubscriber()
    {

    }
    ~PhoneBook()
    {
    }
};


int main()
{
    setlocale(0, "");
    PhoneBook Subscriber1(0);
    PhoneBook Subscriber2(0);
    Subscriber1.CinSubscriber();
    Subscriber2.CinSubscriber();
    Subscriber1.CoutSubscriber();
    Subscriber2.CoutSubscriber();
    system("pause");
}