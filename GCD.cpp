#include <iostream>
using namespace std;

int gcd(int a, int b){
    // while (b != 0)
    // {
    //     int temp = b;
    //     b = a%b;
    //     a = temp;
    // }
    // return a;
    if (a==0)
        return b;
    if (b==0)
        return a;

    return gcd(b, a%b);
}

int main(){
    cout << "Enter two numbers to find their GCD: ";
    int x, y;
    cin >> x >> y;

    cout << "GCD IS: " << gcd(x, y);
    return 0;
}