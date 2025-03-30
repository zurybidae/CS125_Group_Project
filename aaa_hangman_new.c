#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "guy_printer.h"

#define MAX 100

//00000000000000000000000 variables
char word[MAX];
char word2[MAX];
char filler[MAX];
char guess[MAX];
char word_bank[MAX];
int i,length, number, input;
int count=-1;
int wrong_guess=0;
int game_over=0;
int safe=0;
int b;



void word_picker(int x) //----------------------------------------------------------------------
{
  srand(time(NULL));
  int ran_num = rand()%5+1;

  if(x==1)    //animal
  {
    FILE *words = fopen("animal_words.txt","r");    
    for(i=0;i<ran_num;i++)
    {
        fgets(word,MAX,words);
    }
    
  }
  else if(x==2)  //places       
  {
    FILE *words = fopen("place_words.txt","r");    
    for(i=0;i<ran_num;i++)
    {
        fgets(word,MAX,words);
    }
    
  }
  else  //food 
  {
    FILE *words = fopen("food_words.txt","r");    
    for(i=0;i<ran_num;i++)
    {
        fgets(word,MAX,words);
    }

  }
  word[strcspn(word, "\n")] = '\0';      //from geeks for geeks
}


void letter_correct(char word2[])  //------------------------------------------
{
    if(strlen(guess)>1)
    {
        if(strcmp(guess,word)==0)
        {
            game_over = 0;
            strcpy(word2,guess);
        }
        else
        {
            strcpy(guess,"7777");
            printf("That is not the right word\n");
        }
    }
    for (i=0; i<length; i++)
	{
		if (guess[0]==word[i])
		{
			word2[i]=guess[0];
			safe++;
		}
		
	}
}


    
int main() //--------------------------------------------------------------------
{
    char their_choice[10];
    int choice;
    printf("\n\e[0;36mWelcome to Hangman!\n\n\e[0;37m");
    
    printf("Chose a catagory of words:\n");
    do
	{
		printf("1) Animals  2) Places  3) Foods \n");
                scanf(" %s", their_choice); 
		
		if (!isdigit(their_choice[0]))
		{
			input=1;
			printf("That is not a number. Try Again.\n");
		}
		else if(strlen(their_choice)!=1)
                {
                    printf("This is not a valid choice. Try Again.\n");
                    input=1;
                }
		else if(their_choice[0]=='1')
		{
			choice=1;
			input=0;
		}
		else if(their_choice[0] =='2')
                {
                    choice=2;
                    input=0;
                }
                else if(their_choice[0] =='3')
                {
                    choice=3;
                    input=0;
                }
                else
                {
                    printf("This is not a valid choice. Try Again.\n");
                    input=1;
                }
	} while(input==1);
    
   
    word_picker(choice);
    
    printf("\nThis game works like most other games of hangman.\n");
    printf("Blank spaces will be displayed that show the length of the word\n");
    printf("and you will be prompted to guess letters (lowercase only, for your own sake).\n");
    printf("\e[0;33mBut beware!\e[0;37m\nYou only have 6 guesses before your man meets his maker!\n\n");
    printf("If you think you know the word you can take a shot at it, but this will cost a guess.\n\n");
    printf("Also no funny buisness with guessing numbers, characters, or more then one letter at a time.\n\n");
    printf("\e[0;31mIf you want to surive I recomend playing by the hangman's rules.\n");
    printf("Other than that...\n\n");
    sleep(20);
    printf("\e[0;35mHave fun!\n\n\n\n\e[0;37m");
    
    sleep(2);
        
    length=strlen(word);
    int *size = &length;
    //printf("%s",word);               //testing tools
    //printf("%d\n", *size);
    
    for(i=0;i<*size;i++)
    {
        filler[i]='_';
        printf("%c ", filler[i]);
    }

    for(i=0;i<*size;i++)
    {
        word2[i]='x';
    }
	

	do
	{
		do
		{
			count++;

      word_bank[count]=guess[0];
			
      
			if (count==0)
			{
			    printf("\n");
			}
			else 
			{
			    printf("\n\nletter guessed = ");
			    for (b=0;b<7;b++)
			    {
			        if (isalpha(word_bank[b]) && !isupper(word_bank[b]))
		          {
                  printf("%c  ", word_bank[b]);
              }
			    }
			}
			
      
      
					
			printf("\n\nGuess the letter:\n");			
			scanf(" %s", guess);

			
			if(strlen(guess)>strlen(word))
			{
        input=1;
				printf("That guess is too long. Try Again.\n");
			}
      else if (isalpha(guess[0])&& !isupper(guess[0]))
			{
				input=0;
			}
			else if(isupper(guess[0]))
      {
        input=1;
        printf("This is upper case. Try Again.\n");
      }
      else
			{
				input=1;
        printf("That is not a letter. Try Again.\n");
			}

		} while(input==1);
        
        
        letter_correct(word2);
        if(safe==0)
        {
            wrong_guess++;
        }
        safe=0;
		guy_printer(wrong_guess);
		if (wrong_guess==6)
		{
		game_over++;
		}
		print(word2, length, filler);
		
		if(game_over==1)
		{
		    printf("\e[0;31m\n\nGame Over");
		    printf("\e[0;37m\nThe word was %s.", word);
		    break;
		}
	}while(strcmp(word,word2)!=0);
	
	
	if(game_over ==0)
	{
	    printf("\e[0;32m\n\nSuccess! You guessed the word! \n");
	}

  printf("\e[0;35m\n\nThanks for playing!\n\n\e[0;37m");
	return 0;
}
