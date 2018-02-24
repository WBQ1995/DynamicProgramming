//
//  Knapsack-infinitely.cpp
//  DynamicProgramming
//
//  Created by PRO on 2018-02-24.
//  Copyright © 2018 AIR. All rights reserved.
//

#include <iostream>
using namespace std;
int Knapsack_infinitely(int capacity,int w[],int value[]);

int main(int argc, const char * argv[]) {
    
    int capacity = 9;
    int weight[2] = {5,3};
    int value[2] = {3,2};
    
    int total = Knapsack_infinitely(capacity,weight,value);
    
    cout<<"Maximum total vale is: "<<total<<endl;
    cout<<endl;
    
    return 0;
}

int Knapsack_infinitely(int capacity,int weight[],int value[]){
    
    int w[capacity + 1];
    int chose[capacity + 1];
    for(int i = 0; i < capacity + 1;i ++){
        w[i] = 0;
        chose[i] = -1;
    }
    
    for(int i = 1;i <= capacity;i ++){
        for(int j = 0;j < sizeof(value)/sizeof(value[0]);j ++){
            if(i - weight[j] >= 0){
                int temp = value[j] + w[i - weight[j]];
                if(w[i] < temp){
                    w[i] = temp;
                    chose[i] = j;
                }
            }
        }
    }
    int CurrentWeight = capacity;
    while(CurrentWeight >= 0 && chose[CurrentWeight] >= 0 ){
        
        cout<<"Object: "<<chose[CurrentWeight]<<" "<<"Value: "<< value[chose[CurrentWeight]]<<endl;
    
        CurrentWeight -= weight[chose[CurrentWeight]];
    }
    
    
    return w[capacity];
}


