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
	if(list.head == NULL) { //kiem tra list rong
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
	for(Node *i = list.head; i != NULL; i = i->next)
		for (Node *j = i->next; j != NULL; j=j->next) 
			if(i->info.DiemTB > j->info.DiemTB)
				swapData(i,j);
}

int main() {
	int n; // n la so luong phan tu
	List list;
	initList(list); // khoi tao
	cout << "Nhap so luong sinh vien: ";
	cin >> n; // nhap n
	// nhap n phan tu vao list
	while (n > 0) {
		SinhVien temp;
		cout << "Nhap sinh vien: \n";
		nhapSV(temp);
		Node *gido = CreateNode(temp);
		addTail(list,gido);
		n--;
	}
	cout << "Xuat danh sach: ";
	xuatList(list); 
	cout << "Xuat danh sach sinh vien co diem DTB > 5\n";
	xuatListDTB(list);
	char *ten = new char(50);
	cout << "Nhap ten can tim: ";
	fflush(stdin);
	gets(ten);
	Node *sv = searchSV(list,ten);
	if(sv == NULL) 
		cout << "Khong tim thay\n";
	else {
		cout << "Tim thay: \n";
		XuatSV(sv->info);
	}
	cout << "Danh sach sau khi sort\n";
	sort(list);
	xuatList(list);
}