// I just sort the vector by nondecreasing of left, but
// if some left is same then nonincreasing of right
// then for contains, I go through from n-1 to 0 and keep track of min
// and for contained, I go through from 0 to n-1 and keep track of max 

#include<bits/stdc++.h>
using namespace std;

/// block of AVL tree
			class Node
			{
				public:
				int key,frequency,lftcnt,rhtcnt;
				Node *left;
				Node *right;
				int height;
			};

			int height(Node *N)
			{
				if (N == NULL)
					return 0;
				return N->height;
			}

			Node* newNode(int key)
			{
				Node* node = new Node();
				node->key = key;
				node->left = NULL;
				node->right = NULL;
				node->height = 1; 
				node->frequency=1;
				node->lftcnt=0;
				node->rhtcnt=0;
				return(node);
			}

			Node *rightRotate(Node *y)
			{
				Node *x = y->left;
				Node *T2 = x->right;
				x->right = y;
				y->left = T2;
				y->height = max(height(y->left), height(y->right)) + 1;
				x->height = max(height(x->left),height(x->right)) + 1;
				return x;
			}

			Node *leftRotate(Node *x)
			{
				Node *y = x->right;
				Node *T2 = y->left;
				y->left = x;
				x->right = T2;
				x->height = max(height(x->left), height(x->right)) + 1;
				y->height = max(height(y->left), height(y->right)) + 1;
				return y;
			}

			int getBalance(Node *N)
			{
				if (N == NULL)return 0;
				return height(N->left) - height(N->right);
			}
			Node* insert(Node* node, int key)
			{
				if (node == NULL)
					return(newNode(key));
				if (key < node->key)
					node->left = insert(node->left, key);
				else if (key > node->key)
					node->right = insert(node->right, key);
				else //equal
				{
					node->frequency++;
					return node;
				}

				node->height = 1 + max(height(node->left), height(node->right));
				int balance = getBalance(node);
				// Left Left Case
				if (balance > 1 && key < node->left->key)
					return rightRotate(node);
				// Right Right Case
				if (balance < -1 && key > node->right->key)
					return leftRotate(node);
				// Left Right Case
				if (balance > 1 && key > node->left->key)
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
				// Right Left Case
				if (balance < -1 && key < node->right->key)
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
				return node;
			}
			
			
			//after all insertion, use this to update lftcnt,rhtcnt
			//lftcnt=left subtree size
			int dfs_to_update_lft_rht(Node *root)
			{
				if(root==NULL) return 0;
				root->lftcnt = dfs_to_update_lft_rht(root->left);
				root->rhtcnt = dfs_to_update_lft_rht(root->right);
				return root->lftcnt + root->rhtcnt + root->frequency;
			}
			
			void preOrder(Node *root)
			{
				if(root != NULL)
				{
					cout << root->key << " ";
					preOrder(root->left);
					preOrder(root->right);
				}
			}

///




bool cmp(pair< pair<int,int> ,int> a, pair< pair<int,int> ,int> b)
{
	if(a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}

int main()
{
	int n,i,l,r;
	cin>>n;
	vector< pair< pair<int,int> ,int> >vec;
	vector<int>res1(n,0), res2(n,0);

	for(i=0;i<n;i++)
	{
		cin>>l>>r;
		vec.push_back( {{l,r},i} );
	}
	sort( vec.begin(), vec.end(), cmp);
	
	for(i=n-1; i>=0; i--)
	{
		auto tmp = vec[i].first;
		if( tmp.second >= mn )
		{
			res1[ vec[i].second ]=1;
		}
		mn = min( mn, tmp.second );
	}
	
	for(i=0; i<n; i++)
	{
		auto tmp = vec[i].first;
		if( tmp.second <= mx )
		{
			res2[ vec[i].second ]=1;
		}
		mx = max( mx, tmp.second );
	}
	
	for(i=0;i<n;i++) cout<<res1[i]<<' ';
	cout<<endl;
	for(i=0;i<n;i++) cout<<res2[i]<<' ';
}

