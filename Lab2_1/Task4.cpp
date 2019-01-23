#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::endl;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	std::set<int> set;
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		set.insert(t);
	}
	
	cin >> m;
	for(int i = 0; i < m; i++){
		int  k, ans = 0;
		cin >> k;
		for(int j = 0; j < k; j++){
			int t;
			cin >> t;
			ans += (set.find(t) != set.end());
		}
		cout << ans << endl;
	}
	
	return 0;
}

