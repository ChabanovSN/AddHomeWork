#include "string_.h"
  ///////////////////////////// ДЗ
string_ string_::operator*(const string_& str){
    int minLen = (len<str.len? len: str.len); // минимальная длина из 2 строк
    char ch[minLen];// временный массив для хранения совпадений
   int index = 0;

      for(int i=0;i<len;i++){
          for(int j=0;j<str.len;j++){
              if(S[i]==str.S[j]){
                 ch[index++]=S[i]; // совпадения
              }

          }
      }
      ch[index]='\0';
       string_ newStr(ch);
      return newStr;
}
////////////////////////////////ДЗ
string_::string_(){
    //Начальная инициализация
    S = NULL;
    len = 0;
}
string_::string_(char* s){
    len = strlen(s);
    S = new char[len + 1];
    //Инициализация строкой,
    //переданной пользователем
    strcpy(S, s);
}
string_::string_(const string_& s){
    len = s.len;
    //Безопасное копирование
    S = new char[len + 1];
    strcpy(S, s.S);
}
void string_::Sort(string_ s[], int n)
{
    //Сортировка строк
    //Методом пузырька
    string_ temp;
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            //сравнение двух строк
            if(strcmp(s[j].S,s[j-1].S)<0)
                swap(s[j],s[j-1]);

        }
    }
}
//Функция сцепления строк (перегруженный бинарный плюс)
string_ string_::operator+(const string_ &str)
{
    //Создание временного объекта
    string_ s;
    //Вычисление новой длины строки
    s.len = len + str.len;
    //Выделение памяти под новую строку
    s.S = new char[s.len + 1];
    //Инициализация первой части строки
    strcpy(s.S, S);
    //Инициализация второй части строки
    strcat(s.S, str.S);
    //Возврат нового объекта
    return s;
}
//Функция, реализующая безопасное присваивание
string_& string_::operator=(const string_ &str)
{
    //Предотвращение варианта STRING = STRING;
    //(присваивание самому себе),
    //где STRING переменная класса string
    if(this == &str)
        return *this;
    //если размеры строк не совпадают или строка,
    //в которою производится запись не сформирована
    if(len != str.len || len == 0)
    {
        //Удаление старой строки
        delete [] S;
        //Вычисление новой длины строки
        len = str.len;
        //Выделение памяти под новую строку
        S = new char[len + 1];
    }
    //Инициализация строки
    strcpy(S, str.S);

    return *this;
}
