以下是模拟试卷中所有题目的 **正确答案** 和 **解析**，供您复习：

---

## **一、选择题（共 20 题，每题 3 分，共 60 分）**

1. **正确答案**：B  
   **解析**：`double` 类型的存储范围比 `float` 类型大。`int` 类型用于存储整数，字符型变量不仅可以存储字母，也可以存储其他字符。

2. **正确答案**：B  
   **解析**：`goto` 虽然可以用，但会导致代码结构混乱。不能跨函数跳转，也不能直接替代 `break`。

3. **正确答案**：A  
   **解析**：`*(p + 3)` 是 `arr[3]` 的值，输出为 4。

4. **正确答案**：C  
   **解析**：内层 `fun(5, 6)` 的返回值为 `void`，但可以在外层被调用，此时输出为 `5`。

5. **正确答案**：A  
   **解析**：`*(p - 1)` 指向数组的第一个元素，值为 `1`。

6. **正确答案**：D  
   **解析**：内存按 4 字节对齐，结构体大小为 `4 (c1) + 4 (对齐) + 4 (i) + 4 (c2 + 对齐)` = 16。

7. **正确答案**：C  
   **解析**：顺序表在存储空间已满时需要重新分配空间，时间复杂度为 O(n)。

8. **正确答案**：A  
   **解析**：`switch` 不支持浮点数；`while` 循环需要先判断条件；`do-while` 循环条件在循环体之后。

9. **正确答案**：B  
   **解析**：循环队列满的条件为 `(rear + 1) % maxSize == front`。

10. **正确答案**：A  
    **解析**：邻接矩阵适用于稠密图，邻接表适用于稀疏图。

11. **正确答案**：A  
    **解析**：满二叉树的叶子节点全部位于最后一层。

12. **正确答案**：C  
    **解析**：Prim 和 Kruskal 算法均适用于最小生成树问题。

13. **正确答案**：C  
    **解析**：哈希查找的时间复杂度与哈希函数的选择有关。

14. **正确答案**：B  
    **解析**：快速排序的最坏时间复杂度为 O(n²)。

15. **正确答案**：C  
    **解析**：动态规划适用于有重叠子问题和最优子结构的问题。

16. **正确答案**：D  
    **解析**：`do-while` 循环的条件在循环体之后判断，循环至少执行一次。

17. **正确答案**：B  
    **解析**：数组名是指向数组第一个元素的指针。

18. **正确答案**：D  
    **解析**：单链表适合频繁的插入和删除操作。

19. **正确答案**：B  
    **解析**：循环队列满时 `(rear + 1) % maxSize == front`。

20. **正确答案**：C  
    **解析**：Prim 算法用于求解最小生成树。

---

## **二、填空题（共 10 题，每题 5 分，共 50 分）**

1. **正确答案**：  
   ```c
   z = sqrt(x * x + y * y);
   ```  
   **解析**：C 语言中没有 `^` 操作符表示平方，需用乘法。

2. **正确答案**：  
   ```c
   sum += i;
   ```  
   **解析**：循环中将奇数累加到 `sum` 中。

3. **正确答案**：  
   ```c
   sum += arr[i];
   average = sum / 10.0;
   ```  
   **解析**：`sum` 累加数组元素，`average` 使用浮点数计算。

4. **正确答案**：  
   ```c
   int temp = a;
   a = b;
   b = temp;
   ```  
   **解析**：交换两个变量的常见方法。

5. **正确答案**：  
   ```c
   int temp = *a;
   *a = *b;
   *b = temp;
   ```  
   **解析**：使用指针完成变量交换。

6. **正确答案**：  
   ```c
   struct Student
   ```  
   **解析**：正确的结构体定义语法。

7. **正确答案**：  
   ```c
   Node *temp = head;
   previous->next = temp->next;
   free(temp);
   ```  
   **解析**：指针操作需确保正确释放内存。

8. **正确答案**：  
   ```c
   root->data;
   root->left;
   root->right;
   ```  
   **解析**：二叉树前序遍历访问当前节点后递归左右子树。

9. **正确答案**：  
   ```c
   stack;
   queue;
   ```  
   **解析**：DFS 使用栈，BFS 使用队列。

10. **正确答案**：  
    **以基准元素为界划分为两个子数组**  
    **解析**：快速排序的核心是分区操作。

---

## **三、函数题（共 3 题，每题 10 分，共 30 分）**

1. **正确答案**：  
   ```c
   int factorial(int n) {
       if (n == 0) return 1;
       else return n * factorial(n - 1);
   }
   ```  
   **解析**：递归实现阶乘函数。

2. **正确答案**：  
   ```c
   void reverseString(char str[]) {
       int length = strlen(str);
       for (int i = 0; i < length / 2; i++) {
           char temp = str[i];
           str[i] = str[length - i - 1];
           str[length - i - 1] = temp;
       }
   }
   ```  
   **解析**：对称交换实现字符串反转。

3. **正确答案**：  
   ```c
   int binarySearch(int arr[], int size, int target) {
       int left = 0, right = size - 1;
       while (left <= right) {
           int mid = (left + right) / 2;
           if (arr[mid] == target) return mid;
           else if (arr[mid] < target) left = mid + 1;
           else right = mid - 1;
       }
       return -1;
   }
   ```  
   **解析**：二分查找的标准实现。

---

## **四、应用题（共 2 题，每题 20 分，共 40 分）**
1. **正确答案**：
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int score;
};

int main() {
    struct Student students[100];
    int count = 0;
    double totalscore = 0;
    printf("Enter student name and score (end with EOF): ");
    while (scanf("%s %d", students[count].name, &students[count].score) != EOF) {
        totalscore += students[count].score;
        count++;
    }
    double average = totalscore / count;
    printf("Average score: %.2f\n", average);
    printf("Students above average:\n");
    for (int i = 0; i < count; i++) {
        if (students[i].score > average) {
            printf("%s: %d\n", students[i].name, students[i].score);
        }
    }
    return 0;
}
```
   **解析**：学生信息的输入、平均值计算和筛选功能完整正确。

2. **正确答案**：
   **解析**：链表栈的实现，包含入栈、出栈和查看栈顶操作。
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void pop(struct Node **head){
    if(*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void peek(struct Node *head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", head->data);
}

int main() {
    struct Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    peek(head);
    pop(&head);
    peek(head);
    return 0;
}
```
---

## **五、程序设计题（共 2 题，每题 20 分，共 40 分）**

1. **正确答案**：  
   实现一个表达式求值程序需用栈来解析中缀表达式，转换为后缀表达式，并求值。
```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct TreeNode {
    char value;
    struct TreeNode *left, *right;
} TreeNode;

// 栈结构定义
typedef struct Stack {
    TreeNode *nodes[100];
    int top;
} Stack;

void push(Stack *stack, TreeNode *node) {
    stack->nodes[++stack->top] = node;
}

TreeNode* pop(Stack *stack) {
    return stack->nodes[stack->top--];
}

// 创建新树节点
TreeNode* createNode(char value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// 操作符优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 中缀转后缀
void infixToPostfix(char *infix, char *postfix) {
    char stack[100];
    int top = -1, j = 0;

    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i]; // 操作数直接输出
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // 弹出 '('
        } else { // 操作符
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0'; // 结束符
}

// 构造表达式树
TreeNode* buildExpressionTree(char *postfix) {
    Stack stack = {.top = -1};

    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, createNode(postfix[i])); // 数字节点
        } else { // 操作符
            TreeNode *node = createNode(postfix[i]);
            node->right = pop(&stack); // 右子树
            node->left = pop(&stack);  // 左子树
            push(&stack, node);
        }
    }
    return pop(&stack);
}

// 计算表达式
int evaluate(TreeNode *root) {
    if (!root) return 0;
    if (isdigit(root->value)) return root->value - '0'; // 数字
    int left = evaluate(root->left);
    int right = evaluate(root->right);
    switch (root->value) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    return 0;
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    TreeNode *root = buildExpressionTree(postfix);
    printf("Result: %d\n", evaluate(root));
    return 0;
}

```

2. **正确答案**：  
   Kruskal 算法实现需掌握并查集操作和图的边排序。
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Edge {
    int u, v, weight;
} Edge;

typedef struct Graph {
    int vertices, edges;
    Edge edge[MAX];
} Graph;

int parent[MAX];

// 找到集合的根节点
int find(int i) {
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}

// 合并两个集合
void unionSet(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    parent[xroot] = yroot;
}

// 比较函数
int compareEdges(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->weight - e2->weight;
}

// Kruskal 算法
void KruskalMST(Graph *graph) {
    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);

    for (int i = 0; i < graph->vertices; i++) {
        parent[i] = -1;
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    int mst_weight = 0;

    for (int i = 0; i < graph->edges; i++) {
        int u = graph->edge[i].u;
        int v = graph->edge[i].v;
        int w = graph->edge[i].weight;

        if (find(u) != find(v)) {
            printf("%d -- %d == %d\n", u, v, w);
            unionSet(u, v);
            mst_weight += w;
        }
    }
    printf("Total weight of MST: %d\n", mst_weight);
}

int main() {
    Graph graph;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &graph.vertices, &graph.edges);

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < graph.edges; i++) {
        scanf("%d %d %d", &graph.edge[i].u, &graph.edge[i].v, &graph.edge[i].weight);
    }

    KruskalMST(&graph);
    return 0;
}

```
（这两题稍难，建议多做类似题目练习）

---

如果需要进一步解析或示例代码，可以告诉我！