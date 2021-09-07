#include <bits/stdc++.h>

using namespace std;

#define MAX 100

struct NgayThang {
	int Ngay;
	int Thang;
	int Nam;
};

struct SinhVien {
	char Ma[10];
	char Ten[10];
	NgayThang NgaySinh;
	int GioiTinh; // 0: nam, 1: nu
	float diemToan;
	float diemLy;
	float diemTin;
};

void nhapNgayThang(NgayThang &ngay) {
	printf("Nhap ngay: ");
	scanf("%d", &ngay.Ngay);
	printf("Nhap thang: ");
	scanf("%d", &ngay.Thang);
	printf("Nhap nam: ");
	scanf("%d", &ngay.Nam);
}

void XuatNgay(NgayThang a){
  printf("%02u/%02u/%2u", a.Ngay, a.Thang, a.Nam);
}

void nhapSV(SinhVien &sv)
{
	printf("Nhap vao ma so sinh vien: ");
	fflush(stdin);
	gets(sv.Ma);
	printf("\nNhap vao ho va ten sinh vien: ");
	fflush(stdin);
	gets(sv.Ten);
	printf("\nNam sinh cua sinh vien\n");
	nhapNgayThang(sv.NgaySinh);
	do {
		printf("Nhap gioi tinh cua sinh vien ");
		fflush(stdin);
		scanf("%d", &sv.GioiTinh);
		if(sv.GioiTinh != 0 && sv.GioiTinh != 1)
			printf("Nhap sai nhap lai\n");
	}while(sv.GioiTinh != 0 && sv.GioiTinh != 1);
	printf("Nhap diem toan: ");
	scanf("%f", &sv.diemToan);
	printf("Nhap diem ly: ");
	scanf("%f", &sv.diemLy);
	printf("Nhap diem tin: ");
	scanf("%f", &sv.diemTin);
}

void nhapSV_ConTro(SinhVien *sv){
	printf("\nNhap ma so sinh vien: ");
	fflush(stdin);
	gets(sv->Ma);
	printf("\nNhap ho ten: ");
	fflush(stdin);
	gets(sv->Ten);
	fflush(stdin);
	printf("Nhap ngay sinh\n");
	nhapNgayThang(sv->NgaySinh);
	do {
		printf("Nhap gioi tinh cua sinh vien ");
		fflush(stdin);
		scanf("%d", &sv->GioiTinh);
		if(sv->GioiTinh != 0 && sv->GioiTinh != 1)
			printf("Nhap sai nhap lai\n");
	}while(sv->GioiTinh != 0 && sv->GioiTinh != 1);
	printf("\nNhap diem trung binh Ly : ");
	scanf("%f", &(sv->diemLy));
	fflush(stdin);
	printf("\nNhap diem trung binh Toan: ");
	scanf("%f", &(sv->diemToan));
	fflush(stdin);
	printf("\nNhap diem trung binh Tin: ");
	scanf("%f", &(sv->diemTin));
}

void XuatSV(SinhVien a){
	printf("%-12s%-28s", a.Ma, a.Ten);
	XuatNgay(a.NgaySinh);
	printf("%-5s", (a.GioiTinh == 0)?"Nu":"Nam");
	printf("%-3.1f   %-3.1f   %-3.1f", a.diemToan, a.diemLy, a.diemTin);
}

void XuatSV_ConTro(SinhVien *a){
	printf("%-12s%-28s", a->Ma, a->Ten);
	XuatNgay(a->NgaySinh);
	printf("%-5s", (a->GioiTinh == 0)?"Nu":"Nam");
	printf("%-3.1f   %-3.1f   %-3.1f", a->diemToan, a->diemLy, a->diemTin);
}

void NhapDSSV(SinhVien a[],int n){
	printf("\nNhap thong tin sinh vien:\n");
	for(int i=0;i<n;i++){
		nhapSV(a[i]);
	}
}

void nhapDSSV_ConTro(SinhVien *a, int n) {
	for(int i=0; i<n; i++) {
		printf("Sinh vien thu %d: \n", i);
		nhapSV_ConTro(a+i);
	}
}

void xuatDSSV(SinhVien a[], int n) {
	for(int i=0; i<n; i++) {
		printf("Sinh vien thu %d: \n", i);
		XuatSV(a[i]);
	}
}

void xuatDSSV_ConTro(SinhVien *a, int n) {
	for(int i=0; i<n; i++) {
		printf("Sinh vien thu %d: \n", i);
		XuatSV_ConTro((a+i));
		printf("\n");
	}
}

void capPhat(SinhVien *b, int n) {
	b = (SinhVien*)malloc(n*sizeof(SinhVien));
}

int main() {
	int n;
	SinhVien a[MAX];
	SinhVien *b;
	cout << "nhap n: ";
	cin >> n;
	capPhat(b,n);
	cout << "\nNhap sinh vien kieu binh thuong\n";
	NhapDSSV(a,n);
	cout << "Nhap sinh vien kieu con tro\n";
	nhapDSSV_ConTro(b,n);
	cout << "Xuat sinh vien kieu binh thuong\n";
	xuatDSSV(a,n);
	cout << "\nXuat sinh vien kieu con tro\n";
	xuatDSSV_ConTro(b,n);
	free(b);
}