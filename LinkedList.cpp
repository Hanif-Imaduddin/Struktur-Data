#include <iostream>

struct Node
{
	int data;
	struct Node *next;
};

class LinkedList{
	private:
		Node *head;
		Node *tail;
	public:
		int length;
		LinkedList(){
			this->head = nullptr;
			this->length = 0;
		}
		void append(int data){
			if (this->head == nullptr){
				this->head = new Node;
				this->head->data = data;
				this->head->next = nullptr;
				
				this->tail = this->head;
			}else{
				this->tail->next = new Node;
				this->tail->next->data = data;
				this->tail->next->next = nullptr;
				this->tail = this->tail->next;
			}
			this->length++;
		}
		void print(){
			Node *temp;
			temp = this->head;
			while (temp != nullptr){
				std::cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
		void println(){
			Node *temp;
			temp = this->head;
			while (temp != nullptr){
				std::cout<<temp->data<<" ";
				temp = temp->next;
			}
			std::cout<<std::endl;
		}
		void remove(int idx){
			if (idx >= this->length || idx < 0){
				std::cout<<"Index out of range"<<std::endl;
			}else{
				Node* prev;
				Node* temp;
				prev = this->head;
				for (int i = 0;i < idx-1;i++){
					prev = prev->next;
				}
				if (prev == this->head){
					this->head = this->head->next;
					delete prev;
				}else{
					temp = prev->next;
					prev->next = temp->next;
					if (prev->next == nullptr){
						this->tail = prev;
					}
					delete temp;
					this->length--;
				}
			}
		}
		void insert(int idx,int data){
			Node* temp;
			if (idx > this->length || idx < 0){
				std::cout<<"Index out of range"<<std::endl;
			}else if(idx == 0){
				temp = new Node;
				temp->data = data;
				temp->next = this->head;
				this->head = temp;
				this->length++;
			}else{
				Node* prev;
				prev = this->head;
				for (int i = 0;i < idx-1;i++){
					prev = prev->next;
				}
				temp = new Node;
				temp->data = data;
				temp->next = prev->next;
				prev->next = temp;
				if (temp->next == nullptr){
					this->tail = temp;
				}
				this->length++;
			}
		}
		int get(int idx){
			if (idx >= this->length || idx < 0){
				std::cout<<"Index out of range"<<std::endl;
				return -999;
			}else{
				Node* temp;
				temp = this->head;
				for (int i = 0;i < idx;i++){
					temp = temp->next;
				}
				return temp->data;
			}
		}
		void update(int idx,int data){
			if (idx >= this->length || length < 0){
				std::cout<<"Index out of range"<<std::endl;
			}else{
				Node *temp;
				temp = this->head;
				for (int i = 0;i < idx;i++){
					temp = temp->next;
				}
				temp->data = data;
			}
		}
};

int main(){
	LinkedList A;
	int x, y;
	A.append(1);
	A.append(2);
	A.append(3);
	A.println();
	std::cout<<"Input number: ";
	std::cin>>x;
	std::cin>>y;
	A.update(x,y);
	A.append(99);
	A.print();
}