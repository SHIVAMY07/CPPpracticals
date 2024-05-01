#include <iostream>
using namespace std;

void printAddress(const char* str) 
{
    while (*str != '\0') 
    {
        cout << "Character: " << *str << ", Address: " << (void*)str << endl;
        str++;
    }
}
int strLength(char*str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void copyStr(char*str1, char*str2)
{
    int i = 0;
    while(str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}

void concatenateStr(const char* str1, const char* str2, char* result) {
    int i = 0;
    int j = 0;

    while (str1[i] != '\0') {
        result[j++] = str1[i++];
    }

    i = 0;
    while (str2[i] != '\0') {
        result[j++] = str2[i++];
    }

    // Null-terminate the result string
    result[j] = '\0';
}

int compareStr(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}

void toUpperCase(char* str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}

int strReverse(char*str)
{
    int i = 0;
    int j = strLength(str) - 1;
    
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void insertString(char*destination, char*source, int position) {
    int destLength = strLength(destination);
    int sourceLength = strLength(source);

    // Shift characters to make space for the inserted string
    for (int i = destLength; i >= position; i--) {
        destination[i + sourceLength] = destination[i];
    }

    // Copy the source string into the destination at the specified position
    for (int i = 0; i < sourceLength; i++) {
        destination[position + i] = source[i];
    }
}

int main() 
{
    char str1[100];
    char str2[100];
    int position;

    cout << "Enter the first string: ";
    cin.getline(str1, 100);

    cout << "Enter the second string: ";
    cin.getline(str2, 100);

    // Example usage of the provided functions
    char result[200];

    // Length of a string
    cout << "Length of str1: " << strLength(str1) << endl;

    // Printing address of the character
    cout << "Addresses of characters in str1:" << endl;
    printAddress(str1);

    // Copying a string
    copyStr(str1, result);
    cout << "Copied string: " << result << endl;

    // Concatenating strings
    concatenateStr(str1, str2, result);
    cout << "Concatenated string: " << result << endl;

    // Comparing strings
    int comparison = compareStr(str1, str2);
    if (comparison < 0) 
    {
        cout << "str1 is less than str2" << endl;
    } 
    else if (comparison > 0) 
    {
        cout << "str1 is greater than str2" << endl;
    } 
    else 
    {
        cout << "str1 is equal to str2" << endl;
    }

    // Convert the string to uppercase
    toUpperCase(str1);
    cout << "Uppercase string: " << str1 << endl;

    // Reversing a string
    strReverse(str1);
    cout << "Reversed str1: " << str1 << endl;

    cout << "Enter a string to insert: ";
    cin.getline(str2, 100);

    cout << "Enter the position to insert the string: ";
    cin >> position;

    // Insert the string into the original string at the specified position
    insertString(str1, str2, position);
    cout << "Modified string after insertion: " << str1 << endl;
    return 0;
}
