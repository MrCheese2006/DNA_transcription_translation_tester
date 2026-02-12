# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

// could implement a "streak tracker"

char *DNA_code_generator() {
    // a function that generates a random gene from DNA

    int multiplier = (rand() % 6) + 3; // have 3-8 codons in the string
    int size = 4 * multiplier - 1; // (3 bases + space) * number _of_codons - no_space_at_end = size of string
    char *code = (char *)malloc(size+1);
    *(code + size) = '\0';

    // start codon
    *(code + 0) = 'A';
    *(code + 1) = 'T';
    *(code + 2) = 'G';
    

    int len = strlen(code);

    int mode;
    int i = 3;

    for (i; i <= len - 3; i++) {
        
        if ((i+1) % 4 ==  0 & i != 0) { // break the sequence into codons
            *(code + i) = ' ';
            continue;
        }

        mode = rand() % 4; // get random numbers from 0 to 3

        if (mode == 0) { // select base from random number
            *(code + i) = 'A';
        }
        else if (mode == 1) {
            *(code + i) = 'T';
        } 
        else if (mode == 2) {
            *(code + i) = 'G';
        }    
        else {
            *(code + i) = 'C';
        }
    }

    // stop codon in DNA code
    int stop_mode = rand() % 3; // random numer to choose stop codon
    if (stop_mode == 0) {
        *(code + len-3) = 'T';
        *(code + len-2) = 'A';
        *(code + len-1) = 'A';
    }
    else if (stop_mode == 1) {
        *(code + len-3) = 'T';
        *(code + len-2) = 'A';
        *(code + len-1) = 'G';
    }
    else {
        *(code + len-3) = 'T';
        *(code + len-2) = 'G'; 
        *(code + len-1) = 'A'; 
    }

    return code;

}

char * DNA_template_generator() {
    // a function that generates a random gene template from DNA

    int multiplier = (rand() % 6) + 3; // have 2-7 codons in the string
    int size = 4 * multiplier - 1; // (3 bases + space) * number _of_codons - no_space_at_end = size of string
    char *template = (char *)malloc(size+1);
    *(template + size) = '\0';

    // start codon
    *(template + 0) = 'T';
    *(template + 1) = 'A';
    *(template + 2) = 'C';
    

    int len = strlen(template);

    int mode;
    int i = 3;

    for (i; i <= len - 3; i++) {
        
        if ((i+1) % 4 ==  0 & i != 0) { // break the sequence into codons
            *(template + i) = ' ';
            continue;
        }

        mode = rand() % 4; // get random numbers from 0 to 3

        if (mode == 0) { // select base from random number
            *(template + i) = 'A';
        }
        else if (mode == 1) {
            *(template + i) = 'T';
        } 
        else if (mode == 2) {
            *(template + i) = 'G';
        }    
        else {
            *(template + i) = 'C';
        }
    }

    // stop codon in DNA template
    int stop_mode = rand() % 3; // random numer to choose stop codon
    if (stop_mode == 0) {
        *(template + len-3) = 'A';
        *(template + len-2) = 'T';
        *(template + len-1) = 'T';
    }
    else if (stop_mode == 1) {
        *(template + len-3) = 'A';
        *(template + len-2) = 'T';
        *(template + len-1) = 'C';
    }
    else {
        *(template + len-3) = 'A';
        *(template + len-2) = 'C'; 
        *(template + len-1) = 'T'; 
    }

    return template;
}

char *mRNA_from_code_ans(char *code) {
    // generates the mRNA strand given a DNA code strand

    int len = strlen(code); // length of coding strand, not including null character

    char *mRNA = (char *)malloc(len+1); // initialize mRNA from code string
    mRNA[len] = '\0';

    for (int i = 0; i < len; i++) {

        if (code[i] == 'T') {
            mRNA[i] = 'U';
        }
        else {
            mRNA[i] = code[i];
        }
    }

    return mRNA;
}

char *mRNA_from_template_ans(char *template) {
    // generates the mRNA strand given a DNA template strand

    int len = strlen(template); // length of coding strand, not including null character

    char *mRNA = (char *)malloc(len+1); // initialize mRNA from code string
    mRNA[len] = '\0';

    for (int i = 0; i < len; i++) {

        if (template[i] == 'A') {
            mRNA[i] = 'U';
        }
        else if (template[i] == 'T') {
            mRNA[i] = 'A';
        }
        else if (template[i] == 'G') {
            mRNA[i] = 'C';
        }
        else if (template[i] == 'C') {
            mRNA[i] = 'G';
        }
        else {
            mRNA[i] = ' ';
        }
    }

    return mRNA;

}

int compare_transcription() {
    // compares the generated mRNA strand answer with the user-inputted mRNA strand
}

int DNA_tester() {

    int cont = 1;

    while (cont) {

        int mode = rand() % 3; // get either 0, 1 or 2 for 3 transcription from template, transcription from code and translation to AA's

        if (mode == 0) { // transcription from DNA template strand

            char * template = DNA_template_generator(); // generate the template

            char *mRNA_attempt;
            printf("Enter the transcription of the DNA template: "); scanf("%s", mRNA_attempt); // get the users' attempt at mRNA transcription

            compare_transcription(); // compare the transcription

        }
        else if (mode == 1) {  // transcription from DNA code strand

            char * code = DNA_code_generator(); // generate the code

            char *mRNA_attempt;
            printf("Enter the transcription of the DNA code: "); scanf("%s", mRNA_attempt); // get the users' attempt at mRNA transcription

            compare_transcription(); // compare the transcription

        }
        else { // translation to AA's

        }

        printf("%s", "Would you like to continue (enter 1 or 0)? "); scanf("%d", cont); // check if they want to continue

        if (!cont) {
            printf("%s", "Session Terminated. Please run code again to start over.");
        }

    }

    return 0;
}

int main() {

    srand(time(NULL)); // seed the code so rand() produces a new number each time

    char * code = DNA_code_generator();
    char * mRNA_from_code = mRNA_from_code_ans(code);
    // char * template = DNA_template_generator();

    printf("DNA code: %s\n    mRNA: %s\n", code, mRNA_from_code);

    char * template = DNA_template_generator();
    char * mRNA_from_template = mRNA_from_template_ans(template);

    printf("DNA template: %s\n        mRNA: %s\n", template, mRNA_from_template);

    return 0;
}