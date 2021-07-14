// Многопоточность.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <future>
#include <vector>
#include <numeric>
#include "profile.h"
using namespace std; 

vector<int> generateVector(size_t size) {
    vector<int> result(size);
    for (size_t i = 0; i < size; i++) {
        result.push_back(i); 
    }
    return result; 
}
int64_t sumVector(const vector<int>& v) {
    return accumulate(begin(v), end(v), int64_t(0)); //чтобы не было преобразования in int => int64_t(0)
}
int main()
{
    const size_t size = 10'000'000; 
    const size_t count = 3; 
    {
        LOG_DURATION("Single thread vector"); 
        vector<vector<int>> vectors;
        vectors.reserve(3); 
        {
            LOG_DURATION("Generate single vector");
        for (size_t i = 0; i < count; i++) {
            vectors.push_back(generateVector(size)); 
        }
        }
        {
            LOG_DURATION("Sum single vector");
            for (const auto& v : vectors) {
                cout << sumVector(v) << endl; 
            }
        }
    }

    {
        LOG_DURATION("Multi thread vector");
        vector<vector<int>> vectors;
        vectors.reserve(3);
        {
            LOG_DURATION("Generate Multi vector");
            vector<future<vector<int>>> futures; 
            futures.reserve(3); 
            for (size_t i = 0; i < count; i++) {
                futures.push_back(async([size]() {
                    return generateVector(size); 
                     }
                ));
            }
            for (auto& f : futures) {
                vectors.push_back(f.get()); 
            }
        }
        
        {
            LOG_DURATION("Sum Multi vector");
            for (const auto& v : vectors) {
                cout << sumVector(v) << endl;
            }
        }
        
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
