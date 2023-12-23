#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
#include<unistd.h>

#define dash_f 'e'
#define dash_b 'q'
#define left 'a'
#define right 'd'
#define attack 'f'

int i,j,game_border,wall,enemy;//alien position=32

typedef struct Player{
    bool alive;
    int pos;
    //Spike position = {22,47,68}
    //Wall position ={10}
}plr;

void enviornment(plr *,bool);
void game(plr *, char);

int main()
{
    plr player;
    L1:player.alive=true;
    player.pos=0;
    game_border=10;
    wall=enemy=true;
    char move;
    printf("*************** Welcome to Chintu Fighter ***************\nHelp chintu cross the area.\nControls:-\n:- A to move left\n:- D to move right\n:- F to attack\n:- E to dash forward\n:- Q to dash backward\n\nPress any key to continue.\n");
    getch();
    system("cls");
    enviornment(&player,false);
    while(1){
        move=getch();
        if(move>='A' && move<='Z')
        move+=32;
        system("cls");
        game(&player,move);
        if(player.alive==false){
            printf("\nYou were killed.\nGame over.\nPress x to restart game.\nPress any other key to exit.");
            move=getch();
            if(move=='x'||move=='X'){
                system("cls");
                goto L1;
            }
            else
            break;
        }else{
            if(player.pos==82){
                printf("\nCongratulations! You completed the game, Chintu is now saved.\n");
                break;
            }
        }
    }
    getch();
    return 0;
}

void enviornment(plr *player,bool atk){
    printf("_______________________________________________________________________________________\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<=game_border;j++){
            if(j!=player->pos && j!=32 && j!=10 && (j!=22 && j!=47 && j!=68))
            printf(" ");
            else{
                if(j==player->pos){
                    if(i==0){
                        printf(" * ");
                        j+=2;
                        continue;
                    }
                    else if(i==1){
                        if(atk==false){
                            printf("L|-");
                            j+=2;
                        }
                        else{
                            printf("L|\\-");
                            j+=3;
                        }
                        continue;
                    }
                    else if(i==2){
                        printf("/ \\");
                        j+=2;
                        continue;
                    }
                }else if((j==22||j==47||j==68)){
                    if(i==2)
                    printf("/\\");
                    else printf("  ");
                    j+=1;
                }else if(j==10){
                    if(wall==true)
                    printf("|");
                    else
                    printf(" ");
                }else if(j==32 && player->pos!=32){
                    if(enemy==true){
                        if(i==1){
                            printf("Q__,");
                        }else if(i==2){
                            printf("/  \\");
                            
                        }
                        j+=3;
                    }else{
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777");
    if(atk==true){
        usleep(80000);
        system("cls");
        enviornment(player,false);
    }
}

void game(plr *player, char move){
    if(wall==true){
        game_border=10;
    }else{
        game_border=85;
    }
    bool atk=false;
    int spikes[]={22,23,47,48,68,69};
    if(move==left){
        if(player->pos!=0){
            player->pos-=1;
        }
    }else if(move==right){
        if(player->pos!=game_border-3){
            player->pos+=1;
        }
    }else if(move==attack){
        atk=true;
        if(player->pos==7){
            wall=false;
            game_border=85;
        }
        if(player->pos==28){
            enemy=false;
        }
    }else if(move==dash_f){
        if(player->pos<game_border-7){
            player->pos+=5;
        }
    }else if(move==dash_b){
        if(player->pos>=5){
            player->pos-=5;
        }
    }
    if(player->pos==29 && enemy==true){
        player->alive=false;
    };
    for(i=0;i<3;i++){
        for(j=0;j<6;j++){
            if(player->pos+i==spikes[j]){
                player->alive=false;
                break;
            }
        }
    }
    enviornment(player, atk);
}
