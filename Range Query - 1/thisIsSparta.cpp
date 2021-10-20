// This is Sparta!
// Send Feedback
// King Leonidas of Sparta is preparing his men and country for a war against the Persian King Xerxes. He has N soldiers with him and he has arranged them in a line at The Hot Gates. Let us number them from 1 to N. Leonidas will fight Xerxes' army for Q days, and each day he can send only one of his men to fight.
// For each warrior, we know 2 traits: Strength and Cowardice. These are given to us in a form of integer. Each day, Leonidas can choose his warrior from a range Li to Ri, and he will choose the warrior with maximum Strength value. If there is more than one warrior having the same maximum Strength value, he will choose the warrior with minimum Cowardice value. If there is still more than 1 warrior with the same maximum Strength value and same minimum Cowardice value, he chooses the one with lower index in line.
// King Leonidas is ready to lay his life for Sparta. You, his right hand man, have to help him save Sparta by helping him choose a warrior for each day.
// Input Format:
// First line contains a single integer N, denoting the number of warriors Leonidas has. 
// Second line contains N space separated integers, representing Strength of ith warrior. 
// Third line contains N space separated integers, representing Cowardice of ith warrior
// Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
// Each of the next Q lines contains 2 integers Li and Ri.
// Constraints:
// 1 ≤ N,Q ≤ 10^5
// 1 ≤ Ai,Bi ≤ 10^9
// 1 ≤ Li ≤ Ri
// Output Format:
// For each Li and Ri, print the index of the warrior that King Leonidas should choose.
// Sample Input 1:
// 5
// 1 8 4 6 8
// 4 8 6 3 7
// 4
// 1 4
// 2 4
// 3 4
// 1 5
// Sample Output 1:
// 2
// 2
// 4
// 5

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class Warrior
{
public:
    ll strength, cowardice, index;
};

void buildTree(Warrior* arr, Warrior* segmentTree, int start, int end, int idx)
{
    if (start == end)
    {
        segmentTree[idx] = arr[start];
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(arr, segmentTree, start, mid, 2*idx + 1);
    buildTree(arr, segmentTree, mid + 1, end, 2*idx + 2);
    
    Warrior x = segmentTree[2*idx + 1];
    Warrior y = segmentTree[2*idx + 2];
    
    if (x.strength > y.strength)
        segmentTree[idx] = x;
    else if (x.strength < y.strength)
    	segmentTree[idx] = y;
    else
    {
        if (x.cowardice < y.cowardice)
            segmentTree[idx] = x;
        else if (x.cowardice > y.cowardice)
            segmentTree[idx] = y;
        else
        {
            if (x.index < y.index)
            	segmentTree[idx] = x;
        	else
            	segmentTree[idx] = y;
        }
    }
}

Warrior bestWarrior(Warrior* segmentTree, int start, int end, int idx, int l, int r)
{
    if (end < l || start > r)
        return {LLONG_MIN, LLONG_MAX, LLONG_MAX};
    if (start >= l && end <= r)
        return segmentTree[idx];
    
    int mid = start + (end - start)/2;
    
    Warrior x = bestWarrior(segmentTree, start, mid, 2*idx + 1, l, r);
    Warrior y = bestWarrior(segmentTree, mid + 1, end, 2*idx + 2, l, r);
    
    if (x.strength > y.strength)
        return x;
    else if (x.strength < y.strength)
    	return y;
    else
    {
        if (x.cowardice < y.cowardice)
            return x;
        else if (x.cowardice > y.cowardice)
            return y;
        else
        {
            if (x.index < y.index)
            	return x;
        	else
            	return y;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    Warrior* arr = new Warrior[n];
    Warrior* segmentTree = new Warrior[4*n];
    
    for (int i=0;i<n;i++)
    {
        cin>>arr[i].strength;
        arr[i].index = i;
    }
    
    for (int i=0;i<n;i++)
        cin>>arr[i].cowardice;
    
    buildTree(arr, segmentTree, 0, n-1, 0);
    
    int q;
    cin>>q;
    
    while (q--)
    {
        int l, r;
        cin>>l>>r;
        
        cout<<bestWarrior(segmentTree, 0, n-1, 0, l-1, r-1).index + 1<<"\n";
    }
    
    return 0;
}
