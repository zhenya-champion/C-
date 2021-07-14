//ДЕРЕВЬЯ

/*Тип информационного поля char
Найти количество листьев в дереве.*/
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

struct point
{
    char* data;   //информационное поле
    point* left;  //адрес левого поддерева
    point* right;  //адрес правого поддерева
};

point* tree(int n, point* p)
{
    point* r;
    int nl, nr;
    if (n == 0) { p = NULL; return p; }
    nl = n / 2;
    nr = n - nl - 1;
    r = new point;
    char s[50];
    cout << "Значение: ";
    cin >> s;
    r->data = new char[strlen(s) + 1];
    strcpy(r->data, s);
    r->left = tree(nl, r->left);
    r->right = tree(nr, r->right);
    p = r;
    return p;
}

void treeprint(point* p, int& count) {
    if (p != NULL) {
        treeprint(p->left, count);
        cout << p->data << "  ";
        treeprint(p->right, count);
        if ((p->left == NULL) && (p->right == NULL))
            count = count + 1;
    }
}

int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(NULL));
    int n = 0, k = 0, count = 0;
    point* beg = nullptr;
    do
    {
        cout << "1. Посторить бинарное дерево\n";
        cout << "2. Показать бинарное дерево\n";
        cout << "3. Выход\n";
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "Введите количество элементов" << endl;
            cin >> n;
            beg = tree(n, beg);
            cout << endl;
            break;
        case 2:
            treeprint(beg, count);
            cout << endl;
            cout << "Листьев в дереве: " << count << endl;
            break;
        }
    } while (k != 3);
    system("pause");
    return 0;
}