#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int Data;
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
Node* CreateNode(int value){
	Node* q = new Node();
	if(q != NULL)
	{
		q->Data = value;
		q->Next = NULL;
	}
	return q;
}
bool isempty(Queue queue){
	return queue.head == NULL;
}
void push(Queue &queue, int value){
	Node* a = CreateNode(value);
	if(isempty(queue)){
		queue.head = queue.tail = a;
	}
	else{
		queue.tail->Next = a;
		queue.tail = a;
	}
}
bool pop(Queue &queue, int &top){
	top = queue.head->Data;
	if(!isempty(queue)){
		Node* i = queue.head;
		queue.head = queue.head->Next;
		delete i;
		return true; 
	}
	else{
		return true;
	}
	return false;
}
int main(){
	Queue queue;
	initQueue(queue);
	int top = 0,chon;
	do{
		system("cls");
		printf("\n----- Menu -----\n");
		printf("1.Them Phan Tu Vao Queue\n2.Xoa Phan Tu Queue\n3.In danh sach\n4.Phan Tu Vua Xoa\n0.Thoat\n");
		printf("Chon: ");
		scanf("%d",&chon);
		switch (chon)
		{
		case 1:
			int temp;
			printf("Nhap: ");
			scanf("%d",&temp);
			push(queue,temp);
			break;
		case 2:
			pop(queue,top);
			(pop(queue,top) == true) ? cout<<"\nXoa thanh cong ! \n" : cout<<"\nError !\n";
			break;
		case 3:
		{
			Node* i = queue.head;
			cout<<endl;
			while (i != NULL)
			{
				printf("%4d",i->Data);
				i=i->Next;
			}
			cout<<endl;
			system("pause");
			break;
		}
		case 4:
			printf("\nPhan tu vua xoa la: %d\n",top);
			system("pause");
			break;
		default:
			if(chon != 0){
				printf("\nChon sai chuc nang !\nNhap lai !\n");
				system("pause");
			}
			break;
		}
	}while(chon != 0);	
}