
#include"Header.h"
void swap(int* left, int* right) {
	int temp;
	temp = *left;
	*left = *right;
	*right = temp;
}
void sort(int l , int h) {
	
	int i, last;
	if (l >= h) {
		return;
	}
	last = l;
	for (i = l + 1; i <= h;i++) {
		if (histogram[i] < histogram[l]) {
			++last;
			swap(histogram + last, histogram + i);
		}
	}
	swap(histogram + l, histogram + last);
	sort(l, last - 1);
	sort(last + 1, h);


}
