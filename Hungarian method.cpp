#include <iostream>
using namespace std;

int MinInRows[4] = {};
int MinInCol[4] = {};
int rowzeros[4]; 	
int colzeros[4];
int AssigningMatrix[4][4] = { 0 };


int FindMinInCol(int arr[4][4]) {


	int mincol1 = arr[0][0];
	int mincol2 = arr[0][1];
	int mincol3 = arr[0][2];
	int mincol4 = arr[0][3];


	int tmp;

	for (int j = 0; j < 4; j++)
	{
		tmp = arr[j][0];
		if (tmp <= mincol1)
		{
			mincol1 = tmp;
		}
	}

	//

	for (int j = 0; j < 4; j++)
	{
		tmp = arr[j][1];
		if (tmp <= mincol2)
		{
			mincol2 = tmp;
		}
	}


	//

	for (int j = 0; j < 4; j++)
	{
		tmp = arr[j][2];
		if (tmp <= mincol3)
		{
			mincol3 = tmp;
		}
	}




	//

	for (int j = 0; j < 4; j++)
	{
		tmp = arr[j][3];
		if (tmp <= mincol4)
		{
			mincol4 = tmp;
		}
	}


	MinInCol[0] = mincol1;
	MinInCol[1] = mincol2;

	MinInCol[2] = mincol3;
	MinInCol[3] = mincol4;


	//

	//cout << "ARR: " << minval1 << minval2 << minval3 << minval4;










	return 0;
}

void printarrr(int arr[4][4]) {


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {

			cout << arr[i][j] << "\t";
		} cout << endl;
	}

	
}

int FindMinInRow(int arr[4][4]) {


	int minval1 = arr[0][0];
	int minval2 = arr[1][0];
	int minval3 = arr[2][0];
	int minval4 = arr[3][0];


	int tmp;

	for (int j = 0; j < 4; j++)
	{
		tmp = arr[0][j];
		if (tmp <= minval1)
		{
			minval1 = tmp;
		}
	}

	//

	for (int j = 0; j < 4; j++)
	{
		tmp = arr[1][j];
		if (tmp <= minval2)
		{
			minval2 = tmp;
		}
	}


	//

	for (int j = 0; j < 4; j++)
	{
		tmp = arr[2][j];
		if (tmp <= minval3)
		{
			minval3 = tmp;
		}
	}




	//

	for (int j = 0; j < 4; j++)
	{
		tmp = arr[3][j];
		if (tmp <= minval4)
		{
			minval4 = tmp;
		}
	}
	MinInRows[0] = minval1;
	MinInRows[1] = minval2;

	MinInRows[2] = minval3;
	MinInRows[3] = minval4;


	//

	//cout << "ARR: " << minval1 << minval2 << minval3 << minval4;


	







	return 0;
}

int SubRow( int arr[4][4]) {
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = (arr[i][j] - (MinInRows[k]));
		}
		k++;
	}
	return 0;
}

int SubCol(int arr[4][4]) {
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[j][i] = (arr[j][i] - (MinInCol[k]));
		}
		k++;
	}
	return 0;
}

int GetNumOfZeros(int arr[4][4], int &r1, int &r2, int &r3, int &r4, int &col1, int &col2, int &col3,int &col4) {
	



	for (int i = 0; i < 4 ; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (  arr[i][j] == 0   ) {

				if (i==0)
				{
					r1++;
					if (j==0)
					{
						
						col1++;
					}
					else if ( j==1 )
					{
						
						col2++;
					}
					else if (j == 2 )
					{
						
						col3++;
					}
					else {
						col4++;
					}
				}
				else if (i == 1)
				{
					r2++;
					if (j == 0)
					{

						col1++;
					}
					else if (j == 1)
					{

						col2++;
					}
					else if (j == 2)
					{

						col3++;
					}
					else {
						col4++;
					}

				}
				else if (i == 2)
				{
					r3++;
					if (j == 0)
					{

						col1++;
					}
					else if (j == 1)
					{

						col2++;
					}
					else if (j == 2)
					{

						col3++;
					}
					else {
						col4++;
					}
				}
				else
				{
					r4++;
					if (j == 0)
					{

						col1++;
					}
					else if (j == 1)
					{

						col2++;
					}
					else if (j == 2)
					{

						col3++;
					}
					else {
						col4++;
					}
				}
				
			}
		}


	}




	//cout << "---------------------\n\tNUMEROF ZEROS: " << numofzeros; 
	return 0;
}

int GetNumOfZerosAndUncrossed(int arr[4][4],int Crossed[4][4] ,int& r1, int& r2, int& r3, int& r4, int& col1, int& col2, int& col3, int& col4) {


	r1 = r2 = r3 = r4 = col1 = col2 = col3 = col4 = 0;




	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0 && Crossed[i][j] == 0  ) {

				if (i == 0 && Crossed[i][j] == 0 )
				{
					r1++;
					if (j == 0 && Crossed[i][j] == 0)
					{

						col1++;
					}
					else if (j == 1 && Crossed[i][j] == 0)
					{

						col2++;
					}
					else if (j == 2 && Crossed[i][j] == 0)
					{

						col3++;
					}
					else {
						col4++;
					}
				}
				else if (i == 1 && Crossed[i][j] == 0)
				{
					r2++;
					if (j == 0 && Crossed[i][j] == 0)
					{

						col1++;
					}
					else if (j == 1 && Crossed[i][j] == 0)
					{

						col2++;
					}
					else if (j == 2 && Crossed[i][j] == 0)
					{

						col3++;
					}
					else {
						col4++;
					}

				}
				else if (i == 2 && Crossed[i][j] == 0)
				{
					r3++;
					if (j == 0 && Crossed[i][j] == 0)
					{

						col1++;
					}
					else if (j == 1 && Crossed[i][j] == 0)
					{

						col2++;
					}
					else if (j == 2 && Crossed[i][j] == 0)
					{

						col3++;
					}
					else {
						col4++;
					}
				}
				else
				{
					r4++;
					if (j == 0 && Crossed[i][j] == 0)
					{

						col1++;
					}
					else if (j == 1 && Crossed[i][j] == 0)
					{

						col2++;
					}
					else if (j == 2 && Crossed[i][j] == 0)
					{

						col3++;
					}
					else {
						col4++;
					}
				}

			}
		}


	}




	//cout << "---------------------\n\tNUMEROF ZEROS: " << numofzeros; 
	return 0;
}
 // int FindMaxZerosCols(int col1, int col2, int col3, int col4) {}
int max(int a, int b) {

	if (a > b)
	{
		return 1;
	}
	else if (a < b) {
		return 2;
	}
	else
		return 1;
}


int GetSmallestUncoverd(int arr[4][4], int Crossed[4][4]) {
	int tmp; int smallest = 99999999;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			 tmp = arr[i][j];

			if (tmp < smallest && Crossed[i][j] ==0 )
			{
				smallest = tmp; 

			}


		}
	}

	cout << "\n\nSmallest uncorssed: " << smallest; 
	return smallest;


}

int SubSmallestFromUncovered(int arr[4][4], int Crossed[4][4], int smallest) {




	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {


			if ( Crossed[i][j] == 0 )
			{
				arr[i][j] = ( arr[i][j] - smallest ) ;
			}


		}
	}

	return 0;
}



int AddSmallestUncoverdToPivot(int arr[4][4], int Crossed[4][4], int smallest) {


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {


			if (Crossed[i][j] == -1)
			{
				arr[i][j] = (arr[i][j] + smallest);
			}


		}
	}



	return 0;

}



int PutColAndRowZerosToMatrix(int &r1, int &r2, int &r3, int &r4, int &col1, int &col2, int &col3,int &col4) {


	cout << "\n\nPRINTED VALUES:    \n\n";
	rowzeros[0] = r1;
	rowzeros[1] = r2;
	rowzeros[2] = r3;
	rowzeros[3] = r4;
	colzeros[0] = col1;
	colzeros[1] = col2;
	colzeros[2] = col3;
	colzeros[3] = col4;



	cout << " ??????????-------------------- \n";
	cout << "\nR1 = " << r1;
	cout << "\nR2 = " << r2;
	cout << "\nR3 = " << r3;
	cout << "\nR4 = " << r4;


	cout << "\nCOL1 = arr " << col1;
	cout << "\nCOL2 = " << col2;
	cout << "\nCOL3 = " << col3;
	cout << "\nCOL4 = " << col4;

	return 0;
}



void OptimalAssigning2(int arr[4][4]) {

//	AssigningMatrix[4][4] = {0};

	for (int i = 0; i < 4; i++)
	{
		for (int  j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0 && AssigningMatrix[i][j] == 0 )
			{
				cout << "\nWorker number " << (i + 1) << " Is Assigned to job : " << (j + 1)<<endl; 
				int index_of_col_to_delet = j;

				for (int k = 0; k < 4; k++)
				{
					AssigningMatrix[k][index_of_col_to_delet] = 1;
					
				}break;




			}
		}

	}


}


int CompareMaxOfRowsAndCol(int RowMaxZeros, int ColMaxZeros, int IndexOfRowMaxZeros, int  IndexOfColMaxZeros, int CrossedArr[4][4], int& CoveringLines) {


	if (RowMaxZeros >= ColMaxZeros)
	{
		//cross the row elements by by making all 0 to 1 in mirror array to represent the crossed and uncrossed
		for (int j = 0; j < 4; j++) {

			if (CrossedArr[IndexOfRowMaxZeros][j] == 0) {
				CrossedArr[IndexOfRowMaxZeros][j] = 1;
			}
			else {
				CrossedArr[IndexOfRowMaxZeros][j] = -1;
			}


		}CoveringLines++;



	}
	else if (RowMaxZeros < ColMaxZeros)
	{

		//cross col
		for (int j = 0; j < 4; j++) {

			if (CrossedArr[j][IndexOfColMaxZeros] == 0) {
				CrossedArr[j][IndexOfColMaxZeros] = 1;
			}
			else {
				CrossedArr[j][IndexOfColMaxZeros] = -1;
			}

		} CoveringLines++;


	}

	return 0; 
}



int main()
{



	int arr[4][4] = { { 82,83,69,92 } , {77,37,49,92} , { 11,69,5,86 } , { 8,9,98,23  } } ;
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
	SubCol(arr);
	cout << " -------------------- \n";
	printarrr(arr);

	GetNumOfZeros(arr, r1, r2, r3, r4, col1, col2, col3, col4);



	cout << " -------------111111111------- \n";
	cout << "\nR1 = " << r1;
	cout << "\nR2 = " << r2;
	cout << "\nR3 = " << r3;
	cout << "\nR4 = " << r4;


	cout << "\nCOL1 = " << col1;
	cout << "\nCOL2 = " << col2;
	cout << "\nCOL3 = " << col3;
	cout << "\nCOL4 = " << col4;

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


	cout << "\n\nRow with max zeros is ROW NUMBER: " << (indexofmaxzeros +1) << " , and have " << maxzeros << " Zeros. ";


	int CrossedArr[4][4] = { 0 } ;

	//printarrr(CrossedArr);

		

		cout << "\n";
		printarrr(CrossedArr);



		int maxzeroscol = 0; int tmpcol;
		int indexofmaxzeroscol;
		//loop to get the index of the column with highest number of zeros + the highest nymber of zeros
		for (int i = 0; i < 4; i++)
		{

			tmpcol = colzeros[i];
			if (tmpcol > maxzeroscol)
			{
				maxzeroscol = tmpcol;
				indexofmaxzeroscol = i;
			}

		}

		cout << "\n\COLUMN with max zeros is COL NUMBER: " << (indexofmaxzeroscol + 1) << " , and have " << maxzeroscol << " Zeros. ";


		



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

		cout << " ??????????-------------------- \n";
		cout << "\nR1 = " << r1;
		cout << "\nR2 = " << r2;
		cout << "\nR3 = " << r3;
		cout << "\nR4 = " << r4;


		cout << "\nCOL1 = arr " << colzeros[0];
		cout << "\nCOL2 = " << col2;
		cout << "\nCOL3 = " << col3;
		cout << "\nCOL4 = " << col4;


 		int colmaxzeros2 = 0; int tmp2=0;
		int indexofcolmaxzeros2=0;
		//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
		for (int i = 0; i < 4; i++)
		{

			tmp2 = colzeros[i];
			if (tmp2 > colmaxzeros2)
			{
				colmaxzeros2 = tmp2;
				indexofcolmaxzeros2 = i;
			}

		}

		cout << "\n\n col with max zeros is col num:  = " << (indexofcolmaxzeros2+1) << "\n\n";
		cout << "\nAnd has =" << colmaxzeros2 << " Zeors!!!!!"; 

		int rowmaxzeros2 = 0; int tmp3 = 0;
		int indexofrowmaxzeros2 = 0;
		//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
		for (int i = 0; i < 4; i++)
		{

			tmp3 = rowzeros[i];
			if (tmp3 > rowmaxzeros2)
			{
				rowmaxzeros2 = tmp3;
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
	//	PutColAndRowZerosToMatrix(r1, r2, r3, r4, col1, col2, col3, col4);



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
		cout << "\nR1 = " << r1;
		cout << "\nR2 = " << r2;
		cout << "\nR333333333333333333 = " << r3;
		cout << "\nR4 = " << r4;


		cout << "\nCOL1 = " << col1;
		cout << "\nCOL2 = " << col2;
		cout << "\nCOL3 = " << col3;
		cout << "\nCOL4 = " << col4;
		

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
				cout << "\n\n-----------AFTER ITERATIVE 3 : -----------\n\n";
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
				cout << "\nR1 = " << r1;
				cout << "\nR2 = " << r2;
				cout << "\nR3 = " << r3;
				cout << "\nR4 = " << r4;


				cout << "\nCOL1 = arr " << colzeros[0];
				cout << "\nCOL2 = " << col2;
				cout << "\nCOL3 = " << col3;
				cout << "\nCOL4 = " << col4;



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
				cout << "\n\n ITERATIVE 3 :  col with max zeros is col num:  = " << (indexofcolmaxzeros8 + 1) << "\n\n";
				cout << "\n\tAnd has =" << colmaxzeros8 << " Zeors!!!!!";





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




				cout << "\n\n ITERATIVE 3 :  row with max zeros is row nummmmmmmmm:  = " << (indexofrowmaxzeros3 + 1) << "\n\n";
				cout << "\n\tAnd has =" << rowmaxzeros3 << " Zeors!!!!!\n\n";


				if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && col1 == 0 && col2 == 0 && col3 == 0 && col4 == 0) {

					

				}
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
					cout << "\nR1 = " << r1;
					cout << "\nR2 = " << r2;
					cout << "\nR3 = " << r3;
					cout << "\nR4 = " << r4;


					cout << "\nCOL1 = arr " << colzeros[0];
					cout << "\nCOL2 = " << col2;
					cout << "\nCOL3 = " << col3;
					cout << "\nCOL4 = " << col4;

				}
				


		if (r1==0 && r2 == 0 && r3 == 0 && r4 == 0 && col1 == 0 && col2 == 0 && col3 == 0 && col4 == 0)
		{
			if (CoveringLines==SizeOfArr) 
			{
				cout << "\n\n\n COVERING LINGES = SIZE OF MATRIX = " << SizeOfArr; 
				cout << " \nnOptimal Solution accuired!\n\n";
				printarrr(arr);
				cout << "\n-------------------------------\n"; 

				OptimalAssigning2(arr);

			} 
			else if (CoveringLines < SizeOfArr)
			{
				cout << "\n\n COVERING LINGES = "<<CoveringLines<<"  And SIZE OF MATRIX = " << SizeOfArr;
				cout << " Optimal Solution NOT YET accuired";


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

				cout << " -------------------- \n";
				cout << "\nR1 = " << r1;
				cout << "\nR2 = " << r2;
				cout << "\nR3 = " << r3;
				cout << "\nR4 = " << r4;


				cout << "\nCOL1 = " << col1;
				cout << "\nCOL2 = " << col2;
				cout << "\nCOL3 = " << col3;
				cout << "\nCOL4 = " << col4;
				

				int colmaxzeros4 = 0; int tmp6 = 0;
				int indexofcolmaxzeros4 = 0;


				//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
				for (int i = 0; i < 4; i++)
				{

					tmp6 = colzeros[i];
					if (tmp6 > colmaxzeros4)
					{
						colmaxzeros4 = tmp6;
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
				cout << "\nR1 = " << r1;
				cout << "\nR2 = " << r2;
				cout << "\nR3 = " << r3;
				cout << "\nR4 = " << r4;


				cout << "\nCOL1 = arr " << colzeros[0];
				cout << "\nCOL2 = " << col2;
				cout << "\nCOL3 = " << col3;
				cout << "\nCOL4 = " << col4; 



				////////////////////////////////////

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

				//PutColAndRowZerosToMatrix(r1, r2, r3, r4, col1, col2, col3, col4);
				
				rowzeros[0] = r1;
				rowzeros[1] = r2;
				rowzeros[2] = r3;
				rowzeros[3] = r4;
				colzeros[0] = col1;
				colzeros[1] = col2;
				colzeros[2] = col3;
				colzeros[3] = col4;

				
				cout << "\nR1 = " << r1;
				cout << "\nR2 = " << r2;
				cout << "\nR3 = " << r3;
				cout << "\nR4 = " << r4;


				cout << "\nCOL1 = arr " << colzeros[0];
				cout << "\nCOL2 = " << col2;
				cout << "\nCOL3 = " << col3;
				cout << "\nCOL4 = " << col4;
				
				////////////////////////////////////

				int colmaxzeros6 = 0; int tmp10 = 0;
				int indexofcolmaxzeros6 = 0;


				//loop to get the index of the col with highest number of zeros + the highest nymber of zeros
				for (int i = 0; i < 4; i++)
				{

					tmp10 = colzeros[i];
					if (tmp10 > colmaxzeros6)
					{
						colmaxzeros6= tmp10;
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
				
				//PutColAndRowZerosToMatrix(r1, r2, r3, r4, col1, col2, col3, col4);
				
				
				rowzeros[0] = r1;
				rowzeros[1] = r2;
				rowzeros[2] = r3;
				rowzeros[3] = r4;
				colzeros[0] = col1;
				colzeros[1] = col2;
				colzeros[2] = col3;
				colzeros[3] = col4;

				cout << " ??????????-------------------- \n";
				cout << "\nR1 = " << r1;
				cout << "\nR2 = " << r2;
				cout << "\nR3 = " << r3;
				cout << "\nR4 = " << r4;


				cout << "\nCOL1 = arr " << colzeros[0];
				cout << "\nCOL2 = " << col2;
				cout << "\nCOL3 = " << col3;
				cout << "\nCOL4 = " << col4;



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
				cout << "\n\n ITERATIVE 7 :  col with max zeros is col numberrrr:  = " << (indexofcolmaxzeros7 + 1) << "\n\n";
				cout << "\n\tAnd has =" << colmaxzeros7 << " Zeors!!!!!";





				int rowmaxzeros7 = 0; int tmp13 = 0;
				int indexofrowmaxzeros7 = 0;
				//loop to get the index of the row with highest number of zeros + the highest nymber of zeros
				for (int i = 0; i < 4; i++)
				{

					tmp13 = rowzeros[i];
					if (tmp13 > rowmaxzeros7)
					{
						rowmaxzeros7 = tmp13;
						indexofrowmaxzeros7 = i;
					}
				}




				cout << "\n\n ITERATIVE 7 :  row with max zeros is row num:  = " << (indexofrowmaxzeros7 + 1) << "\n\n";
				cout << "\n\tAnd has =" << rowmaxzeros7 << " Zeors!!!!!\n\n";


				CompareMaxOfRowsAndCol(rowmaxzeros7, colmaxzeros7, indexofrowmaxzeros7, indexofcolmaxzeros7, CrossedArr, CoveringLines); 
				cout << "\n\n-----------AFTER ITERATIVE 7 : -----------\n\n";
				printarrr(CrossedArr);

				cout << "\n\nCOVERINGLINES : " << CoveringLines << endl;

				if (CoveringLines == SizeOfArr)
				{
					cout << "\n\n\n COVERING LINGES = SIZE OF MATRIX = " << SizeOfArr;
					cout << " \nnOptimal Solution accuired!!!!!!!!!!!????EWDFSCDSFD!\n\n";


					OptimalAssigning2(arr);
				}
			}
			else {
				cout << "\nNO IF CONDITION APPLIEED???!!!!!\n\n";
			}
		}





		return 0; }