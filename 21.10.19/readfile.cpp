#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream file;
	file.open("mat.txt");
	int n;
	file >> n;

	int a[n][n];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			file >>	a[i][j];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout <<	a[i][j] << " ";			
		cout << "\n";
	}
}