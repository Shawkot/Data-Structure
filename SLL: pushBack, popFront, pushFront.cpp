#include <iostream>
using namespace std;

struct node* head = NULL;
struct node* tail = NULL;

struct node
{
    int data;
    node *next;
};
void insert(int n) // Or push-back operation
{
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL){ // Check if the node is null or not
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = tail->next;
    }
}

void insert_at_position_n(int data,int position) // Add before of after a specific position
{
    	 node *ptr = new node;
    	ptr->data=data;

    	int i;
        node *temp=head;
    	if(position==1){
        		ptr->next=temp;
        		head=ptr;
        		return;
    	}

    	for(i=1;i<position-1;i++){
        		temp=temp->next;
    	}

    	ptr->next=temp->next;
    	temp->next=ptr;
}

void popfront() // Delete an element from the top
{
    if(head == NULL)
        cout << "Error: Empty list " << endl;
    else{
        head = head->next;
    }
}

void pushfront(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = head;
    head = temp;
    if(tail == NULL){
        tail = head;
    }
}

void popBack() // Delete an element from back
{
    if(head == NULL)
        cout << "Error: Empty list !!" << endl;
    else if(head == tail){
        tail == NULL;
        head = tail;
    }
    else{
        node* pt = new node;
        pt = head;
        while(pt->next->next != NULL){
            pt = pt->next;
        }
        pt->next = NULL;
        tail = pt;
    }
}
void display() // For displaying the node
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL){
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }

int main()
{
    insert(1);
    insert(2);
    insert_at_position_n(5,2);
    insert_at_position_n(3,3);
    insert(6);
    cout << "Before pop operation" << endl;
    display();
    cout << "After pop operation at front" << endl;
    popfront();
    display();
    pushfront(1);
    cout << "After pushing at front" << endl;
    display();
    popBack();
    cout << "After popping from back" << endl;
    display();
    cout << "*****************" << endl;
    insert_at_position_n(4,4);
    display();
    return 0;
}
