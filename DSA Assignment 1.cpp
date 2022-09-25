//DSA Assignment 1
//Sarthak Kalia
//sid-21105042
using namespace std;
#include <bits/stdc++.h>
// Creating node class
class node
{
public:
    // Creating class objects
    string name;
    int age;
    node *next; // A node pointer for next node
    node *prev; // A node pointer for previous node

    // Constructor
    node(string name, int age)
    {
        this->name = name;
        this->age = age;

        // initialising both pointer as NULL
        next = NULL;
        prev = NULL;
    }
};

// Function to insert new node at head
void insert_at_head(node *&head, string name, int age)
{
    node *newnode = new node(name, age);
    newnode->next = head;
    if (head != NULL)
    {

        head->prev = newnode;
    }

    head = newnode;
}

// function to insert new node at end(tail)
void insert_at_tail(node *&head, string name, int age)
{
    if (head == NULL)
    {
        insert_at_head(head, name, age);
        return;
    }
    node *newnode = new node(name, age);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Function to display Linked List
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {

        cout << temp->name << " " << temp->age << endl;

        temp = temp->next;
    }
    cout << endl;
}

// Function to delete head node
void deletehead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

// Function to delete node
void deletion(node *&head, int posn)
{
    if (posn == 1)
    {
        deletehead(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != posn)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}
int main()
{
    // Initialising an empty linked list
    node *head = NULL;

    // Taking number of family members as input
    int family_members_count;
    cout << "Enter number of family members:" << endl;
    cin >> family_members_count;

    // Initializing a vector pair to stores member's data
    vector<pair<string, int>> member_data;

    // Storing data
    for (int i = 1; i <= family_members_count; i++)
    {
        string name;
        int age;
        cout << "Enter family member " << i << " name:" << endl;
        cin >> name;
        cout << "Enter " << name << "'s age:" << endl;
        cin >> age;

        member_data.push_back({name, age});
    }

    // Adding data in Linked List
    for (int i = 0; i < member_data.size(); i++)
    {
        insert_at_tail(head, member_data[i].first, member_data[i].second);
    }
    cout << "Doubly linked list with family member's name and age as its elements is as follow:" << endl;

    // Printing doubly linked list
    display(head);

    return 0;
}
/*BONUS QUESTION
Q.Try to find a way to link the family members' doubly-linked list based on their relationship.
Ans.One way to link the family members doubly-linked list is by sorting the doubly linked list according to age in decending order.By doing so we will get a doubly linked list in which older generation people will be close to head in double linked list and new generation people will be close to tail in doubly linked list.
*/
