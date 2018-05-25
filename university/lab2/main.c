// lab2_mod1.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 6

void search2() {
	int arr[ARR_SIZE], right = ARR_SIZE - 1, left = 0, middle, i, x, flag = 0;
	cout << "Enter " << ARR_SIZE << " numbers: " << endl;
	for (i = 0; i < ARR_SIZE; i++) {
		cout << "-> ";
		cin >> arr[i];
	}

	cout << "Enter x: ";
	cin >> x;

	while (left <= right) {
		middle = (int)((left + right) / 2);

		if (arr[middle] == x) {
			flag = 1;
			break;
		}
		if (x > arr[middle]) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}

	if (flag) {
		cout << "index = " << middle << endl;
	}
	else {
		cout << "not found" << endl;
	}
}
 

int main()
{
	//START Variables

	int arrX[ARR_SIZE], a, i, j, tmp;
	int flag = 0;

	//END Variables
	
	cout << "Enter " << ARR_SIZE << " numbers" << endl;

	for (i = 0; i < ARR_SIZE; i++) {
		cout << "-> ";
		cin >> arrX[i];
	}

	cout << "Enter A: ";
	cin >> a;


	/*SEARCH - FIRST WAY*/
	cout << "Searching A... (first way)" << endl;
	for (i = 0; i<ARR_SIZE; i++) {
		if (arrX[i] == a) {
			cout << "index = " << i << endl;
			flag = true;
		}
	}

	if (flag == false) {
		cout << "Not Found" << endl;
	}


	/*SORTING START*/
	for (i = 1; i < ARR_SIZE; i++) {
		for (j = 0; j < ARR_SIZE - 1; j++) {
			if (arrX[j] < arrX[j + 1]) {
				tmp = arrX[j + 1];
				arrX[j + 1] = arrX[j];
				arrX[j] = tmp;
			}
		}
	}

	cout << endl;
	cout << "Array after sorting: ";

	for (i = 0; i < ARR_SIZE; i++) {
		cout << arrX[i] << " ";
	}

	cout << endl << endl;

	/*SEARCH - ANOTHER WAY*/
	cout << "Searching A... (another way)" << endl << endl;
	search2();



	return 0;
}


// lab2_mod1.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #include <conio.h>
// #include <iostream>
// using namespace std;

// #define ARR_SIZE 10

// int _tmain(int argc, _TCHAR* argv[])
// {
// 	//START Variables
	
// 	int arrX[ARR_SIZE], a, i, j, tmp, left, right, middle;
// 	bool flag = false;
	
// 	//END Variables
	
// 	cout << "Enter " << ARR_SIZE << " numbers" << endl;

// 	for( i = 0;i < ARR_SIZE;i++ ) {
// 		cout << "-> ";
// 		cin >> arrX[i];
// 	}

// 	cout << "Enter A: ";
// 	cin >> a;
	
// 	cout << "Searching A... (first way)" << endl;
// 	for( i=0;i<ARR_SIZE;i++) {
// 		if( arrX[i] == a ) {
// 			cout << "index = " << i << endl;
// 			flag = true;
// 		}
// 	}

// 	if(flag == false) {
// 		cout << "Not Found" << endl;
// 	}
	
// 	for( i = 1;i < ARR_SIZE;i++ ) {
// 		for( j = 0;j < ARR_SIZE - 1;j++ ){
// 			if(arrX[j] < arrX[j+1]) {
// 				tmp = arrX[j + 1];
// 				arrX[j + 1] = arrX[j];
// 				arrX[j] = tmp;
// 			}			
// 		}
// 	}
// 	cout << endl << endl;
	
// 	cout << "Searching A... (second way)" << endl;
// 	middle = 0;
// 	left = 0;
// 	right = ARR_SIZE - 1;
// 	flag = false;

	


// 	do {
// 		middle = right - ((right - left)/2);

// 		if(arrX[middle] < a) {
// 			left = middle + 1;
// 			//cout << "if 1" << left << endl;
// 		} else {
// 			right = middle - 1;
// 			//cout << "if 2" << right << endl;
// 		}
// 	} while ( (left <= right) && (arrX[middle] != a) );
	
// 	cout << "index 2: " << arrX[middle] << endl;
	
	


// 	/*while(left <= right) {
// 		middle = (int)((left+right)/2);
// 		//cout << "Left: " << left << endl;
// 		//cout << "Right: " << right << endl;
// 		//cout << "Middle: " << middle << endl;

// 		if(arrX[middle] == a) {
// 			flag = true;
// 			break;
// 			cout << "Middle: " << middle << endl;
// 		}

// 		if(a > arrX[middle]) {
// 			left = middle + 1;
// 			cout << "if 1" << left << endl;
// 		} else {
// 			right = middle - 1;
// 			cout << "if 2" << right << endl;
// 		}
		
// 		if(flag == true) {
// 			//cout << "index = " << middle << endl;
// 		} else {
// 			//cout << "Not Found" << endl;		
// 		}
// 	}
// */
// 	cout << endl << endl;
// 	cout << "Array after sorting: ";
// 	for( i = 0;i < ARR_SIZE;i++ ) {
// 		cout << arrX[i] << " ";
// 	}
// 	cout << endl;


// 	return 0;
// }
