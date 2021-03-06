// Activity Selection
#include<bits/stdc++.h>

using namespace std;

class Activity
{
public:
    int start, finish;
};

bool sortFinish(Activity a1, Activity a2)
{
    if (a1.finish == a2.finish)
        return a1.start > a2.start;
    
    return a1.finish < a2.finish;
}

int main()
{
    int n, activityCount = 1, j = 0;
    cin>>n;
    
    vector<Activity> arr(n);
    
    for (int i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].finish;
    
    sort(arr.begin(), arr.end(), sortFinish);
    
    for (int i=1;i<n;i++)
    {
        if (arr[i].start >= arr[j].finish)
        {
            activityCount++;
            j = i;
        }
    }
    
    cout<<activityCount<<"\n";
    
    return 0;
}
// You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Input Format
// The first line of input contains one integer denoting N.
// Next N lines contains two space separated integers denoting the start time and finish time for the ith activity. 
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di ≤ 10^9
// Output Format
// Output one integer, the maximum number of activities that can be performed
// Sample Input 1
// 6
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9
// Sample Output 1
// 4
// Explanation:
// The four activities will be done at following time intervals:
// 1. 1 2
// 2. 3 4
// 3. 5 7
// 4. 8 9

#include<bits/stdc++.h>

using namespace std;

class Activity
{
public:
    int start, finish;
};

bool sortFinish(Activity a1, Activity a2)
{
    if (a1.finish == a2.finish)
        return a1.start > a2.start;
    
    return a1.finish < a2.finish;
}

int main()
{
    int n, activityCount = 1, j = 0;
    cin>>n;
    
    vector<Activity> arr(n);
    
    for (int i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].finish;
    
    sort(arr.begin(), arr.end(), sortFinish);
    
    for (int i=1;i<n;i++)
    {
        if (arr[i].start >= arr[j].finish)
        {
            activityCount++;
            j = i;
        }
    }
    
    cout<<activityCount<<"\n";
    
    return 0;
}
