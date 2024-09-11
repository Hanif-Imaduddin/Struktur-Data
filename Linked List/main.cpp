#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void append(Node** head,int data){

    if(*head == nullptr){
        *head = new Node;
        (*head)->data = data;
        (*head)->next = nullptr;
    }else{
        Node* temp;
        temp = *head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new Node;
        temp->next->data = data;
        temp->next->next = nullptr;
    }
}

void display(Node* head){
    if(head != nullptr){
        cout<<head->data<<" ";
        display(head->next);
    }else{
        return;
    }
}

void deleteNode(Node* head,int i){
    if(head == nullptr){
        return;
    }else if(head->next==nullptr){
        delete head;
    }else{
        Node* temp;
        Node* prev;
        prev = head;
        for(int j = 0;j < i-1;j++){
            prev = prev->next;
        }
        temp = prev->next->next;
        delete prev->next;
        prev->next = temp;
    }
}

int main()
{
    struct Node* A;
    A = nullptr;
    int B[] = {2,4,1,5,6};
    for(int i = 0;i < 5;i++){
        append(&A,B[i]);
    }
    display(A);
    deleteNode(A,4);
    cout<<endl;
    display(A);
    return 0;
}
