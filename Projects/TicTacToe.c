//Code to create tic tac toe.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int base(int a,char x);

int main()
{
    int x=0,o=0,end;
    char plr;
    printf("Press number to enter\n 1 | 2 | 3 \n-----------\n");    //Prints the game controls
    printf(" 4 | 5 | 6 \n-----------\n");   //printed in 3 lines just for fun, can be done in 1 line as well.
    printf(" 7 | 8 | 9 \n\nChoose X or O: ");
    scanf("%c",&plr);   //Select player type.
    system("cls");
    printf("\n   |   |   \n-----------\n");    //Prints the game controls
    printf("   |   |   \n-----------\n");   //printed in 3 lines just for fun, can be done in 1 line as well.
    printf("   |   |   \n\n");

    //Starts game according to player selected
    if(plr=='X' || plr=='x'){
        goto L1;
    }else{
        goto L2;
    }

    //Infinite loop runs until game is won or drawn
    while(1){
        L1:printf("Player X turn: ");
        scanf("%d",&x);
        end=base(x,'X');
        if(end==10){        //Checks if the game ended.
            printf("The game is draw.\n\n");
            break;
        }else if(end==1){
            printf("Player X won the game\n\n");
            break;
        }else if(end==-1){
            printf("Player O won the game\n\n");
            break;
        }else if(end==9){
            goto L1;
        }

        L2:printf("Player O turn: ");
        scanf("%d",&o);
        end=base(o,'O');
        if(end==10){        //Checks if the game ended again.
            printf("\nThe game is draw.\n\n");
            break;
        }else if(end==1){
            printf("\nPlayer X won the game\n\n");
            break;
        }else if(end==-1){
            printf("\nPlayer O won the game\n\n");
            break;
        }else if(end==9){
            goto L2;
        }
    }
    getch();
}

//This function tracs all the game data and refresh the board
int base(int a,char c){  //Real brain teasing technique to track players decisions.
    static int times=0;     //static data remembers previous values each time it is called.
    static char input[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};  //Table for printing X and O.
    static int trace[]={0,0,0,0,0,0,0,0,0};     //Traces different players, 0 if empty, 1 for x and -1 for o
    int i;
    int win[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};    //Winning possibilities indexes.

    //Checks invalid moves else changes the trace array for player's moves
    if(input[a-1]!=' '){
        printf("You cannot use that move.\n");
        return 9;
    }else{
        times++;
        if(c=='X'){
            trace[a-1]=1;
        }else{
            trace[a-1]=-1;
        }
    }

    system("cls");

    //Changes characters in printing table to be x or o accordingly
    input[a-1]=c;

    //Prints the table
    printf("\n %c | %c | %c \n-----------\n",input[0],input[1],input[2]);
    printf(" %c | %c | %c \n-----------\n",input[3],input[4],input[5]);
    printf(" %c | %c | %c \n\n",input[6],input[7],input[8]);

    //Checks if the winning possibilies occur and returns who won.
    for(i=0;i<8;i++){       
            int w1=win[i][0],w2=win[i][1],w3=win[i][2];
            if(trace[w1]==trace[w2] && trace[w1]==trace[w3]){
                return trace[w2];
            }
    }

    //If 9 moves have been done and none won already, it's a draw
    if(times==9){
        return ++times;
    }
}