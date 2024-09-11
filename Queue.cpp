#include <iostream>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class Queue{
	private:
		Node *head;
		Node *tail;
	public:
		int length;
		Queue() : head(nullptr),tail(nullptr),length(0){}
		
		void enqueue(int data){
			Node *temp = new Node();
			temp->data = data;
			if (this->tail == nullptr){
				this->head = this->tail = temp;
			}else{
				this->tail->next = temp;
				this->tail = this->tail->next;
			}
			this->length++;
		}
		
		int dequeue(){
			int data = -999;
			if (this->head == nullptr){
				return data;
			}else if (this->head->next == nullptr){
				data = this->head->data;
				delete this->head;
				this->head = nullptr;
				return data;
			}else{
				data = this->head->data;
				Node *temp = this->head->next;
				delete this->head;
				this->head = temp;
				return data;
			}
		}
};	 

void isiQueue(Queue *Q,int A[10]){
	for (int i = 0;i < 10;i++){
		Q->enqueue(A[i]);
	}
}

void kosongkanQueue(Queue *Q){
	int lim = Q->length;
	for (int i = 0;i < lim;i++){
		std::cout<<Q->dequeue()<<" "<<i<<std::endl;
	}
	std::cout<<std::endl;
}

int main(){
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	Queue Q;
	isiQueue(&Q,A);
	std::cout<<Q.length<<std::endl;
	kosongkanQueue(&Q);
}