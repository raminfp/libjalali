#include <stdio.h>
#include <time.h>
#include <jalali/jalali.h>

int main(){

    int y, m, d;
    time_t bin_time;
    struct tm *br_time;

    time(&bin_time);
    br_time = localtime(&bin_time);

    gregorian_to_jalali(&y, &m, &d,1900+br_time->tm_year,1+br_time->tm_mon,br_time->tm_mday);

    printf("Current Jalali date: %d %s %d\n", d, j_month_name[m], y);
    
    printf("Current Jalali date with number month: %d %s %d\n", d, j_month_number[m], y);

    printf("Name Week Day : %s\n", fa_nameweekdays());

    return 0;
}
