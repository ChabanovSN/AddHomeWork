#include <iostream>
#include "date_.h"
#include "string_.h"
using namespace std;
/*
Создайте класс Date, который будет содержать информацию о дате (день, месяц, год).
С помощью механизма перегрузки операторов, определите операцию
разности двух дат (результат в виде количества дней
между датами), а также операцию увеличения даты
на определенное количество дней.*/
void task1(){
    Date_ d1(1,1,2019);
    Date_ d2(31,12,2019);
     cout<<(d1-d2)<<endl; // 364
     cout<<d1+365<<endl;  //01: января :2020  вывод даты на виндос может не печатать русские буква
}
/*
 * Добавить в строковый класс функцию, которая создает строку, содержащую пересечение двух строк,
то есть общие символы для двух строк. Например,
результатом пересечения строк "sdqcg" "rgfas34" будет
строка "sg". Для реализации функции перегрузить
оператор * (бинарное умножение).
*/
void task2(){
    string_ s1("sdqcg");
    string_ s2("rgfas34");
    string_ ss = s1*s2;
    cout<<ss.GetStr()<<endl;
}
int main()
{
  task1();
  task2();
  return 0;
}
