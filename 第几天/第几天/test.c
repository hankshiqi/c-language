#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int islipyear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 29;
	else
		return 28;
}
int count_day(int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		return 28;
	}
}
int main()
{
	int year,month,day= 0;
	int lipyear = 0;
	int count = 0;
	int i = 0;
	scanf("%d%d%d", &year, &month, &day);
	int day_of_2 = islipyear(year);
	if (month == 1)
		count = day;
	if (month == 2)
		count = day + 31;
	for (i = 1; i < month; i++)
	{
		
		count += count_day(i);
	}
	count = count + day;
	if (day_of_2 == 29)
	{
		count++;
	}
	printf("%d\n", count);
	return 0;
}