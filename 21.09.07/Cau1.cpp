#include <bits/stdc++.h>

using namespace std;

#define MAX 100

void NhapN(int &n){
	do{
		printf("nhap so phan tu mang: ");
		scanf("%d",&n);
		if(n<=0 || n>100)
			printf("nhap lai, ");
	}while(n<=0 || n>100);
}

void NhapMang(int a[],int n){
	for(int i=0;i<n;i++){
		printf("nhap a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}

void XuatMang(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%5d",a[i]);
}

int TinhTong(int a[], int n) {
	int s = 0;
	for(int i=0; i<n; i++) 
		s += a[i];
	return s;
}

bool CheckNgto(int n){
	if(n<=1)
		return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return false;
	}
	return true;
}

void xuatNgto(int a[],int n){
	for(int i=0;i<n;i++){
		if(CheckNgto(a[i])==true)
			printf("%4d",a[i]);
	}
}

int demNgto(int a[], int n) {
	int c = 0;
	for(int i=0; i<n; i++) 
		if(CheckNgto(a[i]))
			c++;
	return c;
}

int main() {
	int n, a[MAX];
	NhapN(n);
	cout << "Nhap mang: \n";
	NhapMang(a,n);
	cout << "\nMang vua nhap la:\n";
	XuatMang(a,n);
	cout << "\nTong cac so trong mang la: " << TinhTong(a,n) << "\n";
	cout << "So luong cac so nguyen to: " << demNgto(a,n) << "\n";
	cout << "Cac so nguyen to co trong mang: \n";
	xuatNgto(a,n);
}
