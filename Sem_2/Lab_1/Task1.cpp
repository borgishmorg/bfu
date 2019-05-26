#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int di[] = {1, 0, -1, 0},
	dj[] = {0, 1, 0, -1};

void dfs(int i0, int j0, int n, int m, vector<vector<int> > &g){
	g[i0][j0] = 1;
	
	for(int k = 0; k < 4; k++){
		int i = i0 + di[k],
			j = j0 + dj[k];
		
		if(i >= 0 && j >= 0 && i < n && j < m && g[i][j] == 0){
			g[i][j] = 1;
			dfs(i, j, n, m, g);
		}
			
	}
}

int components(const int &n, const int &m, vector<vector<int> > &g){
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!g[i][j]){
				ans++;
				dfs(i, j, n, m, g);
			}
	return ans;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n, m;
	std::string s;
	vector<vector<int> > g;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		vector<int> v;
		cin >> s;
		for(auto c : s) v.push_back(c=='.');
		g.push_back(v);
	}
	cout << components(n, m, g);	
	return 0;
}

