#include <iostream>
#include <algorithm>

using namespace std;

int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    sort(arr, arr+n);

    int temp[n];
    int j = 0;

    for (int i = 0; i < n-1; i++)
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];

        temp[j++] = arr[n-1];

        for (int i = 0; i < j; i++)
            arr[i] = temp[i];

        return j;
}

int main()
{
    int arr[] = {1,2,3,3,4,5,6,3,5,7,6,7,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeDuplicates(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}