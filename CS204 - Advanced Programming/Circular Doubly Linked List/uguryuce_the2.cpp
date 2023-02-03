#include <iostream>
#include <string>
#include <sstream>
#include <cctype>


using namespace std;

struct node
{
    struct node *prev; // pointer to previous node
	string name;
	int count, price;
    struct node *next; // pointer to next node
	
	//default constructor
	node() {}

	//constructor
	node(node *pre, string n, int c, int p, node *nex) //constructor with 3 parameters.
	{
		prev = pre;
		name = n;
		count = c;
		price = p;
		next = nex;
	}
};

int countList(node* start)
{
    node* temp = start;
    int count = 0;
 
    while (temp->next != start) 
	{
        temp = temp->next;
        count++;
    }
    count++;
    return count;
}

struct node *addInOrder(node* &start, string name, int count, int price)
{
	cout << "addInOrder was run" << endl;

	if(start == NULL) //if list is empty
	{
		start = new node(start, name, count, price, start);
		start->next = start;
		start->prev = start;
		#ifdef _DEBUG
			cout << "null run " << endl;
		#endif
		return start;
	}
	
	if((countList(start) == 1)) //if list has 1 node
	{
		
		if((count*price) > (start->count*start->price))
		{
			node* temp = start;
			temp->next = start;
			temp->prev = start;
			start = new node(temp, name, count, price, temp);
			#ifdef _DEBUG
				cout << "1 if okey " << endl;
			#endif
			return start;
		}
		else
		{
			node* temp = new node(start, name, count, price, start);
			start->next = temp;
			start->prev = temp;
			#ifdef _DEBUG
				cout << "1 else okey " << endl;
			#endif
			return start;
		}
	}
	
	node *ptr = start;
	while(ptr->next != start)
	{
		node *prev_temp = ptr->prev;
		if((count*price) > (ptr->count*ptr->price))
		{
			node *temp = new node(prev_temp, name, count, price, ptr);
			prev_temp->next = temp;
			ptr->prev = temp;
			#ifdef _DEBUG
				cout << "while if is run" << endl;
			#endif
			return start;
		}
		ptr = ptr->next;
	}

	if(ptr->next == start) //if you add before or after last node
	{
		cout << "now ptr=last(ptr->next = start)" << endl;
		if ((count*price) > (ptr->count*ptr->price))
		{
			node *ptr_prev = ptr->prev;
			node* temp = new node(ptr_prev, name, count, price, ptr);
			ptr_prev->next = temp;
			ptr->prev = temp;
			#ifdef _DEBUG
				cout << "last node part if okey" << endl;
			#endif
			return start;
		}
		else
		{
			node* temp = new node(ptr, name, count, price, start);
			ptr->next = temp;
			start->prev = temp;
			#ifdef _DEBUG
				cout << "last node part else okey" << endl;
			#endif
			return start;		
		}
	}
}

bool update(node* start, string name, int count, int price)
{
	node *ptr = start;
	bool check = false;
	while(ptr->next != start)
	{
		if(ptr->name == name)
		{
			ptr->count = count;
			if(price<ptr->price)
			{
				ptr->price = price;
			}
			check = true;
		}
		ptr = ptr->next;
	}
	return check;
}

void deleteNode(node *&start, string name)
{
	if(start == NULL) //if list is empty
	{
		cout << "The item " << name << "could not be found in the list." << endl;
		return;
	}

	node *ptr = start;
	node *pre = NULL;

	while(ptr->name != name) //if item that is deleted cannot be found in the list
	{
		if(ptr->next == start)
		{
			cout << "The item " << name << "could not be found in the list." << endl;
		}
		pre = ptr;
		ptr = ptr->next;
	}

	if(countList(start)==1) //if list has just 1 node
	{
		delete start;
		start = NULL;
		return;
	}

	if(ptr == start) //if it is the start(first) node
	{
		pre = start->prev;
		start = start->next;
		pre->next = start;
		start->prev = pre;
		delete ptr;
		ptr = NULL;
	}
	
	else if(ptr->next == start) // if it is the tail(last) node
	{
		pre->next = start;
		start->prev = pre;
		delete ptr;
		ptr = NULL;
	}
	else
	{
		node *temp = ptr->next;
		pre->next = temp;
		temp->prev = pre;
		delete ptr;
		ptr = NULL;
	}
}

	
void print(node *start) 
{
	if(start == NULL)
	{
		cout << "The shopping list is empty." << endl;
	}
	else
	{
		node * ptr = start;
		for(int y=0; y < countList(start); y++)
		{
			cout << "Item: " << ptr ->name << "\n" << "Quantity: " << ptr ->count << "\n" << "Unit Price: " << ptr->price << endl;
			ptr = ptr->next;
		}
	}
}

void totalPrice(node *start)
{
	int total_price=0;
	node* temp = start;

	for(int y=0; y < countList(start); y++) 
	{
		total_price += (temp->count*temp->price);
		temp = temp->next;
    }
	cout << "Total price: " << total_price << "\n" << "Unique items: " << countList(start) << endl;
}

void clearList(node * & start)
{
	
	if (start != NULL)
    {
        node *temp, *current;
		current = start->next;

		while(current!=start)
		{
			temp = current->next;
			delete current;
			current = temp;
		}
		delete start;
		start = NULL;
    }
	cout << "List is cleared." << endl;
}


int main()
{
	node *start = NULL; 
	node *end = start->prev;
	
	/*start = addInOrder(start, "ugur", 19, 7);
	start = addInOrder(start, "mel", 6, 8);
	start = addInOrder(start, "fener", 10, 11);
	start = addInOrder(start, "d", 2, 1);
	start = addInOrder(start, "geyik", 3, 9);
	int count = countList(start);
	print(start);
	totalPrice(start);
	clearList(start);
	print(start);
	*/
	
	string command;
	cin >> command;

	string name;
	cin.ignore();
	getline(cin, name);

	int count, price;
	cin.ignore();
	cin >> count;
	cin.ignore();
	cin >> price;
	if(command == "add")
	{
		if(!update(start, name, count, price))
		{
			start = addInOrder(start, name, count, price);
		}
	}
	else if(command == "delete")
	{
		deleteNode(start, name);
		
	}
	else if(command == "print")
	{
		print(start);
	}
	else if(command == "totalPrice")
	{
		totalPrice(start);
	}
	else if(command == "clear")
	{
		clearList(start);
	}
	else
	{
		cout << "Invalid command." << endl;
	}


	while(command != "exit")
	{
		string command;
		cin >> command;

		string name;
		cin.ignore();
		getline(cin, name);

		int count, price;
		cin.ignore();
		cin >> count;
		cin >> price;
		if(command == "add")
		{
			if(!update(start, name, count, price))
			{
				start = addInOrder(start, name, count, price);
			}
		}
		else if(command == "delete")
		{
			deleteNode(start, name);
		
		}
		else if(command == "print")
		{
			print(start);
		}
		else if(command == "totalPrice")
		{
			totalPrice(start);
		}
		else if(command == "clear")
		{
			clearList(start);
		}
		else
		{
			cout << "Invalid command." << endl;
		}
	}
	return 0;
}