#include <iostream>
#include <string>
using namespace std;
#include "node.h"

Node::Node(const string& name) : name(name) {
    cout << "Node with name " << name << " created!" << endl;
};

Node::~Node() {
    for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
        if (*iter == NULL) {
            break;
        }
        else if (!(*iter)->nodes.empty()) {
            delete *iter;
        } else {
            nodes.clear();
        }
    }
    cout << "Node with name " << name << " deleted!" << endl;
};

string Node::get_name() const {
    return name;
}

void Node::set_name(const string& new_name) {
    name = new_name;
}

int Node::get_nr_children() const {
    return nodes.size();
}

Node* Node::get_child(int i) const {
    int count = 0;
    for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
        if (count == i)
            return *iter;
    }
    return NULL;
}

void Node::add_child(Node child) {
    nodes.push_back(&child);
}