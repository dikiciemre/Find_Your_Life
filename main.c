#include <stdio.h>
#include <time.h>



int main() {
    
    int day, month, year,hour,minute;
    printf("Please enter your birthday. (DD.MM.YYYY): ");
    scanf("%d.%d.%d", &day, &month, &year);
    
    printf("What Time did you born ? ");
    scanf("%d.%d",&hour,&minute);

    
    time_t now;
    time(&now);
    struct tm *now_date = localtime(&now);


    int your_year = now_date->tm_year + 1900 - year;
    int your_month = now_date->tm_mon + 1 - month;
    int your_day = now_date->tm_mday - day;
    int your_hours = now_date->tm_hour - hour;
    int your_minute = now_date->tm_min - minute;

    

    if (your_month < 0) {
        your_year--;
        your_month += 12;
    }
    if (your_day < 0) {
        your_month--;
        your_day += 30;
    }
    if (your_hours < 0) {
        your_day--;
        your_hours += 24;
    }
    if (your_minute < 0) {
        your_hours--;
        your_minute += 60;
    }

    // print the results
    printf("Your Age : %d year, %d month, %d day, %d hours, %d minute\n", your_year, your_month, your_day, your_hours,your_minute);

    return 0;
}
