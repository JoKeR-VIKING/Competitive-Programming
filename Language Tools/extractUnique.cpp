#include<bits/stdc++.h>

string uniqueChar(string str) 
{
    unordered_map<char, bool> m;
    string s;
    
    for (auto it : str)
    {
        if (!m[it])
        {
            m[it] = true;
            s.push_back(it);
        }
    }
    
    return s;
}
