#include <iostream>
#include <algorithm>
using namespace std;
int MinInRows[4] = {};
int MinInCol[4] = {};

int AssigningMatrix[4][4] = { 0 };
void printRowAndCol(int r[4], int col[4]) {
	cout << "\nR1 = " << r[0]<< "\nR2 = " << r[1]<< "\nR3 = " << r[2]<< "\nR4 = " << r[3]<< "\nCOL1 = " << col[0]<< "\nCOL2 = " << col[1]<< "\nCOL3 = " << col[2]<< "\nCOL4 = " << col[3] << '\n';
}
int FindMinInCol(int arr[4][4]) {
	int mincol[4] = {};
	for (int i = 0; i < 4; i++) mincol[i] = arr[0][i];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[j][i] < mincol[i]) mincol[i] = arr[j][i];
	for (int i = 0; i < 4; i++) MinInCol[i] = mincol[i];
	return 0;
}
void printarrr(int arr[4][4]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << arr[i][j] << '\t';
		cout << endl;
	}cout << endl;
}
void FindMinInRow(int arr[4][4]) {
	int minval[4] = {};
	for (int i = 0; i < 4; i++) minval[i] = arr[i][0];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[i][j] < minval[i]) minval[i] = arr[i][j];
	for (int i = 0; i < 4; i++) MinInRows[i] = minval[i];
}
void SubRow(int arr[4][4]) {
	for (int i = 0, k = 0; i < 4; i++, k++)
		for (int j = 0; j < 4; j++)
			arr[i][j] = arr[i][j] - MinInRows[k];
}
void SubCol(int arr[4][4]) {
	for (int i = 0, k = 0; i < 4; i++, k++)
		for (int j = 0; j < 4; j++)
			arr[j][i] = arr[j][i] - MinInCol[k];
}
void GetNumOfZeros(int arr[4][4], int& r1, int& r2, int& r3, int& r4, int& col1, int& col2, int& col3, int& col4) {
	int r[4] = { r1,r2,r3,r4 };
	int col[4] = { col1,col2,col3,col4 };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[i][j] == 0) {
				r[i]++;
				col[j]++;
			}
	r1 = r[0]; r2 = r[1]; r3 = r[2]; r4 = r[3];
	col1 = col[0]; col2 = col[1]; col3 = col[2]; col4 = col[3];
}
void GetNumOfZerosAndUncrossed(int arr[4][4], int Crossed[4][4], int& r1, int& r2, int& r3, int& r4, int& col1, int& col2, int& col3, int& col4) {
	r1 = r2 = r3 = r4 = col1 = col2 = col3 = col4 = 0;
	int r[4] = { 0,0,0,0 };
	int col[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[i][j] == 0 && Crossed[i][j] == 0) {
				r[i]++;
				col[j]++;
			}
	r1 = r[0]; r2 = r[1]; r3 = r[2]; r4 = r[3];
	col1 = col[0];  col2 = col[1]; col3 = col[2]; col4 = col[3];
}
int GetSmallestUncoverd(int arr[4][4], int Crossed[4][4]) {
	int smallest = 0x7FFFFFFF;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[i][j] < smallest && Crossed[i][j] == 0) smallest = arr[i][j];
	cout << "Smallest uncorssed: " << smallest << endl;
	return smallest;
}
void SubSmallestFromUncovered(int arr[4][4], int Crossed[4][4], int smallest) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (Crossed[i][j] == 0)
				arr[i][j] = (arr[i][j] - smallest);
}
void AddSmallestUncoverdToPivot(int arr[4][4], int Crossed[4][4], int smallest) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (Crossed[i][j] == -1)
				arr[i][j] = (arr[i][j] + smallest);
}
void OptimalAssigning2(int arr[4][4]) {
	for (int i = 0; i < 4; i++) // basically the assigning matrix!
		for (int j = 0; j < 4; j++)
			if (arr[i][j] == 0 && AssigningMatrix[i][j] == 0)
			{
				cout << "Worker number " << i + 1 << " Is Assigned to job : " << j + 1 << endl;
				int index_of_col_to_delet = j;
				for (int k = 0; k < 4; k++)
					AssigningMatrix[k][index_of_col_to_delet] = 1;
				break;
			}
}
void CompareMaxOfRowsAndCol(int RowMaxZeros, int ColMaxZeros, int IndexOfRowMaxZeros, int  IndexOfColMaxZeros, int CrossedArr[4][4], int& CoveringLines) {
	if (RowMaxZeros >= ColMaxZeros)
		for (int j = 0; j < 4; j++)
			CrossedArr[IndexOfRowMaxZeros][j] = CrossedArr[IndexOfRowMaxZeros][j] == 0 ? 1 : -1;
	else if (RowMaxZeros < ColMaxZeros)
		for (int j = 0; j < 4; j++)
			CrossedArr[j][IndexOfColMaxZeros] = CrossedArr[j][IndexOfColMaxZeros] == 0 ? 1 : -1;
	CoveringLines++;
}
int main()
{
	int arr[4][4] = { { 82,83,69,92 }, {77,37,49,92} , { 11,69,5,86 } , { 8,9,98,23  } };
	int arr2[4][4] = { { 2500, 4000, 3500 , 2500 } , {4000 , 6000, 3500, 3500} , {2000, 4000, 2500 , 2000} , {2300,1500,6969,2312} };
	//two examples of Matrices, program runs on " arr[4][4] " 
	// you can try running with any of the two arrays by naming it arr[4][4]
	int CoveringLines = 0;
	int SizeOfArr = 4;
	int r[4] = { 0,0,0,0 };
	int col[4] = { 0,0,0,0 };
	int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	int col1 = 0, col2 = 0, col3 = 0, col4 = 0;
	// 
	int rowmaxzeros[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	int colmaxzeros[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	// 
	FindMinInRow(arr);
	SubRow(arr);
	printarrr(arr);
	FindMinInCol(arr);
	SubCol(arr);
	printarrr(arr);
	GetNumOfZeros(arr, r1, r2, r3, r4, col1, col2, col3, col4);
	cout << " -------------111111111------- \n";
	r[0] = r1; r[1] = r2; r[2] = r3; r[3] = r4;
	col[0] = col1; col[1] = col2; col[2] = col3; col[3] = col4;
	printRowAndCol(r, col);
	int rowzeros[4] = { r1,r2,r3,r4 };
	int colzeros[4] = { col1,col2,col3,col4 };

	int indexofmaxzeros;
	//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
		if (rowzeros[i] > rowmaxzeros[0])
		{
			rowmaxzeros[0] = rowzeros[i];
			indexofmaxzeros = i;
		}
	cout << "Row with max zeros is ROW NUMBER: " << (indexofmaxzeros + 1) << " , and have " << rowmaxzeros[0] << " Zeros. " << endl;
	int CrossedArr[4][4] = { 0 };
	printarrr(CrossedArr);
	int maxzeroscol = 0;
	int indexofmaxzeroscol;
	//loop to get the index of the column with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
		if (colzeros[i] > colmaxzeros[0])
		{
			colmaxzeros[0] = colzeros[i];
			indexofmaxzeroscol = i;
		}

	cout << "COLUMN with max zeros is COL NUMBER: " << (indexofmaxzeroscol + 1) << " , and have " << maxzeroscol << " Zeros. " << endl;

	// for iterative 1: we again decide what cross first a column or a row
	//by comparing the rowsmaxzeros and colmaxzeros and then crossing the one
	//with the highest number of zeros FIRST, then search again!.
	CompareMaxOfRowsAndCol(rowmaxzeros[0], maxzeroscol, indexofmaxzeros, indexofmaxzeroscol, CrossedArr, CoveringLines);
	printarrr(CrossedArr);

	GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
	rowzeros[0] = r1; rowzeros[1] = r2; rowzeros[2] = r3; rowzeros[3] = r4;
	colzeros[0] = col1; colzeros[1] = col2; colzeros[2] = col3; colzeros[3] = col4;
	cout << "??????????-------------------- \n";
	r[0] = r1; r[1] = r2; r[2] = r3; r[3] = r4;
	col[0] = col1; col[1] = col2; col[2] = col3; col[3] = col4;
	printRowAndCol(r, col);
	int colmaxzeros2 = 0;
	int indexofcolmaxzeros2 = 0;
	for (int i = 0; i < 4; i++)  	//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
		if (colzeros[i] > colmaxzeros2)
		{
			colmaxzeros2 = colzeros[i];
			indexofcolmaxzeros2 = i;
		}
	cout << "col with max zeros is col num:  = " << (indexofcolmaxzeros2 + 1) << "\n";
	cout << "And has =" << colmaxzeros2 << " Zeors!!!!!" << endl;
	// int rowmaxzeros[1] = 0; 
	int indexofrowmaxzeros2 = 0;
	//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
		if (rowzeros[i] > rowmaxzeros[1])
		{
			rowmaxzeros[1] = rowzeros[i];
			indexofrowmaxzeros2 = i;
		}
	cout << "r0w with the maxzeros2 is row num = " << (indexofrowmaxzeros2 + 1) << "\n";
	cout << "And has = " << rowmaxzeros[1] << " Zeors!!!!!\n";
	// for iterative 2: we again decide what cross first a column or a row
	//by comparing the rowsmaxzeros2 and colmaxzeros2 and then crossing the one
	//with the highest number of zeros FIRST, then search again!.
	CompareMaxOfRowsAndCol(rowmaxzeros[1], colmaxzeros2, indexofrowmaxzeros2, indexofcolmaxzeros2, CrossedArr, CoveringLines);
	cout << "________iterative 2 - row or col with max zeros corssed!__________\n";
	printarrr(CrossedArr);
	cout << endl << CoveringLines << endl;
	GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
	cout << "PRINTED VALUES:    \n";
	rowzeros[0] = r1;rowzeros[1] = r2;rowzeros[2] = r3;rowzeros[3] = r4;
	colzeros[0] = col1;colzeros[1] = col2;colzeros[2] = col3; colzeros[3] = col4;
	cout << " -------------------- \n";
	r[0] = r1; r[1] = r2; r[2] = r3; r[3] = r4;
	col[0] = col1; col[1] = col2; col[2] = col3; col[3] = col4;
	printRowAndCol(r, col);
	cout << "----------------XXXX-------------END\n";
	//////////// ITERATIVE 33333333333333
	int colmaxzeros3 = 0; int tmp4 = 0;
	int indexofcolmaxzeros3 = 0;
	//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
		if (colzeros[i] > colmaxzeros3)
		{
			colmaxzeros3 = colzeros[i];
			indexofcolmaxzeros3 = i;
		}
	cout << "ITERATIVE 3 :  col with max zeros is col num:  = " << (indexofcolmaxzeros3 + 1) << "\n\n";
	cout << "\n\tAnd has =" << colmaxzeros3 << " Zeors!!!!!";
	int indexofrowmaxzeros3 = 0;
	//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
		if (rowzeros[i] > rowmaxzeros[2])
		{
			rowmaxzeros[2] = rowzeros[i];
			indexofrowmaxzeros3 = i;
		}
	cout << "ITERATIVE 3 :  row with max zeros is row num:  = " << (indexofrowmaxzeros3 + 1) << "\n";
	cout << "And has =" << rowmaxzeros[2] << " Zeors!!!!!\n";
	// for iterative 33333333333: we again decide what cross first a column or a row
	//by comparing the rowsmaxzeros2 and colmaxzeros2 and then crossing the one
	//with the highest number of zeros FIRST, then search again!.
	CompareMaxOfRowsAndCol(rowmaxzeros[2], colmaxzeros3, indexofrowmaxzeros3, indexofcolmaxzeros3, CrossedArr, CoveringLines);
	cout << "\n-----------AFTER ITERATIVE 3 : -----------\n";
	printarrr(CrossedArr);
	GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
	rowzeros[0] = r1;rowzeros[1] = r2;rowzeros[2] = r3;rowzeros[3] = r4;
	colzeros[0] = col1;colzeros[1] = col2;colzeros[2] = col3;colzeros[3] = col4;
	cout << "??????????-------------------- \n";
	r[0] = r1;r[1] = r2;r[2] = r3;r[3] = r4;
	col[0] = col1;col[1] = col2;col[2] = col3; col[3] = col4;
	printRowAndCol(r, col);
	// printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
	int colmaxzeros8 = 0;
	int indexofcolmaxzeros8 = 0;
	//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
		if (colzeros[i] > colmaxzeros8)
		{
			colmaxzeros8 = colzeros[i];
			indexofcolmaxzeros8 = i;
		}
	cout << "ITERATIVE 3 :  col with max zeros is col num:  = " << (indexofcolmaxzeros8 + 1) << "\n";
	cout << "And has =" << colmaxzeros8 << " Zeors!!!!!" << '\n';
	int indexofrowmaxzeros8 = 0;
	//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
		if (rowzeros[i] > rowmaxzeros[7])
		{
			rowmaxzeros[7] = rowzeros[i];
			indexofrowmaxzeros8 = i;
		}
	cout << "ITERATIVE 3 :  row with max zeros is row nummmmmmmmm:  = " << (indexofrowmaxzeros3 + 1) << "\n";
	cout << "And has =" << rowmaxzeros[2] << " Zeors!!!!!\n";
	if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && col1 == 0 && col2 == 0 && col3 == 0 && col4 == 0);
	else {
		CompareMaxOfRowsAndCol(rowmaxzeros[7], colmaxzeros8, indexofrowmaxzeros8, indexofcolmaxzeros8, CrossedArr, CoveringLines);
		printarrr(CrossedArr);
		GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
		cout << " \n\nCovering Lines: " << CoveringLines << endl;
		rowzeros[0] = r1;rowzeros[1] = r2;rowzeros[2] = r3;rowzeros[3] = r4;
		colzeros[0] = col1;colzeros[1] = col2;colzeros[2] = col3;colzeros[3] = col4;
		cout << " ??????????-------------------- \n";
		r[0] = r1;r[1] = r2;r[2] = r3;r[3] = r4;
		col[0] = col1;col[1] = col2;col[2] = col3;col[3] = col4;
		printRowAndCol(r, col);
	}
	if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && col1 == 0 && col2 == 0 && col3 == 0 && col4 == 0)
	{
		if (CoveringLines == SizeOfArr)
		{
			cout << "COVERING LINGES = SIZE OF MATRIX = " << SizeOfArr << endl;
			cout << "Optimal Solution accuired!\n\n";
			printarrr(arr);
			cout << "-------------------------------\n";
			OptimalAssigning2(arr);
		}
		else if (CoveringLines < SizeOfArr)
		{
			cout << "COVERING LINGES = " << CoveringLines << "  And SIZE OF MATRIX = " << SizeOfArr << "\n";
			cout << "Optimal Solution NOT YET accuired" << endl;
			int smallestUncovered = GetSmallestUncoverd(arr, CrossedArr);
			cout << "SMALLES UNCOVERED RECIVEDD:  " << smallestUncovered;
			SubSmallestFromUncovered(arr, CrossedArr, smallestUncovered);
			cout << "___________________________\n";
			printarrr(arr);
			AddSmallestUncoverdToPivot(arr, CrossedArr, smallestUncovered);
			cout << "___________________________999999999999....!!.....\n";
			printarrr(arr);
			GetNumOfZeros(arr, r1, r2, r3, r4, col1, col2, col3, col4);
			rowzeros[0] = r1;rowzeros[1] = r2;rowzeros[2] = r3;rowzeros[3] = r4;
			colzeros[0] = col1;colzeros[1] = col2;colzeros[2] = col3;colzeros[3] = col4;
			cout << "----------------XXXX-------------\n";
			r[0] = r1;r[1] = r2;r[2] = r3;r[3] = r4;
			col[0] = col1;col[1] = col2;col[2] = col3;col[3] = col4;
			printRowAndCol(r, col);
			int colmaxzeros4 = 0;
			int indexofcolmaxzeros4 = 0;
			//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
				if (colzeros[i] > colmaxzeros4)
				{
					colmaxzeros4 = colzeros[i];
					indexofcolmaxzeros4 = i;
				}
			cout << "ITERATIVE 4 :  col with max zeros is col numberrrr:  = " << (indexofcolmaxzeros4 + 1) << "\n";
			cout << "And has =" << colmaxzeros4 << " Zeors!!!!!\n";
			int indexofrowmaxzeros4 = 0;
			//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
				if (rowzeros[i] > rowmaxzeros[3])
				{
					rowmaxzeros[3] = rowzeros[i];
					indexofrowmaxzeros4 = i;
				}
			cout << "\n\n ITERATIVE 4 :  row with max zeros is row num:  = " << (indexofrowmaxzeros4 + 1) << "\n\n";
			cout << "\n\tAnd has =" << rowmaxzeros[3] << " Zeors!!!!!\n\n";
			int CrossedArr[4][4] = { 0 };
			CoveringLines = 0;
			CompareMaxOfRowsAndCol(rowmaxzeros[3], colmaxzeros4, indexofrowmaxzeros4, indexofcolmaxzeros4, CrossedArr, CoveringLines);
			cout << "\n\n-----------AFTER ITERATIVE 4 : -----------\n\n";
			printarrr(CrossedArr);
			GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
			rowzeros[0] = r1;rowzeros[1] = r2;rowzeros[2] = r3;rowzeros[3] = r4;
			colzeros[0] = col1;colzeros[1] = col2;colzeros[2] = col3;colzeros[3] = col4;
			cout << " ??????????-------------------- \n";
			r[0] = r1;r[1] = r2;r[2] = r3;r[3] = r4;
			col[0] = col1;col[1] = col2;col[2] = col3;col[3] = col4;
			printRowAndCol(r, col); 			// printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
			int colmaxzeros5 = 0; int tmp8 = 0;
			int indexofcolmaxzeros5 = 0;
			//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
			{
				tmp8 = colzeros[i];
				if (tmp8 > colmaxzeros5)
				{
					colmaxzeros5 = tmp8;
					indexofcolmaxzeros5 = i;
				}
			}
			cout << "\n\n ITERATIVE 5 :  col with max zeros is col numberrrr:  = " << (indexofcolmaxzeros5 + 1) << "\n\n";
			cout << "\n\tAnd has =" << colmaxzeros5 << " Zeors!!!!!";
			int indexofrowmaxzeros5 = 0;
			//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
				if (rowzeros[i] > rowmaxzeros[4])
				{
					rowmaxzeros[4] = rowzeros[i];
					indexofrowmaxzeros5 = i;
				}
			cout << "\n\n ITERATIVE 5 :  row with max zeros is row num:  = " << (indexofrowmaxzeros5 + 1) << "\n\n";
			cout << "\n\tAnd has =" << rowmaxzeros[4] << " Zeors!!!!!\n\n";
			CompareMaxOfRowsAndCol(rowmaxzeros[4], colmaxzeros5, indexofrowmaxzeros5, indexofcolmaxzeros5, CrossedArr, CoveringLines);
			cout << "\n\n-----------AFTER ITERATIVE 5 : -----------\n\n";
			printarrr(CrossedArr);
			GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
			cout << " ??????????----------555555---------- \n";
			rowzeros[0] = r1;rowzeros[1] = r2;rowzeros[2] = r3;rowzeros[3] = r4;
			colzeros[0] = col1;colzeros[1] = col2;colzeros[2] = col3;colzeros[3] = col4;
			r[0] = r1;r[1] = r2;r[2] = r3;r[3] = r4;
			col[0] = col1;col[1] = col2;col[2] = col3;col[3] = col4;
			printRowAndCol(r, col);
			int colmaxzeros6 = 0;
			int indexofcolmaxzeros6 = 0;
			//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
				if (colzeros[i] > colmaxzeros6)
				{
					colmaxzeros6 = colzeros[i];
					indexofcolmaxzeros6 = i;
				}
			cout << "\n\n ITERATIVE 6 :  col with max zeros is col numberrrr:  = " << (indexofcolmaxzeros6 + 1) << "\n\n";
			cout << "\n\tAnd has =" << colmaxzeros6 << " Zeors!!!!!";
			int indexofrowmaxzeros6 = 0;
			//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
				if (rowzeros[i] > rowmaxzeros[5])
				{
					rowmaxzeros[5] = rowzeros[i];
					indexofrowmaxzeros6 = i;
				}
			cout << "\n\n ITERATIVE 6 :  row with max zeros is row num:  = " << (indexofrowmaxzeros6 + 1) << "\n\n";
			cout << "\n\tAnd has =" << rowmaxzeros[5] << " Zeors!!!!!\n\n";
			CompareMaxOfRowsAndCol(rowmaxzeros[5], colmaxzeros6, indexofrowmaxzeros6, indexofcolmaxzeros6, CrossedArr, CoveringLines);
			cout << "\n\n-----------AFTER ITERATIVE 6 : -----------\n\n";
			printarrr(CrossedArr);
			GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
			rowzeros[0] = r1;rowzeros[1] = r2;rowzeros[2] = r3;rowzeros[3] = r4;
			colzeros[0] = col1;colzeros[1] = col2;colzeros[2] = col3;colzeros[3] = col4;
			cout << " ??????????-------------------- \n";
			r[0] = r1;r[1] = r2;r[2] = r3;r[3] = r4;
			col[0] = col1;col[1] = col2;col[2] = col3;col[3] = col4;
			printRowAndCol(r, col);
			int colmaxzeros7 = 0;
			int indexofcolmaxzeros7 = 0;
			//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
				if (colzeros[i] > colmaxzeros7)
				{
					colmaxzeros7 = colzeros[i];
					indexofcolmaxzeros7 = i;
				}
			cout << "\nITERATIVE 7 :  col with max zeros is col numberrrr:  = " << (indexofcolmaxzeros7 + 1) << "\n";
			cout << "And has =" << colmaxzeros7 << " Zeors!!!!!\n";
			int indexofrowmaxzeros7 = 0;
			//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
				if (rowzeros[i] > rowmaxzeros[6])
				{
					rowmaxzeros[6] = rowzeros[i];
					indexofrowmaxzeros7 = i;
				}
			cout << "ITERATIVE 7 :  row with max zeros is row num:  = " << (indexofrowmaxzeros7 + 1) << "\n";
			cout << "And has =" << rowmaxzeros[6] << " Zeors!!!!!\n";
			CompareMaxOfRowsAndCol(rowmaxzeros[6], colmaxzeros7, indexofrowmaxzeros7, indexofcolmaxzeros7, CrossedArr, CoveringLines);
			cout << "-----------AFTER ITERATIVE 7 : -----------\n";
			printarrr(CrossedArr);
			cout << "\n\nCOVERINGLINES : " << CoveringLines << endl;
			if (CoveringLines == SizeOfArr)
			{
				cout << "\n COVERING LINGES = SIZE OF MATRIX = " << SizeOfArr
					<< "\nnOptimal Solution accuired!!!!!!!!!!!????EWDFSCDSFD!\n\n";
				OptimalAssigning2(arr);
			}
		}
		else cout << "\nNO IF CONDITION APPLIEED???!!!!!\n\n";
	}
	return 0;
}
