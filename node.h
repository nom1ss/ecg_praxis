#include <string>
#include <vector>
using namespace std;

class Node {
private:
    string name;
    vector<Node*> nodes;

public:
    Node(const string& name);
    ~Node();
    string get_name() const;
    void set_name(const string& new_name);
    int get_nr_children() const;
    Node* get_child(int i) const;
    void add_child(Node* child);
};