/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        
        queue<UndirectedGraphNode *> q;
        unordered_map<UndirectedGraphNode *, int> afterQueue;
        vector<UndirectedGraphNode *> source, target;
        
        q.push(node);
        afterQueue[node] = 100;
        
        while (!q.empty()){
            UndirectedGraphNode *head = q.front();
            q.pop();
            afterQueue[head] = 100 + (int)source.size();
            source.push_back(head);
            target.push_back(new UndirectedGraphNode(head->label));
            for (UndirectedGraphNode *child : head->neighbors) {
                if (afterQueue.count(child) == 0 || afterQueue[child] == 0) {
                    q.push(child);
                    afterQueue[node]++;
                }
            }
        }
        
        for (int i = 0; i < target.size(); i++){
            for (auto node : source[i]->neighbors){
                target[i]->neighbors.push_back(target[afterQueue[node]-100]);
            }
        }
        
        return target[0];
    }
};