#include <bits/stdc++.h>
#define MAX 3
#define ll long long int
using namespace std;

// p = No. of process in the system
// rt = No. of resouce types
// Available -> size rt
// Max, Allocation, Need -> shape p * rt

void calculateNeed(ll **need, ll **allocation, ll **max, ll p, ll rt) {
	for(ll i = 0; i < p; ++i)
		for(ll j = 0; j < rt; ++j)
			*(*(need + i) + j) = *(*(max + i) + j) - *(*(allocation + i) + j);
}

void displayArray(ll **arr, string heading, ll n, ll m) {
	cout << heading << endl;
	for(ll i = 0; i < n; ++i) {
		for(ll j = 0; j < m; ++j)
			cout << *(*(arr + i) + j) << " ";
		cout << endl;
	}
	cout << endl;
}

bool isInSafeState(ll p, ll rt, ll *available, ll **allocation, ll **max, ll **need) {
	ll work[rt];
	bool finish[p];
	vector<int> seq;

	for(ll i = 0; i < rt; ++i)
		work[i] = available[i];
	
	for(ll i = 0; i < p; ++i)
		finish[i] = false;
	int x;
	for(x = 0; x < p; ++x) {
		for (ll i = 0; i < p; ++i) {
			if (!finish[i]) {
				bool flag2 = true;
				for(ll j = 0; j < rt; ++j)
					if(*(*(need + i) + j) > work[j]) {
						flag2 = false;
						break;
					}
				if(flag2) {
					finish[i] = true;
					for(ll j = 0; j < rt; ++j) {
						work[j] += *(*(allocation + i) + j);
					}
					seq.push_back(i);
					break;
				}
			}
		}
	}

	cout << "Safe sequence : ";
	for(int i = 0; i < seq.size(); ++i)
		cout << (seq.at(i) + 1) << " ";
	cout << endl;

	return true;
}

int main() {
	ll p, rt;
	cin >> p >> rt;
	ll *available = new ll[rt], **max = new ll*[p], **allocation = new ll*[p];
	for(ll i = 0; i < p; ++i) {
		max[i] = new ll[rt];
		allocation[i] = new ll[rt];
	}
	cout << "Available : ";
	for(int i = 0; i < rt; ++i)
		cin >> available[i];
	cout << "MAX : " << endl;
	for(int i = 0; i < p; ++i)
		for(int j = 0; j < rt; ++j)
			cin >> max[i][j];
	cout << "Allocation : " << endl;
	for(int i = 0; i < p; ++i)
		for(int j = 0; j < rt; ++j)
			cin >> allocation[i][j];

	ll **need = new ll*[p];
	for(ll i = 0; i < p; ++i) {
		need[i] = new ll[rt];
	}

	// int avail[] = {3, 3, 2}; 

	// int maxm[][MAX] = {{7, 5, 3}, 
	// 				{3, 2, 2}, 
	// 				{9, 0, 2}, 
	// 				{2, 2, 2}, 
	// 				{4, 3, 3}}; 

	// // Resources allocated to processes 
	// int allot[][MAX] = {{0, 1, 0}, 
	// 				{2, 0, 0}, 
	// 				{3, 0, 2}, 
	// 				{2, 1, 1}, 
	// 				{0, 0, 2}}; 

	calculateNeed(need, allocation, max, p, rt);
	displayArray(need, "Need", p, rt);
	bool state = isInSafeState(p , rt, available, allocation, max, need);
	return 0;
}