//
//  main.cpp
//  MagicSquare
//
//  Created by Russ Fenenga on 3/4/15.
//  Copyright (c) 2015 com. All rights reserved.
//

#include <iostream>
#include <vector>
#include "MagicSquare.h"
using namespace std;

int main() {
    int dim = 0;
    bool done = false;
    bool validRow = false;
    bool validCol = false;
    int row =0;
    int col = 0;
    while(!done){
        cout << "Enter an odd number between 1 and 15 or 0 to quit. \n";
        cin >> dim;
        if(((dim>=1)&&(dim<=15))&&(dim%2!=0)){
            validRow=false;
            validCol=false;
            MagicSquare square(dim);
            square.display();
            cout << "What row would you like to sum up? \n";
            while(!validRow){
                cin >> row;
                if ((row<=dim)&&(row>0)){
                    square.sumForRow(row);
                    validRow=true;
                }else{
                    cout << "Please enter a valid row using 1 based indexing. \n";
                }
            }
            cout << "What column would you like to sum up? \n";
            while(!validCol){
                cin >> col;
                if ((col<=dim)&&(col>0)){
                    square.sumForCol(col);
                    validCol=true;
                }else{
                    cout << "Please enter a valid column using 1 based indexing. \n";
                }
            }

        } else if (dim==0) {
            done = true;
        } else {
            cout << "Please follow the rules. \n";
        }
    }
}
