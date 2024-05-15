#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	cin.tie(0)->sync_with_stdio(0);
    

	int num;
	char ch;
	cin >> num;
	
	int total = 0;

	for(int i = 0; i < num; i++) {
		cin >> ch;
		total += ch - '0';
	}

	cout << total;

}