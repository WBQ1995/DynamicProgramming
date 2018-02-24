//
//  Knapsack-01.cpp
//  DynamicProgramming
//
//  Created by PRO on 2018-02-24.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;
int Knapsack_01(int capacity,int w[],int value[],int num_object);

int main(int argc, const char * argv[]) {
    
    int capacity = 200;
    int weight[8] = {79,58,86,11,28,62,15,68};
    int value[8] = {83,14,54,79,72,52,48,62};
    
    int num_object = sizeof(value)/sizeof(value[0]);
    
    int total = Knapsack_01(capacity,weight,value,num_object);
    
    cout<<"Maximum total value is: "<<total<<endl;
    cout<<endl;
    
    return 0;
}

int Knapsack_01(int capacity,int weight[],int value[], int num_object){

    int w[capacity + 1][num_object + 1];
    int chose[capacity + 1][num_object + 1];
    
    for(int i = 0;i <= num_object;i ++){
        w[0][i] = 0;
    }
    for(int i = 0; i <= capacity; i ++){
        w[i][0] = 0;
    }
    
    for(int i = 1; i <= capacity; i ++){
        for(int j = 1;j <= num_object; j ++){
            
            int left = w[i][j - 1];
            int right = 0;
            
            if(i - weight[j - 1] >= 0){
                right = w[i - weight[j - 1]][j - 1] + value[j - 1];
            }
            if(left < right){
                w[i][j] = right;
                chose[i][j] = 1;
            }
            else{
                w[i][j] = left;
            }
        }
    }
    
    int CurrentWeight = capacity;
    int n = num_object;

    while(chose[CurrentWeight][n]!= 0){
        if(chose[CurrentWeight][n] == 1){
            cout<<"Object: "<<n<<" "<<"Value: "<< value[n - 1]<<endl;
        }
        CurrentWeight -= weight[n - 1];
        n --;
    }
    
    return w[capacity][num_object];

    return 0;
}
