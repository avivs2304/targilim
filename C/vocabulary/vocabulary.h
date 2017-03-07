
#ifndef VOCABULARY_H_
#define VOCABULARY_H_

#define NEWLINE -2

char * replacement_from_dictionary(FILE * fp, char * word, int * len);
void write_to_file(char * replace_word, long len, FILE * fo);
void set_fseek(FILE * fp, long orig_offset);
int get_word(FILE * fp, long * offset, char * word);
void copy_from_to(FILE * a, FILE * b);
void scan_and_replace(FILE * fp, FILE * fp_dictionary, FILE * fo);

#endif /* VOCABULARY_H_ */
