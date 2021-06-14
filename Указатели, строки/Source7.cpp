//Написать функцию, которая удаляет из строки символ с заданным номером.

void Del(char*& s, int pos)
{
    int size = 0;
    while (s[++size]);

    if (size < pos)
        return;

    char* r = new char[size];
    for (int i = 0, j = 0; i < size; ++i, j++)
    {
        if (i != pos)
            r[j] = s[i];
        else
            --j;
    }

    r[size - 1] = '\0';

    delete[] s;
    s = r;
}


int main()
{
    char* s = new char[5]{ "1234" };
    Del(s, 1);

    return 0;
}