#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,c;
    cin>>n;
    multiset<int>mst;
    while(n--)
    {
        cin>>c;
        auto it=mst.upper_bound(c);
        if( it != mst.end()) 
            mst.erase(it);
        mst.insert(c);
    }
    cout<<mst.size()<<endl;
}