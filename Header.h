#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma once
#define MAX 26
//histogram declaration 
extern int histogram[MAX];
//HUFFNODE typedef
typedef struct HUFFNODE NODE;
//HUFFNODE declaration
struct HUFFNODE {
	char s;
	int weight;
	NODE* left;
	NODE* right;
};

void swap(int*, int*);
void sort(int, int);
char* getbuffer(FILE* , char* , long* );
int gethist(char* , long );
void reader(FILE* , FILE* , char* , char* );
NODE* getForest(int);
void swapNode(NODE*, NODE*);
void heapify(NODE* , int , int);
int buildHeap(NODE* , int );
NODE pop(NODE*, int*);
void pushCorrector(NODE* , int , int );
int push(NODE* tree, NODE , int* , int);
NODE buildTree(NODE* , int , int*);