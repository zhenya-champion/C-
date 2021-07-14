// HandleException.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std; 

void foo() {
    int a, b;
    try {
        cin >> a >> b; 
        if (b == 0) throw "division by zero!";
        cout << "result: " << a / b << endl; 
    }
    catch (const char* s) {
        cout <<"handle in foo: " << s << endl; 
        throw; 
    }
}
int main()
{
    /*
    cout << "start 3...2...1\n"; 
    try {
        cout << "Before" << endl; 
        throw ":)";
        throw 100; 
        cout << "After\n"; 
    }
    catch (int g) {
        cout << "Exception: " << g << endl; 
    }
    catch (const char* s) {
        cout << "Exception: " << s << endl;
    }
    cout << "end\n"; 
   
   
    try {
        int a, b; 
        cin >> a >> b; 
        if (b==0)
        throw b;
        cout << "result: " << a / b << endl; 
        
    }
    catch (int b) {
        cout << "Exception: " << b << endl;
    }
    cout << "end\n";
    

    try {
        int* ptr = nullptr; 
        int size; 
        cout << "enter size: "; 
        cin >> size;
        if (size < 1 || size > 500) {
            throw "size error!";
        }
        ptr = new int[size]; 
        if (!ptr) {
            throw "memory error! "; 
        }
        int a; 
        cout << "Put digit: "; 
        cin >> a; 
        if (a == 0) {
            throw a; 
        }
    }
    catch (const char* str) {
        cout << str << endl;
    }
    catch (int b) {
        cout << "error a" << endl;
    }
    */
    
    try {
        foo(); 
    }
    catch (const char* s) {
        cout << ":) " << s << endl; 
    }
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
