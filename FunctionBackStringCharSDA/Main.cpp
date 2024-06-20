#include <iostream>
#include <cstring>
#include <cstdarg>
#include <windows.h>

using namespace std;

// ������� ��� �������� ������ �� ����������� ���������� ��������
char* createString(int count, ...)
{
    va_list args;
    va_start(args, count);

    char* result = new char[count + 1];  // +1 ��� ����-�����������

    for (int i = 0; i < count; ++i)
    {
        result[i] = va_arg(args, int);  // va_arg ������������ ��� ��������� ���������
    }
    result[count] = '\0';  // ��������� ������ ����-������������

    va_end(args);
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* text = createString(3, '�', '�', '�');
    cout << text << endl;
    delete[] text;  // ����������� ������������ ������

    return 0;
}