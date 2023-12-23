//Code to create a working calender
#include <stdio.h>
#include <conio.h>
int findDate(int, int, int, char);
void findMonth(int, int);
int findLeap(int);
int dateCheck(int, int, int);
int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char days[][10] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
void main()
{
    int date, month, year, choice;
    printf("Choose the following\n1. Search date  2. Search month\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter date, month and year: ");
        scanf("%d %d %d",&date, &month, &year);
        if(date<1 || month<1 || year<0 || month>12 || dateCheck(date,month,year) == 0){
            printf("The given date is invalid.\n");
        }else{
            findDate(date, month, year, 'd');
        }
    }else if(choice==2){
        printf("Enter month and year: ");
        scanf("%d %d",&month, &year);
        if(month<1 || month>12 || year<0){
            printf("The given month is invalid.\n");
        }else{
            findMonth(month, year);
        }
    }else{
        printf("Invalid option chosen\n");
    }
    getch();
}
int findLeap(int year){
    if((year%4==0 && year%100!=0) || year%400==0){
        return 1;
    }else{
        return 0;
    }
}
int findDate(int date, int month, int year, char finding){
    long long int datesToAdd=0, i;
    datesToAdd+=(365*3 + 366)*(year/4) + 365*(year%4);   //adds amount of days in 4 years since each 3 year is a non leap and 4th year is a leap year and then multiply by amount of 4 years in those years and adds remaining non leap year days
    for(i=0;i<month-1;i++){ //month
        datesToAdd+=monthDays[i];
        if(findLeap(year)==1 && i==1){  //just add an extra day in february if leap year
            datesToAdd+=1;
        }
    }
    datesToAdd+=date;   //date
    int finalDate = datesToAdd%7;
    if(finding =='d'){
        printf("\n%.2d-%.2d-%d is %s\n",date,month,year,days[finalDate]);
    }else if(finding=='m'){
        return finalDate;
    }
}
void findMonth(int month, int year){
    int firstdate = findDate(1,month,year,'m');
    printf("\nMon Tue Wed Thu Fri Sat Sun\n");
    int daysInMonth=monthDays[month-1];
    if(findLeap(year)==1 && month==2){  //just add an extra day if month is feb and leap year
        daysInMonth+=1;
    }
    firstdate+=firstdate>=0 && firstdate<=2?4:-3;   //Adjust the days array so that it prints from monday instead of friday
    int date=1;
    for(int i=0;i<6;i++){   //prints the month table
        for(int j=0;j<7;j++){
            if(date==1 && j<firstdate || date>daysInMonth){
                printf("    ");
            }else{
                printf(" %.2d ",date);
                date++;
            }
        }
        printf("\n");
    }
}
int dateCheck(int date, int month, int year){
    if((month==2 && monthDays[month-1]+findLeap(year)<date) || (month!=2 && monthDays[month-1]<date)) {
        return 0;
    }else{
        return 1;
    }
}