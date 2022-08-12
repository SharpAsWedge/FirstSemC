#include "tohide.h"

int main(){
    int cur, alph[26]={0};
    char curr;
    char which;
    int doornot=1;
    char filename[20];
    vpos();
    hpos();printf("------------------SCRAWLER--------------------\n\n");
    hpos();printf("A basic text analysis project using C Lang\n\n");
    hpos();printf("A project created by:\n");
    hpos();printf("1. Arun Chandra Bhusal (BEI007)   - Coding portion\n");
    hpos();printf("2. Unmesh Subedi (BEI045)         - Debugging\n");
    hpos();printf("3. Sulav Kandel (BEI041)          - Project Idea and Features\n");
    hpos();printf("4. Ganesh Rokaya (BEI013)         - UI/UX\n\n");
    hpos();printf("To start the program, press any key....");
    getch();

    system("cls");
    vpos();hpos();rowborder();
    hpos();printf("Welcome to our program.\n\n");
    hpos();printf("Here we allow you to check characters/string you have in any text file\n\n");
    hpos();printf("The file should be located in the same folder as this source file\n\n");
    hpos();printf("Put your desired text there first\n\n");
    hpos();printf("When you are ready, press any key to continue...\n");hpos();rowborder();
    getch();

    file_input(filename);

    FILE *fp=fopen(filename,"r");
    if (fp==NULL){
        fprintf(stderr,"Error opening the file");
        return -1;
    }

    while (getc(fp)!=EOF){
        cur=getc(fp);
        curr=tolower(cur);
        check(curr,alph);
    }

    while (doornot==1){
    system("cls");
    vpos();hpos();rowborder();
    hpos();printf("What do you want to do? The options are:\n\n");
    hpos();printf("1. Display the tally of all character occurences\n");
    hpos();printf("2. Display the statistics of the text file\n");
    hpos();printf("3. Search for occurences of a string in the file\n\n");
    hpos();printf("Enter your choice:\n");hpos();rowborder();

    which=getchar();

    system("cls");
    vpos();

    switch (which){
    case '1':
        tally(alph);
        printf("\n\nDo you want to do something else?(y/n)");
        if (getch()=='y') continue;
        doornot=0;
        break;
    case '2':
        statistics(alph);
        printf("\n\nDo you want to do something else?(y/n)");
        if (getch()=='y') continue;
        doornot=0;
        break;
    case '3':
        searchword(fp);
        printf("\n\nDo you want to do something else?(y/n)");
        if (getch()=='y') continue;
        doornot=0;
        break;
    default:
        printf("Please enter a valid value\n\n");
        continue;
    }

    }

    fclose(fp);vpos();
    hpos();printf("\nThank you for using our program!");getch();
    return 0;
}

void tally(int *alph){
    int i,j;
	hpos();printf("The graphical representation will be like this: \n");hpos();rowborder();
    for (i=0;i<26;i++){
    	hpos();printf("%c:\t",(i+'a'));
        for (j=0;j<=*(alph+i);j++){
            printf("|");
        }
        putchar('\n');
    }
    hpos();rowborder();
}

void statistics(int *alph){
    printf("%d",*(alph+0));
   int cur,i;
    int tot=0,max=0,min=10000;
    float avg,perc;
    char maxchar,minchar;
    vpos();
    for (i=0;i<26;i++){
        cur= *(alph+i);
        if (cur>max){
            max=cur;
            maxchar=i+'a';
        }
        else if (cur<min){
            min=cur;
            minchar=i+'a';
        }
        tot+=cur; 
    }
    hpos();printf("The total number of characters in the given file is: %d\n",tot);
    hpos();printf("The character %c appears the most i.e. %d times\n",maxchar,max);
    hpos();printf("The character %c appears the least i.e. %d times\n\n",minchar,min);
    avg=tot/26;
    hpos();printf("The average number of repititions is: %.2f\n\n",avg);vpos();hpos();rowborder();
    for (i=0;i<26;i++){
        cur=*(alph+i);
        perc=((float)cur/tot)*100.0;
        hpos();printf("The percentage of %c in the total text file is: %.3f\n\n",(i+'a'),perc);
    }
    hpos();rowborder();
}

void check(char cur,int *alph){
    int i;
	for (i=0;i<26;i++){
        if(cur>='a' && cur<='z'){
            if (cur==(char)(i+'a')) *(alph+i) +=1;
        }
    }
}

void file_input(char * filename){
    int len,i;
    char name[20];
    system("cls");vpos();
    hpos();printf("Enter the file name (no extension) you want to read from\n");
    hpos();printf("Extension must be .txt\n");
    hpos();scanf("%s",name);
    strcpy(filename,name);
    strcat(filename,".txt");
}

void searchword (FILE *fp){
    char word[50],fstring[50];
    int i=0,count=0;
    hpos();rowborder();
    hpos();printf("So you want to search for a word?\n");
    hpos();printf("Type the word you want to search:\n");
    hpos();printf(">>");scanf("%s",word);
    hpos();printf("Please wait while we search for all the entries...\n\n");
    while (getc(fp)!=EOF){
        if (getc(fp)!=' ' && getc(fp)!='\n' && getc(fp)!='.'){
            fstring[i]=getc(fp);
            i++;
        }
        else{
            if (strcmp(fstring,word)==0){
                count++;
            }
        }
    }
    hpos();printf("%d results found within the text file \n\n",count);
    hpos();rowborder();
}

void vpos(){printf("\n\n\n\n\n\n\n\n\n\n");}

void hpos(){ printf("\t\t\t");}

void rowborder(){ printf("*************************************************************************\n");}