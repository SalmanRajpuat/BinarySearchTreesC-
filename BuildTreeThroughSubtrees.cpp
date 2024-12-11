#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* right;
    struct Node* left;

    Node(int val) {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

// to search the preOrder first node in the inOrder list to build tree
int search(int inOrder[], int start, int end, int curr) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == curr)
            return i;
    }
    return -1;
}

// function to build tree (first builds root, then left, then right)
Node* buildTree(int preOrder[], int inOrder[], int start, int end) {
    static int idx = 0;  // Keeps track of current index in preOrder array
    if (start > end) {
        return nullptr;
    }

    int curr = preOrder[idx];
    idx++;  // Move to the next element in preOrder array
    Node* node = new Node(curr);

    if (start == end) {
        return node;
    }

    int pos = search(inOrder, start, end, curr);

    // Recursively build left and right subtrees
    node->left = buildTree(preOrder, inOrder, start, pos - 1);
    node->right = buildTree(preOrder, inOrder, pos + 1, end);

    return node;
}

void inOrderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main() {
    int preOrder[] = {1, 2, 3, 4, 5};
    int inOrder[] = {4, 2, 1, 5, 3};

    // Build tree
    Node* root = buildTree(preOrder, inOrder, 0, 4);

    // Print tree in-order
    inOrderPrint(root);

    return 0;
}
