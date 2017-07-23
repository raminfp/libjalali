#include <stdio.h>
#include <time.h>
#include <jalali/jalali.h>
#include <string.h>
#include <stdlib.h>


#define MAX_STRING 13
char DATE1[MAX_STRING];
char day[3];

int main(){

    int y, m, d;
    time_t bin_time;
    struct tm *br_time;
    char c = (char) d;

    time(&bin_time);
    br_time = localtime(&bin_time);

    gregorian_to_jalali(&y, &m, &d,1900+br_time->tm_year,1+br_time->tm_mon,br_time->tm_mday);

    if (strlen(&c) == 0){
        snprintf(day,3,"0%d",(int)d);
    } 

    printf("Current Jalali date: %s %s %d\n", day, j_month_name[m], y);
    
    printf("Current Jalali date with number month: %s %s %d\n", day, j_month_number[m], y);

    printf("Name Week Day : %s\n", fa_nameweekdays());
    snprintf(DATE1, MAX_STRING, "%d/%s/%s", y,j_month_number[m],day);

    printf("Date now : %s\n",DATE1);

    return 0;
}
