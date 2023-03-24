#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_left = 0;
int i;

if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
{
days_in_month[2] = 29; /* update days in February */
}

for (i = month; i <= 12; i++)
{
days_left += days_in_month[i];
}

days_left -= day;

if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
{
if (month < 3 || (month == 3 && day <= 1))
{
days_left += 1; /* leap year and before March 1st */
}
}

if (days_left == 0)
{
printf("Day of the year: %d\n", convert_day(month, day));
printf("Happy New Year!!!\n");
}
else if (days_left < 0)
{
printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
}
else
{
printf("Day of the year: %d\n", convert_day(month, day));
printf("Remaining days: %d\n", days_left);
}
}
