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

//the function word_picker is used to allow the player to choose what category of word they want, the player can enter a 1,2, or 3 and that corresponds to the word category 1=animals, 2=places, and 3=food,
//based on the number the player chooses then the code will open the text file for that category and (using randi) choose a word from the list.


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
     word[strcspn(word, "\n")] = '\0';     
     
     //Because we are reading in the words from a file with fgets, the char string will include a newline char that we don't want                                         
     //We fix this by using strcspn() (idea from geeks for geeks) which allows us to remove the newline char from the end of the word

  }


//This code checks if the letter the player guessed is correct. It also allows the player to try and guess the correct word if they think they know it,
// but they have to guess the word completely right in order to win.


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
     //This code helps with error checking, it stops the user from being able to enter anything other than the number 1, 2, or 3. This means the player can't enter multiple numbers, letters, or symbols.
     //After checking to make sure the player is following directions it then uses the word_picker function to select the word for the hangman game.

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
	       //isdigit is a  new code that we learned during this project, it checks whether the player entered a number.
               //In this code it is used as error checking, if the player entered anything other than a number they will be asked to try again.
               //We used the website https://stackoverflow.com/questions/1478932/check-if-user-inputs-a-letter-or-number-in-c to learn about the isdigit code

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
     

     //This code prints out instructions so that the player knows the rules of the game.

   
     printf("\nThis game works like most other games of hangman.\n");
     printf("Blank spaces will be displayed that show the length of the word\n");
     printf("and you will be prompted to guess letters (lowercase only, for your own sake).\n");
     printf("\e[0;33mBut beware!\e[0;37m\nYou only have 6 guesses before your man meets his maker!\n\n");
     printf("If you think you know the word you can take a shot at it, but this will cost a guess.\n\n");
     printf("Also no funny buisness with guessing numbers, characters, or more then one letter at a time.\n\n");
     printf("\e[0;31mIf you want to surive I recomend playing by the hangman's rules.\n");
     printf("Other than that...\n\n");
     sleep(2);
     printf("\e[0;35mHave fun!\n\n\n\n\e[0;37m");
    
     sleep(2);
        

     //This code prints out underscores for the length of the word, so that the player knows how many letters are in the word

 
     length=strlen(word);
     int *size = &length;
    
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

               //This code print out all the letters the player types so that they know which letters they have already entered.
               // It also has error checking so that numbers and symbols aren't written in the letter bank.
	       // It will not run the first time because no letters have been guessed

               
	       count++;
               word_bank[count]=guess[0];		
               if (count==0)
                 {
                    printf("\n");
                 }
               else 
	         {
                    printf("\n\nletter guessed = ");
                    for (b=0;b<40;b++)
                      {
                         if (isalpha(word_bank[b]) && !isupper(word_bank[b]))
		           {
                              printf("%c  ", word_bank[b]);
                           }
		      }
                 }


               //This code prompts the player to guess a letter. It has error checking so that the player can't enter symbols,numbers, or more than a certain amount of letters. 
               //It then starts the letter_correct function to check if the letter the player typed in is apart of the word.

					
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


          //This code decides whether the player wins or loses. If the player guesses the wrong letter six times then it is game over.
          //If the player successfully guesses the correct letters and finishes the word then they win. 
          //When the player types in the wrong letter then the code references an h file called guy_printer.h   


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
       } while(strcmp(word,word2)!=0);

		
     if(game_over ==0)
       {
          printf("\e[0;32m\n\nSuccess! You guessed the word! \n");
       }
     printf("\e[0;35m\n\nThanks for playing!\n\n\e[0;37m");
     return 0;
  }
