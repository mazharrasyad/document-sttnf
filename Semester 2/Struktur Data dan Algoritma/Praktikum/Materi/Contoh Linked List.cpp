#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct node{ //deklarasi sebuah node
	int data; //isi data
	node *next;	//menunjuk node selanjutnya
}*head=NULL, *tail=NULL, *baru, *bantu, *bantu1;//*bantu dibutuhkan karena head n tail tdk blh pindah
void membuatNode(int nilai);
void tambahDepan(),tambahTengah(),tambahBelakang();
void lihatAll(),lihatDepan(),lihatTengah(),lihatBelakang();
void ubahDepan(),ubahTengah(),ubahBelakang();
void hapusDepan(),hapusTengah(),hapusBelakang();
int nilai,dataBaru,posisi;

int main(){
	int Pilihan=0;
	do{
		cout<<"MENU SINGLE LINKED LIST\n";
		cout<<"1. Tambah Depan\n";
		cout<<"2. Tambah Tengah\n";
		cout<<"3. Tambah Belakang\n";
		cout<<"4. Hapus Depan\n";
		cout<<"5. Hapus Tengah\n";
		cout<<"6. Hapus Belakang\n";
		cout<<"7. Tampilkan Seluruh Data\n";
		cout<<"8. Tampilkan Data Depan\n";
		cout<<"9. Tampilkan Data Tengah\n";
		cout<<"10. Tampilkan Data Belakang\n";
		cout<<"11. Ubah data Depan\n";
		cout<<"12. Ubah data Tengah\n";
		cout<<"13. Ubah data Belakang\n";
		cout<<"14. Selesai\n";
		cout<<"Pilihan Anda : ";cin>>Pilihan;
		switch(Pilihan){
			case 1:
			system("cls");
			tambahDepan();
			system("cls");
			break;
			case 2:
			system("cls");
			tambahTengah();
			system("cls");
			break;
			case 3:
			system("cls");
			tambahBelakang();
			system("cls");
			break;
			case 4:
			system("cls");
			hapusDepan();
			system("cls");
			break;
			case 5:
			system("cls");
			hapusTengah();
			system("cls");
			break;
			case 6:
			system("cls");
			hapusBelakang();
			system("cls");
			break;
			case 7:
			system("cls");
			lihatAll();
			system("cls");
			break;
			case 8:
			system("cls");
			lihatDepan();
			system("cls");
			break;
			case 9:
			system("cls");
			lihatTengah();
			system("cls");
			break;
			case 10:
			system("cls");
			lihatBelakang();
			system("cls");
			break;
			case 11:
			system("cls");
			ubahDepan();
			system("cls");
			break;
			case 12:
			system("cls");
			ubahTengah();
			system("cls");
			break;
			case 13:
			system("cls");
			ubahBelakang();
			system("cls");
			break;
			case 14:
			cout<<"Terima Kasih\n";
			getch();
			break;
		}
	}while(Pilihan != 14);
	return 0;
}

void membuatNode(int nilai){
	baru = new node;//new(instruksi dasar)
	baru->data = nilai;//isi data
	baru->next = NULL;//karena terdiri dari 1 node,maka next= null
}
void tambahDepan(){
	cout<<"Input nilai : ";cin>>nilai;
	membuatNode(nilai);
	if(head == NULL){//mengetahui linklist kosong
		head = baru;//head menunjuk sebuah node yang diketahui oleh baru
		tail = baru;//tail menunjuk sebuah node yang diketahui oleh baru
		tail->next = NULL;
	}
	else{//mengetahui linklist berisi
		baru->next=head;//head karena head mengetahui node dari head
		head=baru;
	}
	cout<<"Data berhasil di simpan "<<endl;
	getch();
}
void tambahTengah(){
	if(head != NULL && head != tail){
		bantu = head;
		cout<<"Masukkan posisi yang ingin ditambah : ";cin>>posisi;
		for(int i = 1; i<--posisi; i++){
			bantu = bantu -> next;
		}
		cout<<"Input nilai : ";cin>>nilai;
		membuatNode(nilai);
		bantu1 = bantu -> next;
		baru -> next = bantu1;
		bantu -> next = baru;
		cout<<"Data berhasil di simpan "<<endl;
	}
	else{
		cout<<"Operasi Tidak Bisa Dilakukan";	
	}
	getch();
}
void tambahBelakang(){
	cout<<"Input nilai : ";cin>>nilai;
	membuatNode(nilai);
	if(tail == NULL){//mengetahui linklist kosong
		tail = baru;//tail menunjuk sebuah node yang diketahui oleh baru
		head = baru;//head menunjuk sebuah node yang diketahui oleh baru
	}
	else{//mengetahui linklist berisi
		tail->next = baru;//tail next akan menyimpan alamat ke baru
		tail = baru;//baru akan menjadi tail
	}
	cout<<"Data berhasil di simpan "<<endl;
	getch();
}
void lihatAll(){
	//cek apakah linked list kosong?
	if(head == NULL){//mengetahui linklist kosong
		cout<<"Linked list kosong";	
	}
	//jika tidak apakah terdiri dari 1 atau n node
	else if(head->next == NULL){//head setelah dia =null
		cout<<"Isi linked list adalah "<<head->data;
	}
	//jika lebih dari >1 maka baca semua node
	else{
		bantu=head;
		cout<<"Isi Linked List:\n";
		while(bantu!=NULL){//jika bantu sudah null,maka dia sudah ada di akhir linklist
			cout<<bantu->data<<",";//mengakses data dari node bantu
			bantu=bantu->next;//memindahkan bantu ke nod selanjutnya dengan menggunakan bantu next
		}
	}
	getch();
	system("cls");	
}
void lihatDepan(){
	if(head == NULL){
		cout<<"Linked list kosong";
		getch();
	}
	else{
		cout<<"Isi linked list adalah "<<head->data;
		getch();
	}
}
void lihatTengah(){
	if(head != NULL && head != tail){
		bantu = head;
		cout<<"Masukkan posisi yang ingin dilihat : ";cin>>posisi;
		for(int i = 1; i<posisi; i++){
			bantu = bantu -> next;
		}
		cout<<"Data di posisi "<<posisi<<" adalah "<<bantu->data;
		getch();
	}
	else{
		cout<<"Operasi Tidak Bisa Dilakukan";	
	}
}
void lihatBelakang(){
	if(tail == NULL){
		cout<<"Linked list kosong";
		getch();
	}
	else{
		cout<<"Isi linked list adalah "<<tail->data;
		getch();
	}
}
void ubahDepan(){
	if(head != NULL){
		cout<<"Data yang akan diubah adalah "<<head -> data;
		cout<<"\nMasukan data baru : "; cin>>dataBaru;
		head->data = dataBaru;
		cout<<"Data berhasil diubah\n";
	}
	else{
		cout<<"linked list kosong\n";
	}
	getch();
}
void ubahTengah(){
	if(head != NULL && head != tail){
		bantu = head;
		cout<<"Masukkan posisi yang ingin diubah : ";cin>>posisi;
		for(int i = 1; i<posisi; i++){
			bantu = bantu -> next;
		}
		cout<<"Data yang akan diubah adalah "<<bantu -> data;
		cout<<"\nMasukkan data baru : ";cin>>dataBaru;
		bantu -> data = dataBaru;
		cout<<"Data berhasil diubah";
	}
	else{
		cout<<"Operasi Tidak Bisa Dilakukan";	
	}
	getch();
}
void ubahBelakang(){
	if(tail != NULL){//mengetahui linklist kosong
		cout<<"Data yang akan diubah adalah "<<tail -> data;
		cout<<"\nMasukan data baru : "; cin>>dataBaru;
		tail->data = dataBaru;
		cout<<"Data berhasil diubah\n";
	}
	else{//mengetahui linklist berisi
		cout<<"linked list kosong\n";
	}
	getch();
}
void hapusDepan(){
	if(head != NULL ){
		if(head->next == NULL){
			head = NULL;
			tail = NULL;
		}
		else{
			cout<<"Nilai yang dihapus adalah "<<head->data<<"\n";
			bantu = head;
			bantu = bantu -> next;
			head -> next = NULL;
			head = bantu;
		}	
	cout<<"Data berhasil di hapus"<<endl;
	}else{
		cout<<"Linked list kosong"<<endl;
	}
	getch();
}
void hapusTengah(){
	if(head != NULL && head != tail){
		bantu = head;
		cout<<"Masukkan posisi yang ingin dihapus : ";cin>>posisi;
		for(int i = 1; i<--posisi; i++){
			bantu = bantu -> next;
		}
		bantu1 = bantu->next;//bantu1 terletak di posisi setelah bantu
		bantu->next = bantu1->next;//ubah next bantu benjadi next bantu1
		bantu1->next = NULL;//ubah alamat next bantu 1 jadi NULL
		cout<<"Nilai yang dihapus adalah "<<bantu1->data<<"\n";
		cout<<"Data berhasil dihapus\n";		
	}
	else{
		cout<<"Operasi Tidak Bisa Dilakukan";	
	}
	getch();
}
void hapusBelakang(){
	if(tail != NULL ){
		if(tail->next == NULL){
			cout<<"Nilai yang dihapus adalah "<<tail->data;
			bantu = head;
			while(bantu->next != tail){
				bantu = bantu -> next;		
			}
			bantu -> next = NULL;
			bantu = tail;
		}
	cout<<"\nData berhasil di hapus"<<endl;
	}
	else{
		cout<<"Linked list kosong"<<endl;
	}
	getch();
}

