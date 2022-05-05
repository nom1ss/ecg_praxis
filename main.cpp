#include <iostream>
#include "node.h"
using namespace std;

int main() {
    Node* root = new Node("");
    /*
    Node* l_child = new Node("left child");
    Node* r_child = new Node("right child");
    Node* one = new Node("");
    Node* two = new Node("");
    Node* three = new Node("");
    l_child->set_name("");
    root->add_child(l_child);
    root->add_child(r_child);
    cout << "l_child name: " << l_child->get_name() << endl;
    cout << "two name: " << two->get_name() << endl;

    cout << "Number of children in root: " << root->get_nr_children() << endl;
    cout << root->get_child(2)->get_name() << endl;
    //delete root;
    */

    root->create_complete_tree(2, 4);
    cout << root;

    return 0;
}