// It easily understandable by simulate some testcase that, answer will be max of twoice of maximum given time or sum of all times. 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,i,time,sum=0,mx=INT_MIN;
	cin>>n;
	for(i=0;i<n;i++) 
	{
		cin>>time;
		sum+=time;
		mx=max(mx,time);
	}
	cout<<max(sum,2*mx)<<endl;
}
