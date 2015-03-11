//
//  MagicSquare.cpp
//  MagicSquare
//
//  Created by Russ Fenenga on 3/4/15.
//  Copyright (c) 2015 com. All rights reserved.
//

#include "MagicSquare.h"
#include <vector>
#include <iostream>
using namespace std;

//contruct the board.

int size = 0;
vector<vector<int>> square(0, vector<int>(0,0));

//Contructor for building the square.
MagicSquare::MagicSquare(int dim){
    size = dim;
    vector<vector<int>> v2DVector(dim, vector<int>(dim,0));
    
    // Set the indices to the first row and middle column.
    int row = 0;
    int col = size/2;
    
    // One by one put all values in magic square
    for (int value=1; value <= size*size; value++){
        //check top row then go to bottom
        if (row < 0){
            row = size-1;
        }
        //if at the right edge
        if (col == size){
            col = 0;
        }
        //check if there is a value in the spot
        if (v2DVector[row][col]!=0){
            row=row+2;
            col=col-1;
        }
        v2DVector[row][col] = value;
        
        //check if you are in the top right and fix it
        
        if((col==size-1)&&(row==0)&&(v2DVector[row][col])){
            row = 1;
        } else {
            row = row - 1;
            col = col +1;
        }
    }
    // set to global vector because i'm lazy AF
    square = v2DVector;
    
}

void MagicSquare::display(){
    
    cout << "Magic Square for size " << size << ".\n";
    for(int i = 0;i<size;i++){
        for(int j = 0; j<size;j++){
            cout << square[i][j] << " ";
        }
        cout << "\n";
    }
}

int MagicSquare::sumForRow(int row){
    int sum = 0;
    row = row - 1; //change to 0 based indexing from the 1 based indexing that was passed in.
    for (int i = 0;i<size;i++){
        int val = square[row][i];
        cout<< val << "\t";
        sum = sum + val;
    }
    cout << "\n";
    cout << "The sum for row " << row + 1 << " is " << sum << ".\n";
    return sum;
}
int MagicSquare::sumForCol(int col){
    int sum = 0;
    col= col - 1; //change to 0 based indexing from the 1 based indexing that was passed in.
    for (int i = 0;i<size;i++){
        int val = square[i][col];
        cout<< val << "\n";
        sum = sum + val;
    }
    cout << "The sum for column " << col + 1 << " is " << sum << ".\n";
    return sum;
}