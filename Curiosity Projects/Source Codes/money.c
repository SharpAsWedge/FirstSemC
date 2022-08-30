#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float net_income(int);
void calculation(float);
void readable(float);
void eachpart(int,int);

int main(){
    int doit=1,num;
    float income[20],total=0;
    system("cls");
    puts("\t\tFamily wealth calculation algorithm");
    puts("\t\t____________________________________\n\n");
    puts("Do you want to begin? Press Enter");
    getchar();
    system("cls");
    puts("How many members in the family earn?");
    scanf("%d",&num);
    for (int i=0;i<num;i++){
    income[i]=net_income(i);
    total+=income[i];
    }
    while(doit=1){
        calculation(total);
        puts("Do you want to do it again?");
        puts("1. Calculate again\n2. Exit");
        scanf("%d",doit);
        if(doit==2)
        return 0;
    }
    return 0;
}

float net_income(int person){
    int inc,rent,food,other,chk;
    float tax,net;
    printf("For the #%d memeber of the family\n",person+1);
    puts("______________________________________\n\n");
    puts("Monthly(1) or yearly(2) income?");
    scanf("%d",&chk);
    puts("Then the income:");
    scanf("%d",&inc);
    if(chk==1) inc*=12;
    puts("Tax rate:");
    scanf("%f",&tax);
    puts("Rent monthly:");
    scanf("%d",&rent);
    puts("Food expense per day:");
    scanf("%d",&food);
    puts("Other expense per month:");
    scanf("%d",&other);
    puts("_____________________________________________\n\n");
    net=inc*(1-tax/100)-12*rent-365*food-12*other;
    return net;
}

void calculation(float net){
    float rate,princ;
    int time;
    puts("Enter the rate of interest");
    scanf("%f",&rate);
    puts("How many years to keep in bank?");
    scanf("%d",&time);
    princ=net;
    for (int y=1;y<=time;y++){
        princ*=(1+rate/100)*0.97;
        if(y!=time) princ+=net;
    }
    puts("After that time, total money in the family:");
    readable(princ);
    printf("\n");
}

void readable(float money){
    float test=money;
    int deci,part[5];
    int testint=1,parts=0;
        deci=(int)(test*100)%100;
        deci=abs(deci);
        testint=(int)test;
        for(int i=0;testint!=0;i++){
            part[i]=testint%1000;
            testint/=1000;
            parts++;
        }

    puts("In figures:");
    for(int i=parts;i>0;i--){
        printf("%03d,",part[i-1]);
    }
    printf("\b.%d",deci);

    puts("\nIn words:");
    while (parts>0){
    eachpart(part[parts-1],parts);
    parts--;
    }
}

void eachpart(int part,int num){
    int ones,tens,hundreds,two;
    char first[19][20]={
        "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
    };
    char ten[8][20]={
        "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
    };
    char partstring[5][20]={
        "","Thousand","Million","Billion","Trillion"
    };
    two=part%100;
    if (two>19){
        ones=two%10;
        tens=two/10;
    }
    hundreds=part/100;

    if (hundreds!=0)
    printf("%s Hundred ",first[hundreds-1]);

    if(two<20)
    printf("%s",first[two-1]);
    else{
        printf("%s ",ten[tens-2]);
        if(ones!=0)
        printf("%s ",first[ones-1]);
    }
    printf("%s ",partstring[num-1]);
}
