// Nathan Goldberg
// ECE 205 Final Project

/* user inputs infix arithmetic expression,
 * converts it to a postfix expression,
 * converts that to a binary tree,
 * then evaluates the expression using a stack */

#include <cctype>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>

enum LeafValueType {
    TYPE_Operator,
    TYPE_Number
};
// struct definition for a binary tree leaf (node)
struct Leaf {
    // used a tagged union for storing the value of the leaf, since it can be either an operator or a number
    union {
        int num;
        char op;
    } value;
    LeafValueType type;
    Leaf *left;
    Leaf *right;
};



int precedence(char op) {
    // numerical values are arbitrary, just chose so that ^ is higher than *,/, which are higher than +,-
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int isLeftAssociative(char op) {
    // only '^' is right associative, all other operators are left-associative
    switch (op) {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    case '^':
        return 0;
    default:
        return -1;
    }
}

bool shouldPopOp(char opstackTop, char infixOp) {
    // determines whether or not the top element of opstack should be popped onto postfix stack in while loop
    if (precedence(opstackTop) < precedence(infixOp)) {
        // the opstack top element should be popped if it has greater precedent than scanned infix operator.
        return false;
    } else if (precedence(opstackTop) > precedence(infixOp)) {
        // if is has smaller precedent, then it should not be popped.
        return true;
    } else if (isLeftAssociative(infixOp)) {
        // however, if precedence is equal, pop only if the scanned infix operator is left-associative
        return true;
    }
    return false;
}

// function that returns true if c is an operator, otherwise returns false
bool isOperator(char c) {
    switch (c) {
    case '+': case '-': case '*': case '/': case '^':
        return true;
    default:
        return false;
    }
}

// remove spaces from a string
std::string removeSpaces(std::string str) {
    std::string result;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            result.push_back(str[i]);
        }
    }
    return result;
}


// convert infix to postfix expression
// using the algorithm from slides, plus some extra code to handle multi-digit numbers
std::string infixToPostfix(std::string str) {
    std::stack<char> opstack;
    std::string operandStr;
    std::string postfix;

    // remove spaces from input infix expression
    std::string infix = removeSpaces(str);

    // 1. scan one character at a time of an infix expression from left to right
    for (int i = 0; i < infix.length(); i++) {
        // 3 repeat until there is data in the infix expression
        switch (infix[i]) {
            // 3.1 if scanned character is '(' then push it to opstack
        case '(':
            opstack.push(infix[i]);
            break;

            // 3.3 if scanned character is operator
        case '+': case '-': case '*': case '/': case '^':
            while(!opstack.empty() && shouldPopOp(opstack.top(), infix[i])) {
                postfix.push_back(opstack.top());
                postfix.push_back(' ');
                opstack.pop();
            }
            opstack.push(infix[i]);
            break;


            // 3.4 if scanned character is ')'
        case ')':
            while (!opstack.empty() && opstack.top() != '(') {
                postfix.push_back(opstack.top());
                postfix.push_back(' ');
                opstack.pop();
            }
            opstack.pop();
            break;

        case ' ':
            break;

            // 3.2 if scanned character is operand then push to poststack
        default:
            // to detect multi-digit numbers, scan through next infix characters intil it is no longer a digit, and push each found digit to postfix
            int j = 0;
            for (j = 0; std::isdigit(infix[i+j]) && i+j < infix.length(); j++) {
                postfix.push_back(infix[i+j]);
            }
            // update i to be i+j-1 to not repeat digits with multi-digit numbers
            i = i+j-1;
            postfix.push_back(' ');
            break;
        }

    }

    // 4. pop and push into poststack until opstack is not empty
    while (!opstack.empty()) {
        postfix.push_back(opstack.top());
        postfix.push_back(' ');
        opstack.pop();
    }

    // 5. return poststack
    return postfix;
}

// evaluate an expression of two integers and an operator; returns a <op> b; 
// e.g. if a is 3, b is 4, op is *, returns 3*4=12
int evalWithOperator (int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return std::pow(a,b);
    default:
        return 0;
    }
}

// test function to print each element of a tree using left-DFS just to make sure postfixToBinaryTree function works
void printTree(Leaf *leaf) {
    if (leaf->type == TYPE_Number) {
        std::cout << leaf->value.num << std::endl;
    } else {
        std::cout << leaf->value.op << std::endl;
    }

    if (leaf->left != NULL) {
        printTree(leaf->left);
    }
    if (leaf->right != NULL) {
        printTree(leaf->right);
    }
}


Leaf *postfixToBinaryTree(std::string postfix) {
    // create empty stack
    std::stack<Leaf *> leaves;

    // loop through all characters in string
    for (int i = 0; i < postfix.length(); i++) {
        // if the scanned character is a space, skip
        if (postfix[i] == ' ') {
            continue;
        }

        if (isOperator(postfix[i])) {
            // if current character is an operator, pop the top two nodes, assign one to leftLeaf and rightLeaf
            Leaf *rightLeaf = leaves.top();
            leaves.pop();
            Leaf *leftLeaf = leaves.top();
            leaves.pop();

            // create a new leaf with value of current operator, with left->leftLeaf and right->rightLeaf
            leaves.push(new Leaf{postfix[i], TYPE_Operator, leftLeaf, rightLeaf});
        } else {
            std::string numStr;
            // if current character is not an operator, it must be a digit. loop through next characters until space to construct full integer
            int j = 0;
            for (j = 0; postfix[i+j] != ' ' && i+j < postfix.length(); j++) {
                numStr.push_back(postfix[i+j]);
            }
            i = i+j-1;
            // make new string with no children, set value to the number that was found in previous for loop
            leaves.push(new Leaf{std::stoi(numStr), TYPE_Number, NULL, NULL});
        }
    }

    // top node on stack is the root node
    Leaf *root = leaves.top();
    leaves.pop();

    return root;
}

// recursive function to evaluate tree
int evaluateTree(Leaf *leaf) {
    int result = 0;
    // base case: if node is type Number, it can't have any children so return its numerical value
    if (leaf->type == TYPE_Number) {
        result = leaf->value.num;
    } else {
        // operator node: evaluate its left and right nodes. then do <leftVal> <operator> <rightVal> (infix way)
        int leftVal = evaluateTree(leaf->left);
        int rightVal = evaluateTree(leaf->right);
        
        result = evalWithOperator(leftVal, rightVal, leaf->value.op);
    }
    return result;
}

int main() {
    std::string infix;
    std::cout << "enter infix expression: " << std::endl;
    // using std::getline to allow for spaces in infix expression
    std::getline(std::cin, infix);

    std::string postfix = infixToPostfix(infix);
    std::cout << "postfix expression: " << postfix << std::endl;

    Leaf *tree = postfixToBinaryTree(postfix);

    std::cout << "evaluated expression: " << evaluateTree(tree) << std::endl;

    return 0;
}
