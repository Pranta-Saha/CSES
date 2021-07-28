// applied binary search over answer/minimum time required. 
// for each prediction/mid, I just itterate over given times, and calculated how many products I can produce within prediction time. if it less then "t", I updated lo=mid+1, else hi=mid-1.

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,t,i,ans,sum,lo,hi,mid;
	cin>>n>>t;
	vector<long long>machines(n);
	for(i=0;i<n;i++)
		cin>>machines[i];
	sort(machines.begin(),machines.end());
	lo=1;
	hi=(machines[0]*t);
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		sum=0;
		for(i=0;i<n;i++)
		{
			if( mid/machines[i] == 0 ) break;
			sum+=(mid/machines[i]);
		}
		if(sum < t) lo=mid+1;
		else
		{
			hi=mid-1;
			ans=mid;
		}
	}
	cout<<ans<<endl;

}
