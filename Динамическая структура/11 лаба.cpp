/*Записи в линейном списке содержат ключевое поле типа *char(строка символов).
Сформировать двунаправленный список. Удалить из него элемент с заданным ключом.*/

#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>


using namespace std;

class List
{
    
public:
    List() : root(0) {}
    void Add(char const* rhs)
    {
        if (!root)
            root = new Node(0, rhs);
        else
            root->Add(rhs);
    }
    void Erase(char const* rhs)             //  удаления из списка
    {
        if (root)
        {
            if (!strcmp(root->pstr, rhs))
            {
                cout << "Что нужно удалить: ";
                Node* tmp = root;
                root = root->next;
                if (root)
                    root->prev = 0;
                tmp->prev = 0;
                tmp->next = 0;
                delete tmp;
                cout << "Что осталось: ";
            }
            else
                root->Erase(rhs);
        }
    }
    ~List()
    {
        delete root;
        root = 0;
    }
private:
    struct Node
    {
        Node(Node* pnode) : prev(pnode), next(0), pstr(0) {}
        Node(Node* pnode, char const* rhs) : prev(pnode), next(0)
        {
            pstr = new char[strlen(rhs) + 1];
            strcpy(pstr, rhs);
        }
        void Add(char const* rhs)
        {
            if (!next)
                next = new Node(this, rhs);
            else
                next->Add(rhs);
        }
        void Erase(char const* rhs)
        {
            if (!strcmp(rhs, pstr))
            {
                cout << "Что нужно удалить: ";
                prev->next = next;
                if (next)
                    next->prev = prev;
                prev = 0;
                next = 0;
                delete this;
                cout << "Что осталось: ";
            }
            else if (next)
                next->Erase(rhs);

        }
        ~Node()
        {
            if (next)
                delete next;
            prev = 0;
            next = 0;
            cout << pstr << '\n';
            delete[] pstr;
            pstr = 0;
        }
        Node* prev, * next;
        char* pstr;
    private:                                //   Оператор присваивания.
        Node(Node const&);
        Node& operator=(Node);
    };
    Node* root;
    List(List const&);
    List& operator=(List);
    friend struct Node;
};

int main()
{
    setlocale(0, "Russian");
    List lst;

    lst.Add("СИЛА");
    lst.Add("ЛОВКОСТЬ");
    lst.Add("ИНТЕЛЕКТ");

    lst.Erase("ИНТЕЛЕКТ");

    system("pause");
    return 0;
}

