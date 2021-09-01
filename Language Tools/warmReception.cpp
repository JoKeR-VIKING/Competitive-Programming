#include<bits/stdc++.h>

using namespace std;

int Countchair(int arr[], int dep[], int n) 
{ 
  
   sort(arr, arr+n); 
   sort(dep, dep+n); 
  
    
   int chair_needed = 1, result = 1; 
   int i = 1, j = 0; 
  
  
   while (i < n && j < n) 
   { 
      
      if (arr[i] <= dep[j]) 
      { 
          chair_needed++; 
          i++; 
  
         
          if (chair_needed > result)  
              result = chair_needed; 
      } 
  
      else
      { 
          chair_needed--; 
          j++; 
      } 
   } 
  
   return result; 
}

int main() 
{
    int n;
    cin>>n;
    
    int* startTime = new int[n];
    int* endTime = new int[n];
    
    for (int i=0;i<n;i++)
    	cin>>startTime[i];
    
    for (int i=0;i<n;i++)
    	cin>>endTime[i];
    
    int chairs = Countchair(startTime, endTime, n);
    
    cout<<chairs<<"\n";
}
