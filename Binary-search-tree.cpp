//
// Created by Nithin K Shine on 22-11-2021.
//
#include <iostream>
using namespace std;

// To create a binary search tree of patients
struct patient{
    string name;// Name of the patient
    string description;// Info about the patients' disease
    patient *left;
    patient *right;
};
// To create a new node
patient* newpatient(string name,string dsc)
{
    patient *temp=new patient;
    temp->name = name;
    temp->description = dsc;
    temp->left = temp->right = nullptr;
    return temp;
}
// To search for a patient using name
// It returns the address of the node
patient* search(patient *root,string name){
    if((root== nullptr)||(root->name==name))return root;
    if(name<root->name)return search(root->left,name);
    return search(root->right,name);
}

// To insert a new node in BST
/* The new node is inserted in left or right of the root node
 * by checking the precedence in alphabetical order
 * if it's greater in alphabetical order then it's added in the right node
 * and vice-versa*/
patient* insert(patient *patient, string name,string dsc){
    /* If the tree is empty, return a new patient */
    if (patient == nullptr) return newpatient(name,dsc);
    /* Otherwise, recur down the tree */
    if (name <= patient->name)
        patient->left = insert(patient->left, name,dsc);
    else if (name > patient->name)
        patient->right = insert(patient->right, name,dsc);
    /* return the (unchanged) patient pointer */
    return patient;
}

//Inorder display of patients
void Display(patient  *patient){
    if (patient == nullptr)return;
    Display(patient->left);
    cout<<patient->name<<"->";
    Display(patient->right);
}

// To delete a node in BST
patient* del(patient *root,string name){
    if(root== nullptr){
        cout<<"Patient not found";
        return root;
    }
    else if(name<root->name)root->left=del(root->left,name);
    else if(name>root->name)root->right=del(root->right,name);
    else{
        if(root->left== nullptr&&root->right==nullptr)return nullptr;
        else if(root->left== nullptr){
            patient *tmp=root->right;
            delete(root);
            return tmp;
        }
        else if(root->right== nullptr){
            patient *tmp=root->left;
            delete(root);
            return tmp;
        }
        patient* ptr = root->right;
        while (ptr && ptr->left != nullptr)
            ptr = ptr->left;
        root->name=ptr->name;
        root->right=del(root->right,ptr->name);
    }
    return root;
}