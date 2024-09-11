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
		Stack() : tail(nullptr),head(nullptr),length(0) {}
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
				
				this->tail->next = temp;
				this->tail = this->tail->next;
			}
			this->length++;
		}
		int pop(){
			if (this->head == nullptr){
				return -999;
			}else if (this->head->next == nullptr){
				int data = this->head->data;
				delete this->head;
				this->head = nullptr;
				this->tail = this->head;
				this->length--;
				return data;
			}else{
				int data = this->tail->data;
				Node *temp;
				temp = this->head;
				while (temp->next->next != nullptr){
					temp = temp->next;
				}
				temp->next = nullptr;
				delete this->tail;
				this->tail = temp;
				this->length--;
				return data;
			}
		}
};

void isiStack(Stack *S,int A[10]){
	for (int i = 0;i < 10;i++){
		S->push(A[i]);
	}
}

void kosongkanStack(Stack *S){
	int lim = S->length;
	for (int i = 0;i < lim;i++){
		std::cout<<S->pop()<<" "<<i<<std::endl;
	}
	std::cout<<std::endl;
}

int main(){
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	Stack S;
	isiStack(&S,A);
	std::cout<<S.length<<std::endl;
	kosongkanStack(&S);
}