#include<bits/stdc++.h>
using namespace std;
int main() {
	int currentHash = 0;
	map<string, int> hashMap;
	#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
    #endif
	const int MAX_CACHE = 1200;
	vector<map<int, int>> callStack;
	callStack.push_back(map<int, int>());
	string current;
	while (getline(cin, current)) {
		if (current == "{") {
			if (callStack.size() < MAX_CACHE ) {
				map<int, int> tempMap;
				for (int i = callStack.size() - MAX_CACHE; i < callStack.size(); i++) {
					for (auto& var : callStack[i]) {
						tempMap[var.first] = var.second;
					}
				}
				callStack.push_back(map<int, int>(tempMap));
			} else {
				callStack.push_back(map<int, int>());
			}
		} else if (current == "}") {
			callStack.pop_back();
		} else {
			int sig = current.find('=');
			string leftPart = current.substr(0, sig);
			string rightPart = current.substr(sig + 1);

			if (hashMap.count(leftPart) == 0) {
				hashMap[leftPart] = currentHash++;
			}
			int leftHash = hashMap[leftPart];

			if (rightPart.find_first_of("-0123456789") != string::npos) {
				callStack.back()[leftHash] = stoi(rightPart);
			} else {
				if (hashMap.count(rightPart) == 0) {
					hashMap[rightPart] = currentHash++;
				}
				int rightHash = hashMap[rightPart];

				for (int i = callStack.size() - 1; i >= 0; i--) {
					if (callStack[i].count(rightHash)) {
						callStack.back()[leftHash] = callStack[i][rightHash];
						cout << callStack[i][rightHash] << endl;
						break;
					}
					if (i==0) {
						callStack.back()[leftHash] = 0;
						cout << "0" << endl;
					}
				}
			}
		}
	}

}
