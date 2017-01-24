#include <iostream>
#include <queue>
using namespace std;

// Node class
class Node {
    int key;
    Node* left;
    Node* right;
public:
    Node() { key=-1; left=NULL; right=NULL; };
    void setKey(int aKey) { key = aKey; };
    void setLeft(Node* aLeft) { left = aLeft; };
    void setRight(Node* aRight) { right = aRight; };
    int Key() { return key; };
    Node* Left() { return left; };
    Node* Right() { return right; };
};

// Tree class
class Tree {
     Node* root;
public:
     Tree();
     ~Tree();
     Node* Root() { return root; };
     void addNode(int key);
     void levelOrder(Node* n);
private:
     void addNode(int key, Node* leaf);
     void freeNode(Node* leaf);
};

Tree::Tree() {
     root = NULL;
}

Tree::~Tree() {
     freeNode(root);
}

void Tree::freeNode(Node* leaf)
{
    if ( leaf != NULL )
    {
       freeNode(leaf->Left());
       freeNode(leaf->Right());
       delete leaf;
    }
}

void Tree::addNode(int key) {
     // If no elements, add as root
     if ( root == NULL ) {
        cout << "add root node ... " << key << endl;
        Node* n = new Node();
        n->setKey(key);
    root = n;
     }
     else {
    cout << "add other node ... " << key << endl;
    addNode(key, root);
     }
}

// Add a node (private)
void Tree::addNode(int key, Node* leaf) {
    if ( key <= leaf->Key() ) {
       if ( leaf->Left() != NULL )
      addNode(key, leaf->Left());
       else {
      Node* n = new Node();
      n->setKey(key);
      leaf->setLeft(n);
       }
    }
    else {
       if ( leaf->Right() != NULL )
      addNode(key, leaf->Right());
       else {
      Node* n = new Node();
      n->setKey(key);
      leaf->setRight(n);
       }
    }
}

// Print the tree level-order assisted by queue
void Tree::levelOrder(Node* n) {
   queue<Node*> q;

   q.push(n);

   while ( ! q.empty() )
   {
       Node* v = q.front();
       cout << v->Key() << " ";

       if ( v->Left() != NULL )
            q.push(v->Left());

       if ( v->Right() != NULL )
            q.push(v->Right());

       q.pop();
   }
}

int main() {
   Tree* tree = new Tree();
   tree->addNode(1);
   tree->addNode(2);
   tree->addNode(3);
   tree->addNode(4);
   tree->addNode(5);

   cout << "Level order traversal: " << endl;
   tree->levelOrder(tree->Root());
   cout << endl;

   delete tree;
   return 0;
}
