#include<iostream>
using namespace std;

void tampil(int n,int data[]);
void binSearch(int n, int data[], int find);
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

    binSearch(n,data,find);
}

void tampil(int n, int data[]){
    cout<<"Data yang dimasukkan : ";
    for(int i = 0;i<n;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

void binSearch(int n, int data[], int find){
    int l = 0, r = n-1, m;
    bool isFound = false;
    while(!isFound && l<=r){
        m = (l+r)/2;
        if(data[m] == find){
            isFound = true;            
        }else if(data[m] < find){
            l = m+1;
        }else if(data[m] > find){
            r = m-1;
        }
    }
    hasilSearch(isFound, m);
}

void hasilSearch(bool isFound, int counter){
    if(isFound){
        cout<<"Data ada di urutan ke-"<<counter+1;
    }else{
        cout<<"Maaf, data tidak ditemukan";
    }
    cout<<endl;
}
