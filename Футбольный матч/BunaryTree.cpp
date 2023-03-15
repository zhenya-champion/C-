
#include <iostream>
#include "Tree.h"
#include "Match.h"
#include <vector>
#include <time.h>
#include <string>
using namespace std; 
using NodeMatchType = TreeNode<Match>; 



//
unique_ptr<Tree<Match>> Game(vector<string> Commands){
    auto tournament = make_unique<Tree<Match>>();
    //переменные для итерирования
    size_t i, j;
    //переменные для хранения счета
    size_t p1, p2; 
    //каждая команда играет 2 раза - дома и в гостях
    size_t k; 
    shared_ptr<NodeMatchType> temp;
    for (k = 0; k < 2; k++) {
        //цикл по командам
        for (i = 0; i < Commands.size()-1; i++) {
            //создание матча
            for (j = i + 1; j < Commands.size(); j++) {


                temp = make_unique<NodeMatchType>();
                //заполняем матч
                if (k == 0) {// 1 game
                    temp->data.Name = Commands[i];
                    temp->data.Opponent = Commands[j];
                }
                else {
                    temp->data.Name = Commands[j];
                    temp->data.Opponent = Commands[i];
                }

                p1 = rand() % 6;
                p2 = rand() % 6;
                //обработка результата матча
                if (p1 > p2) {
                    temp->data.OwnerPoints = 3;
                    temp->data.OppPoints = 0;
                }
                else if (p1 == p2) {
                    temp->data.OwnerPoints = 1;
                    temp->data.OppPoints = 1;
                }
                else {
                    temp->data.OwnerPoints = 0;
                    temp->data.OppPoints = 3;
                }
                temp->data.match = to_string(p1) + " : " + to_string(p2);
                //добавление матча в дерево
                tournament->Insert(temp);
            }
        }
    }
    return tournament; 
}

int main()
{
    srand(time(0));
    vector<string> Commands =
    {
     "Arsenal",
     "Liverpool",
     "Lits United",
     "Manchester United"
    };
    auto tree = Game(Commands); 
    tree->print(tree->getRoot()); cout << endl; cout << endl;
    Match searchMatch;
    searchMatch.Name = "Manchester United"; 
    auto node = tree->search(tree->getRoot(), searchMatch);
    tree->Del(node); 
    tree->print(tree->getRoot());

    

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
