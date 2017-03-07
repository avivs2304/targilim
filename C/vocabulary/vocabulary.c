#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vocabulary.h"

/*
 * 		This program takes an input from command line and finds synonyms from
 * 		a provided dictionary (also from command line).
 *
 * 		The dictionary format is as following:
 *
 * 		word1_option1&word1_option2&word1_option3......&word1_option(n)
 * 		word2_option1&word2_option2&word2_option3......&word2_option(n)
 * 		word3_option1&word3_option2&word3_option3......&word3_option(n)
 *
 * 									etc...
 *
 * 		it separates the synonyms by the uncommon character "&"
 */




/*
 * 		Sets the offset for the next read
 */

void set_fseek(FILE * fp, long orig_offset){
	if(0!=fseek(fp, orig_offset, SEEK_SET))
	{
		printf("fseek failed");
	}
}

/*
 * 		Function returns the next word from a FILE * fp stream.
 */

int get_word(FILE * fp, long * offset, char * word){
	int c = 0;
	long orig_offset = *offset;
	int flag;
	int err = 0;
	set_fseek(fp, orig_offset);
	/* Counts the length of the word */
	while(' ' != (c=fgetc(fp)) && c!=EOF && c!='\n' && c!='&'){
		++*offset;
	}
	if(c==EOF){
		flag = EOF;
	} else {
		if(c=='\n'){
			flag = NEWLINE;
		}
	}
	int i = 0;
	memset(word, 0, *offset-orig_offset);
	set_fseek(fp, orig_offset); /* Back to original offset */

	/* Add the counted amount of chars */
	for(i=0;i<(*offset-orig_offset);i++){
		*(word+i)=fgetc(fp);
	}
	if(flag < 0){
		return flag;
	} else {
		return 0;
	}

}

/*
 * 		Copy all content from file a to file b and closes them.
 */
void copy_from_to(FILE * a, FILE * b){
	int c = 0;
	while(EOF != (c =fgetc(a))){
		fputc(c, b);
	}
	fclose(a);
	fclose(b);
}

/*
 * 		Function checks each word for a synonyms in the dictionary and replaces each word it can.
 */

void scan_and_replace(FILE * fp, FILE * fp_dictionary, FILE * fo){
	long offset = 0;
	long pre_offset = 0;
	int flag=0;
	char * word = malloc(sizeof(char *));
	char * replace_word;
	int * len = 0;
	while(flag != EOF){
		pre_offset=offset;
		/* Get original word */
		flag = get_word(fp, &offset, word);
		/* Find replacement word */
		replace_word = replacement_from_dictionary(fp_dictionary, word, &len);
		if(replace_word != 0){
			/* If we found a replacement word replace, if not the write the original word */
			write_to_file(replace_word, len, fo);
		} else {
			write_to_file(word, (offset-pre_offset), fo);
		}
		++offset;
		memset(word, 0, sizeof(char *));
	}
	fclose(fo);
	fclose(fp);
}

/*
 * 		Writes word in len length to file and adds a space.
 */

void write_to_file(char * replace_word, long len, FILE * fo){
	int i;
	for(i=0;i<len;i++){
		fputc(*(replace_word+i), fo);
	}
	fputc(32, fo);
}

/*
 * 		Function searches through dictionary to find a replacement word.
 */

char * replacement_from_dictionary(FILE * fp_dictionary, char * word, int * len){
	long dictionary_offset = 0;
	char * dictionary_word = malloc(sizeof(char *));
	char * first_dictionary_word = malloc(sizeof(char *));
	int flag = 0;
	int c = 0;
	int fword_offset =0;
	long offset_before =0;
	int word_offset =0;
	/* Go through the whole dictionary */
	while(flag != EOF){
		fword_offset =0;
		word_offset =0;
		memset(first_dictionary_word, 0, sizeof(char *));
		memset(dictionary_word, 0, sizeof(char *));
		offset_before=dictionary_offset;
		flag = get_word(fp_dictionary ,&dictionary_offset, first_dictionary_word);
		/* First word offset */
		fword_offset=(dictionary_offset - offset_before)- fword_offset;
		++dictionary_offset;

		offset_before=dictionary_offset;
		flag = get_word(fp_dictionary, &dictionary_offset, dictionary_word);
		/* Next word offset */
		word_offset = dictionary_offset - offset_before;
		++dictionary_offset;
		offset_before=dictionary_offset;

		if(strcmp(first_dictionary_word,word) == 0){
			/* If first word = original word, replace original with second word (return second word) */
			*len = word_offset;
			return dictionary_word;
		} else {
			while(flag != EOF && flag != NEWLINE){
				if(strcmp(dictionary_word,word)==0){
					/* If other word = original word, replace with first word (return first word) */
					*len = fword_offset;
					return first_dictionary_word;
				}
				memset(dictionary_word, 0, sizeof(char *));
				flag = get_word(fp_dictionary, &dictionary_offset, dictionary_word);
				++dictionary_offset;
				offset_before=dictionary_offset;
			}
			if(strcmp(dictionary_word,word)==0){
				/* If other word = original word, replace with first word (return first word) */
				*len = fword_offset;
				return first_dictionary_word;
			}
		}
	}
	return 0;
}

int main(int argc, char * argv[]){
	FILE * fp = fopen(argv[1], "r");
	FILE * fp_dictionary = fopen(argv[2], "r");
	FILE * fo = fopen("tmp.txt", "w");
	copy_from_to(fp, fo); /* fp gets copied to fo and both get closed. */
	fp = fopen("tmp.txt", "r");
	fo = fopen(argv[1], "w");
	scan_and_replace(fp, fp_dictionary, fo);
	return 0;
}
