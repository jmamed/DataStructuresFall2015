#include <string>
#include <iostream>
using namespace std;

void countingSort(int *a, int n, int max)
{
	int *counting = new int[max];
	int k = 0;
	for(int i = 0; i < max; i++)
		counting[i] = 0;
	for(int i = 0; i < n; i++)
		counting[a[i]]++;
	for(int i = 0; i < max; i++)
	{
		int count = counting[i];
		for(int j = 0; j < count; j++)
		{
			a[k] = i;
			k++;
		}
	}
}

void Output()
{
	cout << " " << endl;
	int a[] = {1, 4, 1, 2, 7, 5, 2};
	cout << "Original Array: ";
	for(int i = 0; i < 7; i++)
		cout << a[i] << " ";
	cout << endl << endl;
	countingSort(a, 8, 7);
	cout << "CountingSort: ";
	for(int i = 0; i < 8; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	Output();
	return 0;
}
