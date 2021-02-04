#include "Header.h"

void reader(FILE* fp, FILE* wp, char* sfp, char* swp) {
	int content;
	if ((fp = fopen(sfp, "r")) == NULL) {
		perror("Error");
	}
	else {
		if ((wp = fopen(swp, "a")) == NULL) {
			perror("Error");
		}
		else {
			putc('\n', wp);
			while ((content = getc(fp)) != EOF) {
				printf("%c", content);
				putc(content, wp);
			}
			putc('c', wp);
			fclose(wp);
		}
		fclose(fp);
	}
}
int gethist(char* buffer, long length) {
	int diffchar = 0;
	long i = 0;
	while (i < length) {
		if(histogram[buffer[i] - 'a'] >0)
		histogram[buffer[i++] - 'a']++;
		else {
			diffchar++;
			histogram[buffer[i++] - 'a']++;
		}
	}
	return diffchar;
}
char* getbuffer(FILE* fp, char* sfp, long* length) {
	char* buffer;
	if ((fp = fopen(sfp, "r")) == NULL) {
		perror("fp error");
		return NULL;
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		*length = ftell(fp);
		rewind(fp);
		buffer = (char*)malloc((*length) + 1 * sizeof(char));
		if (buffer == NULL) {
			perror("buffer cannot be allocated sorry");
			return buffer;
		}
		else {
			fread(buffer, *length, 1, fp);
			buffer[*length] = '\0';
			fclose(fp);
			return buffer;
		}
	}
}
