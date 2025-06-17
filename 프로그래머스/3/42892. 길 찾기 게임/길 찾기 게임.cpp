#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y, idx;
    Node *left, *right;
};

bool compare(Node a, Node b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

void insert(Node* parent, Node* child) {
    if (child->x < parent->x) {
        if (parent->left == nullptr) parent->left = child;
        else insert(parent->left, child);
    } else {
        if (parent->right == nullptr) parent->right = child;
        else insert(parent->right, child);
    }
}

void preorder(Node* node, vector<int>& result) {
    if (!node) return;
    result.push_back(node->idx);
    preorder(node->left, result);
    preorder(node->right, result);
}

void postorder(Node* node, vector<int>& result) {
    if (!node) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> nodes;
    for(int i = 0; i < nodeinfo.size(); i++){
        nodes.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1, nullptr, nullptr});
    }
    
    sort(nodes.begin(), nodes.end(), compare);
    
    Node* root = &nodes[0];
    
    for (int i = 1; i < nodes.size(); i++) {
        insert(root, &nodes[i]);
    }

    vector<int> preorder_result;
    vector<int> postorder_result;

    preorder(root, preorder_result);
    postorder(root, postorder_result);
    
    return {preorder_result, postorder_result};
}