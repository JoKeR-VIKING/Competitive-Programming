#include <bits/stdc++.h>

using namespace std;

int main() 
{
    map<string, int> m;
    
    string s, word;
    getline(cin, s);
    
    istringstream ss(s);
    
    while (ss >> word)
        m[word]++;
    
    bool checker = false;
    
    for (auto& it : m)
    {
        if (it.second > 1)
        {
            checker = true;
        	cout<<it.first<<" "<<it.second<<"\n";
        }
    }
    
    if (!checker)
        cout<<-1<<"\n";
    
    return 0;
}
