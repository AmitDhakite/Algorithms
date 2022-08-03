#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& v) 
{
    int n = v.size();
    for(int i = 0; i < n-1; i++)
    {
        int minInd = i;
        for(int j = i+1; j < n; j++)
        {
            if(v[minInd] > v[j])
                minInd = j;
        }
        
        swap(v[i], v[minInd]);
    }
}

int main()
{
    int n; 
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    selectionSort(v);
    for(auto &it: v)
        cout<<it<<" ";

    return 0;
}