#include "arithmeticExpression.h"
#include <stack>
#include <sstream>
#include <fstream>

using namespace std;

arithmeticExpression::arithmeticExpression(const string &expression) : infixExpression(expression), root(nullptr)
{}

void arithmeticExpression::buildTree() {
    string postFix = infix_to_postfix();
    char key = 'a';
    stack<TreeNode *> tree;
    TreeNode* currNode;
    TreeNode* leftNode;
    TreeNode* rightNode;
    
    /* Transverse through each character in the postfix string */
    for (unsigned i = 0; i < postFix.size(); i++) {
        char curr = postFix.at(i);
        currNode = new TreeNode(curr, key);
        /* if the current char is an operator */
        if (priority(curr) != 0) {
            /* store the nodes from the stack and remove them */
            rightNode = tree.top();
            tree.pop();
            leftNode = tree.top();
            tree.pop();
            /* set the respective nodes as children */
            currNode->left = leftNode;
            currNode->right = rightNode;
        }
        /* add operand or subexpression into the stack, increment key */
        tree.push(currNode);
        key++;
    }
    /* return the completed stack's top node as the tree's root */
    root = tree.top();
}

void arithmeticExpression::infix() {
    infix(root);
}

void arithmeticExpression::prefix() {
    prefix(root);
}

void arithmeticExpression::postfix() {
    postfix(root);
}

void arithmeticExpression::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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

int arithmeticExpression::priority(char op) {
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix() {
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

/* infix tranverses tree as left -> parent -> right */
void arithmeticExpression::infix(TreeNode *node) {
    if (node) {
        if (node->left) {
            cout << '(';
        }
        infix(node->left);
        cout << node->data;
        infix(node->right);
        if (node->right) {
            cout << ')';
        }
    }
}

/* prefix tranverses tree as parent -> all left children -> all right children */
void arithmeticExpression::prefix(TreeNode *node) {
    if (node) {
        cout << node->data;
        prefix(node->left);
        prefix(node->right);
    }
}

/* postfix tranverses tree as left -> right -> parent */
void arithmeticExpression::postfix(TreeNode *node) {
    if (node) {
        postfix(node->left);
        postfix(node->right);
        cout << node->data;
    }
}

/* traverses in prefix order algorithm */
void arithmeticExpression::visualizeTree(ofstream & outFS, TreeNode *n){
    if(n){
        outFS<<n->key << "[ label = \""<<n->data<<"\"];"<<endl;
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