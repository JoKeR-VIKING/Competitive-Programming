#include<bits/stdc++.h>

using namespace std;

string removeDuplicates(string s, int i)
{
    if (i == s.length())
        return "";
    
    while (s[i] == s[i+1])
        i++;
    
    string smallString = removeDuplicates(s, i+1);
    
    return s[i] + smallString;
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        string s;
        cin>>s;
        
        s = removeDuplicates(s, 0);
        
        cout<<s<<"\n";
    }
    
    return 0;
}
