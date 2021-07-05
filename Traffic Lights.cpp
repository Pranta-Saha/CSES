// I just keep track of gaps using a multiset, which was initialized by x(coz at first full road was a gap)
// Considering a position is actualy pertitioning a gap into two.
// I just find that gap containing the position, delete that gap, insert two new gap. 
// biggest one gap is answer of each iteration. 

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,n,i,p,lft,rht,gap;
	cin>>x>>n;
	multiset<int>gaps;
	set<int>positions;
	gaps.insert(x);

	while(n--)
	{
		cin>>p;
		positions.insert(p);
		auto it = positions.find(p);
		if( it == positions.begin() )
		{
			lft = 0;
		}
		else 
		{
			it--;
			lft = *it;
			it++;
		}
		it++;
		rht = (it == positions.end())? x : *it;
	      	gap = rht-lft;
		gaps.erase( gaps.find(gap) );
		gaps.insert( p-lft );
		gaps.insert( rht-p );
		cout<< *gaps.rbegin()<<endl;
	}
}
