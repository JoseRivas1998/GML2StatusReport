//
// Created by tcgdeploy on 3/9/2019.
//
#ifndef GML2STATUSREPORT_STATUSTREE_H
#define GML2STATUSREPORT_STATUSTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

typedef char GML2_STATUS[BUFFER_SIZE];

typedef struct status {
    int laptopNum;
    GML2_STATUS status;
} STATUS;

typedef struct node {
    STATUS *data;
    struct node *leftChild;
    struct node *rightChild;
} NODE;

NODE *createNode(STATUS *data);

bool add(NODE **root, STATUS *data);

void freeNode(NODE **node);

void printTable(FILE *file, NODE **root);
void printTr(FILE *file, NODE **root);

#endif //GML2STATUSREPORT_STATUSTREE_H
