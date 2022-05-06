#include <iostream>
#include <string>

// This code is crap ...does not work. GuessNonRecursive.cpp is the correct solution

using namespace std;

int myRound(double x, bool up)
{
   int baba = int(x);
   if(up)
   {
      if ((double)baba == x)
      {
         return 0;
      }
      else
      {
         return -1;
      }
   }
   else
   {
      if ((double)baba == x)
      {
         return 0;
      }
      else
      {
         return 1;
      }
   }
}

int guessAgain(int oldGuess, int oldDiff, bool higher)
{
   int guess, diff;
   if (higher)
   {
      if (oldDiff % 2 == 1)
      {
         diff =  int(oldDiff / 2.0);
         guess = oldGuess + diff + myRound(oldDiff / 2.0, true);

      }
      else
      {
         diff = oldDiff / 2;
      }
      guess = oldGuess + diff; // different here (plus)
      std::cout << guess << std::endl;
      std::cout.flush();
   }
   else
   {
      if (oldDiff % 2 == 1)
      {
         diff =  int(oldDiff / 2.0);
         guess = oldGuess - diff + myRound(oldDiff / 2.0, true); // plus or minus here???
      }
      else
      {
         diff = oldDiff / 2;
         guess = oldGuess - diff;
      }
      std::cout << guess << std::endl;
      std::cout.flush();
   }

   string answer;
   std::cin >> answer;
   if (answer != "correct")
   {
      if (answer == "lower")
      {
         guessAgain(guess, diff, false);
      }
      else if (answer == "higher")
      {
         guessAgain(guess, diff, true);
      }
   }
   else // don't know if I need this else statement
   {
      return 0;
   }
   return 0;
}

int main()
{
   int guess = 500;
   std::cout << guess << std::endl;
   std::cout.flush();

   string answer;
   std::cin >> answer;
   if (answer != "correct")
   {
      if (answer == "lower")
      {
         guessAgain(guess, guess, false);
      }
      else if (answer == "higher")
      {
         guessAgain(guess, guess, true);
      }
   }
   else // don't know if I need this else statement
   {
      return 0;
   }
   return 0;
}