#include "AVLTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;


//public 
AVLTree::AVLTree() : root(nullptr)
{}

void AVLTree::insert(const string &word) {
    Node* newNode = new Node(word);
    Node* currNode = root;
    Node* parentNode = nullptr;

    if (root == nullptr) {
        root = newNode;
        return;
    }

    while (currNode != nullptr){
        parentNode = currNode;
        if (newNode -> key == parentNode -> key){
            newNode -> count += 1;
            return;
        }
        if (newNode -> key < parentNode -> key){
            currNode = currNode->left;
        }
        if (newNode -> key >= parentNode -> key){
            currNode = currNode->right;
        }
    }

    if (newNode -> key < parentNode -> key){
        parentNode -> left = newNode;
        newNode -> parent = parentNode;
    }else if(newNode -> key > parentNode -> key){
        parentNode -> right = newNode;
        newNode -> parent = parentNode;
    }

    setBalanceFactors(root);
    rebalance(newNode);
}

int AVLTree::height(const string &key) const {
    Node* node = search(key, root);
    return height(node);
}

int AVLTree::balanceFactor(Node* node){
    int leftHeight = 0;
    int rightHeight = 0;

    if(node == nullptr){
        return -1;
    }

    if(node -> left){
        leftHeight = height(node -> left);
    }else if(node -> left == nullptr){
        leftHeight = -1;
    }

    if(node -> right){
        rightHeight = height(node -> right);
    }else if(node -> right == nullptr){
        rightHeight = -1;
    }

    return leftHeight - rightHeight;

}

bool AVLTree::search(const string &key) const {
    Node* node = search(key, root);
    if (node) {
        return true;
    }
    return false;
}

void AVLTree::printBalanceFactors(){
	rebalance(root);
	printBalanceFactors(root);
	cout << endl;
}

void AVLTree::visualizeTree(const string &outputFilename){
	ofstream outFS(outputFilename.c_str());
	if(!outFS.is_open()){
		cout<<"Error"<<endl;
		return;
	}
	outFS<<"digraph G {"<<endl;
	visualizeTree(outFS,root);
	outFS<<"}";
	outFS.close();
	string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
	string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
	system(command.c_str());
}

//privates


Node* AVLTree::findUnbalancedNode(Node* node){
    Node* currNode = node;

	while (currNode != nullptr){
		if (balanceFactor(currNode) >= 2 || balanceFactor(currNode) <= -2){
			return currNode;
		}else{
			currNode = currNode->parent;
		}
	}

	return nullptr;
}

Node* AVLTree::rotateLeft(Node* node) {
    Node* parent = node->parent;
	Node* child = node->right;
	Node* childChild = child->left;
	
	if(parent == nullptr){
		root = child;
	}else{
		if(parent->key > node->key){
			parent->left = child;
		}else if(parent->key < node->key){
			parent->right = child;
		}
	}
	
	child->left = node;
	node->right = childChild;
	child->parent = node->parent;
	node->parent = child;
	
	return child;
}

Node* AVLTree::rotateRight(Node* node) {
    Node* parent = node->parent;
	Node* child = node->left;
	Node* childChild = child->right;
	
	if(parent == nullptr){
		root = child;
	}else{
		if(parent->key > node->key){
			parent->left = child;
		}else if(parent->key < node->key){
			parent->right = child;
		}
	}
	
	child->right = node;
	node->left = childChild;
	child->parent = node->parent;
	node->parent = child;
	
	return child;
}

void AVLTree::printBalanceFactors(Node* node) {
	if (node != nullptr) {
		printBalanceFactors(node->left);
		cout << node->key << "(" << balanceFactor(node) << "), ";
		printBalanceFactors(node->right);
	}
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
	if(n){
		if(n->left){
			visualizeTree(outFS,n->left);
			outFS<<n->key <<" -> " <<n->left->key<<";"<<endl;    
		}

		if(n->right){
			visualizeTree(outFS,n->right);
			outFS<<n->key <<" -> " <<n->right->key<<";"<<endl;    
		}
	}
}

void AVLTree::rebalance(Node* node){
    while(findUnbalancedNode(node) != nullptr){
        Node* unbalancedNode = findUnbalancedNode(node);
        int balFac = balanceFactor(unbalancedNode);
		int balFacLeft = balanceFactor(unbalancedNode->left);
		int balFacRight = balanceFactor(unbalancedNode->right);

		if (balFac == -2 && balFacLeft == -1) {
			rotateLeft(unbalancedNode);
		}
		else if (balFac == 2 && balFacLeft == -1) {
			rotateLeft(unbalancedNode->left);
			rotateRight(unbalancedNode);
		}
		else if (balFac == 2 && balFacRight == 1 ){
			rotateRight(unbalancedNode);
		}
		else {
			rotateRight(unbalancedNode->right);
			rotateLeft(unbalancedNode);
		}

		setBalanceFactors(root);
    }
}

void AVLTree::setBalanceFactors(Node* node){
    if(node != nullptr){
        node->balFactor = balanceFactor(node);
        setBalanceFactors(node -> left);
        setBalanceFactors(node -> right);
    }
}



int AVLTree::height(Node* root) const {
    if (!root) {
        return -1;
    } else if (!root->left && !root->right) {
        return 0;
    }
    int LH = height(root->left);
    int RH = height(root->right);
    if (LH > RH) {
        return LH + 1;
    } else {
        return RH + 1;
    }
    return 0;
}

Node* AVLTree::search(const string &key, Node* root) const {
    if (!root || root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(key, root->right);
    } else {
        return search(key, root->left);
    }
}








