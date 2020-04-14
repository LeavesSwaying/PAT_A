#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN = 100005;

int N, M, K;
int Hash[MaxN];

map<int, vector<int>> mp;

int main()
{
	int a, b;
	scanf("%d%d", &N, &M);
	for (int i = 0; i<N; ++i)
	{
		scanf("%d%d", &a, &b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for (int i = 0; i<M; ++i)
	{
		scanf("%d", &K);
		bool F = false;
		fill(Hash, Hash + MaxN, 0);
		for (int j = 0; j<K; ++j)
		{
			scanf("%d", &a);
			Hash[a] = 1;
			if (mp.find(a) != mp.end())
			for (int k = 0; k<mp[a].size(); ++k)
			{
				if (Hash[mp[a][k]] == 1)
				{
					if(F==false) printf("No\n");
					F = true;
				}
			}
		}
		if (F == false) printf("Yes\n");
	}
	return 0;
}
