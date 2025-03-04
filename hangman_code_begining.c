//2-27-2025 started
//3-4-2025 finished into word picker

/*
*hello
*
*/


//https://stackoverflow.com/questions/1478932/check-if-user-inputs-a-letter-or-number-in-c 
//for checking is digit

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char word[50];



void word_picker(int x)
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
      strcpy(word, "orcha");
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
      strcpy(word, "disnyland");
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
      strcpy(word, "beagle");
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



int main()
{
  int choice;
  printf("Welcome to Hangman!\n\n");
  printf("Chose a catagory of words:\n");
  printf("1) Animals  2) Places  3) Foods \n");
  scanf("%d", &choice);                          //needs varificvation system

  word_picker(choice);
//   for(int x=0; x<strlen(word) ;x++)
//   {
//     printf("%c", word[x]);
//   }
  
  
  return 0;
}
