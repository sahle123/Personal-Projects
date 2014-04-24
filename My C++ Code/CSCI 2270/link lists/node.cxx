#include"node.h"

//*****************************************************************************

int main( )
{
    node *a;
    node *b;
    node *c;
    a = new node(18, NULL);
    b = new node(203, NULL);
    c = new node(77, NULL);

    cout << *a << " || " << *b << " || " << *c << " " << endl;
    // set_data and set_link mod functions: WORKING
    (*a).set_data(50);
    a->set_link(b);
    (*b).set_link(c);

    cout << *a << " || " << *b << " || " << *c << " " << endl;
    cout << "Address of b and c, respectively: " << b << " "
	 << c << endl;

    // list_print and list_head_erase member functions: WORKING
/*
      cout <<"\n\n\n";
      (*a).list_print(a);
      cout <<"\n" << "printing list after A got deallocated." << endl;
      (*a).list_head_erase(a);
      (*a).list_print(a);
*/

    // Assignment test: WORKING
    /*a = b;
      c = b;
      cout << *a << " || " << *b << " || " << *c << " " << endl;
    */

    // list_head_insert test: Checking...

    (*a).list_head_insert(a, 667);
    (*a).list_print(a);
    (*a).list_head_insert(a, 2184);
    (*a).list_print(a);

    delete a;
    cout << "A deleted \t";
    delete b;
    cout << "B deleted \t";
    delete c;
    cout << "C deleted" << endl;

    cout << "\nSUCCESSFUL EXIT! (^O^)/." << endl;
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Other Functions:

//------------------------------------------------------------------------------

