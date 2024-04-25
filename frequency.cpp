#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        cout << "Usage: " << argv[0] << " <text>" << endl;
        return 1;
    }

    string text = argv[1];
    map<char, int> counts;

    for (char c : text)
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        {
            counts[tolower(c)]++;
        }
    }


    for (auto &entry : counts){
    // {   cout<<"Alphabet    Frequency"<<endl;
        cout << entry.first << " : " << entry.second<< endl;
    }

    return 0;
}