#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    // Merge the arrays
    vector<int> mergedArray;
    mergedArray.reserve(arr1.size() + arr2.size());

    // Merge arrays after sorting
    vector<int> sortedArr1 = arr1;
    vector<int> sortedArr2 = arr2;
    sort(sortedArr1.begin(), sortedArr1.end());
    sort(sortedArr2.begin(), sortedArr2.end());

    merge(sortedArr1.begin(), sortedArr1.end(), sortedArr2.begin(), sortedArr2.end(), back_inserter(mergedArray));

    return mergedArray;
}

int main() {
   
    vector<int> arr1 = {5, 3, 7, 1, 9};
    vector<int> arr2 = {8, 6, 2, 4, 10};

   
    vector<int> mergedArray = mergeArrays(arr1, arr2);

   
    cout << "Merged Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
   

    return 0;
}
