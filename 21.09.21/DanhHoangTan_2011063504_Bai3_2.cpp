#include<bits/stdc++.h>
using namespace std;
struct QLHH
{
	int Ma;
	char Ten[30];
	float Gia;
};
void ThongTinHangHoa(QLHH &value){	
	printf("\nNhap Ma hang hoa: ");
	scanf("%d",&value.Ma);
	printf("Nhap Ten hang hoa: ");
	fflush(stdin);
	gets(value.Ten);
	printf("Nhap Gia hang hoa: ");
	scanf("%f",&value.Gia);
}
void XuatHangHoa(QLHH value){
	printf("Ma So: %-10d Ten: %-30s Gia: %.2f\n",value.Ma,value.Ten,value.Gia);
}

struct Node
{
	QLHH Data;
	Node* Next;
};
struct Queue
{
	Node* head;
	Node* tail;
};
void initQueue(Queue &queue){
	queue.head = NULL;
	queue.tail = NULL;
}
bool isempty(Queue queue){
	return queue.head == NULL;
}
Node* CreateNode(QLHH value){
	Node* q = new Node();
	if(q != NULL)
	{
		q->Data = value;
		q->Next = NULL;
	}
	return q;
}
void XuatDS(Queue queue) {
	Node *i = queue.head;
	while(i != NULL) {
		XuatHangHoa(i->Data);
		i = i->Next;
	}
}
void PushTail(Queue &queue, QLHH value){
	Node* a = CreateNode(value);
	if(isempty(queue)){
		queue.head = queue.tail = a;
	}
	else{
		queue.tail->Next = a;
		queue.tail = a;
	}
}
void PushHead(Queue &queue, QLHH value){
	Node* a = CreateNode(value);
	if(isempty(queue)){
		queue.head = queue.tail = a;
	}
	else{
		a->Next=queue.head;
		queue.head = a;
	}
}

int PopHead(Queue &queue, QLHH &value){
	if(!isempty(queue))
	{		
		queue.head->Data = value;
		Node* i = queue.head;
		queue.head = queue.head->Next;
		delete i;
		return 1;
	}
return -1;
}
int PopTail(Queue &queue, QLHH &value){
	Node* i = queue.head;
	if(queue.head->Next!=NULL)
	{		
		while(i->Next!=queue.tail){
			i=i->Next;
		}
		i->Next=queue.tail->Next;
		delete(queue.tail);
		queue.tail=i;
		return 1;
	}
	else {
		queue.head=queue.tail=NULL;
	}
return -1;
}
int main(){
	Queue queue;
	initQueue(queue);
	int top = 0,chon;
	do{
		printf("\n----- Menu -----");
		printf("\n1.Tao danh sach hang hoa");
		printf("\n2.Xuat danh sach hang hoa");
		printf("\n3.Them 1 hang hoa vao cuoi");
		printf("\n4.Xoa 1 hang hoa vi tri dau");
		printf("\n5.Them 1 hang hoa vao dau");
		printf("\n6.Xoa 1 hang hoa vi tri cuoi");
		printf("\n0.Thoat\n");
		printf("Chon: ");
		scanf("%d",&chon);
		switch (chon)
		{
		case 1:
			int n;
			printf("Nhap so luong hang hoa: ");
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				printf("Hang hoa thu %d: ",i+1);
				QLHH value;
				ThongTinHangHoa(value);
				PushTail(queue,value);
			}
			break;
		case 2:
			printf("\nDanh sach hang hoa: \n");
			XuatDS(queue);
			break;
		case 3:
			printf("\nNhap thong tin hang hoa can them: ");
			QLHH value;
			ThongTinHangHoa(value);
			PushTail(queue,value);
			break;
		case 4:
			QLHH temp; 
			if(PopHead(queue,temp)<0) printf("\n! ! Erorr ! !");
			else printf("\nXoa thanh cong");			
			break;
		case 5:
			printf("\nNhap thong tin hang hoa can them: ");
			QLHH x;
			ThongTinHangHoa(x);
			PushHead(queue,x);
			break;
		case 6:
			QLHH y; 
			if(PopTail(queue,y)<0) printf("\n! ! Erorr ! !");
			else printf("\nXoa thanh cong");			
			break;
		default:
			if(chon != 0){
				printf("\nChon sai chuc nang !\nNhap lai !\n");
			}
			break;
		}
	}while(chon != 0);	
}