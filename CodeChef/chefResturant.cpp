#include <bits/stdc++.h>
#define MOD 1000000007

using ll = long long;

using namespace std;

class Time
{
public:
    ll start, end;

    Time(ll start, ll end)
    {
        this -> start = start;
        this -> end = end;
    }
};

bool sortFunc(Time t1, Time t2)
{
    return t1.start < t2.start;
}

ll lowestMaximumStart(vector<Time>& intervals, ll entry)
{
    ll start = 0, end = intervals.size() - 1, idx = -1;

    while (start <= end)
    {
        ll mid = start + (end - start)/2;

        if (intervals[mid].start == entry)
        {
            return 0;
        }
        else if (intervals[mid].start > entry)
        {
            idx = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (idx == -1)
    {
        if (intervals[0].start >= entry)
            return intervals[0].start - entry;
        else if (intervals.back().end > entry)
            return 0;
        else
            return -1;
    }
    else if (idx == 0 || intervals[idx - 1].end <= entry)
        return intervals[idx].start - entry;
    else
        return 0;
}

int main()
{
    ll t;
    cin>>t;

    while (t--)
    {
        ll n, m;
        cin>>n>>m;

        vector<Time> intervals;

        for (ll i=0;i<n;i++)
        {
            ll s, e;
            cin>>s>>e;

            intervals.push_back({s, e});
        }

        sort(intervals.begin(), intervals.end(), sortFunc);

        while (m--)
        {
            ll entry;
            cin>>entry;

            ll ans = lowestMaximumStart(intervals, entry);

            cout<<ans<<"\n";
        }
    }

    return 0;
}
