#include <iostream>
using namespace std;

int binarySearch(int A[], int n, int item)
{
    int beg = 0;
    int end = n - 1;
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (A[mid] == item)
            return mid;
        if (A[mid] > item)
        {
            end = mid - 1;
        }
        if (A[mid] < item)
        {
            beg = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int A[20], n, item, loc;
    cout << "Enter no. of elements in array: ";
    cin >> n;
    cout << "Enter elements of the array in ascending order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "Enter the element you want to search: ";
    cin >> item;
    loc = binarySearch(A, n, item);
    if (loc == -1)
        cout << "Element Not Found" << endl;
    else
        cout << "Element found at index " << loc << endl;

    return 0;
}