//DL 

#include<iostream>

using namespace std;

class node{
		public:
		int data;
		//TAKE pointer to next node
		node* next;
		//take pointer to previous node
		node* prev;
		
		//constructor makes it null lol
		node(){
			next=NULL;
			prev=NULL;
			}
	};



class list{
		public:
	
	//node type pointers
	node* head;
	node* tail;
	
	//constructor --
	list(){
		head=NULL;
		tail=NULL;
		}
	
	//node will be DL
	
	//insert a node at the end
	void insert(int val){
		node* temp=new node;

		temp->data=val;	
		if(head==NULL)     
	
		{
			head=temp;
			}
			
			
		else{             //    
			temp->prev=tail;
			tail->next=temp;
			}
		tail=temp;
		}
		
	//Insert a node at a position	
	
	void insertAt(int pos,int val)
	{
		node* current=head;
		//reaching the place before position 
		
		//if pos not 1
		if(pos!=1)
		{
			int i=1;
			while(i<pos-1){
				i++;
				current=current->next;
				}
			//creating a new node 	
			node* temp=new node;
			//assign value
			temp->data=val;
			
			//inserting
			temp->next=current->next;
			current->next->prev=temp;
			current->next=temp;
			temp->prev=current;
			}
			
		//if position is 1
		
		else{
		    //creating new node
			node* temp=new node;
			temp->data=val;
			current->prev=temp;
			temp->next=current;
			head=temp;
			}
		}
		
	
		
	void delet(){
	    
		node* temp=tail;
		
		node* current=head;
		
		
		while(current->next!=NULL)
		{
			current=current->next;
			}
		current->next=NULL;
		tail=current;
		
		
		delete temp;
		}
		
	void deleteAt(int pos){
	    
	    //assigning head to current
	    node* current=head;
	    int i=1;
	    while(i<pos-1)
	    {
	        i++;
	        current=current->next;
	    }
	    //pointer for the file to be deleted
	    node* temp=current->next;
	    //assign link of the previous element to the next of next element
	    current->next=temp->next;
	    temp->next->prev=current;
	    //deletion
	    delete temp;
	}
	void revDisplay(){
		revDisplay2(head);
		cout<<endl;
		
	}
	
	//displaying the dll in reverse 
	
	void revDisplay2(node * current){
		//moves to next(till available)
		if(current==NULL){
			cout<<"NULL->";
			return;
		}
		else{
			revDisplay2(current->next);
			
			//while coming back you print
			if(current!=head){
			cout<<current->data<<"->";
			}
			else{
				cout<<current->data;
			}
		}
	}
	
	//display the dll

	void display(){
		node * current=head;
		while(current !=NULL){
			cout<< current ->data<<"->";	
			current =current->next;	
		}
		cout<<"Null"<<endl;	
	}
	
	//for counting
	void countItems(){
		node * current=head;
		int i=0;
		while(current !=NULL){	
			current =current->next;	
			i++;
		}
		cout<<"the number of elemwnts in the linked list is-"<<i<<endl;
	}
	
};

int main(){
	list l1;
	l1.insert(1);
	l1.insert(5);
	l1.insert(7);
	l1.insert(10);
	l1.display();
	l1.countItems();
	l1.revDisplay();
	l1.insert(5);
	l1.insertAt(2,1);
	cout<<endl;
	l1.display();
	l1.delet();
	cout<<endl;
	l1.display();
	cout<<endl;
	l1.deleteAt(3);
	l1.display();
	return 0;
}

