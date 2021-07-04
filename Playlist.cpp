// two pointer
// I just keep ereasing arr[j], untill set contains no arr[i] 


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,mx=0,k,j=0;
	cin>>n;
	vector<int>vec(n);
	set< int >st;
	for(i=0;i<n;i++)
	{
		cin>>k;
		vec[i]=k;
		while( st.find(k) != st.end() )
		{
			st.erase(vec[j++]);
		}
		st.insert(k);
		mx = max( mx, (int)st.size());
	}
	cout<<mx<<endl;
}

