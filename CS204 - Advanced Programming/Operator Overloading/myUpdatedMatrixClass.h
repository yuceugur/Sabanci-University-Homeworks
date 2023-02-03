#ifndef _myupdatedmatrixclass
#define _myupdatedmatrixclass

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "myUpdatedMatrixClass.h"

using namespace std;

class Matrix2D {
	friend ifstream & operator >> (ifstream &, Matrix2D &);
    friend ostream & operator << (ostream &, Matrix2D &);
    friend Matrix2D  operator + (const Matrix2D &, const Matrix2D &);
	private: 
		int rows, cols;
		int **data;
    public:
		Matrix2D();
		~Matrix2D();
		Matrix2D(const Matrix2D&);
		Matrix2D(const int &, const int &);
		int GetIndex(const int &, const int &) const;
		void SetIndex(const int &, const int &, const int &) const;
		bool isEmpty();
		Matrix2D & operator += (const Matrix2D &);
        Matrix2D & operator = (const Matrix2D &);
};

Matrix2D::Matrix2D()
{
	rows = 0;
	cols = 0;
	data = nullptr;
}

bool Matrix2D::isEmpty()
{
	bool check = false;
	if(*data == nullptr)
	{
		check = true;
	}
	return check;
}

Matrix2D::Matrix2D(const Matrix2D& copy)
{
    rows = copy.rows;
    cols = copy.cols;

    data = new int*[copy.rows];

    for (int i = 0; i < rows; i++)
		data[i] = new int[cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = copy.data[i][j];
        }
    }
}

ifstream & operator >> (ifstream & input, Matrix2D &arr)
{
	string line;
	int row=0, col=0;
	while(getline(input, line))
	{
		stringstream ss(line);
		int num;
		while(ss>>num)
		{
			col++;
		}
		row++;
	}
	arr.rows=row;
	arr.cols=col;

	arr.data=new int *[row];

	for(int x=0;x<row;x++)
	{
		arr.data[x] = new int[col];
	}
	input.seekg(0);

	int i=0;
	while(getline(input, line))
	{
		int u=0;
		stringstream ss(line);
		int num;
		while(ss>>num)
		{
			arr.data[i][u] = num;
			u++;
		}
		i++;
	}
	return input;
}

ostream & operator << (ostream & output, Matrix2D & arr)
{
	for(int i=0; i<arr.rows; i++)
	{
		for(int j=0; j<arr.cols; j++)
		{
			output << arr.data[i][j];
		}
		cout << endl;
	}

	return output;
}

Matrix2D & Matrix2D:: operator += (const Matrix2D &rhs)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			data[i][j] += rhs.data[i][j];
		}
	}
	return *this;
}

Matrix2D &Matrix2D:: operator = (const Matrix2D &rhs)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			data[i][j] = rhs.data[i][j];
		}
		delete rhs.data[i];
	}
	delete rhs.data;
	return *this;
}

Matrix2D operator +(const Matrix2D &lhs, const Matrix2D &rhs)
{
	Matrix2D temp = Matrix2D(lhs);
	for(int i = 0; i < lhs.rows ; i++)
    {
        for(int j = 0; j < lhs.cols ; j++)
        {
            temp.data[i][j] += rhs.data[i][j];
        }
    }
    return temp;
}

Matrix2D::Matrix2D(const int & r, const int & c): rows(r), cols(c) {
	data = new int* [r]; 
	for (int i = 0; i<rows; i++) 
		data[i] = new int[cols];
}

int Matrix2D::GetIndex(const int & i, const int & j) const{
    return data[i][j];
}

void Matrix2D::SetIndex(const int & i, const int & j, const int &value) const{
    data[i][j] = value;
}

Matrix2D::~Matrix2D()
{
    for(int i = 0; i< rows; i++)
    {
        delete [] data[i];
    }
    delete[] data;
}

#endif
