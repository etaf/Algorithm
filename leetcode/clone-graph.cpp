#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:

    unordered_map<UndirectedGraphNode*,UndirectedGraphNode* > ns;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)return NULL;
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        ns[node] = new_node;
        for(size_t i=0;i<node->neighbors.size();++i){
            unordered_map<UndirectedGraphNode* ,UndirectedGraphNode* >::iterator it = ns.find(node->neighbors[i]);
            if(it != ns.end()) {
                new_node->neighbors.push_back(it->second);
            }
            else{
                new_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return new_node;
    }
};

int main(){
    return 0;
}
