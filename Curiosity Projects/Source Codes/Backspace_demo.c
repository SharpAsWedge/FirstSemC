#include <stdio.h>
#include <string.h>

int main(){
    char text[100]="PaScHiMaNcHaL";
    for (int i=0;i<=(strlen(text))/2;i++) //This allows members in a row to reach 1 and then terminate right after
    {
        for (int j=0;j<i;j++)  // Displaying blank space right before word to push it to the right
        {
            printf(" ");
        }

        printf("%s",text);   // Each time the full string is printed without any alternation

        for (int j=0;j<i;j++)
        {
            printf("\b\b");   //But it gets backspaced by 2 increasingly in every next line
        }

        for (int j=0;j<i;j++)
        {
            printf("  ");       //But since \b acts as an insertion tool rather than backspace, we need to add two spaces to cover
        }

        printf("\n");      //Goes to new line
    }
    int a=getchar();
    return 0;
}