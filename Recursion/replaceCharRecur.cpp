#include<bits/stdc++.h>

using namespace std;

void replaceCharacter(string& s, char c1, char c2, int i)
{
    if (i == s.length())
        return;
    
    if (s[i] == c1)
    {
        s[i] = c2;
    }
    
    replaceCharacter(s, c1, c2, i+1);
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
    	string s;
    	cin>>s;
    
    	char c1, c2;
    	cin>>c1>>c2;
        
        replaceCharacter(s, c1, c2, 0);
        
        cout<<s<<"\n";
    }

    return 0;
}
