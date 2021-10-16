// Fractional Knapsack

// You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
// Note: You are allowed to break the items in parts.
// Input Format:
// The first line of input contains two space separated integers, that denote the value of N and W.
// Each of the following N lines contains two space separated integers, that denote value and weight, respectively, of the N items.    
// Constraints:
// 1 <= N = 2*10^5
// 1 <= W <= 10^9
// 1 <= value, weight <= 10^5
// Time Limit: 1 sec
// Output Format:
// Print the maximum total value upto six decimal places.
// Sample Input 1:
// 4 22
// 6 4
// 6 4
// 4 4
// 4 4
// Sample Output 1:
// 20.000000
// Explanation:
// The total weight of all the items is 16 units, which is less than the total capacity of knapsack, i.e 22 units. Hence, we will add all the items in the knapsack and total value will be 20 units.

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class Item
{
public:
    double value, weight;
};

bool sortFunc(Item i1, Item i2)
{
    return i1.value/i1.weight > i2.value/i2.weight;
}

int main()
{
    cout<<setprecision(6)<<fixed;
    
    ll n, w;
    cin>>n>>w;
    
    Item* arr = new Item[n];
    
    for (int i=0;i<n;i++)
        cin>>arr[i].value>>arr[i].weight;
    
    sort(arr, arr+n, sortFunc);
    double maxProfit = 0;
    
    int i = 0;
    
    while (w >= 0 && i < n)
    {
        if (w - arr[i].weight < 0)
        {
            maxProfit += w * arr[i].value/arr[i].weight;
            break;
        }
        
        maxProfit += arr[i].value;
        w -= arr[i].weight;
        i++;
    }
    
    cout<<maxProfit<<"\n";
    
    return 0;
}
