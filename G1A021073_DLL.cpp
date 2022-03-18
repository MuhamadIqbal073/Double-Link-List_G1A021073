#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;

typedef struct node
{
      long data;
      node* next;
      node* prev;
};
node* head;
node* tail;
node* print;
node* del;
node* entry;

void inisialisasi()
{
      head = NULL;
      tail = NULL;
}

int isEmpty()
{
      if(head == NULL)
            return 1;
      else
            return 0;
}

void input(int *dta)
{
      entry = new node;
      entry->data = *dta;
      entry->next = NULL;
      entry->prev = NULL;
      if(isEmpty()==1)
      {
            head = entry;
            head->next = NULL;
            head->prev = NULL;
            tail=head;
      }
      else
      {
            tail->next = entry;
            entry->prev = tail;
            tail = entry;
      }
}
void hapus()
{
      int simpan;
      if(head!=NULL)
      {
            if(head->next != NULL)
            {
            del=head;
            simpan = head->data;
            cout<<"\n"<<simpan<<" telah dihapus"<<endl;
            head = head->next;
            head->prev = NULL;
            delete del;
            }
            else
            {
                  simpan = head->data;
                  cout<<"\n"<<simpan<<" telah dihapus"<<endl;
                  head = NULL;
            }

      }
      else
            cout<<"\nLinked List kosong penghapusan tidak dapat dilakukan"<<endl;
}

void cetak()
{
      print = head;
      if(head!=NULL)
      {
            while(print!=NULL)
            {
                  cout<<"\n\t"<<print->data;
                  print = print->next;
            }
      }
      else
            cout<<"\nTidak ada data dalam linked list"<<endl;

}
void menu()
{
      char pilih, ulang;
      int data;
      do
      {
            system("CLS");
menu :
      cout<<"DOUBLE LINKED LIST"<<endl;
      cout<<"-------------------------------"<<endl;
      cout<<"Menu: ";
      cout<<"\n1. Masukan Data";
      cout<<"\n2. Hapus Data";
      cout<<"\n3. Cetak Data";
      cout<<"\n4. Keluar";
      cout<<"\nMasukkan pilihan Anda : ";
      cin>>pilih;

      switch(pilih)
      {
      case '1' :
            cout<<"\nMasukkan Data yang anda inginkan  : ";
            cin>>data;

            input(&data);
            cout<<"\n"<<data<<" telah ditambahkan"<<endl;
            break;
      case '2' :
            hapus();
            break;
      case '3'  :
            cetak();
            break;
      case '4' :
            cout<<"\nTerima kasih"<<endl;
            exit;
            break;
      default :
            cout<<"\nPilih ulang"<<endl;
            goto menu;
      }
      cout<<"\nKembali ke menu? (y/n)";
      cin>>ulang;
      }while(ulang=='y' || ulang =='Y');
}

int main()
{
      inisialisasi();
      menu();
      return 0 ;
}
