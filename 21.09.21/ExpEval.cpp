#include <bits/stdc++.h>

using namespace std;

bool isNumber(string str);
int find_first(string exp, char x);
bool isPolynomial (string exp);
string infixToPostfixl(string e);

int main() {
	string e;
	cin >> e;
	cout << infixToPostfix(e) << "\n"; 
}

/*
* Chuyen bieu thuc tu trung to -> hau to
*	co tat ca 3 truong hop xay  ra khi xu ly bieu thuc (bieu thuc chi chua: so, + - * /)
*	1. Bieu thuc la da thuc (con ton tai + - trong bieu thuc)
*	2. Bieu thuc la don thuc (chi con * / trong bieu thuc)
*	3. Bieu thuc la so
*/
string infixToPostfix(string e) {
	// th1: Bieu thuc la da thuc
	if(isPolynomial(e)) {
		int lastMinus = e.find_last_of('-');
		int lastPlus = e.find_last_of('+');
		int last = (lastMinus > lastPlus? lastMinus:lastPlus);
		string left = e.substr(0,last);
		string right = e.substr(last+1);
		return infixToPostfix(left) + infixToPostfix(right) + e.at(last) + " ";
	}
	else {
		// th2: Bieu thuc la don thuc
		if(!isNumber(e)) {
			int lastDiv = e.find_last_of('/');
			int lastMul = e.find_last_of('*');
			int last = (lastDiv > lastMul? lastDiv:lastMul);
			string left = e.substr(0,last);
			string right = e.substr(last+1);
			return infixToPostfix(left) + infixToPostfix(right) + e.at(last) + " ";
		}
		//th3: Bieu thuc la so
		return e + " ";
	}
}

/*
* input: exp: bieu thuc can keim tra
*	return: true neu bieu thuc la so, false neu bieu thuc khong la so
*/
bool isNumber(string exp) { 
	//return -1 neu la so || > -1 neu khong phai so
	for(int i=0 ; i<exp.size(); i++) 
		if(exp.at(i) > 57 || exp.at(i) < 48)
			return false;
	return true;
}


/*
* kiem tra co phai da thuc khong
* input: exp: bieu thuc can kiem tra
*	return: true neu bieu thuc da cho la da thuc, false neu khong la da thuc
*/
bool isPolynomial(string exp) {
	if(exp.size() == 1)
		return false;
	return exp.find_first_of('+') != string::npos || exp.find_first_of('-') != string::npos;
}

/*
* tinh toan bieu thuc
* input: exp: bieu thuc can tinh toan
*	return: so thuc la ket qua da tinh toan
*/
float calculate(string exp) {

}