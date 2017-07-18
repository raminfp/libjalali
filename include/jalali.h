#ifndef JALALI_H_INCLUDED
#define JALALI_H_INCLUDED


void gregorian_to_jalali(int *j_y, int *j_m, int *j_d,int  g_y, int  g_m, int  g_d);

void jalali_to_gregorian(int *g_y, int *g_m, int *g_d,int  j_y, int  j_m, int  j_d);

const char *j_month_name[13];

const char *j_month_number[13];

#endif //JALALI_H
