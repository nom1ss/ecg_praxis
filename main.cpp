#include <iostream>
#include "node.h"
using namespace std;

int main() {
    Node* root = new Node("root");
    Node* l_child = new Node("left child");
    Node* r_child = new Node("right child");
    root->add_child(l_child);
    root->add_child(r_child);

    cout << "Number of children in root: " << root->get_nr_children() << endl;
    cout << root->get_child(2)->get_name() << endl;
    delete root;

    return 0;
}