#include<bits/stdc++.h>

using namespace std;

char crossword[10][10];

bool canPlaceHorizontally(string currentWord, int i, int j)
{
    if (j-1 >= 0 && crossword[i][j-1] != '+')
        return false;
    if (j + currentWord.length() < 10 && crossword[i][j + currentWord.length()] != '+')
        return false;
    
    for (int k=0;k<currentWord.length();k++)
    {
        if (j + k >= 10)
            return false;
        if (crossword[i][j + k] != '-' && crossword[i][j + k] != currentWord[k])
            return false;
    }
    
    return true;
}

bool* placeHorizontally(string currentWord, int i, int j)
{
    bool* placedWords = new bool[currentWord.length()];
    
    for (int k=0;k<currentWord.length();k++)
    {
        if (crossword[i][j + k] == '-')
        {
        	crossword[i][j + k] = currentWord[k];
            placedWords[k] = true;
        }
    }
    
    return placedWords;
}

void unplaceHorizontally(bool* placedWords, int i, int j, int len)
{
    for (int k=0;k<len;k++)
    {        
        if (placedWords[k])
        {
            crossword[i][j + k] = '-';
            placedWords[k] = false;
        }
    }
}

bool canPlaceVertically(string currentWord, int i, int j)
{
    if (i-1 >= 0 && crossword[i-1][j] != '+')
        return false;
    if (i + currentWord.length() < 10 && crossword[i + currentWord.length()][j] != '+')
        return false;
    
    for (int k=0;k<currentWord.length();k++)
    {
        if (i + k >= 10)
            return false;
        if (crossword[i + k][j] != '-' && crossword[i + k][j] != currentWord[k])
            return false;
    }
    
    return true;
}

bool* placeVertically(string currentWord, int i, int j)
{
    bool* placedWords = new bool[currentWord.length()];
    
    for (int k=0;k<currentWord.length();k++)
    {
        if (crossword[i + k][j] == '-')
        {
        	crossword[i + k][j] = currentWord[k];
            placedWords[k] = true;
        }
    }
    
    return placedWords;
}

void unplaceVeritcally(bool* placedWords, int i, int j, int len)
{
    for (int k=0;k<len;k++)
    {        
        if (placedWords[k])
        {
            crossword[i + k][j] = '-';
            placedWords[k] = false;
        }
    }
}

void printCrossword()
{
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            cout<<crossword[i][j];
        }
        
        cout<<"\n";
    }
}

void solveCrossword(vector<string> words, int idx)
{
    if (idx == words.size())
    {
        printCrossword();
        return;
    }
    
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            if (crossword[i][j] == '-' || crossword[i][j] == words[idx][0])
            {
                if (canPlaceHorizontally(words[idx], i, j))
                {
                    bool* placedWords = placeHorizontally(words[idx], i, j);
                    solveCrossword(words, idx+1);
                    unplaceHorizontally(placedWords, i, j, words[idx].length());
                }
                
                if (canPlaceVertically(words[idx], i, j))
                {
                    bool* placedWords = placeVertically(words[idx], i, j);
                    solveCrossword(words, idx+1);
                    unplaceVeritcally(placedWords, i, j, words[idx].length());
                }
            }
        }
    }
}

int main()
{
	for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            cin>>crossword[i][j];
        }
    }
    
    string s, temp = "";
    cin>>s;
    
    vector<string> words;
    
    for (int i=0;i<s.length();i++)
    {
        if (s[i] == ';')
        {
            words.push_back(temp);
            temp = "";
            continue;
        }
        
        temp.push_back(s[i]);
    }
    
    words.push_back(temp);
    
    solveCrossword(words, 0);
    
    return 0;
}
