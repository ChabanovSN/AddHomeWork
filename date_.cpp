#include "date_.h"
#include<math.h>
#include<iomanip>

int Date_::day_of_year (int y, int m, int d)
{
int i, leap;
leap = getLeap(y) ;// индекс в массиве daytab 0 невысокосный, 1 высокосный
for (i = 1; i < m; i++)
d += daytab[leap][i];
return d;
}
int Date_::get_fulldays_ofyears(int year1,int year2){
    int all_days_of_year= 0;
    while(year1++<year2) //добираем дни полных годов
        if(getLeap(year1))
             all_days_of_year +=366;
        else
             all_days_of_year +=365;
    return all_days_of_year;

}
int Date_::operator-(Date_ &d2){
    int all_days_of_year= 0; //на случай если годa разные
    int yearNew;
    int firstD, secondD, sum_in_oneYear=0;
    if(year<d2.year){
         all_days_of_year= get_fulldays_ofyears( year, d2.year);
        yearNew = d2.year;//  выравниваем года по 2му году
    }
 else if (d2.year<year) {
         all_days_of_year = get_fulldays_ofyears(d2.year, year);
         yearNew = year;//  выравниваем года по 1му году
     }
    else
         yearNew = year;// //  выравниваем года по 1му году  т.к. года рaвны
        firstD = day_of_year(yearNew,month,day); // кол дней от начала года 1-я дата
        secondD = day_of_year(yearNew,d2.month,d2.day);// кол дней от начала года 2-я дата
        sum_in_oneYear = abs(firstD-secondD); // их разность по модолю
    return all_days_of_year + sum_in_oneYear;// сумма разных годов и сумма разности в одном годе
}
Date_ Date_::operator+(int days_){
    int days = days_; // пересохраняем так как будем её изменять
    Date_ newDate(*this);
    int leap = getLeap(year);      //проверка на высокосный год
    // дней до конца месяца
    if( (day + days) <= daytab[leap][month]){
        newDate.day +=days;
        return newDate;
    }else{
        int d = daytab[leap][month] - day; // остаток дней текущего месяца
         newDate.day +=d;
         days -=d;
    }

    // дней до конца года
    for(int i= month+1;i<=12;i++){
        if( days<= daytab[leap][i]){
            newDate.month=i; // устанавливаем новое занчение месяца
            newDate.day = days;// остаток дней
             return newDate;
        }else{
             newDate.month=i;
             days -= daytab[leap][i];
        }
    }
    while(days){ //если дни ещу остались добавляем год
              ++newDate.year;
              leap = getLeap(newDate.year);
              newDate.month=1; //январь нового года
              for(int i=1;i<=12;i++){
                  if( days<= daytab[leap][i]){
                      newDate.month=i; // устанавливаем новое занчение месяца
                      newDate.day = days;// остаток дней
                       return newDate;
                  }else{
                       newDate.month=i;
                       days -= daytab[leap][i];
                  }
              }
    }
    return newDate;
}
istream& operator>> (istream &in, Date_ &d){
    cout<<" Введите день "<<endl;
    int i; in>>i;
    while(i<1 || i>31 ){
        cout<<"День должен быть от 1 до 31, повтор попытки"<<endl;
        in>>i;
    }
    d.day=i;

    cout<<" Введите месяц (1-12) "<<endl;
    in>>i;
    while(i<1 || i>12 ){
        cout<<"Месяц должен быть от 1 до 12, повтор попытки"<<endl;
        in>>i;
    }
    d.month=i;
    cout<<" Введите год в формате YYYY"<<endl;
    in>>i;
    while(i<0){
        cout<<"Год должен быть больше 0, повтор попытки"<<endl;
        in>>i;
    }
    d.year=i;

    return in;
}
ostream& operator<< (ostream &out, const Date_ &d){
    out.fill('0');
    out<<setw(2)<<d.day<<": "<<d.months[d.month]<<" :"<<d.year<<endl;
    return out;
}
