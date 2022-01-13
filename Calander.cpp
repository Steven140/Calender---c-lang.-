#include<stdio.h>
#include<stdlib.h>
int get_first_weekDay(int year)
{
	int day;
	day = (((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year)/400)+1)%7;
	return day;
}

int main()
{
	int year, startingDay, daysinMonth, month, weekDay=0, day=1;
	printf("Enter a year: ");
	scanf("%d",&year);
	
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int monthDays [] = {31,28,31,30,31,30,31,30,31,31,30,31};
	
	if((year%4==0 && year%100!=0) || year%400==0)	
	{
		monthDays[1] = 29;
				  }	      
				  
	startingDay = get_first_weekDay(year);
	for(month=0; month<12; month++)
	{
		daysinMonth = monthDays[month];
		
		printf("\n\n-------------%s-----------------\n" ,months[month]);
		printf("\nsun     mon     tue     wed     thu     fri     sat\n");
		
		for(weekDay=0; weekDay<startingDay; weekDay++)
		printf("       ");
		
		for(day=1; day<=daysinMonth; day++)
		{
			printf("  %5d", day);
			
			if(++weekDay>6)
			{
				printf(" \n");
				weekDay=0;
			}
			startingDay=weekDay;
		}
					  }			      
}
