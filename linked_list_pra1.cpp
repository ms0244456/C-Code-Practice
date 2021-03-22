#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next ; 
};

//using *(*node) can replace the content of head
void add_node(node ** ori_node, int value)
{
    struct node * new_node = new node();
    new_node -> data = value;
    new_node -> next = NULL;

    //if there is no node in linked-list, add a new node to it.
    if(ori_node == NULL){
        *ori_node = new_node;
        return;
    }
    //else, the last node add new node to it.
    // for example , the origin list A -> B -> NULL
    // new node C, A -> B -> C -> NULL
    else{
        struct node * current = *ori_node;
        while( current->next != NULL){current = current -> next;} // keep searching the last node.
        current -> next = new_node; //if finding the last node, then last node -> next = new node.
        return;
    }  
}
//reverse linked-list
// prev  current                                 prev   current
// NULL     A    --->   B  -> C        NULL <----  A  ->   B    -> C 
// first, store current->next in temp
// current->next now point to previous.
// previous node goes to current, then current node goes to temp(current->next).
void rev_nodes(node ** ori_node)
{   
    struct node * current = *ori_node;
    struct node * prev = new node();
    struct node * temp = new node();

    while(current != NULL)
    {
        temp = current -> next;
        current -> next = prev;
        prev = current;
        current = temp;
    }
                                                           //  pre current
    *ori_node = prev; //change head to prev,  NULL <- A <- B <- C <- NULL
}

//print linked-list nodes
void print_nodes(node * node)
{   //while not pointing last node(NULL), then print it. 
    while(node != NULL )
    {
        if(node -> data != 0)
        {
            cout << node->data << " ";
        }
        node = node -> next; //go to next nodes
    }
    cout << endl;
}
// free memory
void free_nodes(node * node)
{
    struct node * current = node, * temp;;
    while(current != NULL) //while not pointing last node(NULL), free it. 
    {
        temp = current;
        current = current -> next;  //go to next nodes
        free(temp);
    }
}
int main()
{
    
    struct node * head = new node();

    add_node(&head, 5);
	add_node(&head, 100);
	add_node(&head, 150);
    print_nodes(head);

    rev_nodes(&head);
    print_nodes(head);

    free_nodes(head);


    return 0;
}
