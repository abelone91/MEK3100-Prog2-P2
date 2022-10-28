#include <iostream>
#include <string>
using namespace std;

//max nr of books is 1000, hence the array size
const int array_size= 1000;  

void insert_record();
void delete_entry();
void undelete_entry();
void print_record();
void search_by_ISBN();

struct Entry {
    int book_ISBN; 
    string book_title; 
    string book_author;
    int book_pub_year; 
} book[array_size], deleted[array_size];

int book_nr=0;
int books_deleted=0; 


int main() {
    
    char option;
    cout <<"*********************************"; 
    cout <<"\nPlease enter a command: ";
    cout <<"\n'A': Add an entry ";
    cout <<"\n'D': Delete an entry";
    cout <<"\n'U': Undelete an entry";
    cout <<"\n'P': Print the books";
    cout <<"\n'S': Search in the list";
    cout <<"\n'Q': Quit";
    cout <<"\n*********************************"; 
    cout <<"\ninsert your chosen option here: "; 
    cin >> option; 

    switch (option) {

        case 'A':
        insert_record(); 
        break;

        case 'D':
        delete_entry();
        break;

        case 'U':
        break;

        case 'P': 
        print_record();
        break;

        case 'S':
        search_by_ISBN();
        break;

        case 'Q': 
        cout<<"Bye"; 
        exit(0); 

        default: 

        cout<<"!!!Please enter a valid input"<<endl;


    }

    main();
};

//function to insert record 

void insert_record(){
    int n; 
    cout<<"\nHow Many books are you planning to add: ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "Enter book ISBN ";
        cin >> book[book_nr].book_ISBN;
        cout << "Enter book title ";
        cin >> book[book_nr].book_title;
        cout << "Enter name of the author ";
        cin >> book[book_nr].book_author;
        cout << "Enter publication year ";
        cin >> book[book_nr].book_pub_year;
        book_nr++;
     }
     cout <<"Record updated!!"<<endl;

}; 

//function to delete record

void delete_entry(){
    int search_word;
    cout <<"\nEnter ISBN code: ";
    cin >>search_word; 
    for (int i=0; i<book_nr;i++){
        if(search_word==book[i].book_ISBN){
            //copy record to deleted struct member 
            deleted[book_nr].book_ISBN = book[i].book_ISBN;
            deleted[book_nr].book_title = book[i].book_title;
            deleted[book_nr].book_author = book[i].book_author;
            deleted[book_nr].book_pub_year = book[i].book_pub_year;
            // empty book Entry 

            for (int j=i;j<book_nr-1;j++) {
                book[j].book_ISBN = book[j+1].book_ISBN;
                book[j].book_title = book[j+1].book_title;
                book[j].book_author= book[j+1].book_author;
                book[j].book_pub_year = book[j+1].book_pub_year;
            }
            book_nr--;
            books_deleted++;
            cout<<"\nRecord deleted!"<<endl;
        }

        else { 
            cout <<"No record was found!"<<endl;
        }
    }
};

//function to undelete record

void undelete_entry(){
    int search_word;
    cout <<"\nEnter ISBN code: ";
    cin >>search_word; 
    for (int i=0; i<books_deleted;i++){
        if(search_word==deleted[i].book_ISBN){
            book[book_nr].book_ISBN = deleted[i].book_ISBN;
            book[book_nr].book_title = deleted[i].book_title;
            book[book_nr].book_author = deleted[i].book_author;
            book[book_nr].book_pub_year = deleted[i].book_pub_year;
            // empty deleted Entry 

            for (int j=i;j<book_nr-1;j++) {
                deleted[j].book_ISBN = deleted[j+1].book_ISBN;
                deleted[j].book_title = deleted[j+1].book_title;
                deleted[j].book_author= deleted[j+1].book_author;
                deleted[j].book_pub_year = deleted[j+1].book_pub_year;
            }

            books_deleted--; 
            book_nr++;

            cout<<"Record restored!"<<endl;
        }

        else { 
            cout <<"No record was found!"<<endl;
        }
    }
};


//functio to print records

void print_record(){
    cout<<"\n There are "<< book_nr <<" books on record"<<endl;
    for (int i=0; i<book_nr;i++){ 
    cout <<"*********************************"<<endl; 
    cout <<"\nBook ISBN: "<<book[i].book_ISBN<<endl;
    cout <<"\nBook title: "<< book[i].book_title<<endl;
    cout <<"\nBook Author: "<< book[i].book_author<<endl;
    cout <<"\nBook Publication year: "<< book[i].book_pub_year<<endl;
    }
    
};

//search by ISBN 

void search_by_ISBN(){
    int search_word;
    cout <<"\nEnter ISBN code: ";
    cin >>search_word; 
    for (int i=0; i<book_nr;i++){

        if(search_word==book[i].book_ISBN){
                cout <<"\nBook ISBN: "<<book[i].book_ISBN<<endl;
                cout <<"\nBook title: "<< book[i].book_title<<endl;
                cout <<"\nBook Author: "<< book[i].book_author<<endl;
                cout <<"\nBook Publication year: "<< book[i].book_pub_year<<endl;
        }
         else { 
                cout <<"No record found!"<<endl;
        }

    }
};
