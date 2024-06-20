#include <iostream>
#include <cstring>
#include <cstdarg>
#include <windows.h>

using namespace std;

// ‘ункци€ дл€ создани€ строки из переменного количества символов
char* createString(int count, ...)
{
    va_list args;
    va_start(args, count);

    char* result = new char[count + 1];  // +1 дл€ нуль-терминатора

    for (int i = 0; i < count; ++i)
    {
        result[i] = va_arg(args, int);  // va_arg используетс€ дл€ получени€ аргумента
    }
    result[count] = '\0';  // «авершаем строку нуль-терминатором

    va_end(args);
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* text = createString(3, 'м', 'и', 'р');
    cout << text << endl;
    delete[] text;  // ќсвобождаем динамическую пам€ть

    return 0;
}