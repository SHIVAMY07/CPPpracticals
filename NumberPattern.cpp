#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;
    for (int x=0; x<m; x++)
    {
        for (int y=0; y<x; y++)
        {
            cout << x;
        }
        cout << endl;
    }
}