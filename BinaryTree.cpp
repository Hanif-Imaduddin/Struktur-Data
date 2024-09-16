#include <iostream>

using namespace std;

struct BinaryNode{
	int data;
	BinaryNode *lChild;
	BinaryNode *rChild;
	
	BinaryNode():lChild(nullptr),rChild(nullptr){}
};

struct Node{
	BinaryNode *data;
	Node *next;
};

class Queue{
	private:
		Node *head;
		Node *tail;
	public:
		int length;
		Queue() : head(nullptr),tail(nullptr),length(0){}
		
		void enqueue(BinaryNode *data){
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
		
		BinaryNode* dequeue(){
			BinaryNode *data;
			if (this->head == nullptr){
				return data;
			}else if (this->head->next == nullptr){
				data = this->head->data;
				delete this->head;
				this->head=this->tail= nullptr;
				return data;
			}else{
				data = this->head->data;
				Node *temp = this->head->next;
				delete this->head;
				this->head = temp;
				return data;
			}
		}
		bool isEmpty(){
			return this->tail == nullptr;
		}
};

class BinaryTree{
private:
	void preOrder(BinaryNode *n){
		if (n != nullptr){
			cout<<n->data<<" ";
			preOrder(n->lChild);
			preOrder(n->rChild);
		}
	}
public:
	BinaryNode *root;
	int nNode;
	BinaryTree(): root(nullptr),nNode(0){}
	void print(string method){
		if (method == "preorder"){
			this->preOrder(this->root);
		}else{
			cout<<"Method Belum tersedia";
		}
	}
	void println(string method){
		if (method == "preorder"){
			this->preOrder(this->root);
		}else{
			cout<<"Method Belum tersedia";
		}
		cout<<endl;
	}
};

void createBinaryTree(BinaryTree *B){
	Queue Q;
	char c;
	BinaryNode *temp,*p;
	int data,nCount;
	cout<<"Enter Root Data: ";
	cin >> data;
	B->root = new BinaryNode();
	B->root->data = data;
	Q.enqueue(B->root);
	while (!Q.isEmpty()){
		nCount = 0;
		p = Q.dequeue();
		cout<<"Do you want to input left child (y/n)? ";
		cin >> c;
		if (c == 'y'){
			cout<<"Input data: ";
			cin >> data;
			temp = new BinaryNode();
			temp->data = data;
			p->lChild = temp;
			Q.enqueue(temp);
		}else{
			nCount++;
		}
		cout<<"Do you want to input right child (y/n)? ";
		cin >> c;
		if (c == 'y'){
			cout<<"Input data: ";
			cin >> data;
			temp = new BinaryNode();
			temp->data = data;
			p->rChild = temp;
			Q.enqueue(temp);
		}else{
			nCount++;
		}
		if (nCount == 2){
			cout<<"Do you want to end this input session (y/n)? ";
			cin >> c;
			if (c == 'y'){
				break;
			}
		}
	}
	cout<<"Binary tree has been created"<<endl;
}


int main(){
	BinaryTree B;
	createBinaryTree(&B);
	B.println("preorder");
	return 0;
}

