// As ans can't be less then max value of array, I took lowerbound of binary search as max of array.
// Each time I check whether I can divide array at most k subarray having subarray sum at most "mid".
// For each value less then answer, the above condition will not be fullfiled.
// But for each value greater then or equal to answer, the above condition will be true. Which is perfect for binary search.


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,i,k,x[200005],ans,mx,mid,lo=0,hi=1e17;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>x[i];
		lo=max(lo,x[i]);
	}
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		ll sum=0,cnt=0;
		mx=0;
		for(i=0;i<n;i++)
		{
			if(sum+x[i] > mid)
			{
				mx=max(mx,sum);
				sum=x[i];
				cnt++;
			}
			else
			{
				sum+=x[i];
			}
		}
		cnt++;
		mx=max(mx,sum);
		if(cnt<=k)
		{
			hi=mx-1;
			ans=mx;
		}
		else
			lo=mid+1;
	}
	cout<<ans<<endl;
}
