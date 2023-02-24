//
// Created by Nithin K Shine on 22-11-2021.
//

#include <iostream>
#include "Binary-search-tree.cpp"
using namespace std;

// Linked List node of Doctors
class Doc{

public:
    string name;
    Doc* next;
    patient *root= nullptr;
};

// Hash Table
/*
 * Although the hash table data structure is used here,
 * the concept is different from the original hash table
 * When inserting a new patient/doctor the department is asked
 * The department name(string) is used as the Hash table key
 * The modulus 10 of the ASCII code of first character of department name is the hash function
 * (The hash function can be changed later such that each cell of Hash table
 * represent each department of the hospital)
 * The hash table uses separate chaining to prevent collision
 * Each node of the chain contains the details of a doctor in the respective department
 * Each node also contains a root pointer of the BST in which the patient's details are stored
 */
class HashTable{

public:
    Doc** HT;
    HashTable();
    void Insert_doc(string key);
    void Insert_pat(string key);
    void Search(string key);
    void Print(string key);
    void Delete(string key);
    ~HashTable();
};

// Constructor
HashTable::HashTable() {
    HT = new Doc* [10];
    for (int i=0; i<10; i++){
        HT[i] = nullptr;
    }
}

// Inserting a new doctor
void HashTable::Insert_doc(string key) {
    /*ASCII code:
     * o->111
     * c->99
     * n->110*/
    string doc;
    int hIdx = key[0]%10;//hashing
    cout<<"Enter Doctor's name : ";
    cin>>doc;
    Doc* t = new Doc;
    t->name = doc;
    t->next = nullptr;
    // Case: No nodes in the linked list
    if (HT[hIdx] == nullptr)HT[hIdx] = t;
    else {
        Doc *p = HT[hIdx];
        Doc *q=HT[hIdx];
        // Traverse to find insert position
        while (p!=nullptr && p->name < doc){
            q=p;
            p = p->next;
        }
        // Case: insert position is first
        if (q == HT[hIdx]){
            t->next = HT[hIdx];
            HT[hIdx] = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Inserting a new patient under a doctor
void HashTable::Insert_pat(string key) {
    int flag=0;
    int hIdx = key[0]%10;//hashing
    Doc* p = HT[hIdx];
    string doc,pat,dsc;
    cout<<"Enter doctor's name : ";
    cin>>doc;
    while (p){
        if (p->name == doc){
            flag=1;
            cout<<"Enter patient's name : ";
            cin>>pat;
            cout<<"Enter patient disease description : ";
            cin>>dsc;
            p->root=insert(p->root,pat,dsc);
        }
        p = p->next;
    }
    if(flag==0)cout<<"Doctor not found...Insert the Doctor first";
}

// Searching and displaying the details of a patient
void HashTable::Search(string key) {
    int hIdx = key[0]%10;//hashing
    int flag=0;
    Doc* p = HT[hIdx];
    string doc,pat;
    cout<<"Enter doctor's name : ";
    cin>>doc;
    while (p){
        if (p->name == doc){
            flag=1;
            cout<<"Enter patient's name : ";
            cin>>pat;
            if(search(p->root,pat)){
                cout<<"Patient name : "<<p->root->name;
                cout<<"\nDisease description : "<<p->root->description;
            }
            else cout<<"Not found\n";
            break;
        }
        p = p->next;
    }
    if(flag==0)cout<<"Doctor not found...Insert the Doctor first";
}

// Displaying names of all patient's under a doctor
void HashTable::Print(string key){
    string doc;
    int flag=0;
    cout<<"Enter doctor's name : ";
    cin>>doc;
    int hIdx = key[0]%10;//hashing
    Doc *p = HT[hIdx];
    // Traverse to find position
    while (p){
        if(p->name == doc){
            flag=1;
            Display(p->root);
            cout<<"NULL\n";
        }
        p = p->next;
    }
    if(flag==0)cout<<"Doctor not found...Insert the Doctor first";
}

// Removing a patient's data
void HashTable::Delete(string key) {
    int hIdx = key[0]%10;//hashing
    int flag=0;
    Doc* p = HT[hIdx];
    string doc,pat;
    cout<<"Enter doctor's name : ";
    cin>>doc;
    while (p){
        if (p->name == doc){
            flag=1;
            cout<<"Enter patient's name : ";
            cin>>pat;
            p->root= del(p->root,pat);
            break;
        }
        p = p->next;
    }
    if(flag==0)cout<<"Doctor not found...Insert the Doctor first";
}

// Destructor
HashTable::~HashTable() {
    for (int i=0; i<10; i++){
        Doc* p = HT[i];
        while (HT[i]){
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    delete [] HT;
}