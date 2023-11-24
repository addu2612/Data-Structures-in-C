#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *rchild, *lchild;
} * root;

struct Node *Search(struct Node *t, int key) {
    if (t == NULL) {
        return NULL;
    } else if (key == t->data) {
        return t;
    } else if (key > t->data) {
        return Search(t->rchild, key);
    } else if (key < t->data) {
        return Search(t->lchild, key);
    }
}

struct Node *Rinsert(struct Node *p, int key) {
    struct Node *t = NULL;
    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    } else if (key < p->data) {
        p->lchild = Rinsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Rinsert(p->rchild, key);
    }
    return p;
}

struct Node *InPre(struct Node *p) {
    while (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p) {
    while (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

int Height(struct Node *root) {
    int x, y;
    if (root == NULL) {
        return 0;
    }
    x = Height(root->lchild);
    y = Height(root->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *rdelete(struct Node *p, int key) {
    struct Node *q;
    if (p == NULL) {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root) {
            free(p);
            return NULL;
        }
        free(p);
        return NULL;
    }
    if (key < p->data) {
        p->lchild = rdelete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = rdelete(p->rchild, key);
    } else {
        if (p->lchild != NULL) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = rdelete(p->lchild, key);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = rdelete(p->rchild, key);
        }
    }
    return p;
}

void preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p) {
    if (p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

struct Node *mirrorImage(struct Node *root) {
    struct Node *temp;
    if (root) {
        mirrorImage(root->lchild);
        mirrorImage(root->rchild);
        
        // Swap the left and right children
        temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;
    }
    return root;
}

int countLeafNodes(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL) {
        return 1;
    }
    return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
}

int countInternalNodes(struct Node *root) {
    if (root == NULL || (root->lchild == NULL && root->rchild == NULL)) {
        return 0;
    }
    return 1 + countInternalNodes(root->lchild) + countInternalNodes(root->rchild);
}

int main() {
    struct Node *temp;
    root = Rinsert(root, 10);
    Rinsert(root, 19);
    Rinsert(root, 11);
    Rinsert(root, 15);
    Rinsert(root, 20);
    Rinsert(root, 30);

    temp = Search(root, 20);
    if (temp != NULL) {
        printf("Element %d is found\n", temp->data);
    } else {
        printf("Not found\n");
    }

    printf("Tree is:");
    inorder(root);

    root = rdelete(root, 20);

    printf("\nAfter deletion:\n");
    inorder(root);

    return 0;
}


/*
struct Node *insert(struct Node *root, int key) {
    struct Node *r = NULL, *p;

    if (root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root=NULL;
        return p;
    }

    while (root != NULL) {
        r = root;
        if (key == root->data) {
            return root;
        } else if (key < root->data) {
            root = root->lchild;
        } else {
            root = root->rchild;
        }
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (p->data < r->data) {
        r->lchild = p;
    } else {
        r->rchild = p;
    }

}
*/