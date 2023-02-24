//
// Created by Nithin K Shine on 22-11-2021.
//

#include <iostream>
#include "Hashtable-chaining.cpp"
using namespace std;
// The driver code
int main() {
    int ch;
    string x,y;
    //dpts[]={"cardiology","oncology","neurology"};
    HashTable dpt;// Creating a Hash table object
    cout<<"\n\t\t\t***-----------Welcome to VIT Hospital Data Management System-----------***\n";
    cout<<"Enter your choice";

    do
    {
        cout<<"\n1.Insert Doctor | 2.Insert Patient | 3.Search a Patient records | 4.Display Patients | "
              "5.Remove a patient | 6.Exit\n";
        cin>>ch;
        switch(ch)
        {
            // To insert a new Doctor
            case 1:
                cout<<"Enter the department : ";
                cin>>x;
                dpt.Insert_doc(x);
                break;
            // To insert a new Doctor
            case 2:
                cout<<"Enter the department : ";
                cin>>x;
                dpt.Insert_pat(x);
                break;
            // To search for a patient's records
            case 3:
                cout<<"Enter the department : ";
                cin>>x;
                dpt.Search(x);
                break;
            // To display all patient's under a Doctor
            case 4:
                cout<<"Enter the department : ";
                cin>>x;
                dpt.Print(x);
                break;
            // To remove a patient
            case 5:
                cout<<"Enter the department : ";
                cin>>x;
                dpt.Delete(x);
                break;
            // To exit
            case 6:
                cout<<"\t\t\t*****-- Thank you for using VIT Hospital Data Management System --*****";
                break;

            default:
                cout<<"Invalid Input"<<endl;
        }
    }
    while(ch!=6);
    return 0;
}
