//
//  LCS.cpp
//  DynamicProgramming
//
//  Created by PRO on 2018-02-24.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int LCS_Length(char X[],char Y[],int lengthX,int lengthY);
void PrintLCS(char X[],int lengthX,int lengthY, vector<vector<int>> b);

int main(int argc, const char * argv[]) {
    
    char X[10] = {'a','k','c','a','b','c','a','b','c','d'};
    char Y[12] = {'a','b','h','c','a','b','c','a','l','b','c','d'};

    int lengthX = sizeof(X)/sizeof(X[0]);
    int lengthY = sizeof(Y)/sizeof(Y[0]);
    cout<<lengthX<<" "<<lengthY<<endl;
    
    int LCS = LCS_Length(X,Y,lengthX,lengthY);
    cout<<LCS<<endl;
    
}

int LCS_Length(char X[],char Y[],int lengthX,int lengthY){
    
    int c[lengthX + 1][lengthY + 1];
    
    for(int i = 0;i < lengthY; i ++){
        c[0][i] = 0;
    }
    for(int i = 0; i < lengthX;i ++){
        c[i][0] = 0;
    }
    
    //int b[lengthX + 1][lengthY + 1];
    
    vector<vector<int>> b(lengthX + 1);
    for(int i = 0; i <= lengthX; i ++){
        b[i].resize(lengthY + 1);
    }
    
    for(int i = 1; i <= lengthX; i ++){
        for(int j = 1;j <= lengthY; j ++){
            if(X[i - 1] == Y[j - 1]){
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if(c[i - 1][j] > c[i][j - 1]){
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            }
            else{
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }
    PrintLCS(X, lengthX, lengthY, b);
    
    cout<<endl;
    

    return c[lengthX][lengthY];
}
void PrintLCS(char X[],int lengthX,int lengthY, vector<vector<int>> b){
    if(lengthX == 0 || lengthY == 0)
        return;
    if(b[lengthX][lengthY] == 1){
        PrintLCS(X, lengthX - 1, lengthY - 1, b);
        cout<<X[lengthX - 1]<<" ";
    }
    else if (b[lengthX][lengthY] == 2)
        PrintLCS(X, lengthX - 1, lengthY, b);
    else if(b[lengthX][lengthY] == 3)
        PrintLCS(X, lengthX, lengthY - 1, b);
}
