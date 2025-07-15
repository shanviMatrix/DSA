#include <stdio.h>
#include<conio.h>
#include <string.h>

int main() 
{
    char password[10], ch;
    int i=0;

    printf("Enter Password: ");

    while (1) 
    {
        ch=getch();  

        if(ch==13) 
        { 
            password[i]='\0';
            break;
        }

        if(ch==8 && i>0) 
        {  
            i--;
            printf("\b \b");
        } 
        else 
        {
            password[i++]=ch;
            printf("*");
        }
    }

    printf("\n");

    if(strcmp(password,"admin123")==0) 
    {
        printf("Access Granted!");
    } 
    else 
    {
        printf("Access Denied!");
    }

    return 0;
}
