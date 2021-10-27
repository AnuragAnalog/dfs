#include "bstree.h"
#include <stdio.h>

// Function Prototypes
int menu();

int main(void)
{
    int opt, val, h = 0;
    Btree *root = NULL;

    while (opt != 12)
    {
        opt = menu();
        system("clear");
        switch (opt)
        {
        case 1:
            printf("Enter the node to be inserted: ");
            scanf("%d", &val);
            h = insert(&root, val, h);
            break;
        case 2:
            printf("*** In-order Traversal ***\n");
            intraver(root);
            break;
        case 3:
            printf("*** Pre-order Traversal ***\n");
            pretraver(root);
            break;
        case 4:
            printf("*** Post-order Traversal ***\n");
            posttraver(root);
            break;
        case 5:
            printf("*** Delete a leaf node ***\n");
            printf("Enter the leaf node to be deleted: ");
            scanf("%d", &val);
            val = delleaf(root, val);
            printf("%d is deleted.\n", val);
            break;
        case 6:
            printf("*** Delete a Internal node with left rotation ***\n");
            printf("Enter the node to be deleted: ");
            scanf("%d", &val);
            delnodel(root, val);
            printf("%d is deleted.\n", val);
            break;
        case 7:
            printf("*** Delete a Internal node with right rotation ***\n");
            printf("Enter the node to be deleted: ");
            scanf("%d", &val);
            delnoder(root, val);
            printf("%d is deleted.\n", val);
            break;
        case 8:
            printf("*** Search for a node ***\n");
            printf("Enter the node to be searched: ");
            scanf("%d", &val);
            search(root, val);
            break;
        case 9:
            printf("*** Maximum elemnet of the tree ***\n");
            val = findmax(root);
            printf("Maximum element is %d\n", val);
            break;
        case 10:
            printf("Height of the tree is %d.\n", h);
            break;
        case 11:
            display(root, h);
            break;
        case 12:
            cleartree(root);
            printf("Hope you had a good time with my Data-structure :-)\n");
            exit(0);
        default:
            break;
        }
    }

    cleartree(root);
    exit(0);
}

int menu()
{
    int option;

    printf("\n----------------------------------\n");
    printf("    Binary Search Tree(BST)       \n");
    printf("----------------------------------\n");
    printf("Your operations are: \n");
    printf("1) Insert a node.\n");
    printf("2) Perform a In-order traversal.\n");
    printf("3) Perform a Pre-order traversal.\n");
    printf("4) Perform a Post-order traversal.\n");
    printf("5) Delete a leaf node.\n");
    printf("6) Delete a Internal node with left rotation.\n");
    printf("7) Delete a Internal node with right rotation.\n");
    printf("8) Search for a node.\n");
    printf("9) Maximum element in tree.\n");
    printf("10) Height of the tree.\n");
    printf("11) Display the tree.\n");
    printf("12) Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &option);

    return option;
}