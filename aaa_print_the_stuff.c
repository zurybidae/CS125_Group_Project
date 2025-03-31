#include <stdio.h>


//This code allows the player to guess the correct word. If they guess the entire word correctly then the word will be printed,
// but if they guess it wrong the word will be printed with underscores instead of letters.


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


//This code is the animation for the hangman game. For every incorrect guess the player makes, the hangman will get another limb. 
//After six incorrect guesses the hangman will be complete and the player will lose.


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


