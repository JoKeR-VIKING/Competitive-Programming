#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, int> m;
    
    int n;
    cin>>n;
    
    string s;
    cin>>s;
    
    for (int i=0;i<n;i++)
        m[s[i]]++;
    
    cout<<m['a']<<" "<<m['s']<<" "<<m['p']<<"\n";
    
	return 0;
}
