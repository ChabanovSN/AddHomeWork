#ifndef DATE__H
#define DATE__H
#include <iostream>
using namespace std;

class Date_
{
   int day=0, month=0,  year=0;
   const string months[13]= {"","января","февраля","марта","апреля","мая",
                             "июня","июля","августа","сентября","октября",
                             "ноября","декабря"};
   const char daytab[2][13] = {
        {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // дни со второй позиции что бы введение месяца было от 1 до 12
        {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
        };
   int getLeap(int year){ // проверка высокосного года
       return ((year%4 == 0 && year%100 != 0) || (year%400 == 0));
   }
   friend ostream& operator<< (ostream &out, const Date_ &d);
   friend istream& operator>> (istream &in, Date_ &d);
public:
   Date_(int d, int m, int y):day(d),month(m),year(y){};
   int day_of_year (int d, int m, int y); // дней в одном году
   int get_fulldays_ofyears(int,int); // дней в полных годах
   int operator-(Date_ &d2); // разница между годами
   Date_ operator+(int days); //  увеличения даты на определенное количество дней.
};

#endif // DATE__H
