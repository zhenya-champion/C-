//���-�������

/*���, ���������, ���������
H(k) = [M(kAmod1)], 0 < A < 1, mod1 � ��������� ������� �����, [] � ��������� ����� �����	
����� �������� ���������*/


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <Windows.h>

using namespace std;

int razmer;

vector<string> surnames = {
"������","������","�������","�����","����","��������","������","���","����","������","�����","�����"
};
vector<string> names = {
"����","����","�����","������","����","�������","�����","������","�����","�����","��������","����","�������","������","�������"
};
vector<string> patronymics = {
"��������","��������","���������","����������","��������","�����������","���������","����������","��������","���������","������������","��������","����������","����������","����������"
};
class Person
{
public:
	string name;
	string surname;
	string patronymic;
	unsigned int passpotr = NULL;
	unsigned long int number = NULL;
	int colision = NULL;
};

class Hesh {

public:

	Person** persontabl;
	Person* hashtabl[1000];
	int kolis = 0;
	int a = 26;

	Hesh()
	{

		persontabl = new Person * [razmer];
	}

	~Hesh()
	{
		for (int i = 0; i < razmer; i++)
		{
			delete[](persontabl[i]);
		}
		delete[](persontabl);
	}

	void create_list()
	{


		cout << "������� ���������� ���������: ";

		cin >> razmer;

		cout << "������ ������:\n";

		cout << endl;

		for (int i = 0; i < razmer; i++)
		{

			Person* pers = new Person;

			pers->name = names[rand() % 15];

			pers->surname = surnames[rand() % 12];

			pers->patronymic = patronymics[rand() % 15];

			pers->passpotr = rand() * rand() % 999999 + 100000;

			pers->number = rand() * rand() % 999999999 + 100000000;

			pers->colision = NULL;

			persontabl[i] = pers;

			cout << persontabl[i]->surname << " " << persontabl[i]->name << " " << persontabl[i]->patronymic << endl << persontabl[i]->passpotr << "\t" << persontabl[i]->number << "\t";

			cout << persontabl[i];

			cout << endl;

		}

		cout << endl;

	}

	void hash_table()
	{

		for (int i = 0; i < 1000; i++)
		{
			hashtabl[i] = NULL;
		}
		create_table();
	}

	void create_table()
	{
		int four = 0;
		int seven = 0;
		int nine = 0;
		for (int i = 0; i < razmer; i++)
		{
			if (i < 40) { four = kolis; }
			if (i < 75) { seven = kolis; }
			if (i < 90) { nine = kolis; }
			if (hashtabl[heshfunk(persontabl[i]->number, a)] != 0)
			{
				kolis++;
				int k = 0;

				if (heshfunk(persontabl[i]->number, a) == 999 && hashtabl[heshfunk(persontabl[i]->number, a)] != 0)
				{
					int j = 0;

					while (hashtabl[j] != 0)
					{

						j++;

					}

					hashtabl[j] = persontabl[i];

					cout << persontabl[i]->surname << " " << persontabl[i]->name << " " << persontabl[i]->patronymic << endl << persontabl[i]->passpotr << "\t" << persontabl[i]->number << "\t";

					cout << " ����� ������ ��������: " << j;

					hashtabl[j]->colision = j;

					cout << endl << " ��������\n";

					goto skip;

				}
				while (hashtabl[heshfunk(persontabl[i]->number, a) + k] != 0)
				{
					k++;
					if (heshfunk(persontabl[i]->number, a) + k == 999 && hashtabl[heshfunk(persontabl[i]->number, a) + k] != 0)
					{
						int j = 0;
						while (hashtabl[j] != 0)
						{
							j++;
						}
						hashtabl[j] = persontabl[i];
						cout << persontabl[i]->surname << " " << persontabl[i]->name << " " << persontabl[i]->patronymic << endl << persontabl[i]->passpotr << "\t" << persontabl[i]->number << "\t";
						hashtabl[j]->colision = j;
						cout << " ����� ������ ��������: " << j;
						cout << endl << " ��������\n";

						goto skip;
					}
				}

				hashtabl[heshfunk(persontabl[i]->number, a) + k] = persontabl[i];
				cout << persontabl[i]->surname << " " << persontabl[i]->name << " " << persontabl[i]->patronymic << endl << persontabl[i]->passpotr << "\t" << persontabl[i]->number << "\t";

				cout << " ����� ������ ��������: " << heshfunk(persontabl[i]->number, a) + k;
				hashtabl[heshfunk(persontabl[i]->number, a) + k]->colision = heshfunk(persontabl[i]->number, a) + k;
				cout << " ��������\n";

			}
			else
			{
				hashtabl[heshfunk(persontabl[i]->number, a)] = persontabl[i];
			}
		skip:;

		}
		cout << endl;
		cout << "���������� �������� ��� ������� ���-������� 40 ���������: " << four;
		cout << endl;
		cout << "���������� �������� ��� ������� ���-������� 75 ���������: " << seven;
		cout << endl;
		cout << "���������� �������� ��� ������� ���-������� 90 ���������: " << nine;
		cout << endl;
		cout << "���������� �������� ��� ������� ���-������� " << razmer << " ���������: " << kolis;
		cout << endl;
	}

	int heshfunk(int key, int size)
	{

		if (key < 100000000 || key > 9999999999)
		{
			cout << endl;
			cout << "�������� ����!";
			cout << endl;
			return 0;

		}

		int g = key / 10000000;
		int l = key / 100000000 / g;
		int h = size * 0.1343 * (key % 256) + g + l;

		return  h;
	}

	void delete_elem()
	{
		cout << "������� ��������� ����� ��� ����� ��������:";
		int num;
		int k;
		cin >> num;
		if (num < 1000)
		{
			k = num;
		}
		else
		{
			k = heshfunk(num, a);
		}
		if (k != heshfunk(hashtabl[k]->number, a)) kolis--;
		hashtabl[k] = NULL;
		cout << endl;
		razmer--;
		cout << "���������� �������� ��� ������� ���-������� " << razmer << " ���������: " << kolis;
		cout << endl;

	}

	void add_elem()
	{
		int k;
		Person* now = new Person;
		cin.get();
		cout << "������� �������: ";
		getline(cin, now->surname);

		cout << "������� ���: ";
		getline(cin, now->name);

		cout << "������� ��������: ";
		getline(cin, now->patronymic);

		cout << "������� ����� �������� (9 ��������): ";
		cin >> now->number;
		cout << "������� ����� ��������� (6 ��������): ";
		cin >> now->passpotr;

		now->colision = NULL;
		cout << "�������� ����� �������!\n";
		k = heshfunk(now->number, a);
		if (hashtabl[k] != 0)
		{
			kolis++;
			int l = 0;

			if (k == 999 && hashtabl[k] != 0)
			{
				int j = 0;

				while (hashtabl[j] != 0)
				{
					j++;
				}

				hashtabl[j] = now;
				cout << " ����� ������ ��������: " << j;
				hashtabl[j]->colision = j;
				cout << endl << " ��������\n";
				goto skip;
			}
			while (hashtabl[k + l] != 0)
			{
				l++;
				if (k + l == 999 && hashtabl[k + l] != 0)
				{
					int j = 0;
					while (hashtabl[j] != 0)
					{
						j++;
					}
					hashtabl[j] = now;
					hashtabl[j]->colision = j;
					cout << " ����� ������ ��������: " << j;
					cout << endl << " ��������\n";

					goto skip;
				}
			}

			hashtabl[k + l] = now;
			cout << " ����� ������ ��������: " << k + l;
			hashtabl[k + l]->colision = k + l;
			cout << " ��������\n";
		}
		else
		{
			cout << "����� ������ ��������: " << k;
			hashtabl[k] = now;
		}
	skip:;
		razmer++;
		cout << endl;
		cout << "���������� �������� ��� ������� ���-������� " << razmer << " ���������: " << kolis;
		cout << endl;

	}

	void search()
	{
		int k;
		int g;
		bool tr = 0;
		bool ser = 0;
		cout << "������� ������� �����: ";
		cin >> k;
		g = heshfunk(k, a);
		for (int i = 0; i < 1000; i++)
		{

			hashtabl[i];
			if (hashtabl[i] != NULL)
			{
				if (g == i)
				{
					tr = 1;

					if (hashtabl[i + 1] != NULL)
					{
						if (hashtabl[i + 1]->number == k)
						{

							cout << "������� " << hashtabl[i + 1]->colision;
							cout << endl;
							cout << hashtabl[hashtabl[i + 1]->colision]->surname << " " << hashtabl[hashtabl[i + 1]->colision]->name << " " << hashtabl[hashtabl[i + 1]->colision]->patronymic << endl << hashtabl[hashtabl[i + 1]->colision]->passpotr << "\t" << hashtabl[hashtabl[i + 1]->colision]->number << "\t";
							cout << endl;
						}
						else
						{

							cout << "������� " << g;
							cout << endl;
							cout << hashtabl[i]->surname << " " << hashtabl[i]->name << " " << hashtabl[i]->patronymic << endl << hashtabl[i]->passpotr << "\t" << hashtabl[i]->number << "\t";
							cout << endl;
						}
					}
					else
					{

						cout << "������� " << g;
						cout << endl;
						cout << hashtabl[i]->surname << " " << hashtabl[i]->name << " " << hashtabl[i]->patronymic << endl << hashtabl[i]->passpotr << "\t" << hashtabl[i]->number << "\t";
						cout << endl;
					}
				}
			}
		}
		if (tr == 0)
		{
			cout << "������� �� ������!\n";
		}
	}

	void print_Hesh()
	{
		int b = 0;
		cout << "������" << "\t\t\t\t ����� � �������\n";
		cout << endl;
		for (int i = 0; i < 1000; i++)
		{

			if (hashtabl[i] != 0) {

				cout << hashtabl[i]->surname << " " << hashtabl[i]->name << " " << hashtabl[i]->patronymic << endl << hashtabl[i]->passpotr << "\t" << hashtabl[i]->number << "\t";
				if (hashtabl[i]->colision != NULL)
				{
					cout << '\t' << hashtabl[i]->colision;
					cout << endl;
				}
				else
				{
					cout << '\t' << heshfunk(hashtabl[i]->number, a);
					cout << endl;
				}
				b++;
			}
		}
		cout << endl;
		cout << "��������� � �������: ";
		cout << b << endl;
		cout << "��������� � ���������: " << kolis;
		cout << endl;
	}

	void printka()
	{
		int a = 0;
		hash_table();
		for (int i = 0; i < 1000; i++)
		{
			if (hashtabl[i] != 0) {
				a++;
			}
		}
		cout << "��������� � �������: ";
		cout << a << endl;
	}

	void remove()
	{
		for (int i = 0; i < 1000; i++)
		{
			hashtabl[i] = NULL;
		}
		kolis = 0;
	}

	void correct()
	{

		cout << "������� ��������� ����� ��� ����� ��������:";
		int num;
		int k;
		cin >> num;
		if (num < 1000)
		{
			k = num;
			cout << "������� " << k << endl;
			cout << hashtabl[k]->surname << " " << hashtabl[k]->name << " " << hashtabl[k]->patronymic << endl << hashtabl[k]->passpotr << "\t" << hashtabl[k]->number << "\n";

			Person* now = new Person;
			now = hashtabl[k];
			cin.get();
			cout << "������� �������: ";
			getline(cin, now->surname);

			cout << "������� ���: ";
			getline(cin, now->name);

			cout << "������� ��������: ";
			getline(cin, now->patronymic);

			cout << "������� ����� ��������� (6 ��������): ";
			cin >> now->passpotr;
		}
		else
		{
			k = heshfunk(num, a);
			if (hashtabl[k + 1] != NULL)
			{
				if (hashtabl[k + 1]->number == num)
				{

					cout << "������� " << hashtabl[k + 1]->colision << endl;
					cout << hashtabl[k + 1]->surname << " " << hashtabl[k + 1]->name << " " << hashtabl[k + 1]->patronymic << endl << hashtabl[k + 1]->passpotr << "\t" << hashtabl[k + 1]->number << "\n";
					Person* now = new Person;
					now = hashtabl[k + 1];
					cin.get();
					cout << "������� �������: ";
					getline(cin, now->surname);

					cout << "������� ���: ";
					getline(cin, now->name);

					cout << "������� ��������: ";
					getline(cin, now->patronymic);

					cout << "������� ����� ��������� (6 ��������): ";
					cin >> now->passpotr;
				}
				else
				{

					cout << "������� " << k << endl;
					cout << hashtabl[k]->surname << " " << hashtabl[k]->name << " " << hashtabl[k]->patronymic << endl << hashtabl[k]->passpotr << "\t" << hashtabl[k]->number << "\n";

					Person* now = new Person;
					now = hashtabl[k];
					cin.get();
					cout << "������� �������: ";
					getline(cin, now->surname);

					cout << "������� ���: ";
					getline(cin, now->name);

					cout << "������� ��������: ";
					getline(cin, now->patronymic);

					cout << "������� ����� ��������� (6 ��������): ";
					cin >> now->passpotr;
				}
			}
			else
			{
				cout << "������� " << k << endl;

				cout << hashtabl[k]->surname << " " << hashtabl[k]->name << " " << hashtabl[k]->patronymic << endl << hashtabl[k]->passpotr << "\t" << hashtabl[k]->number << "\n";

				Person* now = new Person;
				now = hashtabl[k];
				cin.get();
				cout << "������� �������: ";
				getline(cin, now->surname);

				cout << "������� ���: ";
				getline(cin, now->name);

				cout << "������� ��������: ";
				getline(cin, now->patronymic);

				cout << "������� ����� ��������� (6 ��������): ";
				cin >> now->passpotr;

			}
		}


	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int swt;
	Hesh newtable;

	newtable.create_list();
	do
	{

		cout << "1.������������ � ���������� ��� �������\n";

		cout << "2.������ ��� �������\n";

		cout << "3.�������� ��������\n";

		cout << "4.���������� ��������\n";

		cout << "5.����� ��������\n";

		cout << "6.������������� ��������\n";

		cout << "7.������� �������\n";

		cout << "8.�����\n";

		cin >> swt;

		cout << endl;

		switch (swt)

		{

		case 1: newtable.printka(); break;// ��������

		case 2: newtable.print_Hesh(); break;//������

		case 3:	newtable.delete_elem(); break;//��������

		case 4: newtable.add_elem(); break; // ����������

		case 5: newtable.search(); break;// �����

		case 6: newtable.correct(); break; // �������������

		case 7: newtable.remove(); break; // �������
		}
	} while (swt != 8);//�����
	system("pause");
	return 0;
}

// ���, ���������, ���������
// ���� ���������
//