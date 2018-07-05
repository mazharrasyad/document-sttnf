/*
  Muhammad Azhar Rasyad
  0110217029
  STT Terpadu Nurul Fikri
  Teknik Informatika 1
  Kelas Pagi
  Semester 2
  Struktur Data Algoritma
*/

#include <iostream>

#define max 5
int value;
int counter = 0;

using namespace std;

struct node
{
  int data;
  node *next;
} *top, *baru, *bantu;

void create(int value);
void push();
void pop();
void read();
void clear();

int main()
{
  int menu;

  menu:
  cout << "\n----- Stack Linked List -----" << endl;
  cout << "\n1. Push";
  cout << "\n2. Pop";
  cout << "\n3. Read";
  cout << "\n4. Clear";
  cout << "\n5. Exit" << endl;
  cout << "\nChoose Function : ";
  cin >> menu;

  switch(menu)
  {
    case 1:
      cout << "\nInput Data = ";
      cin >> value;
      create(value);
      push();
      goto menu;
      break;

    case 2:
      pop();
      goto menu;
      break;

    case 3:
      read();
      goto menu;
      break;

    case 4:
      clear();
      goto menu;
      break;

    case 5:
      cout << "\n---------- Thanks For Using The Program ----------" << endl;
      break;

    default:
      cout << "\n---------- Error No Function ----------" << endl;
      cout << "\nPress Any Key To Continue...";
      cin.ignore();
      cin.get();
      goto menu;
      break;
  }
}

void create(int value)
{
  baru = new node;
  baru -> data = value;
  baru -> next = NULL;
}

void push()
{
  if(top == NULL)
  {
    top = baru;
    counter++;

    cout << "\n<---Input Stack Is Success--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else if(counter == max)
  {
    cout << "\n<---Stack Is Full--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else
  {
    baru -> next = top;
    top = baru;
    counter++;

    cout << "\n<---Input Stack Is Success--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
}

void pop()
{
  if(top == NULL)
  {
    cout << "\n<---Stack Is Empty--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else
  {
    top = top -> next;
    counter--;

    cout << "\n<---Delete Stack Is Success--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
}

void read()
{
  if(top == NULL)
  {
    cout << "\n<---Stack Is Empty--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else if(top -> next == NULL)
  {
    cout << "\nData Stack : " << endl;
    cout << "    |" << top -> data << "|" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else
  {
    bantu = top;
    cout << "\nData Stack : " << endl;
    while(bantu != NULL)
    {
      cout << "    |" << bantu -> data << "|" << endl;
      bantu = bantu -> next;
    }
    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
}

void clear()
{
  if(top == NULL)
  {
    cout << "\n<---Stack Is Empty--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else
  {
    top = NULL;
    counter = 0;

    cout << "\n<---Stack Is Clear--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
}
