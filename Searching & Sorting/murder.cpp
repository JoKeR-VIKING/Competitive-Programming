#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll mergeSortedArr(ll* vect, ll start, ll mid, ll end)
{
    ll i = start, j = mid + 1, sum = 0, k = 0;
    ll* temp = new ll[end - start + 1];

    while (i <= mid && j <= end)
    {
        if (vect[i] < vect[j])
        {
            temp[k] = vect[i];
            sum += (end - j + 1) * vect[i];
            i++;
        }
        else
        {
            temp[k] = vect[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
        temp[k++] = vect[i++];

    while (j <= end)
        temp[k++] = vect[j++];

    for (i=start;i<=end;i++)
    {
        vect[i] = temp[i - start];
    }

    return sum;
}

ll mergeSort(ll* vect, ll start, ll end)
{
    if (start >= end)
        return 0;

    ll mid = start + (end - start)/2;

    ll leftSmaller = mergeSort(vect, start, mid);
    ll rightSmaller = mergeSort(vect, mid + 1, end);

    ll mergeSmaller = mergeSortedArr(vect, start, mid, end);

    return leftSmaller + rightSmaller + mergeSmaller;
}

ll allSmaller(ll* vect, ll n)
{
    return mergeSort(vect, 0, n-1);
}

int main()
{
    ll t;
    cin>>t;

    while (t--)
    {
        ll n;
        cin>>n;

        ll* vect = new ll[n];

        for (ll i=0;i<n;i++)
            cin>>vect[i];

        cout<<allSmaller(vect, n)<<"\n";
    }

    return 0;
}
