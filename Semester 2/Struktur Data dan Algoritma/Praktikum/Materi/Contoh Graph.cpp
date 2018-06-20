#include<iostream>
// #include<conio.h>
#include <curses.h>
#include<stdlib.h>
using namespace std;

struct graph{
	graph *left;
	string info;
	int bobot;
	graph *right;
}*PE,*PV,*first,*last,*last1,*baru;
void newGraph(string data,int nilai);

void verteks();
void edge();
void tampil();
bool isEmpty();
bool isFull();

string data,v;
int nilai,maxG,counter;

int main(){
	int pilih;
	cout<<"Masukkan Jumlah Data : ";cin>>maxG;
	system("cls");
	do{
		cout<<"MENU GRAPH LIST\n";
		cout<<"1. Tambah Verteks\n";
		cout<<"2. Tambahn Edge\n";
		cout<<"3. Lihat Graph\n";
		cout<<"4. Exit\n";
		cout<<"Pilih Menu : ";cin>>pilih;
		switch(pilih){
			case 1:
			system("cls");
			verteks();
			system("cls");
			break;
			case 2:
			system("cls");
			edge();
			system("cls");
			break;
			case 3:
			system("cls");
			tampil();
			system("cls");
			break;
			case 4:
			cout<<"Terima Kasih";
			break;
			default:     
			cout<<"Nomor Yang Anda Masukkan Salah";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
		}
	}while(pilih != 4);
}

bool isEmpty(){
	if(first == NULL){
		return true;
	}
	else{
		return false;
	}
}
bool isFull(){
	if(counter == maxG){
		return true;
	}
	else{
		return false;
	}
}
void newGraph(string data,int nilai){
	baru = new graph;//new(instruksi dasar)
	baru->info = data;//isi data
	baru->bobot = nilai;
	baru->left = NULL;//karena terdiri dari 1 node,maka next= null
	baru->right = NULL;
}
void verteks(){
	if(isFull()){
		cout<<"Maaf,Verteks Penuh";
	}
	else{
		cout<<"Masukkan Verteks : ";cin>>data;
		newGraph(data,nilai);
		if(isEmpty()){
			first = baru;
			last = baru;
			last1 = baru;
		}
		else{
			last->left = baru;
			last = baru;
		}
		counter++;
		cout<<"Verteks Berhasil Ditambahkan";
	}
	getchar();
}
void edge(){
	if(isEmpty()){
		cout<<"Maaf,Operasi Tidak Bisa Dilakukan";
		cout<<"Gunakan Tambah Verteks";
	}
	else{
		PV = first;
		cout<<"Tentukan Verteks : ";cin>>v;
		while(PV != NULL){
			if(PV->info != v){
				PV = PV->left;
				last1 = PV;
				if(PV == NULL){
					cout<<"Maaf,Verteks Tidak ada";
				}
			}
			else{
				cout<<"Edge Akan Ditambahkan Ke Verteks : "<<v<<"\n";
				cout<<"Masukkan Edge : ";cin>>data;
				cout<<"Masukkan Bobot : ";cin>>nilai;
				newGraph(data,nilai);
				last1->right = baru;
				last1 = baru;
				cout<<"Tentukan Hubungan : ";cin>>v;
				while(PV != NULL){
					if(PV->info != v){
						PV = PV->left;
						if(PV == NULL){
							cout<<"Maaf,Verteks Tidak ada";
						}
					}
					else{
						baru->left = PV;
						cout<<"Edge Berhasil Ditambahkan";
						break;
					}
				}
				break;
			}
		}
	}	
getchar();
}
void tampil(){
	if(isEmpty()){
		cout<<"Maaf,Graph Kosong";
	}
	else{
		PV = first;
		while (PV != NULL){
			cout<<"Verteks "<<PV->info;
			PE = PV->right;
			while(PE != NULL){
				cout<<", Berhubungan Melalui "<<PE->info<<" Dengan "<<PE->left->info<<" Berbobot "<<PE->bobot;
				PE = PE->right;
			}
			cout<<endl;
			PV = PV->left;
		}
	}
	getchar();
}

