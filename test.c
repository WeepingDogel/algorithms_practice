#include <stdio.h>
#include <stdlib.h>
// 定义表达式树节点类型
struct ExprNode {
    char type;  // 'n' for number, '+' for add, '*' for multiply
    int value;  // stores number value if type is 'n'
    struct ExprNode *left;
    struct ExprNode *right;
};

// 创建新节点
struct ExprNode* createExprNode(char type, int value) {
    struct ExprNode *node = (struct ExprNode*)malloc(sizeof(struct ExprNode));
    node->type = type;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 计算表达式树的值
int evaluate(struct ExprNode *root) {
    if (root == NULL) return 0;
    
    // 如果是数字节点，直接返回值
    if (root->type == 'n') return root->value;
    
    // 递归计算左右子树
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);
    
    // 根据操作符计算结果
    if (root->type == '+') return leftVal + rightVal;
    if (root->type == '*') return leftVal * rightVal;
    
    return 0;
}

int main() {
    struct ExprNode *root = createExprNode('+', 0);
    root->left = createExprNode('n', 3);
    root->right = createExprNode('*', 0);
    root->right->left = createExprNode('n', 2);
    root->right->right = createExprNode('n', 5);
    printf("Result: %d\n", evaluate(root));
    return 0;
}