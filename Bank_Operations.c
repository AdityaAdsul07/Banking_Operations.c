#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BankAccount
{
    long accnum;
    char acctype;
    long accbal;
    int pin;
    char lastTrans[30];
};
struct BankAccount ac[5];
void Balance_check()
            {
                long acnum;
                int p;
                printf("\nEnter Your Account number:");
                scanf("%ld",&acnum);
                printf("\nEnter Your pin:");
                scanf("%d",&p);
                for(int i=0;i<5;i++)
                {
                    if(ac[i].accnum==acnum && ac[i].pin==p)
                    {
                        printf("\nBalance in your account is %ld",ac[i].accbal);
                    }

                }

            }
void Cash_withdrawal()
            {
                long cw,acnum;
                int p;
                printf("\nEnter your Account number:");
                scanf("%ld",&acnum);
                printf("\nEnter your pin:");
                scanf("%d",&p);
                for(int i=0;i<5;i++)
                {
                    if(acnum==ac[i].accnum && p==ac[i].pin)
                    {
                        printf("\nEnter amount you want to withdraw:");
                        scanf("%ld",&cw);
                        if(ac[i].accbal<cw)
                        {
                            printf("\nYou do not have sufficient funds.");
                        }
                        else
                        {
                            printf("\ntransaction succeful.");
                            ac[i].accbal=ac[i].accbal-cw;
                            printf("%ld is debited from account.current balance is %ld",cw,ac[i].accbal);
                        }
                    }
                }


            }
void Deposite()
{
    long acnum,dep;
    printf("\nEnter your account number:");
    scanf("%ld",&acnum);
    for(int i=0;i<5;i++)
    {
        if(ac[i].accnum==acnum)
        {
            printf("\nEnter amount to be deposite:");
            scanf("%ld",&dep);
            ac[i].accbal=ac[i].accbal+dep;
            printf("\n%ld is credited in your account.current balance is %ld",dep,ac[i].accbal);
        }
    }
}
void Change_Pin()
{
    long acnum;
    int p,np;
    printf("\nEnter your account number:");
    scanf("%ld",&acnum);
    printf("\nEnter your pin:");
    scanf("%d",&p);
    for(int i=0;i<5;i++)
    {
        if(acnum==ac[i].accnum && p==ac[i].pin)
        {
            printf("\Enter Your new pin:");
            scanf("%d",&p);
            printf("Confirm your pin:");
            scanf("%d",&np);
            if(np==p)
            {
                ac[i].pin=np;
                printf("Pin changed succesfully");

            }

        }
    }

}
void Change_actype()
{
    long acnum;
    int p;
    char ch;
    printf("\nEnter your account number:");
    scanf("%ld",&acnum);
    printf("Enter your pin:");
    scanf("%d",&p);
    for(int i=0;i<5;i++)
    {
        if(ac[i].accnum==acnum && ac[i].pin==p)
    {
        printf("which type of account you want:");
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='s' || ch=='S')
        {
            printf("Your account is now saving type");
        }
        else if(ch=='c' || ch=='C')
        {
            printf("Your account is now current type");
        }
        else{
            printf("no such type exists");
        }
    }
    }
}
void main()
{
    int ch;
    for(int i=0;i<5;i++)
    {
        printf("\nEnter Account Number:");
        scanf("%ld",&ac[i].accnum);
        fflush(stdin);
        printf("\nEnter Account Type:");
        fflush(stdin);
        scanf("%c",&ac[i].acctype);
        printf("\nEnter Account balance:");
        scanf("%ld",&ac[i].accbal);
        printf("\nEnter your pin:");
        scanf("%d",&ac[i].pin);
        printf("\nEnter Date of Transaction:");
        fflush(stdin);
        scanf("%s",&ac[i].lastTrans);
    }
    do
    {
        int ch;
        printf("\nEnter your choice:");
        printf("\n1-Balance inquiry:");
        printf("\n2- Cash Withdrawal:");
        printf("\n3-Deposite");
        printf("\n4-Pin change");
        printf("\n5-Change Account Type:");
        printf("\n6-Exit");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:Balance_check();
               break;

        case 2:Cash_withdrawal();
               break;
        case 3:Deposite();
               break;
        case 4:Change_Pin();
               break;
        case 5:Change_actype();
               break;
        case 6:exit(0);
               break;

        }
    }
    while(ch!=6);

}
