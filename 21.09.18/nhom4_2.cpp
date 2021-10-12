#include <bits/stdc++.h>

using namespace std;

struct SinhVien {
	char MaSo[10];
	char HoTen[30];
	float DiemTB;
};

void nhapSV(SinhVien &sv) {
	printf("Nhap ma so: ");
	fflush(stdin);
	gets(sv.MaSo);
	printf("Nhap ten: ");
	fflush(stdin);
	gets(sv.HoTen);
	printf("Nhap DTB: ");
	scanf("%f", &sv.DiemTB);
}

void XuatSV(SinhVien sv){
	printf("Ma So: %-10s \nHo Ten: %-30s \nDiemTB: %.2f\n",sv.MaSo,sv.HoTen,sv.DiemTB);
}
struct Node {
	SinhVien info;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

void initList(List &list) {
	list.head = NULL;
	list.tail = NULL;
}

Node * CreateNode(SinhVien value) {
	Node* a=new Node();
	if(a!=NULL)
	{
		a->info = value;
		a->next = NULL;
	}
	return a;
}

void addTail(List &list, Node *a) {
	if(list.head == NULL) {
		list.head = a;
		list.tail = a;
		return;
	}
	list.tail->next = a;
	list.tail = a;
}

void xuatList(List list) {
	Node *i = list.head;
	while(i != NULL) {
		XuatSV(i->info);
		i = i->next;
	}
}

void xuatListDTB(List list) {
	Node* i =list.head;
	while (i!=NULL) {
		if(i->info.DiemTB > 5.0)	
			XuatSV(i->info);
		i = i->next;
	}
}

Node* searchSV(List list, char* ten) {
	Node*i =list.head;
	while (i!=NULL)
	{
		if(strcmp(i->info.HoTen,ten) == 0)
				return i;
		i=i->next;
	}
	return NULL;
}

void swapData(Node *a, Node *b) {
	Node *temp = new Node;
	temp->info = a->info;
	a->info = b->info;
	b->info = temp->info;
}

void sort(List &list) {
	for(Node *i = list.head; i->next != NULL; i = i->next)
		for (Node *j = i->next; j != NULL; j=j->next) 
			if(i->info.DiemTB > j->info.DiemTB)
				swapData(i,j);
}

int main() {
	int n,chon;
	List list;
	initList(list);
	do{
		system("cls");
		printf("\n------Menu-----");
		printf("\n1.Them 1 node");
		printf("\n2.Xuat list");
		printf("\n3.Xuat theo Diem Trung Binh");
		printf("\n4.Tim Sinh Vien co ten la X");
		printf("\n5.Sap xep theo Diem Trung Binh");
		printf("\n0.exit");
		printf("\nChon : ");
		scanf("%d",&chon);
		switch (chon)
		{
		case 1:
			SinhVien temp;
			nhapSV(temp);
			addTail(list,CreateNode(temp));
			break;
		case 2:
			printf("\nDanh sach Sinh Vien: \n");
			xuatList(list);
			system("pause");
			break;
		case 3:
			printf("\nSinh Vien Co Diem Trung Binh > 5 la : \n");
			xuatListDTB(list);
			system("pause");
			break;
		case 4:
		{
			char *ten = new char[50];
			printf("\nNhap Ten Sinh Vien : ");
			fflush(stdin);
			gets(ten);
			Node* a = searchSV(list,ten);
			(a==NULL) ? printf("\nKhong Tim Thay !") : printf("\nTim thay !");
			system("pause");
			break;
		}
		case 5:
			sort(list);
			printf("\n\tDa sap xep xong ! \n");
			system("pause");
			break;
		default:
			printf("\nChuc nang khong ton tai\n");
			printf("Chon lai \n");
			system("pause");
			break;
		}
	}while(chon != 0);
	
}