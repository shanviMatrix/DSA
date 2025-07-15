#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() 
{
    char email[100], ch;
    int i=0;

    printf("Enter your email: ");

    while(1) 
    {
        ch=getch();

        if(ch==13) 
        {  
            email[i]='\0';
            break;
        }

        if(ch==8 && i>0)
        { 
            i--;
            printf("\b \b");
        } 
        else 
        {
            email[i++]=ch;
            printf("*");
        }
    }

    printf("\n");

    if(strstr(email,"@gmail.com")!=NULL && strcmp(email+strlen(email)-10, "@gmail.com")==0) 
    {
        printf("Great! Gmail address is valid.\n");
    } 
    else 
    {
        printf("Invalid! Email must end with @gmail.com\n");
    }

    return 0;
}
