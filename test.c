# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

int main() {
    
    int num;

    // printf("Enter number: "); scanf("%d", &num);

    // printf("Your number is %d", num);

    // int *str;

    // scanf("%s", str);

    // printf("%s", str);

    srand(time(NULL)); // seed the code so rand() produces a new number each time
    int multiplier = (rand() % 5) + 2; // have 2-7 codons in the string
    int size = 4 * multiplier - 1; // (3 bases + space) * number _of_codons - no_space_at_end = size of string
    char *str2 = (char *)malloc(size+1);
    *(str2 + size) = '\0';

    // start codon
    *(str2 + 0) = 'T';
    *(str2 + 1) = 'A';
    *(str2 + 2) = 'C';
    

    int len = strlen(str2);

    printf("%d \n", len);

    int mode;
    int i = 3;

    for (i; i <= len - 3; i++) {
        
        if ((i+1) % 4 ==  0 & i != 0) { // break the sequence into codons
            *(str2 + i) = ' ';
            continue;
        }

        mode = rand() % 4; // get random numbers from 0 to 3

        printf("%d \n", mode);

        if (mode == 0) { // select base from random number
            *(str2 + i) = 'A';
        }
        else if (mode == 1) {
            *(str2 + i) = 'T';
        } 
        else if (mode == 2) {
            *(str2 + i) = 'G';
        }    
        else {
            *(str2 + i) = 'C';
        }

    }

    // stop codon in DNA template
    int stop_mode = rand() % 3; // random numer to choose stop codon
    if (stop_mode == 0) {
        *(str2 + len-3) = 'A';
        *(str2 + len-2) = 'T';
        *(str2 + len-1) = 'T';
    }
    else if (stop_mode == 1) {
        *(str2 + len-3) = 'A';
        *(str2 + len-2) = 'T';
        *(str2 + len-1) = 'C';
    }
    else {
        *(str2 + len-3) = 'A';
        *(str2 + len-2) = 'C'; 
        *(str2 + len-1) = 'T'; 
    }


    printf("%s", str2);
    return 0;
}

    // char * code = DNA_code_generator();
    // printf("Code: %s\n", code);
    // char * mRNA_from_code = mRNA_from_code_ans(code);
    // int len = strlen(mRNA_from_code);
    // char * mRNA_code_attempt = (char *)malloc(len + 1);
    // mRNA_code_attempt[strlen(mRNA_from_code)] = '\0';
    // printf("Input the mRNA strand: "); fgets(mRNA_code_attempt, len+1000, stdin); printf("\n");
    // printf("ans: %s\n", mRNA_from_code);
    // printf("%d\n", compare_transcription(mRNA_from_code, mRNA_code_attempt));
    // // char * template = DNA_template_generator();

    // // printf("DNA code: %s\n    mRNA: %s\n", code, mRNA_from_code);

    // char * template = DNA_template_generator();
    // printf("Template: %s\n", template);
    // char * mRNA_from_template = mRNA_from_template_ans(template);
    // char * mRNA_template_attempt = (char *)malloc(strlen(mRNA_from_template) + 1);
    // mRNA_template_attempt[strlen(mRNA_from_template)] = '\0';
    // printf("Input the mRNA strand: "); fgets(mRNA_template_attempt, len+1000, stdin); printf("\n");
    // printf("ans: %s\n", mRNA_from_template);
    // printf("%d\n", compare_transcription(mRNA_from_template, mRNA_template_attempt));

    // // printf("DNA template: %s\n        mRNA: %s\n", template, mRNA_from_template);