
# Introduction
libjalali is a gregorian to jalali and inverse date convertor for C.

# Quick start guide

```C
#include <stdio.h>
#include <time.h>
#include <jalali/jalali.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAX_STRING 13
char DATE1[MAX_STRING];
char day[3];

//prototype 
//
int lenHelper(unsigned x);
int getLen(int x);

int main(){

    int y, m, d;
    time_t bin_time;
    struct tm *br_time;
    char c = (char) d;

    time(&bin_time);
    br_time = localtime(&bin_time);

    gregorian_to_jalali(&y, &m, &d,1900+br_time->tm_year,1+br_time->tm_mon,br_time->tm_mday);
    
    if (getLen(d) == 1)
        snprintf(day,3,"0%d",(int)d); 
    else
        snprintf(day, 3, "%d",(int)d);

    printf("Current Jalali date: %s %s %d\n", day, j_month_name[m], y);
    
    printf("Current Jalali date with number month: %s %s %d\n", day, j_month_number[m], y);

    printf("Name Week Day : %s\n", fa_nameweekdays());

    snprintf(DATE1, MAX_STRING, "%d/%s/%s", y,j_month_number[m],day);

    printf("Date now : %s\n",DATE1);

    return 0;
}

int getLen(int x) {
    return x < 0 ? lenHelper(-x)+1 : lenHelper(x);
}

int lenHelper(unsigned x) {
    if(x>=1000000000) return 10;
    if(x>=100000000) return 9;
    if(x>=10000000) return 8;
    if(x>=1000000) return 7;
    if(x>=100000) return 6;
    if(x>=10000) return 5;
    if(x>=1000) return 4;
    if(x>=100) return 3;
    if(x>=10) return 2;
    return 1;
}
```
```bash
[root@raminfp]# gcc -ljalali test.c -o test
[root@raminfp]# ./test
Current Jalali date: 28 Tir 1396
Current Jalali date with number month: 28 04 1396
Name Week Day : 4Shanbeh
Date now : 1396/04/28
```

# Installation
The first step is to get the lastest source and unzip it. run this command to configure libjalali for your system:i

```shell
[root@raminfp libjalali]# git clone https://github.com/raminfp/libjalali.git
[root@raminfp libjalali]# cd libjalali
[root@raminfp libjalali]# ./autogen.sh
```

```shell
[root@raminfp libjalali]# ./configure
```
NOTE: if the configure file does not exist, run ./autogen.sh script.
The next step is building the various binary files. So, enter:


```shell
[root@raminfp libjalali]# cd src
[root@raminfp src]# make
```
Then login as root and run:
```shell
[root@raminfp libjalali]# cd src
[root@raminfp src]# make install
```


# Contributing Code
If you are capable of contributing code changes, we encourage you to do so. You can help us in different fields:
* Develop new features (see roadmap above)
* Testing and bug reports
* Improving Documentation
* ...

# Bugs
 Please use github [issues](https://github.com/raminfp/libjalali/issues) to report bugs.


