#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

typedef short typeData;
typedef struct Node tree;//alias penamaan, a.k.a

struct Node{
	short data;
	Node *kiri, *kanan;
}*root, *bantu, *bantu1, *baru;//bantu = Q, bantu1 = P

void buatNode();
void tambahNode();
bool isEmpty();
void preOrder(Node *bantu2);
void inOrder(Node *bantu2);
void postOrder(Node *bantu2);

int main(){
	short pilih;
	do{
		cout<<"MENU TREE"<<endl;
		cout<<"1. Tambah Node"<<endl;
		cout<<"2. Tampil Dengan Metode Preorder"<<endl;
		cout<<"3. Tampil Dengan Metode Inorder"<<endl;
		cout<<"4. Tampil Dengan Metode Postorder"<<endl;
		cout<<"5. Exit"<<endl;
		cin>>pilih;	
		switch(pilih){
			case 1 : 
			tambahNode();
			break;	
			case 2	: 
			cout<<"Isi data pada tree :";
			preOrder(root);
			break;
			case 3 : 
			cout<<"Isi data pada tree :";
			inOrder(root);
			break;
			case 4	: 
			cout<<"Isi data pada tree :";
			postOrder(root);
			break;
			default : cout<<"Pilihan tidak ada"<<endl;
		}
		cout<<endl;
	}while (pilih != 5);
	
}

void buatNode(){
	short nilai;
	cout<<"Input nilai : ";
	cin>>nilai;
	baru = new Node;
	baru->data = nilai;
	baru->kiri = NULL;
	baru->kanan = NULL;
}
bool isEmpty(){
	if(root == NULL)
		return true;
	else
		return false;	
}
void tambahNode(){
	//1. buat node
	buatNode();
	//2. cek apakah tree kosong atau tidak
	if(isEmpty()){
		//3. jika iya, maka data baru sebagai root, perintahnya root = baru
		root = baru;
		cout<<"Data berhasil di inputkan ke dalam tree"<<endl;
	}else{
		//4. jika tidak 
		bantu = root;
		bantu1 = root;
		while(( bantu != NULL) && (baru->data != bantu1->data)){
			//5.  bantu = bantu1
			bantu1 = bantu;
			//6. cek apakah baru->data < bantu1->data
			if(baru->data < bantu1->data){
				bantu = bantu1->kiri;
			}else{
				bantu = bantu1->kanan;
			}
		}	
		//8. cek apakah baru->Data = bantu1->Data
		if (baru->data == bantu1->data){
			cout<<"Data sudah ada di dalam tree"<<endl;
		}else{
			//cek, untuk menentukan posisi
			if(baru->data < bantu1->data){
				bantu1->kiri = baru;
			}else{
				bantu1->kanan = baru;
			}
			cout<<"Data berhasil di inputkan ke dalam tree"<<endl;
		}
		
	}
}
void preOrder(Node *bantu2){
	if (bantu2 != NULL){
		cout<<bantu2->data<<" ";
		preOrder(bantu2->kiri);
		preOrder(bantu2->kanan);
	}
}
void inOrder(Node *bantu2){
	if (bantu2 != NULL){
		inOrder(bantu2->kiri);
		cout<<bantu2->data<<" ";
		inOrder(bantu2->kanan);
	}
}
void postOrder(Node *bantu2){
	if (bantu2 != NULL){
		postOrder(bantu2->kiri);
		postOrder(bantu2->kanan);
		cout<<bantu2->data<<" ";
	}
}


