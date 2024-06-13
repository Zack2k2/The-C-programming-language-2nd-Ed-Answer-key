#include <stdio.h>

int DayOfMountToDayOfYear(int year,int month,int day);
int DayOfYearToDayOfMonth(int year, int yearday, int *month, int *day);
char *MonthName(int n); //returns a pinter to the name of the month
int IsLeap(int year);


int IsLeap(int year) // returns true[1] if the year is leap false[0] othervise
{
    return (year%4==0 && year%100 != 0 || year % 400 == 0);
}

// static char __DayTable__[2][13]={  // A simple table describing days in mounts of year
//     {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // for non-leap years
//     {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // for leap years
// };
static char *DayTable[2] = {
    (char []) {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    (char []) {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
/*
 * The following function returns the name of the month
 * with corrosponding number
 */
char *MonthName(int n){
// The function must be a pointer to char
// because it is returning a pointer to a string
    char *Names[] = {
        "Illegal Month","January","Febuary","March","Aprail",
        "May","June","July","August","September","Octuber","November",
        "December"
    };

    return (n < 1 || n > 12) ? Names[0] : Names[n];
}

// Gives the day-th of the [year] by [month] and [day]
// returns a negative number if the input is some how invalid
// returns -1 if year is invalid
// retunes -2 if month is invalid
// returns -3 if day is invalid
int DayOfMountToDayOfYear(int year,int month,int day)
{
    if (year > 0 &&  year < 3999 )
    {
        int is_leap = IsLeap(year);
        if(month <= 12 && month >= 1 ){
            if (day < *(DayTable[is_leap]+month) && day > 0)
            // the above conditions make sure makes that month is valid
            {
                int i;
                for(i=1;i < month;i++) day += *(DayTable[is_leap]+i);
                return day;
            } else return -3;
        } else return -2;
    }else return -1;
}


int DayOfYearToDayOfMonth(int year, int yearday, int *month, int *day)
{
    int i;
    int TotalDaysInYear = 0;
    if(year > 0 &&  year < 3999 ) // No years after 3999
    {
        printf("%s\n",".." );
        int is_leap = IsLeap(year);
        for(i=1;i<=13;i++)
            TotalDaysInYear += *(DayTable[is_leap]+i);

        if(yearday > 0 && yearday <= TotalDaysInYear ){
            for(i=1;yearday > *(DayTable[is_leap]+i);i++)
                yearday -= *(DayTable[is_leap]+i);

        } else return -2;
    }else return -1;

    *month = i;
    *day   = yearday;
}

int main(int argc, char const *argv[]) {
    printf("the number of days %d\n",DayOfMountToDayOfYear(2013,4,23));
    int dayOftheyear = 123;
    int year = 2020;
    int m,d;
    DayOfYearToDayOfMonth(year,dayOftheyear,&m,&d);
    printf("the month: %d and %d\n",m,d);
    return 0;
}
