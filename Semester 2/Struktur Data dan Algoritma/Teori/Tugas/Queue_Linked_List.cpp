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
} *head, *tail, *baru, *bantu;

void create(int value);
void enqueue();
void dequeue();
void read();
void clear();

int main()
{
  int menu;

  menu:
  cout << "\n----- Queue Linked List -----" << endl;
  cout << "\n1. Enqueue";
  cout << "\n2. Dequeue";
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
      enqueue();
      goto menu;
      break;

    case 2:
      dequeue();
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

void enqueue()
{
  if(head == NULL)
  {
    head = baru;
    tail = baru;
    counter++;

    cout << "\n<---Input Queue Is Success--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else if(counter == max)
  {
    cout << "\n<---Queue Is Full--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else if(head -> next == NULL)
  {
    head -> next = baru;
    tail = baru;
    counter++;

    cout << "\n<---Input Queue Is Success--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else
  {
    bantu = tail;
    tail -> next = baru;
    tail = baru;
    counter++;

    cout << "\n<---Input Queue Is Success--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
}

void dequeue()
{
  if(head == NULL)
  {
    cout << "\n<---Queue Is Empty--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else
  {
    head = head -> next;
    counter--;

    cout << "\n<---Delete Queue Is Success--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
}

void read()
{
  if(head == NULL)
  {
    cout << "\n<---Queue Is Empty--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else if(head -> next == NULL)
  {
    cout << "\nData Queue : " << "|" << tail -> data << "|" << endl;
    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else
  {
    bantu = head;
    cout << "\nData Queue : ";
    while(bantu != NULL)
    {
      cout << "|" << bantu -> data;
      if(bantu -> next == NULL)
      {
        cout << "|";
      }
      else
      {
        cout << "| <- ";
      }
      bantu = bantu -> next;
    }
    cout << endl;
    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
}

void clear()
{
  if(head == NULL)
  {
    cout << "\n<---Queue Is Empty--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
  else
  {
    head = NULL;
    tail = NULL;
    counter = 0;

    cout << "\n<---Queue Is Clear--->" << endl;

    cout << "\nPress Any Key To Continue...";
    cin.ignore();
    cin.get();
  }
}
