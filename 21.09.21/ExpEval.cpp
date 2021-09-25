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

/*
* Chuyen bieu thuc tu trung to -> hau to
*	co tat ca 3 truong hop xay  ra khi xu ly bieu thuc (bieu thuc chi chua: so, + - * /)
*	1. Bieu thuc la da thuc (con ton tai + - trong bieu thuc)
*	2. Bieu thuc la don thuc (chi con * / trong bieu thuc)
*	3. Bieu thuc la so
* .at(i) ~~ [i]
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
* input: exp: bieu thuc can kiem tra
*	return: true neu bieu thuc la so, false neu bieu thuc khong la so
*/
bool isNumber(string exp) { 
	//return -1 neu la so || > -1 neu khong phai so 
	for(int i=0 ; i<exp.size(); i++) 
		if(exp.at(i) > '9' || exp.at(i) < '0')
			return false;
	return true;
}

/*
* input: exp: ky tu can kiem tra
*	return: true neu ky tu la toan tu, false neu ky tu khong toan tu 
*/
bool isOperator(char x) {
	return x == '+' || x == '-' || x == '*' || x == '/';
}

/*
* kiem tra co phai da thuc khong
* input: exp: bieu thuc can kiem tra
*	return: true neu bieu thuc da cho la da thuc, false neu khong la da thuc
*/
bool isPolynomial(string exp) {
	if(exp.size() == 1)
		return false;
	// string::npos ~ -1
	return exp.find_first_of('+') != string::npos || exp.find_first_of('-') != string::npos;
}

/*
* ham tra ve do uu tien cua toan tu
*	input: toan tu x
*	return: 1 so nguyen bieu thi cho do uu tien
*/
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

/*
* ham xu ly toan tu
*/
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

/*
* tinh toan bieu thuc
* input: exp: bieu thuc can tinh toan
*	return: so thuc la ket qua da tinh toan
*/
float calculate(string exp) {
	/*
	* khai bao bien de ho tro viec code
	*	vi code dai qua nen nhom khong tu tao stack ma su dung class stack co san 
	*	ops dung de chua cac toan tu
	* values dung de chua cac toan hang
	* do toan hang co nhieu chu so nen ele dung de luu tru toan hang dang string 
	* sau do ep kieu sang float va push vao values
	* a b la 2 bien tam, ho tro tinh toan
	*/
	stack<char> ops;
	stack<float> values;
	int length = exp.size();
	string ele = "";
	float a, b;

	// duyet tung phan tu cua bieu thuc
	for(int i=0; i<length; i++) {
		// luu phan tu hien tai bang bien current
		char current = exp.at(i);

		// neu current khac ' ' 
		if(current != ' ') {
			// neu current la toan tu thi xu ly
			if(isOperator(current)) {
				// neu ops rong thi ta tinh toan va push gia tri vao values
				if(ops.empty()) {
					b = values.top();
					values.pop();

					a = values.top();
					values.pop();

					values.push(applyOperator(current,a,b));
				}
				// neu ops khong rong thi ta kiem tra do uu tien toan tu
				// neu do uu tien cua toan tu trong stack > uu tien cua toan tu hien tai 
				// 		=> tinh toan va push gia tri vao values va lap lai
				// push current vao ops
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
			// neu current khong la toan tu => current la toan hang
			// 		=> them current vao ele
			else
				ele += current;
		}
		// neu current la ' '
		if(current == ' ') {
			// kiem tra xem ele co rong hay khong
			// neu khong rong => ele la so => ep kieu va push vao values
			if(ele != "")
				values.push((float)stoi(ele));

			// sau do reset la ele = ""
			ele = "";
		}
	}
	// neu ops con phan tu thi lan luot lay cac phan tu ra va thuc hien tinh toan va push vao value
	while(!ops.empty()) {
		b = values.top();
		values.pop();
		
		a = values.top();
		values.pop();

		char op = ops.top();
    ops.pop();

		values.push(applyOperator(op,a,b));
	}
	// luc nay values chi con 1 phan tu va do cung chinh la ket qua can tim
	return (float)values.top();
}