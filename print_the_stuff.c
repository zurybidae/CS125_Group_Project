#include <stdio.h>

void print(char word2[], int length, char filler[])  //-----------------------------------------------------
{
    int i;    

    for(i=0;i<length;i++)
    {
        if (word2[i]!='x')
        {
           printf("%c ", word2[i]);
           
        }
        else
        {
            printf("%c ", filler[i]);
        }
    }
}


void guy_printer(int x) 
{
    
    if(x==0)
    {
        printf("    _ _   \n");
        printf("   |   |  \n");    
        printf("   |      \n");
        printf("   |      \n");
        printf("   |      \n");
        printf("___|_____ \n");
    }
    else if(x==1)
    {
        printf("    _ _   \n");
        printf("   |   |  \n");    
        printf("   |   0  \n");
        printf("   |      \n");
        printf("   |      \n");
        printf("___|_____ \n");
    }
    else if(x==2)
    {
        printf("    _ _   \n");
        printf("   |   |  \n");    
        printf("   |   0  \n");
        printf("   |   |  \n");
        printf("   |      \n");
        printf("___|_____ \n");
    }
    else if(x==3)
    {
        printf("    _ _   \n");
        printf("   |   |  \n");    
        printf("   |   0  \n");
        printf("   |  /|  \n");
        printf("   |      \n");
        printf("___|_____ \n");
    }
    else if(x==4)
    {
        printf("    _ _   \n");
        printf("   |   |  \n");    
        printf("   |   0  \n");
        printf("   |  /|\\ \n");
        printf("   |      \n");
        printf("___|_____ \n");
    }
    else if(x==5)
    {
        printf("    _ _   \n");
        printf("   |   |  \n");    
        printf("   |   0  \n");
        printf("   |  /|\\ \n");
        printf("   |  /   \n");
        printf("___|_____ \n");
    }
    else if(x==6)
    {
        printf("    _ _   \n");
        printf("   |   |  \n");    
        printf("   |   0  \n");
        printf("   |  /|\\ \n");
        printf("   |  / \\ \n");
        printf("___|_____ \n");
        
       
    }
    
}

