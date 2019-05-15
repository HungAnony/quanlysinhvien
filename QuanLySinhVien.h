#include<stdio.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#pragma once 
//khai báo danh sach
 struct SinhVien{	
	char maSV[10];
	char maLop[10];
	char hoTen[35];
   // char ten[12];
	int ngay,thang,nam;
	float dtb;
}sv;

//typedef struct Node*NO;
struct node{
  SinhVien info;
  node *next;	
};



struct List{
	node* first;
	node* last;
};
void Init(List &L){
	L.first = L.last = NULL;
}
//them 1 phan tu vao dau danh sach
void vht(List &L,SinhVien x){
	node *p = new node;
	p->info = x;
	p->next = NULL;
	if(L.first == NULL) L.first = L.last =p;
	else{
		p->next = L.first;
		L.first = p;
	}
}
int length(List &L){//do dai danh sach
	node *p = L.first;
	int i = 0;
	while (p != NULL){
		i++;
		p = p->next;
	}
	return i;
}
//them 1 phan tu vao vi tri k danh sach
void vmt(List &L, int k){
	SinhVien x;
	int d;
	node *p = new node;
	node *q;
	p->next = NULL;
	q = L.first;
	p->info = x;
	if(k == 0 || L.first == NULL) vht(L,x);
	while(d < k-1 && q->next != NULL){
		q = q->next;
		d++;
	}
	// them vao k
	p->next = q->next;
	q->next = p;
}
//them 1 phan tu vao cuoi danh sach
void vct(List &l, SinhVien x){
	node* p = new node;
    p->info = x;
	p->next = NULL;
	if(l.first == NULL) l.first =l.last = p;
	else {
		l.last->next = p;
		l.last = p;
	}
}
//xoa 1 phan tu o dau danh sach
void delF(List &L){
	node *p;
	if(L.first == NULL) return;
	else {
		p = L.first;
		L.first = L.first->next;
		delete p;
	}
}
//xoa 1 phan tu o cuoi danh sach
void delL(List &L){
	if(L.first == NULL) return;
	node *p = L.first;
	node *q = L.last;
	if(p == q){
		L.first =L.last = p;
		delete p;
	}
	else {
		while(p->next != q) p = p->next;
		p->next = NULL;
		L.last= p;
		delete q;
	}
}
//xoa tai vi tri k trong danh sach
void delK(List &L, int k){
	int n;
	node *p, *q;
	if( k<0) return;
	if(k == 0) delF(L);
	p = L.first;
	if(p == NULL) return;
	while(n < k-1 && p->next != NULL){
		p = p->next;
		n++;
	}
	if(p->next == NULL) return;
	//xoa tai k
	q = p->next;
	p->next = q->next;
	delete q;
}
// lay node o giua danh sach
node * middleNode( node * startNode , node * endNode)
{
	
    if( startNode == NULL )
    {
      return NULL;//danh sach lien ket rong

    }
    node * slowPtr = startNode;
    node * fastPtr = startNode -> next;
    while ( fastPtr != endNode )
    {
        fastPtr = fastPtr -> next ;
        if( fastPtr != endNode )
        {
            slowPtr = slowPtr -> next ;
            fastPtr = fastPtr -> next ;//de lay duoc middle thi fastPtr next di 2 lan trong
                                       //khi slowPtr next di 1 lan. khi fastPtr den cuoi danh
                                       //sach thi slowPtr vua den giua danh sach
        }
    }
    return slowPtr ;//Cuoi cung,cac slowPtr se tro den nut giua
} 
