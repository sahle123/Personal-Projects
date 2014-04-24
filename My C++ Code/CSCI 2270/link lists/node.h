/*
 * node.h
 *
 *  Created on: 03/23/12
 *      Author: Sahle A. Alturaigi
 *
 *
 *  Overloaded Operands
 *
 *   -istream& operator >> (istream& ins, node& target)
 *   	Pre: The inputed values must of type node
 *			 Only the data of the node can be stored,
 *			 the address must be done separately using the
 *			 set_link function.
 *		Post: The target node will have a new data type. This is
 *			  just an accelerated version of the set_data() function.
 *
 *	 -ostream& operator << (ostream& outs, node& target)
 *	 	Pre: NONE
 *	 	Post: The data stored in the node along to what it is pointing
 *	 		  to is output on the command prompt.
 */

#ifndef NODE_H_
#define NODE_H_

#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

class node {
public:
	typedef int value_type;

	// Constructor
	node(const value_type& new_data, node* new_link)
	{
		data = new_data;
		link = new_link;
	}

	// Destructor. This is important to deallocate all the dangling nodes.
	//~node::node();

	// MOD functions
	void set_data(const value_type& new_data) {data = new_data;} // Pre: input must be int. Post: sets the input as the new value of the link list
	void set_link(node*& new_link) {link = new_link;} // Pre: input must be an existing node*. Post: The node will point to the inputed node.
	void list_print(const node* head); // Pre: input the HEAD of the list. Post: Will print all the data of the list from head to tail.
	unsigned int list_size(const node* head); // Pre: input the HEAD of the list. Post: the size of the link list is printed.
	void list_head_insert(node*& head, node::value_type new_value);
	void list_head_erase(node*& head); // Pre: input the HEAD. Post: The head now points to nothing and the new head is the node the head pointed to.

	// The double const will make it so that whatever the pointer is pointing to,
	// the values stored in what is being pointed can NOT be manipulated by the pointer.
	node *get_link () {return link;}
	const node *get_link() const {return link;}
	value_type get_data () const {return data;}

	// Overloaded Operands
	friend istream& operator >> (istream &ins, node &target);
	friend ostream& operator << (ostream &outs, node &target);
	node&  operator = (const node &obj); // Post: will copy the objects link and data into the variable.

private:
	value_type data;
	node *link;

}; // END of "node"

/*
~node::node()
{
     node *q;
     if(link == NULL)
     {
          return;
     }
     while( link != NULL)
     {
          q = link;
          delete link;
     }

}*/
void node::list_print(const node *head)
{
	const node *ptr;

	for(ptr = head; ptr; ptr = ptr->get_link())
	{
		cout << ptr->get_data() << "\t"; // \t provides an indent for the line.
	}
	cout << endl;
}

unsigned int node::list_size(const node *head)
{
	unsigned int count = 0;
	const node *ptr;

	for(ptr = head; ptr != NULL; ptr->get_link())
	{
		++count;
	}

	return count;
}

void node::list_head_insert(node *&head, node::value_type new_value)
{
     assert(head != NULL);
     // Does this cause memory Leakage??
	node* new_ptr = new node(new_value, head->get_link());
     head->set_link(new_ptr);
}

void node::list_head_erase(node *&head)
{
	node* temp;
     assert(head != NULL);

	// temp->set_link(head->get_link()); WRONG
	temp = head->get_link();
	delete head; // <- This needs to be explained.
	head = temp;
}

istream& operator >> (istream &ins, node &target)
{
	ins >> target.data;
	return ins;
}

ostream& operator << (ostream &outs, node &target)
{
	outs << target.data << " " << target.link;
	return outs;
}

node& node::operator = (const node &obj)
{
	if(this != &obj)
	{
		data = obj.data;
		link = obj.link;
	}
	return *this;
}
#endif /* NODE_H */
