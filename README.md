
# Introduction
libjalali is a gregorian to jalali and inverse date convertor for C.

# Quick start guide

```C
#include <stdio.h>
#include <time.h>
#include <jalali/jalali.h>

#define MAX_STRING 13
char DATE1[MAX_STRING];


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
    
    snprintf(DATE1, MAX_STRING, "%d/%s/%d", y,j_month_number[m],d);

    printf("Date now : %s\n",DATE1);

    return 0;
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


