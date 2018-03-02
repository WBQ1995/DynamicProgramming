//
//  LongetPalindrome.cpp
//  DynamicProgramming
//
//  Created by PRO on 2018-03-01.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;
int Max_Palindrome(char array[],int p,int r);

int main(int argc, const char * argv[]) {

    char array[10] = {'B','B','A','B','A','A','B','A','B','B'};
    int LongetPalindrome = Max_Palindrome(array,0,9);
    cout<<LongetPalindrome<<endl;
    return 0;
}
int Max_Palindrome(char array[],int p,int r){
    
    if(p <= r){
        if(p == r){
            return 1;
        }
        else if(array[p] == array[r])
            return 2 + Max_Palindrome(array, p + 1, r - 1);
        else{
            int left  = Max_Palindrome(array, p + 1, r);
            int right = Max_Palindrome(array, p, r - 1);
            if(left > right)
                return left;
            else
                return right;
        }
    }
    return 0;
}
