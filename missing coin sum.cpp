#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    vector<ll>vec(n);
    for(ll i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    ll prev=0;
    for(ll i=0;i<n;i++)
    {
        if(prev+1 < vec[i])
        {
            cout<<prev+1<<endl;
            return 0;
        }
        prev += vec[i];
    }
    cout<< prev+1 <<endl;
    return 0;
}