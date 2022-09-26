//DSA Assignment 2
//Sarthak Kalia
//Sid-21105042
//-code starts from here-// 
#include <iostream>
using namespace std;

// Creating node class
class Node
{
public:
	// Creating class objects
	int data;
	Node *next; /*A pointer for next node*/
	Node(int data)
	{
		this->data = data;

		// initialising next pointer as NULL
		this->next = NULL;
	}
};

// Function to input the circular node position

void loopHere(Node *head, Node *tail, int position)
{
	if (position == 0)
		return;

	Node *walk = head;
	for (int i = 1; i < position; i++)
		walk = walk->next;
	tail->next = walk;
}

// Function to cheack cycle
bool detectLoop(Node *head)
{

	if (head == NULL)
	{
		return false;
	}
	if (head->next == NULL)
	{
		return false;
	}

	// Initailising 2 pointer Slow and Fast
	Node *slow = head;
	Node *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		// Making slow pointer move 1 step at a time
		slow = slow->next;

		// Making fast pointer move 2 steps at a time

		fast = fast->next->next;

		// Condition for the linked list to be circular
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}

// Function to take input of linked list
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	int pos;
	cin >> pos;
	loopHere(head, tail, pos);
	return head;
}

// Function to print linked list
void Print(Node *head)
{

	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{

	Node *head = takeinput();

	if (detectLoop(head) == true)
	{
		cout << "The given linked list is circular" << endl;
	}
	else
	{
		cout << "The given linked list is not circular" << endl;
	}

	return 0;
}

/*EXPLANATION
In the above algorithm I used 2 pointers movings at different speed, one of them is moving at twice the speed as of other.
I initialized 2 pointer namely slow and fast, both initailly pointing towards head.
1. While tarversing,the fast pointer may reach the end (NULL) this shows that there is no loop in the linked list.
2.If the Fast pointer again catches the slow pointer at some time therefore a loop exists in the linked list.
Main condition:
So while traversing if both slow and fast pointer point at same node then surely a cycle would be present in the linked list.
Pseudocode:
1.Initialize two-pointers and start traversing the linked list.
2.Move the slow pointer by one position.
3.Move the fast pointer by two positions.
4.If both pointers meet at some point then a loop exists and if the fast pointer meets the end position then no loop exists.
QUESTION-2:
Application of Circular Linked Lists:
1.One of the application of circular linked list is Snake game in our phone.The circular linked list stores the x,y position of each point in the snake's body.The head of the list is the snake's head.The tail is its tail.As we advance the head to a new position, the list wraps around because it is circular. This erases the tail, and leaves all other body parts as they are.So we get the movement of the whole snake simply by adding a new head position.
2.Circular Linked Lists can be used to manage the computing resources of the computer.
3.Data structures such as stacks and queues are implemented with the help of the circular linked lists.
4.Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.
5.It is also used in computer networking for token scheduling.
6.They are also used for things like streaming video. The server sends us chunks of video and sound at kinda unpredictable rates, another chunk of video appears that’s a second or so long.
7.Data structures such as stacks and queues are implemented with the help of the circular linked lists.
*/