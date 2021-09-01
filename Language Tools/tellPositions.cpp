#include<bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name;
    int totalMarks;
    int rollNo;
    
    Student(string name, int totalMarks, int rollNo)
    {
        this -> name = name;
        this -> totalMarks = totalMarks;
        this -> rollNo = rollNo;
    }
};

bool sortByRollNo(Student s1, Student s2)
{
    return s1.rollNo < s2.rollNo;
}

bool sortFunc(Student s1, Student s2)
{
    if (s1.totalMarks == s2.totalMarks)
        return sortByRollNo(s1, s2);
    
    return s1.totalMarks > s2.totalMarks;
}

int main()
{
    int n, i = 0;
    cin>>n;
    
    vector<Student> vect;
    
    while (i < n)
    {
        string s;
        cin>>s;
        
        int a, b, c;
        cin>>a>>b>>c;
        
        vect.push_back({s, a+b+c, i});
        i++;
    }
    
    sort(vect.begin(), vect.end(), sortFunc);
    
    i = 1;
    
    for (auto it : vect)
    {
        cout<<i++<<" "<<it.name<<"\n";
    }
    
	return 0;
}
