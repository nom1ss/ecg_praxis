#include <string>
#include <vector>
using namespace std;


class Node {
private:
    static int node_id;
    string name;
    vector<Node*> nodes;

public:
    Node(const string& name);
    ~Node();
    string get_name() const;
    void set_name(const string& new_name);
    void default_name();
    int get_nr_children() const;
    Node* get_child(int i) const;
    void add_child(Node* child);
    void create_complete_tree(int nr_child_nodes, int tree_depth);
    ostream& print(ostream& os, int depth) const;
};

extern ostream& operator<<(ostream& os, Node* node);