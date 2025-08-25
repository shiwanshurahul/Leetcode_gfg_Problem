/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node *, Node *>mp;

void dfs(Node * node, Node * clone_node){
    for(Node * it: node->neighbors ){  //or auto it: node ke neighbors pe iterate to create clone node of all
        if(mp.find(it) ==mp.end()){
            Node * clone = new Node(it->val);
            mp[it] = clone;  //mp me store

            clone_node->neighbors.push_back(clone);
            dfs(it,clone);
        }
        else {  //already bana chuke curr ka clone = neighbors me dal dp
            clone_node->neighbors.push_back(mp[it]);
        }
    }
}
    Node* cloneGraph(Node* node) {
        //undirected graph diya hai usko clone kro
        //neighbors array me neighbor's ka address store

        if(node == NULL)
            return NULL;

        //clone the given node:
        Node * clone_node = new Node(node->val);    
        mp[node] = clone_node;   //node ke corrosponding clone node store in map
        //now clone the neighbors
        //if a node already exists, access the corrosponding clone_node using map

        dfs(node, clone_node);  //bharo clone_node ko

        return clone_node;
    }
};