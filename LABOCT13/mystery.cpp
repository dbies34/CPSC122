// What does mystery do? Use Allocation Records to find out.
// Do NOT compile!!!!
// October 4

#include <iostream>

void mystery();
void printPrompt();
void printNewlines(int numberOfNewlines);

using namespace std;

int main()
{
   printNewlines(3);
   printPrompt();
   
   mystery();
   printNewlines(3);
   
   return 0;
}

void mystery()
{
   char achar;
   
   cin.get(achar);
   if (achar != '\n')
   { 
       mystery();
       cout << achar;
   } else {
       cout << "output> ";
   }

}

void printPrompt()
{
   cout << "input> ";
}

void printNewlines(int numberOfNewlines)
{
   for (int k = 0; k < numberOfNewlines; k++)
   {
      cout << endl;
   }
}