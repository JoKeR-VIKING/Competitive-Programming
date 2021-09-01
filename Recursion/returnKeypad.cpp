#include <bits/stdc++.h>
using namespace std;

string m[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void help(string output[], string s, int num, int& i)
{
    if (num == 0)
    {
        output[i++] = s;
        return;
    }
    
    int size = m[(num % 10)].length();
    
    for (int j=0;j<size;j++)
    {
        string sub = m[num % 10][j] + s;
        help(output, sub, num/10, i);
    }
}

int keypad(int num, string output[])
{
    int i = 0;
    string s;
    
    help(output, s, num, i);
    
    return i;
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin>>n;
        
        string output[10000];
        int size = keypad(n, output);
        
        for (int i=0;i<size;i++)
            cout<<output[i]<<"\n";
    }
}
