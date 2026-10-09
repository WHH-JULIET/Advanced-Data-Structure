#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct node {
    struct node *left;
    int data;
    struct node *right;
};

// Global root pointer
struct node *root = NULL;

// Function to insert a value into the BST
void insert(int x) {
    struct node *temp, *p, *p1;

    // Allocate memory for new node
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    // If tree is empty, new node becomes root
    if (root == NULL) {
        root = temp;
    } else {
        p = root;
        // Traverse to find the correct insertion location
        while (p != NULL) {
            p1 = p; // p1 keeps track of the parent node
            if (p->data > x) {
                p = p->left;
            } else {
                p = p->right;
            }
        }

        // Attach temp to the parent node p1
        if (p1->data > x) {
            p1->left = temp;
        } else {
            p1->right = temp;
        }
    }
}

// Inorder Traversal: Left -> Root -> Right
void inorder(struct node *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

// Preorder Traversal: Root -> Left -> Right
void preorder(struct node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

// Postorder Traversal: Left -> Right -> Root
void postorder(struct node *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

// Function to search for an element in the BST
void search(int x) {
    struct node *temp = root;

    while (temp != NULL) {
        if (temp->data > x) {
            temp = temp->left;
        } else if (temp->data < x) {
            temp = temp->right;
        } else {
            printf("\nElement %d found in BST.\n", x);
            return;
        }
    }

    if (temp == NULL) {
        printf("\nElement %d not found in BST.\n", x);
    }
}

// Function to find the minimum value node in BST
struct node* findMin(struct node *root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from BST
struct node* deleteNode(struct node *root, int key) {
    if(root == NULL)
        return NULL;
    
    // Search for node
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main Driver Code
int main() {
    int n;

    printf("--- BST Construction ---\n");
    printf("Enter elements to insert into BST (Enter -1 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        insert(n);
    }

    printf("\n--- Traversals ---\n");
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    // Search Example
    printf("\nEnter element to search: ");
    scanf("%d", &n);
    search(n);
    
    printf("\nEnter element to delete: ");
    scanf("%d", &n);
    root = deleteNode(root, n);
    
    printf("Inorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
