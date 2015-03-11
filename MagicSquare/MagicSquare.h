//
//  MagicSquare.h
//  MagicSquare
//
//  Created by Russ Fenenga on 3/4/15.
//  Copyright (c) 2015 com. All rights reserved.
//

#ifndef __MagicSquare__MagicSquare__
#define __MagicSquare__MagicSquare__

#include <stdio.h>
#include <vector>
using namespace std;

class MagicSquare{
public:
    MagicSquare(int);
    void display();
    int sumForRow (int);
    int sumForCol (int);
};

#endif /* defined(__MagicSquare__MagicSquare__) */
