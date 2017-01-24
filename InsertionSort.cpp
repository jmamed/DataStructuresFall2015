#include <cstdlib>
#include <iostream>

using namespace std;
void insertionsort(int arr[], int length);
void print_array(int array[],int size);

int main() {

int array[6]= {12,11,13,5,6};
insertionsort(array,6);

 return 0;
}

void insertionsort(int arr[], int length) {
    int i, j ,tmp;
    for (i = 1; i < length; i++) {
            j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
    arr[j] = arr[j - 1];
    arr[j - 1] = tmp;
    j--;
    }
    print_array(arr,6);
    }
 }

void print_array(int array[], int size){
    cout<< "sorting: ";
    int j;
    for (j=0; j<size;j++)
        for (j=0; j<size;j++)
        cout <<" "<< array[j];
    cout << endl;
 }
