#include <stdio.h>
#include <stdlib.h>

int winstatus(char *inp){
    int a=0;
    for (int i=0;i<6;i+=3){
     if ((inp[i]==inp[i+1] && inp[i]==inp[i+2]) ||
         (inp[i]==inp[i+3] && inp[i]==inp[i+6])||
         (inp[i]==inp[i+4] && inp[i]==inp[i+8]) || 
         (inp[i+2]==inp[i+4] && inp[i+2]==inp[i+6]))
        return 1;
    }

    for (int i=0;i<9;i++){
        if (inp[i]!='X' && inp[i]!='O')
            a=1;
    }
    if (a!=1)
    return 2;

    return -1;
}

int overwrite_check(char *inp,int input){
    if (inp[input]=='X' || inp[input]=='O')
    return 1;
    else
    return 0;
}

void board(char *inp){
    printf(" _______________________________________________\n\n");
    printf("|\t%c\t|\t%c\t|\t%c\t|\n\n",inp[0],inp[1],inp[2]);
    printf("|\t%c\t|\t%c\t|\t%c\t|\n\n",inp[3],inp[4],inp[5]);
    printf("|\t%c\t|\t%c\t|\t%c\t|\n\n",inp[6],inp[7],inp[8]);
    printf(" _______________________________________________\n");
}

int input(int i){
    int a,b;
    a=(i%2==0)?1:2;
    printf("\nPlayer number %d select your box:\t",a);
    scanf("%d",&b);
    return (b-1);
}

void main(){
    int a,b;
    char player_input[9]={'1','2','3','4','5','6','7','8','9'};
    printf("Welcome to the game of Tic Tac Toe by ACB\n");
    printf("In this game you compete against yourself\n");
    printf("Try to beat yourself and have fun\n");
        for (int i=0;i<9;i++){

            if (i>0)
                system("cls");

            printf("\n\nThe board now looks like this: \n\n");
            board(player_input);
            a=input(i);
            
            if (overwrite_check(player_input,a)==1){
                printf("The spot was already chosen as %c\nPlease  choose again \n\n",player_input[a]);
                i--;
                continue;
            }
            else if (a<0 || a>=9){
                printf("\nPlease enter a valid number that appears on the screen\n\n");
                i--;
                continue;
            }

            player_input[a]=(i%2==0)?'X':'O';

            for (int j=0;j<10;j++){
                printf("\n");
            }

            if (winstatus(player_input)>0){
                printf("\nFinal board status: \n\n");
                board(player_input);
                switch (winstatus(player_input))
                {
                case 1:
                    printf("\n\nThe player %d has won, Congratulations!\n",(i%2+1));
                    int hold=getchar(); 
                    hold=getchar();
                    break;
                case 2:
                    printf("\n\nThe match has ended in a draw. Thank you for playing");
                    hold=getchar();
                    hold=getchar();
                    break;
                default:
                    break;
                }
                
                break;
            }
        }
        
}