#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int binary_search(int a[], int low , int high, int key)
{
    int middle = (low + high)/2;  //finds the middle of the array
    while (high >= low)
    {
        if (key < a[middle])
        {
            return binary_search(a, low, middle - 1, key); //low does not change, high is the middle - 1
        }
        else if (key == a[middle])
        {
            return middle;
        }
        else
        {
            return binary_search(a, high, middle + 1, key); //high does not change
        }
    }
    return low - 1;
}

int main(void)
{
    int size;
    int b[7];
    int i;
    int value;
    int index1;
    cout << "Enter number of elements: ";
    cin >> size;
    b[size]; // set array to number of elements inputted by user
    cout << "Enter " << size << " integers: ";
    for (i = 0; i < size; i++){
        cin >> b[i];
    }
    cout << "Enter the value to find: ";
    cin >> value;
    index1 = binary_search(b, 1, size, value);
    cout << "The number " << value << " is found at location: " << index1+1 << endl;

    cout << endl;
    //int a[] = { -4, 5, 8, 9, 11, 43, 485};
    //int idx;

    //idx = binary_search(a, 0, 15, 11);
    //printf("Number exists in the %dth position\n", idx);

    getchar();
    return 0;
}
