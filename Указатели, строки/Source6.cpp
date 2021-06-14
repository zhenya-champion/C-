//Написать функцию, которая получает указатель на статический массив и его размер.Функция
//распределяет положительные, отрицательные и нулевые элементы в отдельные динамические
//массивы.

#include <iostream>
#include <ctime>
using namespace std;
void dispatch_array_to_arrays_neg_zer_pos(
    int* arr, size_t arr_len,
    int*& neg, size_t& neg_len,
    int*& zer, size_t& zer_len,
    int*& pos, size_t& pos_len
)
{
    neg_len = zer_len = pos_len = 0;
    for (size_t i = 0; i < arr_len; ++i)
        if (arr[i] < 0)neg_len++;
        else
            if (!arr[i])zer_len++;
            else pos_len++;

    neg = new int[neg_len];
    zer = new int[zer_len];
    pos = new int[pos_len];

    size_t neg_ind = 0, zer_ind = 0, pos_ind = 0;
    for (size_t i = 0; i < arr_len; ++i)
        if (arr[i] < 0)neg[neg_ind++] = arr[i];
        else
            if (!arr[i])zer[zer_ind++] = arr[i];
            else pos[pos_ind++] = arr[i];
}
void print(int* a, size_t n)
{
    for (size_t i = 0; i < n; ++i)cout << a[i] << " ";
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    const size_t n = 30;
    int A[n];

    //создаём массив

    for (int i = 0; i < n; i++)
        A[i] = rand() % 32 - 16;
    cout << "массив:\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    int* neg, * zer, * pos;
    size_t
        neg_len(0), zer_len(0), pos_len(0),
        & rneg_len(neg_len), & rzer_len(zer_len), & rpos_len(pos_len);
    dispatch_array_to_arrays_neg_zer_pos(A, n, neg, rneg_len, zer, rzer_len, pos, rpos_len);
    cout << "negative" << endl;
    print(neg, rneg_len);
    cout << "zero" << endl;
    print(zer, rzer_len);
    cout << "positive" << endl;
    print(pos, rpos_len);
    delete[]neg;
    delete[]zer;
    delete[]pos;
    system("pause");
    return 0;
}