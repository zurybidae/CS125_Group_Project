//2-27-2025
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

char word[15]={"nope"};



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
      strcpy(word, "whyoming");
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



int main()
{
  int choice;
  printf("Welcome to Hangman!\n\n");
  printf("Chose a catagory of words:\n");
  printf("1) Animals  2) Places 3) Foods \n");
  scanf("%d", &choice);                          //needs varificvation system

  word_picker(choice);
  printf("%s%s", word[0], word[1]);

  return 0;
}
