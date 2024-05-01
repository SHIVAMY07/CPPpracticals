
#include <iostream>
#include <fstream>
#include <cctype> // for isspace function
using namespace std;

int main() {
    
    ifstream sourceFile("source.txt");
    if (!sourceFile) {
        cerr << "Error: Unable to open source file." << endl;
        return 1;
    }

    ofstream destFile("destination.txt");
    if (!destFile) {
        cerr << "Error: Unable to open destination file." << endl;
        sourceFile.close();
        return 1;
    }

    
    char ch;
    while (sourceFile.get(ch)) {
        if (!isspace(ch)) {
            destFile.put(ch);
        }
    }

    sourceFile.close();
    destFile.close();

    cout << "Contents copied from source file to destination file after removing whitespaces." << endl;
    return 0;
}
