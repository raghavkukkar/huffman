#include"Header.h"
#include"dev.h"
void printhist() {
	for (int i = 0; i < MAX;i++) {
		printf("%d", histogram[i]);
	}
}
void printforest(NODE* forest,int size) {
	for (int i = 0; i <= size; i++)
		printf("character %c with weight %d\n", forest[i].s,forest[i].weight);
}