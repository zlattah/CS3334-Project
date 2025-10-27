#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Node {
    public:
        int key;
        int value;
        int height;
        Node* lson;
        Node* rson;

        Node(int k, int v) {
            key = k;
            value = v;
            height = 1;
            lson = nullptr;
            rson = nullptr;
        }
};

class AVLTree {
    private:
        Node* root;

        int h(Node* t) {
            return t==NULL ? 0 : t->height;
        }

        void rotateR(Node*& v) {
            Node* x = v->lson;
            v->lson = x->rson;
            x->rson = v;
            v->height = max(h(v->lson), h(v->rson)) + 1;
            x->height = max(h(x->lson), v->height) + 1;
            v = x;
        }

        void rotateL(Node*& v) {
            Node* x = v->rson;
            v->rson = x->lson;
            x->lson = v;
            v->height = max(h(v->lson), h(v->rson)) + 1;
            x->height = max(h(x->rson), v->height) + 1;
            v = x;
        }

        int BalanceDifference(Node* node) {
            return node ? h(node->lson) - h(node->rson) : 0;
        }

        Node* insert(Node* node, int key, int value) {
            if (!node) return new Node(key, value);

            if (key < node->key) {
                node->lson = insert(node->lson, key, value);
            } else if (key > node->key) {
                node->rson = insert(node->rson, key, value);
            } else {
                node->value = value;
            }

            node->height = 1 + max(h(node->lson), h(node->rson));
            int balancedif = BalanceDifference(node);

            if (balancedif > 1 && key < node->lson->key) {
                rotateR(node);
            } else if (balancedif < -1 && key > node->rson->key) {
                rotateL(node);
            } else if (balancedif > 1 && key > node->lson->key) {
                rotateL(node->lson);
                rotateR(node);
            } else if (balancedif < -1 && key < node->rson->key) {
                rotateR(node->rson);
                rotateL(node);
            }

            return node;
        }

        int getValue(Node* node, int key) {
            if (!node) return 0;
            if (key < node->key) {
                return getValue(node->lson, key);
            } else if (key > node->key) {
                return getValue(node->rson, key);
            } else {
                return node->value;
            }
        }

    public:
        AVLTree() : root(nullptr) {}

        void insert(int key, int value) {
            root = insert(root, key, value);
        }

        int getValue(int key) {
            return getValue(root, key);
        }
};

int mostFrequent(const vector<int>& arr) {
    AVLTree tree;
    int currentCount, count;
    int maxrep = 0;
    int maxel = arr[0];
    
    for (int i = 0; i < arr.size(); i++) {
        currentCount = tree.getValue(arr[i]);
        tree.insert(arr[i], currentCount + 1);
    }

    for (int i = 0; i < arr.size(); i++) {
        count = tree.getValue(arr[i]);
        if (count > maxrep) {
            maxrep = count;
            maxel = arr[i];
        }
    }

    return maxel;
}

void f(string line) {
    istringstream ss(line);
    vector<int> arr;
    int num;

    while (ss >> num) {
        arr.push_back(num);
    }

    if (arr.empty()) {
        cout << "0" << endl;
        return;
    }
    cout << mostFrequent(arr) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string line;
    while (getline(cin, line)) {
        f(line);
    }
    return 0;
}