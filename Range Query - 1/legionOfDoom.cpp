// Legion of Doom
// Send Feedback
// Lex Luthor’s Legion of Doom is a tough organization to get into, even for greatest supervillains. Recently, a spot has opened up because The Mad Hatter has retired. Harley Quinn doesn't want to waste this opportunity, and jumps at the chance of the interview. But she has a PhD in psychology, not in Computer Science. She has kidnapped you and will let you go only if you are able to solve the evil questions of Lex Luthor.
// You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
// 0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.
// 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
// Input Format:
// In the first line you'll be given T, number of test cases.

// Each test case will start with N and C. After that you'll be given C commands in the format as mentioned above
// Constraints:
//  1 <= T <= 10
//  1 <= N, C <= 10000
//  1 <= val <= 10^8
//  1 <= p <= q <= N
// Output Format:
// Print the answers of the queries in new line for each test case.
// Sample Input 1:
// 1
// 8 6
// 0 2 4 26
// 0 4 8 80
// 0 4 5 20
// 1 8 8 
// 0 5 7 14
// 1 4 8
// Sample Output 1:
// 80  
// 508

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void updateTree(vector<ll>& segmentTree, vector<ll>& lazy, ll start, ll end, ll idx, ll l, ll r, ll val)
{
    if (start > end)
        return;
    if (lazy[idx] != 0)
    {
        segmentTree[idx] += (end - start + 1) * lazy[idx];

        if (start < end)
        {
            lazy[2*idx + 1] += lazy[idx];
            lazy[2*idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (end < l || start > r)
        return;
    if (start >= l && end <= r)
    {
        segmentTree[idx] += (end - start + 1) * val;

        if (start < end)
        {
            lazy[2*idx + 1] += val;
            lazy[2*idx + 2] += val;
        }

        return;
    }

    ll mid = start + (end - start)/2;
    updateTree(segmentTree, lazy, start, mid, 2*idx + 1, l, r, val);
    updateTree(segmentTree, lazy, mid + 1, end, 2*idx + 2, l, r, val);

    segmentTree[idx] = segmentTree[2*idx + 1] + segmentTree[2*idx + 2];
}

ll query(vector<ll>& segmentTree, vector<ll>& lazy, ll start, ll end, ll idx, ll l, ll r)
{
    if (start > end)
        return 0;
    if (lazy[idx] != 0)
    {
        segmentTree[idx] += (end - start + 1) * lazy[idx];

        if (start < end)
        {
            lazy[2*idx + 1] += lazy[idx];
            lazy[2*idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (end < l || start > r)
        return 0;
    if (start >= l && end <= r)
        return segmentTree[idx];

    ll mid = start + (end - start)/2;

    ll x = query(segmentTree, lazy, start, mid, 2*idx + 1, l, r);
    ll y = query(segmentTree, lazy, mid + 1, end, 2*idx + 2, l, r);

    return x + y;
}

int main()
{
    ll t;
    cin>>t;

    while (t--)
    {
        ll n, c;
        cin>>n>>c;

        vector<ll> segmentTree(4*n);
        vector<ll> lazy(4*n);

        while (c--)
        {
            ll type;
            cin>>type;

            if (type == 1)
            {
                ll l, r;
                cin>>l>>r;

                cout<<query(segmentTree, lazy, 0, n-1, 0, l-1, r-1)<<"\n";
            }
            else
            {
                ll l, r, val;
                cin>>l>>r>>val;

                updateTree(segmentTree, lazy, 0, n-1, 0, l-1, r-1, val);
            }
        }
    }

    return 0;
}
