#include<stdio.h>

int getDayOfWeek (int day, int month, int year);
int getDayOfMonth (int month, int year);
void printCalender (int startDay, int daysOfMonth);
void printIntro(int month, int year);

int main()
{
    int year, month;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    int startDay = getDayOfWeek(1, month, year);
    int daysOfMonth = getDayOfMonth(month, year);
    printIntro(month, year);
    printCalender(startDay, daysOfMonth);
    return 0;
}

int getDayOfWeek (int day, int month, int year)
{
    int h, a, b, c, d;
    if(month==1 || month==2)
    {
        month+=12;
        year--;
    }
    a = 26*(month+1)/10;
    b = year/4;
    c = year/100;
    d = year/400;
    h = (day+a+year+b+6*c+d)%7;
    if(h==0) h=7;
    return h;
}

int getDayOfMonth (int month, int year)
{
    if(month==2)
    {
        if(year%4==0)
        {
            if(year%100==0)
            {
                if(year%400==0) return 29;
                return 28;
            }
            return 29;
        }
        return 28;
    }
    else if (month==4 || month==6 || month==9 || month==11) return 30;
    return 31;
}

void printCalender (int startDay, int daysOfMonth)
{
    printf("%-7s%-7s%-7s%-7s%-7s%-7s%-7s\n", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT");
    int i;
    int track=1;
    for (i=1; i<=daysOfMonth; track++)
    {
        if(track>=startDay)
        {
            printf("%-7d",i);
            i++;
            if(track%7==0) printf("\n");
        }
        else
        {
            printf("%-7s", " ");
        }
    }
    printf("\n");
    return;
}

void printIntro(int month, int year)
{
    printf("\nCalendar for:\n\n");
    switch (month)
    {
    case 1:
        printf("JANUARY");
        break;
    case 2:
        printf("FEBRUARY");
        break;
    case 3:
        printf("MARCH");
        break;
    case 4:
        printf("APRIL");
        break;
    case 5:
        printf("MAY");
        break;
    case 6:
        printf("JUNE");
        break;
    case 7:
        printf("JULY");
        break;
    case 8:
        printf("AUGUST");
        break;
    case 9:
        printf("SEPTEMBER");
        break;
    case 10:
        printf("OCTOBER");
        break;
    case 11:
        printf("NOVEMBER");
        break;
    case 12:
        printf("DECEMBER");
        break;
    }
    printf(", %d\n\n", year);
    return;
}


