



#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
  string value;
  Node* left;
  Node* right;

  Node(string value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
  Node* root;

  void insert(Node*& node, string value) {
    if (node == nullptr) {
      node = new Node(value);
    } else if (value < node->value) {
      insert(node->left, value);
    } else if (value > node->value) {
      insert(node->right, value);
    } else {
      insert(node->right, value);
    }
  }

  bool search(Node* node, string value) {
    if (node == nullptr) {
      return false;
    } else if (node->value == value) {
      return true;
    } else if (value < node->value) {
      return search(node->left, value);
    } else {
      return search(node->right, value);
    }
  }

  void deleteLeaf(Node*& node, string value) {
    if (node == nullptr) {
      return;
    } else if (node->value == value) {
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
      } else if (node->left == nullptr) {
        Node* temp = node;
        node = node->right;
        delete temp;
      } else if (node->right == nullptr) {
        Node* temp = node;
        node = node->left;
        delete temp;
      } else {
        string nextValue = findNext(node->right);
        deleteLeaf(node->right, nextValue);
        node->value = nextValue;
      }
    } else if (value < node->value) {
      deleteLeaf(node->left, value);
    } else {
      deleteLeaf(node->right, value);
    }
  }

  string findNext(Node* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node->value;
  }

  void inOrder(Node* node) {
    if (node == nullptr) {
      return;
    }
    inOrder(node->left);
    cout <<"'"<<node->value<<"'"<< " ";
    inOrder(node->right);
  }

  void preOrder(Node* node) {
    if (node == nullptr) {
      return;
    }
    cout <<"'"<<node->value<<"'"<< " ";
    preOrder(node->left);
    preOrder(node->right);
  }

  void postOrder(Node* node) {
    if (node == nullptr) {
      return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout <<"'"<<node->value<<"'"<< " ";
  }
  string kthSmallest(Node* node, int k) {
    int leftSize = nodeSize(node->left);
    if (leftSize + 1 == k) {
        return node->value;
       //return 0;
    } else if (k < leftSize + 1) {
      return kthSmallest(node->left, k);
    } else {
      return kthSmallest(node->right, k - leftSize - 1);
    }
  }

  int nodeSize(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return 1 + nodeSize(node->left) + nodeSize(node->right);
  }

  void levelOrder(Node* node) {
    if (node == nullptr) {
      return;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
      Node* current = q.front();
      q.pop();
      cout <<"'"<<current->value<<"'"<< " ";
      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
    }
  }

public:
  BinaryTree() {
    root = nullptr;
  }

  void insert(string value) {
    insert(root, value);
  }

  bool search(string value) {
    return search(root, value);
  }

  void deleteLeaf(string value) {
    deleteLeaf(root, value);
  }

  void inOrder() {
    inOrder(root);
  }

  void preOrder() {
    preOrder(root);
  }

  void postOrder() {
    postOrder(root);
  }

  string kthSmallest(int k) {
    if (root == nullptr || k > nodeSize(root)) {
      return "-1";
    }
    return kthSmallest(root, k);
  }

  void levelOrder() {
    levelOrder(root);
  }
};

int main() {
  BinaryTree tree;

  string input;
  while (cin >> input) {
    if (input == "init_tree") {
      tree = BinaryTree();
    } else if (input == "insert") {
      string value;
      cin >> value;
      tree.insert(value);
    } else if (input == "search") {
      string value;
      cin >> value;
      if(tree.search(value)==1){
          cout <<"True"<< endl;
      }
      else{
          cout <<"False"<< endl;
      }
    } else if (input == "delete") {
      string value;
      cin >> value;
      tree.deleteLeaf(value);
    } else if (input == "in_order") {
      tree.inOrder();
      cout << endl;
    } else if (input == "pre_order") {
      tree.preOrder();
      cout << endl;
    } else if (input == "post_order") {
      tree.postOrder();
      cout << endl;
    } else if (input == "k_th_smallest") {
      int k;
      cin >> k;
      cout << tree.kthSmallest(k) << endl;
    } else if (input == "level_order") {
      tree.levelOrder();
      cout << endl;
    }
  }

  return 0;
}



