#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int k) : val(k), left(nullptr), right(nullptr) {}
};

class BST {
public:
    bool unfoundVal;
    Node* root;
    void changeVectorElement(std::vector<int> &v, int index, int newVal) {
        v[index] = newVal;
    }

    void sortVector(std::vector<int> &v) {
        std::sort(v.begin(), v.end());
    }
    void generateTree(std::vector<int> vec) {
        sortVector(vec);
        int size = (int)vec.size();
        int mid = size/2;

        root = new Node(vec[mid]);

        std::vector<int> lVec, rVec;

        for (int i = 0; i < mid; i++) {
            lVec.push_back(vec[i]);
        }

        for (int i = mid+1; i < size; i++) {
            rVec.push_back(vec[i]);
        }

        root->left = treeMake(lVec);
        root->right = treeMake(rVec);
    }
    
    Node* treeMake(std::vector<int> vec) {
        int size = (int)vec.size();
        int mid = size/2;

        if (size <= 0) {
            return nullptr;
        }

        Node *thisTree = new Node(vec[mid]);

        std::vector<int> lVec, rVec;

        for (int i = 0; i < mid; i++) {
            lVec.push_back(vec[i]);
        }

        for (int i = mid+1; i < size; i++) {
            rVec.push_back(vec[i]);
        }

        thisTree->left = treeMake(lVec);
        thisTree->right = treeMake(rVec);

        return thisTree;
    }

    void leftFirstPrintInner(Node* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->val << " ";
        
        leftFirstPrintInner(node->left);
        leftFirstPrintInner(node->right);
    }

    void leftFirstDepthPrint() {
        std::cout << "Left First Depth Scan: ";
        leftFirstPrintInner(root);
        std::cout << std::endl;
    }

    void rightFirstPrintInner(Node* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->val << " ";
        
        rightFirstPrintInner(node->right);
        rightFirstPrintInner(node->left);
    }

    void rightFirstDepthPrint() {
        std::cout << "Right First Depth Scan: ";
        rightFirstPrintInner(root);
        std::cout << std::endl;
    }

    void valChkByTree(int val) {
        unfoundVal = true;
        if (root == nullptr) {
            std::cout << "Tree is empty\n";
            return;
        }

        if (root->val == val) {
            std::cout << val << " exists in this tree." << std::endl;
            unfoundVal = false;
            return;
        }
        
        Node* tree = root;

        if (root->val < val) {
            tree = tree->right;
            chkTreeRight(root, val);
        }
        
        else {
            tree = tree->left;
            chkTreeLeft(root, val);
        }

        if (unfoundVal) {
            std::cout << val << " doesn't exist in this tree." << std::endl;
        }
    }

    void chkTreeLeft(Node *tree, int v) {
        if (tree == nullptr) {
            return;
        }

        if (tree->val == v) {
            std::cout << v << " exists in this tree." << std::endl;
            unfoundVal = false;
            return;
        }

        if (tree->val < v) {
            tree = tree->right;
            chkTreeRight(tree, v);
        }
        
        else {
            tree = tree->left;
            chkTreeLeft(tree, v);
        }
    }

    void chkTreeRight(Node *tree, int v) {
        if (tree == nullptr) {
            return;
        }

        if (tree->val == v) {
            std::cout << v << " exists in this tree." << std::endl;
            unfoundVal = false;
            return;
        }

        if (tree->val < v) {
            tree = tree->right;
            chkTreeRight(tree, v);
        }

        else {
            tree = tree->left;
            chkTreeLeft(tree, v);
        }
    }

    void leftStartBreadthPrint() {
        std::cout << std::endl;
        if (root == nullptr) {
            std::cout << "Empty Tree\n";
            return;
        }

        std::vector<Node*> thisRoot;
        thisRoot.push_back(root);
        std::cout << "Left First Scan By Layer: ";
        leftBreadth(thisRoot);
    }

    void leftBreadth(std::vector<Node *> vNode) {
        if (vNode.size() == 0) {
            return;
        }

        std::vector<Node *> cNodes;

        for (int i = 0; i < (int)vNode.size(); i++) {
            if (vNode[i]->left != nullptr) {
                cNodes.push_back(vNode[i]->left);
            }
            
            if (vNode[i]->right != nullptr) {
                cNodes.push_back(vNode[i]->right);
            }
        }

        for (int i = 0; i < (int)vNode.size(); i++) {
            std::cout << vNode[i]->val << " ";
        }

        leftBreadth(cNodes);
    }

    void rightStartBreadthPrint() {
        std::cout << std::endl;
        if (root == nullptr) {
            std::cout << "Empty Tree\n";
            return;
        }

        std::vector<Node*> thisRoot;
        thisRoot.push_back(root);
        std::cout << "Right First Scan By Layer: ";
        rightBreadth(thisRoot);
    }

    void rightBreadth(std::vector<Node *> vNode) {
        if (vNode.size() == 0) {
            return;
        }

        std::vector<Node *> cNodes;

        for (int i = 0; i < (int)vNode.size(); i++) {
            if (vNode[i]->right != nullptr) {
                cNodes.push_back(vNode[i]->right);
            }
            
            if (vNode[i]->left != nullptr) {
                cNodes.push_back(vNode[i]->left);
            }
        }

        for (int i = 0; i < (int)vNode.size(); i++) {
            std::cout << vNode[i]->val << " ";
        }

        rightBreadth(cNodes);
    }
};

void clearScreen() {
    std::cout << "\033[2J\033[H";
}

int main() {
    clearScreen();

    std::vector<int> a = {10,20,30,40,50,60,70,80,90};

    BST myTree;

    myTree.generateTree(a);

    myTree.leftFirstDepthPrint();

    //myTree.valChkByTree(100); 

    myTree.rightStartBreadthPrint();

    return 0;
}