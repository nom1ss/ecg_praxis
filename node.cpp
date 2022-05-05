#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
using namespace std;
#include "node.h"

int Node::node_id = 0;

Node::Node(const string& name = "") : name(name) {
    if (name == "") {
        default_name();
    }
    else ++node_id;
    cout << "Node: name " << this->name << "; id " << node_id << " created!" << endl;
};

Node::~Node() {
    for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
        delete *iter;
    }
    nodes.clear();
    cout << "Node with name " << name << " deleted!" << endl;
};


string Node::get_name() const {
    return this->name;
}

void Node::set_name(const string& new_name) {
    if (new_name == "") default_name();
    else name = new_name;
}

void Node::default_name() {
    ++node_id;
    stringstream str_sm;
    str_sm << node_id;
    string node_id_str = str_sm.str();
    this->name = "node_" + node_id_str;
}

int Node::get_nr_children() const {
    return nodes.size();
}

Node* Node::get_child(int i) const {
    int count = 1;
    for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
        if (count == i)
            return *iter;
        count++;
    }
    return NULL;
}

void Node::add_child(Node* child) {
    this->nodes.push_back(child);
}

void Node::create_complete_tree(int nr_child_nodes, int tree_depth) {
    if (tree_depth <= 1) return;
    for (int i = 0; i < nr_child_nodes; i++) {
        Node* to_add = new Node("");
        to_add->create_complete_tree(nr_child_nodes, tree_depth - 1);
        this->add_child(to_add);
    }
}

ostream& Node::print(ostream& os, int depth) const {
    if (this == NULL) return os;
    string current = "";
    for (int i = 0; i < depth; i++)
        current += "   ";
    current += this->get_name() + "\n";
    os << current;
    for (int i = 1; i <= this->get_nr_children(); i+=1) {
        this->get_child(i)->print(os, depth + 1);
    }
    return os;
}

ostream& operator<<(ostream& os, Node* node)
{
    int depth = 0;
    return node->print(os, depth);
}