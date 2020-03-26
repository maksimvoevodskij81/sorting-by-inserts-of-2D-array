#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void showArr(int arr[][5], const int  SIZE_ROW, const int SIZE_COL);
void fillArr(int arr[][5], const int  SIZE_ROW, const int SIZE_COL);
void showar_1_D(int ar_1_D[],int SIZE_ar_1_D);
const int SIZE_ROW = 5;
const int SIZE_COL = 5;
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int arr[SIZE_ROW][SIZE_COL];
	int tmp = 0, keepIndex = 0;
	const int SIZE_ar_1_D = SIZE_ROW * SIZE_COL;
	int ar_1_D[SIZE_ROW * SIZE_COL] = {};
	int counter = 0;
	fillArr(arr, SIZE_ROW,SIZE_COL);
	showArr(arr, SIZE_ROW,SIZE_COL);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" ;
	for (int i = 0; i < SIZE_ROW ; i++)
	{	
		for (int j = 0; j < SIZE_COL; j++)
		{
			ar_1_D[counter] = arr[i][j];
			counter++;
		}
		cout << endl;
	}
	showar_1_D(ar_1_D,SIZE_ar_1_D);
	cout << endl;
	for (int i = 0; i < SIZE_ROW * SIZE_COL; i++)
	{
		tmp = ar_1_D[i];
		keepIndex = i;
		for (int j = i + 1; j < SIZE_ROW * SIZE_COL; j++)
		{
				if (tmp > ar_1_D[j])
				{
					tmp = ar_1_D[j];
					keepIndex = j;
				}
		}
		ar_1_D[keepIndex] = ar_1_D[i];
		ar_1_D[i]=tmp;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	showar_1_D(ar_1_D, SIZE_ar_1_D);
	cout << endl;
	for (int i = 0; i < SIZE_ROW * SIZE_COL; i++)
	{
		 arr[i/ SIZE_ROW][i% SIZE_COL]=ar_1_D[i]  ;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	showArr(arr, SIZE_ROW, SIZE_COL);
}
void showArr(int arr[][5], const int  SIZE_ROW, const int SIZE_COL)
{
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void fillArr(int arr[][5], const int  SIZE_ROW, const int SIZE_COL)
{
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			arr[i][j] = rand() % 50;

		}
	}
}
void showar_1_D(int ar_1_D[],int SIZE_ar_1_D)
{
	for (int i = 0; i < SIZE_ROW * SIZE_COL; i++)
	{
		cout << ar_1_D[i] << ",";
	}
}