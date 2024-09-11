#include <iostream>

struct Node{
	int data;
	Node *next;
};

class Stack{
	private:
		Node *head;
		Node *tail;
	public:
		int length;
		Stack(){
			this->tail = nullptr;
			this->head = nullptr;
			this->length = 0;
		}
		void push(int data){
			if (this->tail == nullptr){
				this->head = new Node;
				this->head->data = data;
				this->head->next = nullptr;
				
				this->tail = this->head;
			}else{
				Node *temp = new Node;
				temp->data = data;
				temp->next = nullptr;
				
				tail->next = temp;
				tail = tail->next;
			}
			this->length++;
		}
		int pop(){
			
		}
}