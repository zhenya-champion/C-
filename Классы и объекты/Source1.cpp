/*�������� ���������� ����������� �����. ����������
������� ������ �� �������� (���, �������� �������,
������� �������, ��������� �������, ��������������
���������� � ��������) ������ ���������������� ������.
��������� ����� �����������-�������, ����������������, ��������������, inline-���������-�������,
����������� ��������������, ���������� ����������.
����������� ���������� �������� ����������� ������ ���
���. ������������ ������������ ����������� ���������
����� ���������, ������� ���������, ������ ���������
�� ���, ���������� ���� ���������.*/

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
        cout << "������� ��� ��������: ";
        getline(cin, FIO);
        cout << "������� �������� ������� ��������: ";
        getline(cin, HPhone);
        cout << "������� ������� ������� ��������: ";
        getline(cin, WPhone);
        cout << "������� ��������� ������� ��������: ";
        getline(cin, MPhone);
        cout << "������� ���. ���������� �� ��������: ";
        getline(cin, DopInfo);
        cout << endl;
    }
    int CoutSubscriber()
    {
        cout << "\n��� ��������: ";
        cout << FIO << endl;
        cout << "�������� ������� ��������: ";
        cout << HPhone << endl;
        cout << "������� ������� ��������: ";
        cout << WPhone << endl;
        cout << "��������� ������� ��������: ";
        cout << MPhone << endl;
        cout << "���. ���������� �� ��������: ";
        cout << DopInfo << endl;
    }
    bool SearchSubscriber()
    {
        string searchFullName;
        cout << "������� ��� ��������, �������� ������� �����: ";
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