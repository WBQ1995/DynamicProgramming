//
//  IncertPalindrome.cpp
//  DynamicProgramming
//
//  Created by PRO on 2018-03-01.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;
int Incert_Palindrome(char array[],int p,int r);

int main(int argc, const char * argv[]) {
    
    char array[5] = {'A','B','3','B','D'};
    int num_character = Incert_Palindrome(array,0,4);
    cout<<num_character<<endl;
    return 0;
}

int Incert_Palindrome(char array[],int p,int r){
    if(p <= r){
        if(p == r){
            return 0;
        }
        else if(array[p] == array[r]){
            return Incert_Palindrome(array, p + 1, r - 1);
        }
        else{
            int left = Incert_Palindrome(array, p + 1, r);
            int right = Incert_Palindrome(array, p, r - 1);
            if(left < right)
                return left + 1;
            else
                return right + 1;
        }
    }
    return 0;
}
