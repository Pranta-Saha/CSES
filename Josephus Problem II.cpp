// I just keep track of childrens using policy based data structure set. Coz we need to know the value
// at pos, as well as erase. Obviously both in O(logn). 
// Each time I increased pos = pos + k; but it can go beyond set size;
// So I do pos = pos % size_of_set.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> special_set;


int main()
{
	int n,i,k,pos=0;
	special_set st;
	cin>>n>>k;
	for(i=1; i<=n; i++)
		st.insert(i);

	for(i=n; i>=1; i--)
	{
		pos += k;
		pos %= i;
		int tmp = *st.find_by_order(pos);
		cout<<tmp<<" ";
		st.erase(tmp);
	}
	return 0;
}

