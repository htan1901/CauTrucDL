#include <bits/stdc++.h>

using namespace std;

bool isNumber(string str);
bool isPolynomial (string exp);
string infixToPostfix(string e);
bool isOperator(char x);
int precedence(char x);
float calculate(string exp);
float applyOperator(char x, float a, float b);

int main() {
	string e;
	cout << "Nhap vao bieu thuc can tinh toan: \n";
	cin >> e;
	e = infixToPostfix(e);
	cout << "Sau khi chuyen\n";
	cout << e;
	cout << "\nSau khi tinh\n";
	cout << calculate(e);
}

string infixToPostfix(string e) {
	if(isPolynomial(e)) {
		int lastMinus = e.find_last_of('-');
		int lastPlus = e.find_last_of('+');
		int last = (lastMinus > lastPlus? lastMinus:lastPlus);
		string left = e.substr(0,last);
		string right = e.substr(last+1);
		return infixToPostfix(left) + infixToPostfix(right) + e.at(last) + " ";
	}
	else {
		if(!isNumber(e)) {
			int lastDiv = e.find_last_of('/');
			int lastMul = e.find_last_of('*');
			int last = (lastDiv > lastMul? lastDiv:lastMul);
			string left = e.substr(0,last);
			string right = e.substr(last+1);
			return infixToPostfix(left) + infixToPostfix(right) + e.at(last) + " ";
		}
		return e + " ";
	}
}

bool isNumber(string exp) { 
	for(int i=0 ; i<exp.size(); i++) 
		if(exp.at(i) > '9' || exp.at(i) < '0')
			return false;
	return true;
}

bool isOperator(char x) {
	return x == '+' || x == '-' || x == '*' || x == '/';
}

bool isPolynomial(string exp) {
	if(exp.size() == 1)
		return false;
	// string::npos ~ -1
	return exp.find_first_of('+') != string::npos || exp.find_first_of('-') != string::npos;
}

int precedence(char x) {
	switch (x)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return 0;
	}
}

float applyOperator(char x, float a, float b) {
	switch (x)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}

float calculate(string exp) {
	stack<char> ops;
	stack<float> values;
	int length = exp.size();
	string ele = "";
	float a, b;

	for(int i=0; i<length; i++) {
		char current = exp.at(i);
		if(current != ' ') {
			if(isOperator(current)) {
				if(ops.empty()) {
					b = values.top();
					values.pop();

					a = values.top();
					values.pop();

					values.push(applyOperator(current,a,b));
				}
				else {
					while(precedence(ops.top()) >= precedence(current)) {
						b = values.top();
						values.pop();

						a = values.top();
						values.pop();

						char op = ops.top();
						ops.pop();

						values.push(applyOperator(op,a,b));
					}
					ops.push(current);
				}
			}
			else
				ele += current;
		}
		if(current == ' ') {
			if(ele != "")
				values.push((float)stoi(ele));
			ele = "";
		}
	}
	while(!ops.empty()) {
		b = values.top();
		values.pop();
		
		a = values.top();
		values.pop();

		char op = ops.top();
    ops.pop();

		values.push(applyOperator(op,a,b));
	}
	return (float)values.top();
}