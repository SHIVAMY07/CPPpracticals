#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float s = 1.0;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = 2; i <= n ; i++)
    {
        if (i%2 != 0)
        {
            s += (1.0/pow(i,i));
        }
        else
        {
            s -= (1.0/pow(i,i));
        }

    }
    cout << "Sum of the series upto" << n << "terms is: " << s << endl;
    return 0;
}