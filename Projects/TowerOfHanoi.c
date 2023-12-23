//Code to perform Tower of Hanoi algorithm with visuals
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<conio.h>

int i,j,n;
int *S,*H,*D;

void transfer(int *,int *);
void toh(int n, int *s, int *h, int *d);
void printtoh(int *, int *, int *);

int main()
{
    printf("Enter number of disks: ");
    scanf("%d",&n);

    //creating 3 arrays for 3 towers of given length
    int A[n],B[n],C[n];

    //Getting the address of each array globally
    S=A,H=B,D=C;

    //Initializing first array with n numbers or loops
    for(i=0;i<n;i++){
        A[i]=i+1;
        B[i]=C[i]=0;
    }

    //Printing all the towers
    printtoh(A,B,C);

    //Calling the recursive function
    toh(n,A,B,C);
    printf("\nSolved");
    getch();
    return 0;
}

//This function is the recursive function which solves the tower
void toh(int r, int *s, int *h, int *d){
    if(r==1){
        transfer(s,d);
        printtoh(S,H,D);
        return;
    }
    toh(r-1,s,d,h);
    transfer(s,d);
    printtoh(S,H,D);
    toh(r-1,h,s,d);
}

//This function is responsible for transfering the numbers/loops
void transfer(int *s, int *d){
    int *disk, *loc;
    for(i=0;i<n;i++){
        if(s[i]==0)
            continue;
        else{
            disk=&s[i];
            break;
        }
    }
    for(i=n-1;i>=0;i--){
        if(d[i]==0){
            loc=&d[i];
            break;
        }
        else
            continue;
    }
    *loc=*disk;
    *disk=0;
    return;
}

//This function prints the current state of all towers
void printtoh(int *s, int *h, int *d){;
    system("cls");
    for(i=0;i<n;i++){
        if(s[i]==0)
            printf("_  ");
        else
            printf("%d  ",s[i]);
        if(h[i]==0)
            printf("_  ");
        else
            printf("%d  ",h[i]);
        if(d[i]==0)
            printf("_  ");
        else
            printf("%d  ",d[i]);
        printf("\n");
    }

    //Added to wait microseconds so we can see the towers solving
    usleep(800000);
}