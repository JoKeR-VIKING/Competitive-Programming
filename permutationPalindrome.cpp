#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        string s;
        cin>>s;

        map<char, vector<int>> m;
        vector<int> vect(s.length());

        for (int i=0;i<s.length();i++)
            m[s[i]].push_back(i);

        int odd_count = 0;

        for (int i=0;i<26;i++)
        {
            if (m[i + 'a'].size() % 2)
                odd_count++;
        }

        if (odd_count > 1)
        {
            cout<<"-1\n";
            continue;
        }

        int i = 0;
        vector<int> odd_vect;

        for (auto& it : m)
        {
            if (it.second.size() % 2)
            {
                odd_vect = it.second;
                continue;
            }
            for (int j=0;j<it.second.size();j+=2, i++)
            {
                vect[i] = it.second[j];
                vect[s.length() - i - 1] = it.second[j+1];
            }
        }

        if (odd_vect.size() > 0)
        {
            for (int j=0;j<odd_vect.size();j+=2, i++)
            {
                vect[i] = odd_vect[j];
                
                if (j < odd_vect.size() - 1)
                    vect[s.length() - i - 1] = odd_vect[j+1];
            }
        }
        
        for (auto& it : vect)
            cout<<it+1<<" ";

        cout<<"\n";
    }

    return 0;
}
