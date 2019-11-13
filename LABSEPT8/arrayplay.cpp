#include <iostream>
using namespace std;

int main()
{
   int a[2];
   int b[2];
   int c;
   int mysize;
   
   // dynamic array
   int* d;
   cout << "Enter the desired size of your array: ";
   cin >> mysize;
   d = new int[mysize];
   d[0] = 11;
   
   for(int i = 0; i < mysize; i++){
	   cout << d[i] << " " << endl;
   }
   cout << "number of bytes for an int: " << sizeof(c) << endl << endl;
   
   a[0] = 2; a[1] = 4; 
   b[0] = 3; b[1] = 5;
   a[4] = 7;       
   cout << "contents of a  " << "contents of b" << endl;
   for (int k = 0; k < 2; k++)
   {
       cout << a[k] << "                  " << b[k] << endl;
   }
   cout << endl << endl;
   
   cout << "         a         b     " << endl;
   cout << a << "       " << b << endl;
   
   
   return 0;
}