// I just keep track of children using set. 
// after print a number I erased that and increased iterator twoice. 

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	set<int>st;
	cin>>n;
	for(i=1; i<=n; i++)
		st.insert(i);
	auto it = st.begin();
	it++;
	if(n==1) { cout<<1<<endl; return 0; }
	while( !st.empty() )
	{
		cout<<*it<<" ";
		int tmp = *it;
		st.erase(it);
		if(st.empty()) break;
		it = st.upper_bound(tmp);
		if(it == st.end() )
			it = st.begin();
		it++;
		if(it == st.end() )
			it = st.begin();
	}
	return 0;
}

