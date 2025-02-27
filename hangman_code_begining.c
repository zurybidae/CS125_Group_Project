//2-27-2025
/*
*hello
*
*/


#include <stdio.h>
#include <string.h>
#include <time.h>

char word[15];



void word_picker(int x)
{
  strand(time(NULL));
  int ran_num = rand()%5+1;

  if(x==1)
  {
    //animal
    switch(ran_num)
    {
    case 1:
    {
      word={"giraffe"};
    }
    case 2:
    {
      word={"bobcat"};
    }
    case 3:
    {
      word={"orcha"};
    }
    case 4:
    {
      word={"quail"};
    }
    case 5:
    {
      word={"muskrat"};
    }
    default:
    {
      printf("oops");
    }
  }

  else if(x==2)
  {
    //places
  }
  else
  {
    //food 
  }

}



int main()
{
  int choice;
  printf("Welcome to Hangman!\n\n");
  printf("Chose a catagory of words:\n");
  printf("1) Animals  2) Places 3) Foods \n");
  scanf("%d", choice);                          //needs varificvation system

  
  if(

  return 0;
}
