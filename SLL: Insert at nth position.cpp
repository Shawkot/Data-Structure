#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
class linked_list
{
private:
    node *head, *tail; // Creating two node
public:
    linked_list()
    {
        head = NULL; // Initialize the node to be null
        tail = NULL;
    }
   void addnode(int n) // Function for adding node
    {
        node *tmp = new node; // Creating a temporary pointer
        tmp->data = n;
        tmp->next = NULL;
        if(head == NULL){ // Check if the node is null or not
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void add_front(int n) // Add an element at the front of the list
    {
        node* temp = new node;
        temp->data = n;
        temp->next = head;
        head = temp;
    }
    node* gethead()
    {
        return head;
    }
    
    void InsertNth(int data, int position){ // Insert an element at nth position
    node *n=new node;
    n->data=data;
    if(position==0)
    {// this will also cover insertion at head (if there is no problem with the input)
      n->next=head;
      head=n;
    }

    else{
      node *c=new node;
      int count=1;
      c=head;
      while(count!=position)
      {
          c=c->next;
          count++;
      }
      n->next=c->next;
      c->next=n;

    }
    return ;
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

};

int main()
{
    linked_list a;
    a.addnode(1);
    a.addnode(2);
    a.addnode(3);
    a.addnode(5);
    a.InsertNth(4,3);
    a.add_front(6);
    a.InsertNth(7,1);
    a.display();
    return 0;
}

