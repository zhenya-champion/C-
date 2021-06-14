 //���� ������

 /*�������������� ���� �������� ������ � ���������, ����������� ������ ���������, ������� �������� ��� ��������, ������, 
������� ����, ����� �� ����� �����, ����� ���������.
������� ���������� � ���������, � ������� ����� �� ����� ����� ����� ���� ����������� �������.*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct stud {

    // ���
    string fio;
    // ������� ����
    double middleBall;
    // �����
    double cash;
};

int main() {
    // ����� ��� ����������� ��������
    double min_cash = 5000;

    // ��������� ����� ������ �� �����
    ifstream in;
    in.open("data.txt");

    // ��������� ����� ������ � ����
    ofstream on;
    on.open("data.txt", ios::app);

    // ������� ������ ���������
    vector<stud> v;

    // ����������, �������������� ������ � ���� ���������
    string answer = "";

    // �� ��� ���, ���� ���������� �� ������� � ��������� ������ exit
    while (answer != "exit") {

        // ������� ���� (1 - ����� ������ ����� ������ (� ������� � ����), 2 - ����� ������� ������ �� �����, 3 - ����� ���������, ����� ������� ������ ���� ����������� �������, exit - ����� �����)
        cout << "Press 1 to enter new data" << endl;
        cout << "Press 2 to read data from file" << endl;
        cout << "Press 3 to print students with low cash" << endl;
        cout << "Write exit to exit programm" << endl;
        cin >> answer;

        // ������������ ��������������� �������
        // ���������� � ����
        if (answer == "1") {

            // ������������ ���� �����, ������� � �������� �������� (������ ����� ������ �������, ��� � ��������), ��� �������� ����� � ������
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

            // ������������� � ������ ����� (����� �������� ����������� ������ � ���� � ������ ���)
            on.close();
            on.clear();
            on.open("data.txt", ios::app);

            // ���� �� ������� ������ �� �����       
        }
        else if (answer == "2") {

            // ��������� ���� ��������� � ������� �� �� ����� + ���������� � ������ ��������� (���� ����������� ���������� ����������)
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

            // ���� ������ ���� - ��������� ���������
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

                // ���� ����� �������� ������ ���� ����������� �������, �� ������� ���
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