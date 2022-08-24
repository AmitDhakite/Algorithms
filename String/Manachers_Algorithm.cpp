#include<bits/stdc++.h>
using namespace std;

vector<int> Manacher(string& s)
{
    string t = "$#";    // for start of string
    for(auto &it: s)
    {
        t.push_back(it);
        t.push_back('#');   // for choosing blank space as center of palindrome
    }
    t.push_back('@');   // for end of string

    int N = t.length();
    vector<int> v(N);
    
    // Manacher's algorithm
    int C = 0, R = 0;
    
    for(int i = 1; i < N - 1; i++)
    {
        int mirr = 2 * C - i;

        if(i < R)
            v[i] = min(R - i, v[mirr]);

        while(t[i + (1 + v[i])] == t[i - (1 + v[i])])
            v[i]++;

        if(i + v[i] > R)
        {
            C = i;
            R = i + v[i];
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout<<i<<" ";
        if(i < 10)
            cout<<" ";
    }
    cout<<endl;
    for(auto &it: t)
        cout<<it<<"  ";
    cout<<endl;
    for(auto &it: v)
        cout<<it<<"  ";
    cout<<endl;

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "CBBD";
    //          0123456789
    vector<int> v = Manacher(s);
    
    return 0;
}