
#include "Header.h"
#include"dev.h"
int histogram[MAX];

int main()
{
	FILE* fp = NULL;
	char* sfp = "C:\\Users\\Work\\Desktop\\file.txt";
	long l = 0;
	long* length = &l;
	char *buffer = getbuffer(fp, sfp, length);
	int diffchar = gethist(buffer, l);
	NODE* forest = getForest(diffchar);
	int current = buildHeap(forest,diffchar);
	printforest(forest, diffchar);
	int* pcurrent = &current;
	NODE* tree = calloc(1, sizeof(NODE));
	*tree = buildTree(forest, diffchar, pcurrent);
	printf("break point");
	return 0;
}
