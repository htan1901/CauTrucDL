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
	printf("Ma So: %-10s Ho Ten: %-30s DiemTB: %.2f",sv.MaSo,sv.HoTen,sv.DiemTB);
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
	}
}

void xuatListDTB(List list) {
	Node* i =list.head;
	while (i!=NULL){
		if(i->info.DiemTB > 5.0)	
			XuatSV(i->info);
		i=i->next;
	}
}

Node* searchSV(List list, char* ten) {
	Node*i =list.head;
    while (i!=NULL)
    {
      if(i->info.HoTen == ten)
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
		for (Node *j = 0; j != NULL; j=j->next) 
			if(i->info.DiemTB > j->info.DiemTB)
				swapData(i,j);
}

int main() {
	int n;
	List list;
	initList(list);
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	while (n) {
		SinhVien temp;
		cout << "Nhap sinh vien: \n";
		nhapSV(temp);
		addTail(list,CreateNode(temp));
		n--;
	}
	cout << "Xuat danh sach: ";
	xuatList(list);
	cout << "Xuat danh sach sinh vien co diem DTB > 5";
	xuatListDTB(list);
	char *ten = new char(50);
	cout << "Nhap ten can tim: ";
	fflush(stdin);
	gets(ten);
	cout << (searchSV(list,ten) == NULL ? "Khong tim thay" : "Tim thay");
	cout << "Danh sach sau khi sort";
	sort(list);
}