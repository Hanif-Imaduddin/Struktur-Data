#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Array{
    int *A;
    int size, length;
};

void displayArray(struct Array arr){
    cout<<"Array: ";
    for(int i = 0;i < arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
}

int main()
{
    struct Array arr;
    cout<<"Enter size of an array: ";
    cin>>arr.size;
    cout<<"Enter length of an array: ";
    cin>>arr.length;
    arr.A = new int[arr.size];
    cout<<"Enter All Elements: ";
    for(int i = 0;i <arr.length;i++){
        cin>>arr.A[i];
    }
    displayArray(arr);
    delete[] arr.A;

    return 0;
}
