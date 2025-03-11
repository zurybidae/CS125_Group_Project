#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

//00000000000000000000000 variables
char word[MAX];
char word2[MAX];
char filler[MAX];
char guess[MAX];
int i,length, number, input;
int count=0;
int wrong_guess=0;
int game_over=0;
int safe=0;



void word_picker(int x)//-----------------------------------------------------------------------------------------------------------------------------------------
{
  srand(time(NULL));
  int ran_num = rand()%5+1;

  if(x==1)    //animal
  {
    switch(ran_num)
    {
    case 1:
    {
      strcpy(word, "giraffe");
      break;
    }
    case 2:
    {
      strcpy(word, "bobcat");
      break;
    }
    case 3:
    {
      strcpy(word, "orca");
      break;
    }
    case 4:
    {
      strcpy(word, "quail");
      break;
    }
    case 5:
    {
      strcpy(word, "muskrat");
      break;
    }
    default:
    {
      printf("oops");
      break;
    }
    }
  }
  else if(x==2)  //places       
  {
    switch(ran_num)
    {
    case 1:
    {
      strcpy(word, "office");
      break;
    }
    case 2:
    {
      strcpy(word, "paris");
      break;
    }
    case 3:
    {
      strcpy(word, "wyoming");
      break;
    }
    case 4:
    {
      strcpy(word, "disneyland");
      break;
    }
    case 5:
    {
      strcpy(word, "playground");
      break;
    }
    default:
    {
      printf("oops");
      break;
    }
    }
  }
  else  //food 
  {
    switch(ran_num)
    {
    case 1:
    {
      strcpy(word, "cheese");
      break;
    }
    case 2:
    {
      strcpy(word, "bagel");
      break;
    }
    case 3:
    {
      strcpy(word, "eggs");
      break;
    }
    case 4:
    {
      strcpy(word, "apple");
      break;
    }
    case 5:
    {
      strcpy(word, "nachos");
      break;
    }
    default:
    {
      printf("oops");
      break;
    }
    }
  }
}


void guy_printer(int x) //-----------------------------------------------------------------------------------------------------------------------------------------
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
        
        game_over++;
    }
    
}

void letter_correct(char word2[])  //-----------------------------------------------------------------------------------------------------------------------------------------
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

void print(char word2[])  //-----------------------------------------------------------------------------------------------------------------------------------------
{
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

    
int main() //-----------------------------------------------------------------------------------------------------------------------------------------
{
    char their_choice[10];
    int choice;
    printf("Welcome to Hangman!\n\n");
    
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
    // for(int x=0; x<strlen(word) ;x++)
    // {
    //   printf("%c", word[x]);
    // }
    
    
    
    length=strlen(word);
    int *size = &length;
    //printf("%d", *size);
    
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
			
			printf("\n\nGuess the letter:\n");
			scanf(" %s", guess);
			
			if (isdigit(guess[0]))
			{
				input=1;
				printf("That is not a letter. Try Again.\n");
			}
			else if(strlen(guess)>strlen(word))
			{
			    input=1;
				printf("That guess is too long. Try Again.\n");
			}
			else
			{
				input=0;
			}

		} while(input==1);
        
        
        letter_correct(word2);
        if(safe==0)
        {
            wrong_guess++;
        }
        safe=0;
		guy_printer(wrong_guess);
		print(word2);
		
		if(game_over==1)
		{
		    printf("\nGame Over");
		    printf("\nThe word was %s", word);
		    break;
		}
	}while(strcmp(word,word2)!=0);
	
	
	if(game_over ==0)
	{
	    printf("\nSuccess! You guessed the word! \n");
	}

	return 0;
}
