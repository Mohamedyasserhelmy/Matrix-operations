// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};


// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
//matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
   // change mat & return new matrix
matrix operator+= (matrix& mat, int scalar);
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);

       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};
  int data4 [] = {1,0,0,0,1,0,0,0,1};
  matrix mat1, mat2, mat3, mat4;

  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);
  createMatrix (3, 3, data4, mat4);



  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat3 - mat1) << endl;
  cout << (mat3 + mat2) << endl;
  cout << (mat3 * mat1) << endl;

  cout<< (mat1 + 3) << endl;
  cout<< (mat1 - 3) << endl;
  cout<< (mat1 * 2) << endl;

  mat1+= mat3;
  cout << mat1 << endl;
  mat2+= 1;
  cout << mat2 << endl;
  mat2-=1;
  cout << mat2 << endl;



  cout << transpose(mat3) ;

/* The next code will not work until you write the functions
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];

}
//
//_________________________________________
// overloading "cout" operator to print matrix in a proper way
ostream& operator<< (ostream& out, matrix mat)
{


    for (int i = 0; i< mat.row; i++)
    {
        for (int j = 0; j< mat.col; j++)
        {
            out << setw(4)<< mat.data[i][j] << setw(4);
        }
        out << endl;
    }
     return out;
}

//
//___________________________________________
//overloading "Cin" operator to get input from user

istream& operator>> (istream& in, matrix& mat)
{
    int _row = mat.row;
    int _col = mat.col;
    int elements[(_row * _col)];
    for (int i = 0; i < (_row * _col); i++)
    {
        in >> elements[i];
    }
    mat.data = new int* [_row];

    for (int i = 0; i < _row; i++)
        mat.data[i] = new int [_col];

    for (int i = 0; i < _row; i++)
        for (int j = 0; j < _col; j++)
            mat.data[i][j] = elements[i * _col + j];

    return in;
}
//
//____________________________________________
// adding 1 for every elements in the matrix

void   operator++ (matrix& mat)
{
    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.data[i][j] = mat.data[i][j] + 1;

}

//
// __________________________________________
// subtracting 1 from each element in the matrix
void   operator-- (matrix& mat)
{
    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.data[i][j] = mat.data[i][j] - 1;

}

//
//___________________________________________
// overloading  operator += to add two matrices and return the value at first matrix
matrix operator+= (matrix& mat1, matrix mat2)
{
   if((mat1.col != mat2.col) && (mat1.row != mat2.col))
      {
          cout << "Sorry, the two matrices does not have the same dimensions ";
      }
      else
        for (int i = 0; i < mat1.row; i++)
            for (int j = 0; j < mat1.col; j++)
                mat1.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
    return mat1;
}

//
//________________________________________________
// overloading operator -= to subtract and return mat1 with reference
matrix operator-= (matrix& mat1, matrix mat2)
{
    if((mat1.col != mat2.col) && (mat1.row != mat2.col))
      {
          cout << "Sorry, the two matrices does not have the same dimensions ";
      }
      else
        for (int i = 0; i < mat1.row; i++)
            for (int j = 0; j < mat1.col; j++)
                mat1.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
    return mat1;
}
//
//__________________________________________________
// adding a scalar to each element in the matrix
matrix operator+= (matrix& mat, int scalar)
{
    int _row = mat.row;
    int _col = mat.col;

    for (int i = 0; i < _row; i++)
            for (int j = 0; j < _col; j++)
                mat.data[i][j] = mat.data[i][j] + scalar;
   return mat;
}
//
//___________________________________________________
// subtracting a scalar from matrix
matrix operator-= (matrix& mat, int scalar)
{
    int _row = mat.row;
    int _col = mat.col;

    for (int i = 0; i < _row; i++)
            for (int j = 0; j < _col; j++)
                mat.data[i][j] = mat.data[i][j] - scalar;
   return mat;
}
//
bool operator!= (matrix mat1, matrix mat2)
{
    if ((mat1.row == mat2.row)&(mat1.col == mat2.col))
    {
        bool a = true;
        for (int i = 0; i < mat1.row; i++){
            for (int j = 0; j < mat1.col; j++)
            {
                if (mat1.data[i][j] != mat1.data[i][j] )
                    a=false;
            }
        }
        if (a == true)
            return true;
        else
            return false;
    }
    else
        return false;
}
//----------------------------------------------------------------------------
// overloading (==) operator to check if two matrices are not identical
bool operator== (matrix mat1, matrix mat2)
{
    if ((mat1.row == mat2.row)&(mat1.col == mat2.col))
    {
        bool a = true;
        for (int i = 0; i < mat1.row; i++){
            for (int j = 0; j < mat1.col; j++)
            {
                if (mat1.data[i][j] == mat1.data[i][j] )
                    a=false;
            }
        }
        if (a == true)
            return true;
        else
            return false;
    }
    else
        return false;
}
//--------------------------------------------------------------------------------
// check if square matrix
bool isSquare (matrix mat){
    if(mat.row == mat.col)
        return true;
    else
        return false;
}

//----------------------------------------------------------------------------------
bool isSymetric (matrix mat1){
    if(mat1.row == mat1.col){
        bool a = true;
        int data1[mat1.row][mat1.col];
        for (int i = 0; i < mat1.row; i++){
            for (int j = 0; j < mat1.col; j++){
                data1[i][j] = mat1.data[j][i];
                }
        }
        for (int i = 0; i < mat1.row; i++){
            for (int j = 0; j < mat1.col; j++)
            {
              if  (data1[i][j] != mat1.data[j][i]){
               a = false;
                }
            }
        }
        if (a == true)
            return true;
}
else
    return false;
}
//-------------------------------------------------------------------------------
//ckeck isIdentity
bool isIdentity (matrix mat){
if (mat.row == mat.col){
    bool a = true;
    int sum1 = 0;
    for(int i = 0;i < mat.row;i++){
        int j = mat.row-i;
        if (mat.data[i][j] != 1)
            a = false;
        for(int r = 0;r < mat.col;r++){
            sum1 += mat.data[i][r];
        }
        if (sum1 != mat.row)
            a = false;
    }
if (a == true)
    return true;
else
    return false;
}
else
    return false;
}
//---------------------------------------------------------------------------------------
//matrix transpose
matrix transpose(matrix mat){
    /*if (mat.col==mat.row){
        matrix tran;
        tran.row = mat.col;
        tran.col = mat.row;
        tran.data = new int* [tran.row];
        for (int i = 0; i < tran.row; i++)
            tran.data[i] = new int [tran.col];
        for (int i = 0; i < mat.row; i++){
            for (int j = 0; j < mat.col; j++){
                tran.data[i][j]=mat.data[j][i];
                }
        }
        return tran;
    }*/
    int transpose1[(mat.row)*(mat.col)];
    int r = 0;
    for(int i = 0;i < mat.col; i++){
        for(int j = 0;j < mat.row; j++){
            transpose1[r] = mat.data[j][i];
            r = r + 1;
        }
   }
   createMatrix(mat.col,mat.row,transpose1,mat);
return mat;

}
//sum 2 matrices
matrix operator+  (matrix mat1, matrix mat2)
{
    if((mat1.row == mat2.row) && (mat1.col == mat2.col))
    {
    matrix summation;
    summation.row = mat1.row;
    summation.col = mat1.col;
    summation.data = new int* [summation.row];

   for (int i = 0; i < summation.row; i++)
      summation.data[i] = new int [summation.col];

      for (int i = 0; i < summation.row; i++)
        for (int j = 0; j < summation.col; j++)
            summation.data[i][j] = mat1.data[i][j] + mat2.data[i][j];


    return summation;
    }
    else
    {
          cout << "Sorry, the two matrices do not have the same dimensions ";

    }

}
//difference 2 matrices
matrix operator-  (matrix mat1, matrix mat2)
{

   if((mat1.col != mat2.col) && (mat1.row != mat2.row))
      {
          cout << "Sorry, the two matrices do not have the same dimensions ";
      }
    matrix diff;
    diff.row = mat1.row;
    diff.col = mat1.col;
    diff.data = new int* [diff.row];

        for (int i = 0; i < diff.row; i++)
        diff.data[i] = new int [diff.col];

        for (int i = 0; i < diff.row; i++)
            for (int j = 0; j < diff.col; j++)
                diff.data[i][j] = mat1.data[i][j] - mat2.data[i][j];

    return diff;
}
//Multiplication of 2 Matrices
matrix operator*  (matrix mat1, matrix mat2)
{

   if((mat1.col != mat2.col) && (mat1.row != mat2.row))
      {
          cout << "Sorry, the two matrices do not have the same dimensions ";
      }
    matrix multi;
    multi.row = mat1.row;
    multi.col = mat1.col;
    multi.data = new int* [multi.row];

        for (int i = 0; i < multi.row; i++)
        multi.data[i] = new int [multi.col];

        for (int i = 0; i < multi.row; i++)
            for (int j = 0; j < multi.col; j++)
                multi.data[i][j] = mat1.data[i][j] - mat2.data[i][j];

        for(int i = 0; i < mat1.row; i++){

            for(int j = 0; j < mat2.col; j++)
                for(int k = 0; k < mat1.col; k++)
                    multi.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
        }

    return multi;
}

//Adding Scalar
matrix operator+  (matrix mat1, int scalar)
{
    matrix sumS;
    sumS.row = mat1.row;
    sumS.col = mat1.col;
    sumS.data = new int* [sumS.row];

    for (int i = 0; i < sumS.row; i++)
        sumS.data[i] = new int [sumS.col];

        for (int i = 0; i < sumS.row; i++)
            for (int j = 0; j < sumS.col; j++)
                sumS.data[i][j] = mat1.data[i][j] + scalar;
    return sumS;
}
//Subtracting Scalar
matrix operator-  (matrix mat1, int scalar)
{
    matrix subS;
    subS.row = mat1.row;
    subS.col = mat1.col;
    subS.data = new int* [subS.row];

    for (int i = 0; i < subS.row; i++)
        subS.data[i] = new int [subS.col];

        for (int i = 0; i < subS.row; i++)
            for (int j = 0; j < subS.col; j++)
                subS.data[i][j] = mat1.data[i][j] - scalar;
    return subS;
}
//Multiplying scalar
matrix operator*  (matrix mat1, int scalar)
{
    matrix multS;
    multS.row = mat1.row;
    multS.col = mat1.col;
    multS.data = new int* [multS.row];

    for (int i = 0; i < multS.row; i++)
        multS.data[i] = new int [multS.col];

        for (int i = 0; i < multS.row; i++)
            for (int j = 0; j < multS.col; j++)
                multS.data[i][j] = mat1.data[i][j] * scalar;
    return multS;
}




