//CL list
#include<iostream>

using namespace std;

class node{
	public:
		
	
	int data;
	//Pointer to the next Node
	node * next;
	
	
	node(){
		next=NULL;
	}
};
class linkedlist{
	
	public:
	
	node* head;
	node* tail;
	
	linkedlist(){
		head=NULL;
		tail=NULL;
	}

	
	void insert(int value){
		//if first node is added
		node * temp=new node;
		temp->data=value;//using here
		
		if (head==NULL){
			head=temp;
			temp->next=head;
		}
		//any other temp only
		else{
			tail->next=temp;
			temp->next=head;
		}
		tail = temp;
		
		
	}
	void insertAT(int pos,int value){
		//reach the place before pos
		node* current=head;
	if(pos!=1){
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//create a node
		node * temp= new node;
		temp->data=value;
		//moving ptrs
		temp->next=current->next;
		current->next=temp;
		
	}
	else{
		//create a node
		node * temp=new node;
		temp->data=value;
		
		temp->next=current;
		//make temp head;
		head=temp;	
	}
		
}
	
	void delet(){
		//store the tail in temp
		node * temp = tail;
		// before tail has to point to null
		node * current=head;
		while(current->next !=tail){
		current =current->next;		
		}
		current->next=head;
		//update tail
		tail=current;
		delete temp;
	}

	void deletAt(int pos){
			//take 
			node *current=head;
				int i=1;
			while(i<pos-1){
				i++;
				current=current->next;
			}
			// crate pointer for the file to be deleted
			node * temp=current->next;
			//assign link of the previous element to the next of next element
			current->next=temp->next;
			//deletion
			delete temp;
			
			
		
	}

	//display
	void display(){
		node * current=head;
		while(current !=tail){
			cout<< current ->data<<"->";	
			current =current->next;	
		}
		cout<<current->data<<"->to the head"<<endl;	
	}
	void countItems(){
		node * current=head;
		int i=1;
		while(current !=tail){	
			current =current->next;	
			i++;
		}
		
		cout<<"the number of elements in the linked list is-"<<i<<endl;
	}
};
int main(){
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	l1.countItems();
	l1.insert(9);
	l1.insertAT(3,4);
	cout<<endl;
	l1.display();
	l1.delet();
	cout<<endl;
	l1.display();
	cout<<endl;
	l1.deletAt(2);
	l1.display();
	l1.display();
	return 0;
}
