/* This file is part of:
 *    Jalali, a Gregorian to Jalali and inverse date convertor
 * Copyright (C) 2001  Roozbeh Pournader <roozbeh@sharif.edu>
 * Copyright (C) 2001  Mohammad Toossi <mohammad@bamdad.org>
 * Copyright (C) 2017  Ramin Farajpour Cami <ramin.blackhat@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You can receive a copy of GNU Lesser General Public License at the
 * World Wide Web address <http://www.gnu.org/licenses/lgpl.html>.
 *
 * For licensing issues, contact The FarsiWeb Project Group,
 * Computing Center, Sharif University of Technology,
 * PO Box 11365-8515, Tehran, Iran, or contact us the
 * email address <FWPG@sharif.edu>.
 */

/* Changes:
 *
 * 2017-Jul-18:
 *	Added j_month_number, by Ramin Farajpour Cami
 *
 * 2017-Jan-07:
 *	Fixed a bug with change type variabel, by Ramin Farajpour Cami
 *
 * 2005-Sep-06:
 *      General cleanup  --Behdad Esfahbod
 *
 * 2001-Sep-21:
 *	Fixed a bug with "30 Esfand" dates, reported by Mahmoud Ghandi
 *
 * 2001-Sep-20:
 *	First LGPL release, with both sides of conversions
 */



/* prototypes */

void gregorian_to_jalali(/* output */ int *j_y, int *j_m, int *j_d,
                         /*  input */ int  g_y, int  g_m, int  g_d);
void jalali_to_gregorian(/* output */ int *g_y, int *g_m, int *g_d,
                         /*  input */ int  j_y, int  j_m, int  j_d);



/* implementation */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char name[10];
int g_days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int j_days_in_month[12] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
const char *j_month_name[13] = {"",
                                "Farvardin", "Ordibehesht", "Khordad",
                                "Tir", "Mordad", "Shahrivar",
                                "Mehr", "Aban", "Azar",
                                "Dey", "Bahman", "Esfand"};

const char *j_month_number[13] = {"",
                                "01", "02", "03",
                                "04", "05", "06",
                                "07", "08", "09",
                                "10", "11", "12"};


void gregorian_to_jalali(int *j_y, int *j_m, int *j_d,
                         int  g_y, int  g_m, int  g_d)
{
   int gy, gm, gd;
   int jy, jm, jd;
   long g_day_no, j_day_no;
   int j_np;

   int i;

   gy = g_y-1600;
   gm = g_m-1;
   gd = g_d-1;

   g_day_no = 365*gy+(gy+3)/4-(gy+99)/100+(gy+399)/400;
   for (i=0;i<gm;++i)
      g_day_no += g_days_in_month[i];
   if (gm>1 && ((gy%4==0 && gy%100!=0) || (gy%400==0)))
      /* leap and after Feb */
      ++g_day_no;
   g_day_no += gd;

   j_day_no = g_day_no-79;

   j_np = (int) j_day_no / 12053;
   j_day_no %= 12053;

   jy = (int)(979+33*j_np+4*(j_day_no/1461));
   j_day_no %= 1461;

   if (j_day_no >= 366) {
      jy += (j_day_no-1)/365;
      j_day_no = (j_day_no-1)%365;
   }

   for (i = 0; i < 11 && j_day_no >= j_days_in_month[i]; ++i) {
      j_day_no -= j_days_in_month[i];
   }
   jm = i+1;
   jd = (int)j_day_no+1;
   *j_y = jy;
   *j_m = jm;
   *j_d = jd;
}

void jalali_to_gregorian(int *g_y, int *g_m, int *g_d,
                         int  j_y, int  j_m, int  j_d)
{
   int gy, gm, gd;
   int jy, jm, jd;
   long g_day_no, j_day_no;
   int leap;

   int i;

   jy = j_y-979;
   jm = j_m-1;
   jd = j_d-1;

   j_day_no = 365*jy + (jy/33)*8 + (jy%33+3)/4;
   for (i=0; i < jm; ++i)
      j_day_no += j_days_in_month[i];

   j_day_no += jd;

   g_day_no = j_day_no+79;

   gy = (int) (1600 + 400*(g_day_no/146097));/* 146097 = 365*400 + 400/4 - 400/100 + 400/400 */
   g_day_no = g_day_no % 146097;

   leap = 1;
   if (g_day_no >= 36525) /* 36525 = 365*100 + 100/4 */
   {
      g_day_no--;
      gy += 100*(g_day_no/36524); /* 36524 = 365*100 + 100/4 - 100/100 */
      g_day_no = g_day_no % 36524;

      if (g_day_no >= 365)
         g_day_no++;
      else
         leap = 0;
   }

   gy += 4*(g_day_no/1461); /* 1461 = 365*4 + 4/4 */
   g_day_no %= 1461;

   if (g_day_no >= 366) {
      leap = 0;

      g_day_no--;
      gy += g_day_no/365;
      g_day_no = g_day_no % 365;
   }

   for (i = 0; g_day_no >= g_days_in_month[i] + (i == 1 && leap); i++)
      g_day_no -= g_days_in_month[i] + (i == 1 && leap);
   gm = i+1;
   gd = (int) g_day_no+1;

   *g_y = gy;
   *g_m = gm;
   *g_d = gd;
}


char *NameWeekDays(){

    int i;
    time_t rawtime;
    struct tm *info;
    char *en_days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri","Sun", "Sat"};
    const char *fa_days[7] = {"2Shanbeh", "3Shanbeh", "4Shanbeh", "5Shanbeh", "Joomeh", "Shanbeh", "1Shanbeh"};

    time( &rawtime );
    info = localtime( &rawtime );
    strftime(name,4,"%a", info);
    for (i = 0;i < sizeof(en_days) / sizeof(char); i++){
        if(strcmp(name, en_days[i]) == 0){
		    memmove(name, fa_days[i], 10);
            break;
        }
    }
    return name;
}


