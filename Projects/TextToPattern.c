//Code to convert text into pattern.
#include<stdio.h>
#include<conio.h>
#include<string.h>

void L1(char x);
void L2(char x);
void L3(char x);
void L4(char x);
void L5(char x);

int main()
{
    int i;
    char msg[25];
    printf("Enter a text(upto 15 letters only): ");
    scanf("%[^\n]%*c",msg);
    for(i=0;i<strlen(msg);i++){
        if(msg[i]>='a'&&msg[i]<='z'){
            msg[i]-=32;
        }
    }

    //Prints line 1
    for(i=0;i<=15;i++){
        L1(msg[i]);
    }

    //Prints line 2
    printf("\n");
    for(i=0;i<=15;i++){
        L2(msg[i]);
    }

    //Prints line 3
    printf("\n");
    for(i=0;i<=15;i++){
        L3(msg[i]);
    }

    //Prints line 4
    printf("\n");
    for(i=0;i<=15;i++){
        L4(msg[i]);
    }

    //Prints line 5
    printf("\n");
    for(i=0;i<=15;i++){
        L5(msg[i]);
    }

    printf("\n");
    getch();
}

//Prints pattern of line 1 according to alphabet
void L1(char x){
    if(x=='A'||x=='C'||x=='E'||x=='F'||x=='I'||x=='J'||x=='P'||x=='R'||x=='T'||x=='Z'){
        printf("##### ");
    }else if(x=='B'||x=='D'){
        printf("####  ");
    }else if(x=='G'|| x=='S'){
        printf(" #### ");
    }else if(x=='H'||x=='K'||x=='M'||x=='N'||x=='U'||x=='V'||x=='W'||x=='X'||x=='Y'){
        printf("#   # ");
    }else if(x=='L'){
        printf("#     ");
    }else if(x=='O'|| x=='Q'){
        printf(" ###  ");
    }else{
        printf("      ");
    }
    return;
}

//Prints pattern of line 2 according to alphabet
void L2(char x){
    if(x=='A'||x=='B'||x=='H'||x=='O'||x=='P'||x=='Q'||x=='R'||x=='U'||x=='V'||x=='W'){
        printf("#   # ");
    }else if(x=='C'||x=='E'||x=='F'||x=='G'||x=='L'||x=='S'){
        printf("#     ");
    }else if(x=='D'){
        printf(" #  # ");
    }else if(x=='I'||x=='J'||x=='T'){
        printf("  #   ");
    }else if(x=='K'){
        printf("#  #  ");
    }else if(x=='M'){
        printf("## ## ");
    }else if(x=='N'){
        printf("##  # ");
    }else if(x=='X'||x=='Y'){
        printf(" # #  ");
    }else if(x=='Z'){
        printf("   #  ");
    }else{
        printf("      ");
    }
    return;
}

//Prints pattern of line 3 according to alphabet
void L3(char x){
    if(x=='A'||x=='H'||x=='P'||x=='R'){
        printf("##### ");
    }else if(x=='B'||x=='E'||x=='F'){
        printf("####  ");
    }else if(x=='C'||x=='L'){
        printf("#     ");
    }else if(x=='D'){
        printf(" #  # ");
    }else if(x=='G'){
        printf("# ### ");
    }else if(x=='I'||x=='J'||x=='T'||x=='X'||x=='Y'||x=='Z'){
        printf("  #   ");
    }else if(x=='K'){
        printf("# #   ");
    }else if(x=='M'||x=='N'||x=='W'){
        printf("# # # ");
    }else if(x=='O'||x=='Q'||x=='U'||x=='V'){
        printf("#   # ");
    }else if(x=='S'){
        printf(" ###  ");
    }else{
        printf("      ");
    }
    return;
}

//Prints pattern of line 4 according to alphabet
void L4(char x){
    if(x=='A'||x=='B'||x=='G'||x=='H'||x=='M'||x=='O'||x=='U'){
        printf("#   # ");
    }else if(x=='C'||x=='E'||x=='F'||x=='L'||x=='P'){
        printf("#     ");
    }else if(x=='D'){
        printf(" #  # ");
    }else if(x=='I'||x=='T'||x=='Y'){
        printf("  #   ");
    }else if(x=='J'){
        printf("# #   ");
    }else if(x=='K'||x=='R'){
        printf("#  #  ");
    }else if(x=='N'||x=='Q'){
        printf("#  ## ");
    }else if(x=='S'){
        printf("    # ");
    }else if(x=='V'||x=='X'){
        printf(" # #  ");
    }else if(x=='W'){
        printf("## ## ");
    }else if(x=='Z'){
        printf(" #    ");
    }else{
        printf("      ");
    }
    return;
}

//Prints pattern of line 5 according to alphabet
void L5(char x){
    if(x=='A'||x=='H'||x=='K'||x=='M'||x=='N'||x=='R'||x=='W'||x=='X'){
        printf("#   # ");
    }else if(x=='B'||x=='D'||x=='S'){
        printf("####  ");
    }else if(x=='C'||x=='E'||x=='I'||x=='L'||x=='U'||x=='Z'){
        printf("##### ");
    }else if(x=='F'||x=='P'){
        printf("#     ");
    }else if(x=='G'){
        printf(" #### ");
    }else if(x=='J'){
        printf("###   ");
    }else if(x=='O'){
        printf(" ###  ");
    }else if(x=='Q'){
        printf(" ## # ");
    }else if(x=='T'||x=='V'||x=='Y'){
        printf("  #   ");
    }else{
        printf("      ");
    }
    return;
}