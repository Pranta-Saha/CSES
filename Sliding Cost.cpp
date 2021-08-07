// I used policy based data structure. As there is no way to keep multiple values, I made pair with indx to get uniqeness.
//

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
	int mid,n,i,k,j=0,range_sum=0;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ordered_set<pair<int,int>>ost;
	for(i=0;i<k;i++)
	{
       		 ost.insert({arr[i],i});
		 range_sum+=arr[i];
	}
	mid=(k-1)/2;
	cout<< abs( (k * (*ost.find_by_order(mid)).first ) - range_sum) <<" ";
	for(i;i<n;i++,j++)
	{
       		ost.erase({arr[j],j});
        	ost.insert({arr[i],i});
		range_sum+=arr[i];
		range_sum-=arr[j];
		cout<< abs( (k * (*ost.find_by_order(mid)).first ) - range_sum) <<" ";
	}
	cout<<endl;
}


