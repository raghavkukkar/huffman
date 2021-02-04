#include "Header.h"
NODE* getForest(int diffchar) {
	diffchar += 1;
	NODE* forest = (NODE*)calloc(diffchar, sizeof(NODE));
	int last = 1;
	if (forest == NULL) {
		perror("there is a error with calloc , cannot allocate space for forest");
		return NULL;
	}
	else {
		for (int i = 0; i < MAX; i++) {
			if (histogram[i] > 0) {
				forest[last].weight = histogram[i];
				forest[last++].s = (char)(i + 'a');
			}
		}
		return forest;
	}
}
void swapNode(NODE *node1 , NODE *node2) {
	NODE x = *(node1);
	*(node1) = *(node2);
	*(node2) = x;

}
void heapify(NODE *forest,int index,int size) {
	int left= index*2, right = index*2+1, smallest = index;
	if(left <= size && forest[left].weight<forest[index].weight)
	{
		smallest = left;
	}

	if (right <= size && forest[right].weight < forest[smallest].weight) {
		smallest = right;
	}
	if (smallest != index) {
		swapNode(forest + index, forest + smallest);
		heapify(forest, smallest, size);
	}
	
}
int buildHeap(NODE *forest,int size) {
	for (int i = size  / 2;i > 0; i--) {
		heapify(forest, i,size);
	}
	return size;
}

NODE pop(NODE* tree, int* current) {
	if (*current < 1) {
		NODE null = {' ',-1};
		return null;
	}
	NODE temp = *(tree + 1);

	*(tree + 1) = *(tree + *current);
	*current -= 1;
	heapify(tree, 1, *current);
	return temp;
}
int push(NODE *tree,NODE node , int *current,int size) {
	if (*current >= size) {
		return -1;
	}
	else {
		*(current) += 1;
		tree[*current] = node;
		pushCorrector(tree, *current,size);
		return 1;
	}
}

void pushCorrector(NODE* tree, int index,int size) {
	if (index > size || index == 1) {
		return;
	}
	if (tree[index].weight < tree[index / 2].weight) {
		swapNode(tree + index, tree + index / 2);
		pushCorrector(tree, index / 2, size);
	}
	else {
		return;
	}
}

NODE  buildTree(NODE* tree, int size, int* current) {
	if (*current == 1) {
		return *tree;
	}
	else {
		NODE* first = (NODE*)calloc(1, sizeof(NODE));
		NODE* second = (NODE*)calloc(1, sizeof(NODE));
		NODE third;
		*first = pop(tree, current);
		printf("the first character out of queue %c\n", first->s);
		*second = pop(tree, current);
		printf("the  character out of queue %c\n", second->s);
		third.weight = first->weight + second->weight;
		third.left = second;
		third.right = first;
		int i = push(tree, third, current, size);
		if (i > 0) {
			return buildTree(tree, size, current);
		}
	}
}