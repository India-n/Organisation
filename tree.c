#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    struct node *child[3];
    int count;
};

struct node* create(char name[]) {
    struct node *p = malloc(sizeof(struct node));
    strcpy(p->name, name);
    p->count = 0;
    return p;
}

void addChild(struct node *parent, struct node *child) {
    parent->child[parent->count++] = child;
}

void levelOrder(struct node *root) {
    struct node *queue[20];
    int front = 0, rear = 0, i;

    queue[rear++] = root;

    while (front < rear) {
        struct node *temp = queue[front++];

        printf("%s ", temp->name);

        for (i = 0; i < temp->count; i++)
            queue[rear++] = temp->child[i];
    }
}

int main() {
    struct node *CEO = create("CEO");
    struct node *HR = create("HR");
    struct node *Finance = create("Finance");
    struct node *IT = create("IT");
    struct node *Development = create("Development");
    struct node *Testing = create("Testing");
    struct node *Frontend = create("Frontend");
    struct node *Backend = create("Backend");

    addChild(CEO, HR);
    addChild(CEO, Finance);
    addChild(CEO, IT);

    addChild(IT, Development);
    addChild(IT, Testing);

    addChild(Development, Frontend);
    addChild(Development, Backend);

    printf("Level Order Traversal:\n");
    levelOrder(CEO);

    return 0;
}
