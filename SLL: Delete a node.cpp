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
    node* head, *tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    node* gethead()
    {
        return head;
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
    void delete_node(node *before_del)
    {
        node *tmp = new node;
        tmp = before_del->next;
        before_del->next = tmp->next;
        delete tmp;
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
    a.delete_node(a.gethead());
    a.display();
}
