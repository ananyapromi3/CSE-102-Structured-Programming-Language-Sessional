#include<stdio.h>

void printDate(int day, int month, int year);
void printDayOfWeek (int day, int month, int year);

int main()
{
    int year, month, day;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);
    printDate(day, month, year);
    printf("is ");
    printDayOfWeek(day, month, year);
    printf("\n");
    return 0;
}

void printDayOfWeek (int day, int month, int year)
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
    switch (h)
    {
    case 0:
        printf("SATURDAY ");
        break;
    case 1:
        printf("SUNDAY ");
        break;
    case 2:
        printf("MONDAY ");
        break;
    case 3:
        printf("TUESDAY ");
        break;
    case 4:
        printf("WEDNESDAY ");
        break;
    case 5:
        printf("THURSDAY ");
        break;
    case 6:
        printf("FRIDAY ");
        break;
    }
    return;
}

void printDate(int day, int month, int year)
{
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
    printf(" %d, %d ", day, year);
    return;
}
