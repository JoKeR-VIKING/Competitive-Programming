#include <iostream>
#include <string>
#include "solution.h"

using namespace std;

string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helpPrint(int num, string s)
{
    if (num == 0)
    {
        cout<<s<<"\n";
        return;
	}
    
    int size = arr[num%10].length();
    
    for (int i=0;i<size;i++)
    {
        string sub = arr[num % 10][i] + s;
        helpPrint(num / 10, sub);
    }
}

void printKeypad(int num)
{
    string s;
    
    helpPrint(num, s);
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
