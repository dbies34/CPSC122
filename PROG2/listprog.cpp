// username: abies2
// Drew Bies
// listprog.cpp
// 9-11-17

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void createList(int*& listptr, int sizeOfList);
int findIndexOfLargest(int*& listptr, int& sizeOfList);
void printList(int* listptr, int sizeOfList, int swap1, int swap2);
int getListSize();
void printNewLines(int desiredNumber);
void printLargestOne(int number);
void swap(int& one, int& two);
void selectionSort(int*& list, int listSize);
void insertionSort(int list[], int listSize);
int search(int list[], int listSize, int target);
void checkIndex(int index1, int index2, int k);

int main(){
	
   int* listptr;
   int listSize;
   int largestGuy;
   int n = -1;
   
   printNewLines(3);
	
   int seed = time(0);
   srand(seed);
	
   listSize = getListSize();
   createList(listptr, listSize);
   printNewLines(2);
   selectionSort(listptr, listSize);
   printList(listptr, listSize, n, n);
   printNewLines(3);
   createList(listptr, listSize);
   insertionSort(listptr, listSize);
   printList(listptr, listSize, n, n);
   printNewLines(3);
   
   delete [] listptr;
   return 0;
}

void createList(int*& listptr, int sizeOfList){
   listptr = nullptr;
   listptr = new int [sizeOfList]; 
   for (int k = 0; k < sizeOfList; k++){
	  listptr[k] = rand() % 78;
   }
}

int findIndexOfLargest(int*& listptr, int& sizeOfList){
	int currentLargest;
	int where = 0;
	currentLargest = listptr[0];
	for (int k = 0; k < sizeOfList; k++){
		if(listptr[k] > currentLargest){
			currentLargest = *(listptr + k);
			where = k;
		}
	}
	return where;
}

void printList(int* listptr, int sizeOfList, int swap1, int swap2){
	cout << "The list:  ";
	for (int k = 0; k < sizeOfList; k++){
		if(*(listptr + k) < 10){
			cout << "      ";
		}else{
			cout << "     ";
		}
		checkIndex(swap1, swap2, k);		
		cout << *(listptr + k);
		checkIndex(swap1, swap2, k);
	}
	cout << endl;
}

int getListSize(){
	int size;
	cout << "Enter the size of your list -> ";
	cin >> size;
	return size;
}

void printNewLines(int desiredNumber){
	for (int k = 0; k < desiredNumber; k++){
		cout << endl;
	}
}

void printLargestOne(int number){
	cout << "Largest value is: " << number << endl;
}

void swap(int& one, int& two){
	int temp;
	
	temp = one;
	one = two;
	two = temp;
}

void selectionSort(int*& list, int listSize){
	cout << "Selection Sort: " << endl;
	cout << "Follow the \"*\" for which two numbers switch." << endl;
	int indexOfLargest;	
	for(int i = listSize; i > 0; i--){	
	    indexOfLargest = findIndexOfLargest(list, i);
		printList(list, listSize, indexOfLargest, i - 1);
	    swap(*(list + indexOfLargest), *(list + i - 1));
	}
	printNewLines(3);
	cout << "Sorted List: " << endl;
}

void insertionSort(int list[], int listSize){
	cout << "Insertion Sort: " << endl;
	cout << "Follow the \"*\" for which two numbers switch." << endl;
    for (int i = 1; i < listSize; i++){
        for (int j = i; j > 0 && list[j - 1] > list[j]; j--){
			printList(list, listSize, j, j - 1);
			swap(list[j], list[j -1]);
        }
    }
	printNewLines(3);
	cout << "Sorted List: " << endl;
}	

int search(int list[], int listSize, int target){
	for(int i = 0; i < listSize; i++){
		if(target == list[i]){
			return i;
		}
	}
    return -1;
}

void checkIndex(int index1, int index2, int k){
	if(index1 == k || index2 == k){
		cout << "*";
	}else{
		cout << " ";
	}
}