// Hasan and Trip

// Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
// There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
// Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
// Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
// Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
// Input format:
// First line will contain T(number of test case).
// First line of each test case will contain an integer N 
// Next N lines of that test case will contain three space-separated integers Xi, Yi, Fi (coordinates and happiness)
// Output format:
// For each test Output one number rounded to 6 digits after floating point, the maximum possible happiness in newline, Hasan can get. 
// Note: If answer is 2 print 2.000000
// Constraints:
// 1 <= T <= 50
// 1 <= N <= 500
// 0 <= Xi, Yi, Fi <= 100,000
// Sample Input
// 1
// 3
// 0 0 1
// 3 1 1
// 6 0 9
// Sample Output
// 4.675445

#include<bits/stdc++.h>

using namespace std;

class City
{
public:
    double x, y, f;

    City()
    {}

    City(double x, double y, double f)
    {
        this -> x = x;
        this -> y = y;
        this -> f = f;
    }
};

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double calcHappiness(City* cities, int n)
{
    double* dp = new double[n];
    
    dp[0] = cities[0].f;
    
    for (int i=1;i<n;i++)
    {
        dp[i] = (double)INT_MIN;
        
        for (int j=i-1;j>=0;j--)
        {
            dp[i] = max(dp[i], dp[j] + cities[i].f - distance(cities[j].x, cities[j].y, cities[i].x, cities[i].y));
        }
    }
    
    return dp[n - 1];
}

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        cout  << setprecision(6)<< fixed;
        
        int n;
        cin>>n;

        City* cities = new City[n];

        for (int i=0;i<n;i++)
        {
            double x, y, f;
            cin>>x>>y>>f;

            cities[i] = City(x, y, f);
        }

        cout<<calcHappiness(cities, n)<<"\n";
    }

    return 0;
}
