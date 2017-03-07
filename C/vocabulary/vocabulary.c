#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NEWLINE -1

char * get_word(FILE * fp, long * offset){
	int c = 0;
	long orig_offset = *offset;
	if(0!=fseek(fp, orig_offset, SEEK_SET))
	{
		printf("fseek failed");
		return 0;
	}
	while(' ' != (c=fgetc(fp)) && c!=EOF && c!='\n' && c!='&'){
		++*offset;
	}
	if(c==EOF){
		return EOF;
	} else {
		if(c=='\n'){
			return NEWLINE;
		}
	}
	int i = 0;
	char * word = malloc(sizeof(char)*(*offset-orig_offset));
	memset(word, 0, *offset-orig_offset);
	if(0!=fseek(fp, orig_offset, SEEK_SET))
	{
		printf("fseek failed");
		return 0;
	}
	for(i=0;i<(*offset-orig_offset);i++){
		*(word+i)=fgetc(fp);
	}
	printf("%s\n", word);
	return word;

}

void replace(FILE * fp, long offset, char * word){
	FILE * fp_dictionary = fopen("dictionary.txt", "r");
	long dictionary_offset = 0;
	char * dictionary_word;
	while(*dictionary_word != EOF){
		dictionary_word = get_word(fp_dictionary ,&dictionary_offset);
		++dictionary_offset;
		if(*dictionary_word == *word){
			dictionary_word = get_word(fp_dictionary, &dictionary_offset);
			printf("can replace with: %s\n", dictionary_word);
			++dictionary_offset;
		}
	}
}

int main(int argc, char * argv[]){
	FILE * fp = fopen("input.txt", "r");
	long offset=0;
	char * word = get_word(fp, &offset);
	replace(fp, &offset, word);
	printf("%d\n", offset);
	return 0;
}
