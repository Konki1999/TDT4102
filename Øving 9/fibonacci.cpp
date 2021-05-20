#include "fibonacci.h"

void fillInFibonacciNumbers(int result[], int length){
    result[0] = 0;
    result[1] = 1;
    for(int i{2}; i < length; i++){
        result[i] = result[i-1] + result[i-2];
    }
}

void printArray(int arr[], int length){
    for(int i{0}; i < length; i++){
        cout<<arr[i];
        if(i != length-1){
            cout<<", ";
        }
    }
    cout<<endl<<endl;
}

void createFibonacci(){
    int length;
    cout<<"How many Fibonacci-numbers do you want?";
    cin>>length;
    int* result = new int[length];
    fillInFibonacciNumbers(result,length);
    printArray(result,length);
    delete[] result;
}