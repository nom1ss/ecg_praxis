#include <iostream>
#include "node.h"
using namespace std;

int main() {
    Node* root = new Node("root");
    root->add_child(Node("left child"));
    root->add_child(Node("right child"));
    root->add_child(Node("big guy"));
    root->add_child(Node("hello"));

    cout << "Number of children in root: " << root->get_nr_children() << endl;
    delete root;

    return 0;
}