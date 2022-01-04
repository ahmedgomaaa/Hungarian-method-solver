#include <iostream>
using namespace std;
int MinInRows[4] = {};
int MinInCol[4] = {};
int rowzeros[4]; 	
int colzeros[4];
int AssigningMatrix[4][4] = { 0 };
void printRowAndCol(int r1, int r2, int r3, int r4, int col1, int col2, int col3, int col4) {
	cout << "\nR1 = " << r1
	<< "\nR2 = " << r2
	<< "\nR3 = " << r3
	<< "\nR4 = " << r4
	<< "\nCOL1 = " << col1
	<< "\nCOL2 = " << col2
	<< "\nCOL3 = " << col3
	<< "\nCOL4 = " << col4
	<< '\n';
}

int FindMinInCol(int arr[4][4]) {
	int mincol[4] = {};
	mincol[0] = arr[0][0];
	mincol[1] = arr[0][1];
	mincol[2] = arr[0][2];
	mincol[3] = arr[0][3];
	for(int i=0;i<4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[j][i] < mincol[i]) mincol[i] = arr[j][i];
	MinInCol[0] = mincol[0];
	MinInCol[1] = mincol[1];
	MinInCol[2] = mincol[2];
	MinInCol[3] = mincol[3];
}
void printarrr(int arr[4][4]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
			cout << arr[i][j] << '\t';
		cout << endl;
	}
}
void FindMinInRow(int arr[4][4]) {
	int minval[4] = {};
	minval[0] = arr[0][0];
	minval[1] = arr[1][0];
	minval[2] = arr[2][0];
	minval[3] = arr[3][0];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[i][j] < minval[i]) minval[i] = arr[i][j];
	MinInRows[0] = minval[0];
	MinInRows[1] = minval[1];
	MinInRows[2] = minval[2];
	MinInRows[3] = minval[3];
}
void SubRow( int arr[4][4]) {
	for (int i = 0, k = 0; i < 4; i++, k++)
		for (int j = 0; j < 4; j++)
			arr[i][j] = arr[i][j] - MinInRows[k];
}
void SubCol(int arr[4][4]) {
	for (int i = 0, k=0; i < 4; i++, k++)
		for (int j = 0; j < 4; j++)
			arr[j][i] = arr[j][i] - MinInCol[k];
}
void GetNumOfZeros(int arr[4][4], int &r1, int &r2, int &r3, int &r4, int &col1, int &col2, int &col3,int &col4) {
	int r[4] = {};
	int col[4] = {};
	r[0] = r1;
	r[1] = r2;
	r[2] = r3;
	r[3] = r4;
	col[0] = col1;
	col[1] = col2;
	col[2] = col3;
	col[3] = col4;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[i][j] == 0) {
				r[i]++;
				col[j]++;
			}
	r1 = r[0];
	r2 = r[1];
	r3 = r[2];
	r4 = r[3];
	col1 = col[0];
	col2 = col[1];
	col3 = col[2];
	col4 = col[3];

}
void GetNumOfZerosAndUncrossed(int arr[4][4],int Crossed[4][4] ,int& r1, int& r2, int& r3, int& r4, int& col1, int& col2, int& col3, int& col4) {
	r1 = r2 = r3 = r4 = col1 = col2 = col3 = col4 = 0;
	int r[4] = { 0,0,0,0 };
	int col[4] = { 0,0,0,0 };
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0 && Crossed[i][j] == 0  ) {
				r[i]++;
				col[j]++;
			}
		}
	}
	r1 = r[0];
	r2 = r[1];
	r3 = r[2];
	r4 = r[3];
	col1 = col[0];
	col2 = col[1];
	col3 = col[2];
	col4 = col[3];

}
int max(int a, int b) {
	return (a > b) ? 1 : -1;
}
int GetSmallestUncoverd(int arr[4][4], int Crossed[4][4]) {
	int smallest = 0x7FFFFFFF;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] < smallest && Crossed[i][j] == 0) smallest = arr[i][j];
			
		}
	}
	cout << "Smallest uncorssed: " << smallest<<endl; 
	return smallest;
}
void SubSmallestFromUncovered(int arr[4][4], int Crossed[4][4], int smallest) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if ( Crossed[i][j] == 0 )
				arr[i][j] = ( arr[i][j] - smallest ) ;
}
void AddSmallestUncoverdToPivot(int arr[4][4], int Crossed[4][4], int smallest) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (Crossed[i][j] == -1)
				arr[i][j] = (arr[i][j] + smallest);
}
void OptimalAssigning2(int arr[4][4]) {
//	AssigningMatrix[4][4] = {0};
	for (int i = 0; i < 4; i++)
	{
		for (int  j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0 && AssigningMatrix[i][j] == 0 )
			{
				cout << "Worker number " << i + 1 << " Is Assigned to job : " << j + 1<<endl; 
				int index_of_col_to_delet = j;
				for (int k = 0; k < 4; k++)
					AssigningMatrix[k][index_of_col_to_delet] = 1;
				break;
			}
		}
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
	int arr[4][4] = {{ 82,83,69,92 }, {77,37,49,92} , { 11,69,5,86 } , { 8,9,98,23  } } ;
	int arr2[4][4] = { { 2500, 4000, 3500 , 2500 } , {4000 , 6000, 3500, 3500} , {2000, 4000, 2500 , 2000} , {2300,1500,6969,2312} };
	//two examples of Matrices, program runs on " arr[4][4] " 
	// you can try running with any of the two arrays by naming it arr[4][4]
	int CoveringLines = 0;
	int SizeOfArr = 4;
	int r1=0;
	int r2= 0;
	int r3=0;
	int r4=0;
	int col1=0;
	int col2=0;
	int col3=0;
	int col4=0;
	FindMinInRow(arr);
	SubRow(arr);
	cout << " -------------------- \n";
	printarrr(arr);
	FindMinInCol(arr);
	// findMinInCol(arr);
	SubCol(arr);
	cout << " -------------------- \n";
	printarrr(arr);
	GetNumOfZeros(arr, r1, r2, r3, r4, col1, col2, col3, col4);
	cout << " -------------111111111------- \n";
	printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
	rowzeros[0] = r1;
	rowzeros[1] = r2;
	rowzeros[2] = r3;
	rowzeros[3] = r4;
	int colzeros[4];
	colzeros[0] = col1;
	colzeros[1] = col2;
	colzeros[2] = col3;
	colzeros[3] = col4;
	int maxzeros = 0; int tmp;
	int indexofmaxzeros;
	//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4 ;  i++)
	{
		tmp = rowzeros[i]; 
		if (tmp > maxzeros)
		{
			maxzeros = tmp;
			indexofmaxzeros = i;
		}
	}
	cout << "Row with max zeros is ROW NUMBER: " << (indexofmaxzeros +1) << " , and have " << maxzeros << " Zeros. ";
	int CrossedArr[4][4] = { 0 } ;
	cout << "\n";
	printarrr(CrossedArr);
	int maxzeroscol = 0;
	int indexofmaxzeroscol;
	//loop to get the index of the column with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
	{
		if (colzeros[i] > maxzeroscol)
		{
			maxzeroscol = colzeros[i];
			indexofmaxzeroscol = i;
		}
	}
	cout << "COLUMN with max zeros is COL NUMBER: " << (indexofmaxzeroscol + 1) << " , and have " << maxzeroscol << " Zeros. "<<endl;
	
	// for iterative 1: we again decide what cross first a column or a row
	//by comparing the rowsmaxzeros and colmaxzeros and then crossing the one
	//with the highest number of zeros FIRST, then search again!.
	CompareMaxOfRowsAndCol(maxzeros, maxzeroscol, indexofmaxzeros, indexofmaxzeroscol, CrossedArr, CoveringLines);
	printarrr(CrossedArr);
	GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
	rowzeros[0] = r1;
	rowzeros[1] = r2;
	rowzeros[2] = r3;
	rowzeros[3] = r4;
	colzeros[0] = col1;
	colzeros[1] = col2;
	colzeros[2] = col3;
	colzeros[3] = col4;
	cout << "??????????-------------------- \n";
	printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
	int colmaxzeros2 = 0;
	int indexofcolmaxzeros2=0;
	//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
	{
		if (colzeros[i] > colmaxzeros2)
		{
			colmaxzeros2 = colzeros[i];
			indexofcolmaxzeros2 = i;
		}
	}
	cout << "col with max zeros is col num:  = " << (indexofcolmaxzeros2+1) << "\n";
	cout << "And has =" << colmaxzeros2 << " Zeors!!!!!" << endl;
	int rowmaxzeros2 = 0; 
	int indexofrowmaxzeros2 = 0;
	//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
	{
		if (rowzeros[i] > rowmaxzeros2)
		{
			rowmaxzeros2 = rowzeros[i];
			indexofrowmaxzeros2 = i;
		}
	}
	cout << "\n\n r0w with the maxzeros2 is row num = " << (indexofrowmaxzeros2+1) << "\n\n";
	cout << "\nAnd has = " << rowmaxzeros2 << " Zeors!!!!!";
	// for iterative 2: we again decide what cross first a column or a row
	//by comparing the rowsmaxzeros2 and colmaxzeros2 and then crossing the one
	//with the highest number of zeros FIRST, then search again!.
	CompareMaxOfRowsAndCol(rowmaxzeros2, colmaxzeros2, indexofrowmaxzeros2, indexofcolmaxzeros2, CrossedArr, CoveringLines);
	cout << "\n\n________iterative 2 - row or col with max zeros corssed!__________\n\n";
	
	printarrr(CrossedArr);
	cout << endl << CoveringLines << endl;
	GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
	cout << "\n\nPRINTED VALUES:    \n\n\n\n";
	rowzeros[0] = r1;
	rowzeros[1] = r2;
	rowzeros[2] = r3;
	rowzeros[3] = r4;
	colzeros[0] = col1;
	colzeros[1] = col2;
	colzeros[2] = col3;
	colzeros[3] = col4;
	cout << "\n----------------XXXX-------------\n\n"; 
	cout << " -------------------- \n";
	printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
	cout << "\n----------------XXXX-------------END\n\n"; 
//	cout << "\nCOVERING LINES::::: " << CoveringLines << endl;
	//////////// ITERATIVE 33333333333333
	int colmaxzeros3 = 0; int tmp4 = 0;
	int indexofcolmaxzeros3 = 0;
	//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
	{
		tmp4 = colzeros[i];
		if (tmp4 > colmaxzeros3)
		{
			colmaxzeros3 = tmp4;
			indexofcolmaxzeros3 = i;
		}
	}
	cout << "\n\n ITERATIVE 3 :  col with max zeros is col num:  = " << (indexofcolmaxzeros3 + 1) << "\n\n";
	cout << "\n\tAnd has =" << colmaxzeros3 << " Zeors!!!!!";
	int rowmaxzeros3 = 0; int tmp5 = 0;
	int indexofrowmaxzeros3 = 0;
	//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
	{
		tmp5 = rowzeros[i];
		if (tmp5 > rowmaxzeros3)
		{
			rowmaxzeros3 = tmp5;
			indexofrowmaxzeros3 = i;
		}
	}
	cout << "\n\n ITERATIVE 3 :  row with max zeros is row num:  = " << (indexofrowmaxzeros3 + 1) << "\n\n";
	cout << "\n\tAnd has =" << rowmaxzeros3 << " Zeors!!!!!\n\n";
	// for iterative 33333333333: we again decide what cross first a column or a row
	//by comparing the rowsmaxzeros2 and colmaxzeros2 and then crossing the one
	//with the highest number of zeros FIRST, then search again!.
	CompareMaxOfRowsAndCol(rowmaxzeros3, colmaxzeros3, indexofrowmaxzeros3, indexofcolmaxzeros3, CrossedArr, CoveringLines);
	cout << "\n-----------AFTER ITERATIVE 3 : -----------\n";
	printarrr(CrossedArr); 
	GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
	rowzeros[0] = r1;
	rowzeros[1] = r2;
	rowzeros[2] = r3;
	rowzeros[3] = r4;
	colzeros[0] = col1;
	colzeros[1] = col2;
	colzeros[2] = col3;
	colzeros[3] = col4;
	cout << " ??????????-------------------- \n";
	printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);

	int colmaxzeros8 = 0; int tmp14 = 0;
	int indexofcolmaxzeros8 = 0;
	//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
	{
		tmp14 = colzeros[i];
		if (tmp14 > colmaxzeros8)
		{
			colmaxzeros8 = tmp4;
			indexofcolmaxzeros8 = i;
		}
	}
	cout << "\n ITERATIVE 3 :  col with max zeros is col num:  = " << (indexofcolmaxzeros8 + 1) << "\n";
	cout << "And has =" << colmaxzeros8 << " Zeors!!!!!"<< '\n';
	int rowmaxzeros8 = 0; int tmp15 = 0;
	int indexofrowmaxzeros8 = 0;
	//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
	for (int i = 0; i < 4; i++)
	{
		tmp5 = rowzeros[i];
		if (tmp5 > rowmaxzeros8)
		{
			rowmaxzeros8 = tmp15;
			indexofrowmaxzeros8 = i;
		}
	}
	cout << "ITERATIVE 3 :  row with max zeros is row nummmmmmmmm:  = " << (indexofrowmaxzeros3 + 1) << "\n";
	cout << "And has =" << rowmaxzeros3 << " Zeors!!!!!\n";
	if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && col1 == 0 && col2 == 0 && col3 == 0 && col4 == 0);
	else {
		CompareMaxOfRowsAndCol(rowmaxzeros8, colmaxzeros8, indexofrowmaxzeros8, indexofcolmaxzeros8, CrossedArr, CoveringLines);
		printarrr(CrossedArr);
		GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
		cout << " \n\nCovering Lines: " << CoveringLines << endl;
		rowzeros[0] = r1;
		rowzeros[1] = r2;
		rowzeros[2] = r3;
		rowzeros[3] = r4;
		colzeros[0] = col1;
		colzeros[1] = col2;
		colzeros[2] = col3;
		colzeros[3] = col4;
		cout << " ??????????-------------------- \n";
		printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
	}
	
	if (r1==0 && r2 == 0 && r3 == 0 && r4 == 0 && col1 == 0 && col2 == 0 && col3 == 0 && col4 == 0)
	{
		if (CoveringLines==SizeOfArr) 
		{
			cout << "COVERING LINGES = SIZE OF MATRIX = " << SizeOfArr << endl;
			cout << "nOptimal Solution accuired!\n\n";
			printarrr(arr);
			cout << "-------------------------------\n"; 
			OptimalAssigning2(arr);
		} 
		else if (CoveringLines < SizeOfArr)
		{
			cout << "COVERING LINGES = "<<CoveringLines<<"  And SIZE OF MATRIX = " << SizeOfArr<<"\n";
			cout << "Optimal Solution NOT YET accuired"<<endl;
			int smallestUncovered = GetSmallestUncoverd(arr, CrossedArr);
			cout << "\n\n\n\nSMALLES UNCOVERED RECIVEDD:  " << smallestUncovered;
			SubSmallestFromUncovered(arr, CrossedArr, smallestUncovered);
			cout << "\n___________________________\n";
			printarrr(arr);
			AddSmallestUncoverdToPivot(arr, CrossedArr, smallestUncovered);
			cout << "\n___________________________999999999999....!!.....\n";
			printarrr(arr);
			GetNumOfZeros(arr, r1, r2, r3, r4, col1, col2, col3, col4);
			rowzeros[0] = r1;
			rowzeros[1] = r2;
			rowzeros[2] = r3;
			rowzeros[3] = r4;
			colzeros[0] = col1;
			colzeros[1] = col2;
			colzeros[2] = col3;
			colzeros[3] = col4;
			cout << "\n----------------XXXX-------------\n\n";
			printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
			int colmaxzeros4 = 0; 
			int indexofcolmaxzeros4 = 0;
			//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
			{
				if (colzeros[i] > colmaxzeros4)
				{
					colmaxzeros4 = colzeros[i];
					indexofcolmaxzeros4 = i;
				}
			}
			cout << "\n\n ITERATIVE 4 :  col with max zeros is col numberrrr:  = " << (indexofcolmaxzeros4 + 1) << "\n\n";
			cout << "\n\tAnd has =" << colmaxzeros4 << " Zeors!!!!!";
			int rowmaxzeros4 = 0; int tmp7 = 0;
			int indexofrowmaxzeros4 = 0;
			//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
			{
				tmp7 = rowzeros[i];
				if (tmp7 > rowmaxzeros4)
				{
					rowmaxzeros4 = tmp7;
					indexofrowmaxzeros4 = i;
				}
			}
			cout << "\n\n ITERATIVE 4 :  row with max zeros is row num:  = " << (indexofrowmaxzeros4 + 1) << "\n\n";
			cout << "\n\tAnd has =" << rowmaxzeros4 << " Zeors!!!!!\n\n";
			int CrossedArr[4][4] = { 0 };
			CoveringLines = 0;
			CompareMaxOfRowsAndCol(rowmaxzeros4, colmaxzeros4, indexofrowmaxzeros4, indexofcolmaxzeros4, CrossedArr, CoveringLines);
			cout << "\n\n-----------AFTER ITERATIVE 4 : -----------\n\n";
			printarrr(CrossedArr);
			GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
			rowzeros[0] = r1;
			rowzeros[1] = r2;
			rowzeros[2] = r3;
			rowzeros[3] = r4;
			colzeros[0] = col1;
			colzeros[1] = col2;
			colzeros[2] = col3;
			colzeros[3] = col4;
			cout << " ??????????-------------------- \n";
			printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
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
			int rowmaxzeros5 = 0; int tmp9 = 0;
			int indexofrowmaxzeros5 = 0;
			//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
			{
				tmp9 = rowzeros[i];
				if (tmp9 > rowmaxzeros5)
				{
					rowmaxzeros5 = tmp9;
					indexofrowmaxzeros5 = i;
				}
			}
			cout << "\n\n ITERATIVE 5 :  row with max zeros is row num:  = " << (indexofrowmaxzeros5 + 1) << "\n\n";
			cout << "\n\tAnd has =" << rowmaxzeros5 << " Zeors!!!!!\n\n";
			CompareMaxOfRowsAndCol(rowmaxzeros5, colmaxzeros5, indexofrowmaxzeros5, indexofcolmaxzeros5, CrossedArr, CoveringLines);
			cout << "\n\n-----------AFTER ITERATIVE 5 : -----------\n\n";
			printarrr(CrossedArr);
			GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
			cout << " ??????????----------555555---------- \n";

			rowzeros[0] = r1;
			rowzeros[1] = r2;
			rowzeros[2] = r3;
			rowzeros[3] = r4;
			colzeros[0] = col1;
			colzeros[1] = col2;
			colzeros[2] = col3;
			colzeros[3] = col4;
			printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
			int colmaxzeros6 = 0;
			int indexofcolmaxzeros6 = 0;
			//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
			{
				if (colzeros[i] > colmaxzeros6)
				{
					colmaxzeros6= colzeros[i];
					indexofcolmaxzeros6 = i;
				}
			}
			cout << "\n\n ITERATIVE 6 :  col with max zeros is col numberrrr:  = " << (indexofcolmaxzeros6 + 1) << "\n\n";
			cout << "\n\tAnd has =" << colmaxzeros6 << " Zeors!!!!!";
			int rowmaxzeros6 = 0; int tmp11 = 0;
			int indexofrowmaxzeros6 = 0;
			//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
			{
				tmp11 = rowzeros[i];
				if (tmp11 > rowmaxzeros6)
				{
					rowmaxzeros6 = tmp11;
					indexofrowmaxzeros6 = i;
				}
			}
			cout << "\n\n ITERATIVE 6 :  row with max zeros is row num:  = " << (indexofrowmaxzeros6 + 1) << "\n\n";
			cout << "\n\tAnd has =" << rowmaxzeros6 << " Zeors!!!!!\n\n";
			CompareMaxOfRowsAndCol(rowmaxzeros6, colmaxzeros6, indexofrowmaxzeros6, indexofcolmaxzeros6, CrossedArr, CoveringLines);
			cout << "\n\n-----------AFTER ITERATIVE 6 : -----------\n\n";
			printarrr(CrossedArr);
			GetNumOfZerosAndUncrossed(arr, CrossedArr, r1, r2, r3, r4, col1, col2, col3, col4);
			rowzeros[0] = r1;
			rowzeros[1] = r2;
			rowzeros[2] = r3;
			rowzeros[3] = r4;
			colzeros[0] = col1;
			colzeros[1] = col2;
			colzeros[2] = col3;
			colzeros[3] = col4;
			cout << " ??????????-------------------- \n";
			printRowAndCol(r1, r2, r3, r4, col1, col2, col3, col4);
			
			int colmaxzeros7 = 0; int tmp12 = 0;
			int indexofcolmaxzeros7 = 0;
			//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
			{
				tmp12 = colzeros[i];
				if (tmp12 > colmaxzeros7)
				{
					colmaxzeros7 = tmp12;
					indexofcolmaxzeros7 = i;
				}
			}
			cout << "\nITERATIVE 7 :  col with max zeros is col numberrrr:  = " << (indexofcolmaxzeros7 + 1) << "\n";
			cout << "And has =" << colmaxzeros7 << " Zeors!!!!!\n";
			int rowmaxzeros7 = 0;
			int indexofrowmaxzeros7 = 0;
			//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
			for (int i = 0; i < 4; i++)
			{
				if (rowzeros[i] > rowmaxzeros7)
				{
					rowmaxzeros7 = rowzeros[i];
					indexofrowmaxzeros7 = i;
				}
			}
			cout << "ITERATIVE 7 :  row with max zeros is row num:  = " << (indexofrowmaxzeros7 + 1) << "\n";
			cout << "And has =" << rowmaxzeros7 << " Zeors!!!!!\n";
			CompareMaxOfRowsAndCol(rowmaxzeros7, colmaxzeros7, indexofrowmaxzeros7, indexofcolmaxzeros7, CrossedArr, CoveringLines); 
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