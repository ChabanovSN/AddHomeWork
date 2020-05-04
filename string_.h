#ifndef STRING__H
#define STRING__H

#include <iostream>
#include <string.h>
using namespace std;
class string_
{
private:
    //Строка
    char* S;
    //Длина строки
    int len;
public:
    string_();
    string_(char* s);
    string_(const string_& s);
    ~string_(){ delete [] S;}
    //Метод сортировки
    void Sort(string_ s[], int n);
    //Константный метод
    //возвращающий содержимое строки
    const char*GetStr()const { return S;}
    //метод позволяющий изменить содержимое
    //с помощью пользователя
    void SetStr(){
        //если строка не пустая - очистить
        if(S!=NULL)
            delete[]S;
        //создаем массив
        //и запрашиваем у пользователя данные
        char a[256];
        cin.getline(a,256);
        //просчитываем размер
        len=strlen(a)+1;
        //выделяем память
        S = new char[len];
        //переписываем в объект введенную строку
        strcpy(S,a);
    }
    string_ operator+(const string_&);
    string_ operator*(const string_&);// пересечение двух строк
    string_&operator=(const string_&);
    operator char*() { return S; }
};

#endif // STRING__H
