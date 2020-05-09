#include <iostream>
using namespace std;

struct node* head = NULL;
struct node* tail = NULL;

struct node
{
    int data;
    node *next;
};
void insert(int n)
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

void insert_at_position_n(int data,int position)
{
    	 node *ptr = new node;
    	//Creating a new node
    	ptr->data=data;

    	int i;
    	struct node *temp=head;
    	//Do not use the pointer variable head directly. If we use it, the address location of the first node in the linked list will be lost
    	//Pointer variable temp is used to traverse the linked list

    	if(position==1)
    {
        //Executed only if position is 1
        		//If position is 1, it is a special case because we need to nodify the head  pointer
        		ptr->next=temp;
        		//ptr->next=head is also valid;

        		head=ptr;
        		//Making head point to newly created node ptr
        		return;
    	}

    	//Function to insert node at position n in the linked list
    	//If we have  5nodes in the linked list, we can insert a new a node between any two nodes of the five nodes present in the linked list

    	for(i=1;i<position-1;i++)//Traversing to the (n-1)th position node in the linked list
    	{
        		temp=temp->next;
    	}

    	ptr->next=temp->next;
    	//Making the newly created node point to next node of pointer temp

    	temp->next=ptr;
    	//Making pointer temp point to newly created node in the linked list
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
    insert(4);
    insert_at_position_n(3,3);
    display();
    return 0;
}
