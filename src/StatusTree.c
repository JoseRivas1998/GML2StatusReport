//
// Created by tcgdeploy on 3/9/2019.
//
#include "StatusTree.h"


NODE *createNode(STATUS *data) {
    NODE *result = malloc(sizeof(NODE));
    result->leftChild = NULL;
    result->rightChild = NULL;
    result->data = data;
    return result;
}

bool add(NODE **root, STATUS *data) {
    if(*root == NULL) {
        *root = createNode(data);
        return true;
    }
    if(data->laptopNum == (*root)->data->laptopNum) {
        return false;
    }
    if(data->laptopNum > (*root)->data->laptopNum) {
        if((*root)->rightChild == NULL) {
            (*root)->rightChild = createNode(data);
            return true;
        } else {
            return add(&(*root)->rightChild, data);
        }
    }
    if(data->laptopNum < (*root)->data->laptopNum) {
        if((*root)->leftChild == NULL) {
            (*root)->leftChild = createNode(data);
            return true;
        } else {
            return add(&(*root)->leftChild, data);
        }
    }
    return false;

}

void freeNode(NODE **node) {
    if(*node != NULL) {
        if((*node)->leftChild != NULL) {
            freeNode(&(*node)->leftChild);
        }
        if((*node)->rightChild != NULL) {
            freeNode(&(*node)->rightChild);
        }
        free((*node)->data);
        free(*node);
    }
}

void printTable(FILE *file, NODE **root) {
    fputs("<!DOCTYPE html>", file);
    fputs("<html lang=\"en\">", file);

    fputs("<head>", file);
    fputs("<title>New Silver Game Maker 2 Status</title>", file);
    fputs("</head>", file);

    fputs("<body>", file);

    fputs("<table border=\"1px\">", file);
    fputs("<tr>", file);
    fputs("<td><strong>Laptop Number</strong></td>", file);
    fputs("<td><strong>Status</strong></td>", file);
    fputs("</tr>", file);
    printTr(file, root);
    fputs("</table>", file);

    fputs("</body>", file);

    fputs("</html>", file);
}

void printTr(FILE *file, NODE **root) {
    if(*root != NULL) {
        printTr(file, &(*root)->leftChild);
        fputs("<tr>", file);
        fprintf(file, "<td>%d</td>", (*root)->data->laptopNum);
        fprintf(file, "<td>%s</td>", (*root)->data->status);
        fputs("</tr>", file);
        printTr(file, &(*root)->rightChild);
    }
}
