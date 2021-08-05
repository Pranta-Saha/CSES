//Imaginge an array consist of modulas of given values by n.
//Then make a prefix sum array
//Now mod each value of preffix sum array by n
//Now this converted into number of subarray with sum 0. 
//Becouse we used only modulas values of given array

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,i,a,sum=0,tmp,ans=0;
	cin>>n;
	map<long long,long long>mp;
	mp[0]=1;
	for(i=0;i<n;i++)
	{
		cin>>a;
		a%=n;
		sum+=a;
		tmp=sum%n;
		if(tmp<0) tmp+=n;
		ans+=mp[tmp];
		mp[tmp]++;
	}
	cout<<ans<<endl;
}
