#include<iostream>
using namespace std;

void tampil(int n,int data[]);
void seqSearch(int n, int data[], int find);
void hasilSearch(bool isFound, int counter);

int main(){
    int n, find;

    //Berikan maksimal jumlah data yang bisa dimasukkan(pada array)
    cout<<"Masukkan jumlah data : ";
    cin>>n;

    int data[n];
    //Masukkan data
    for(int i = 0;i<n;i++){
        cout<<"Masukkan data "<<i+1<<" : ";
        cin>>data[i];
    }

    //Tampilkan data
    tampil(n,data);

    cout<<"Masukkan data yang ingin dicari : ";
    cin>>find;

    seqSearch(n,data,find);
}

void tampil(int n, int data[]){
    cout<<"Data yang dimasukkan : ";
    for(int i = 0;i<n;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

void seqSearch(int n, int data[], int find){
    int counter = 0;
    bool isFound = false;
    while(!isFound && counter <= n){
        if(data[counter] == find){
            isFound = true;            
        }else{
            counter++;
        }
    }
    hasilSearch(isFound, counter);
}

void hasilSearch(bool isFound, int counter){
    if(isFound){
        cout<<"Data ada di urutan ke-"<<counter+1;
    }else{
        cout<<"Maaf, data tidak ditemukan";
    }
    cout<<endl;
}
