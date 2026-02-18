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

int compare_transcription(char *mRNA, char *input) {
    // compares the generated mRNA strand answer with the user-inputted mRNA strand

    int len_mRNA = strlen(mRNA);

    for (int i = 0; i < len_mRNA; i++) {
        if (mRNA[i] != input[i]) {
            return 0;
        }
    }

    return 1;

}

char AA_translator(char *codon) {

    if (codon[0] == 'A') {
        if (codon[1] == 'A') {
            if (codon[2] ==  'A') {
                return 'K';
            }
            else if (codon[2] ==  'G') {
                return 'K';
            }
            else if (codon[2] ==  'U') {
                return 'N';
            }
            else { // C
                return 'N';
            }
        }
        else if (codon[1] == 'G') {
            if (codon[2] ==  'A') {
                return 'R';
            }
            else if (codon[2] ==  'G') {
                return 'R';
            }
            else if (codon[2] ==  'U') {
                return 'S';
            }
            else { // C
                return 'S';
            }
        }
        else if (codon[1] == 'U') {
            if (codon[2] ==  'A') {
                return 'I';
            }
            else if (codon[2] ==  'G') {
                return 'M';
            }
            else if (codon[2] ==  'U') {
                return 'I';
            }
            else { // C
                return 'I';
            }            
        }
        else { // C
            return 'T'; // AC_ all return C
        }
    }
    else if (codon[0] == 'G') {
        if (codon[1] == 'A') {
            if (codon[2] ==  'A') {
                return 'E';
            }
            else if (codon[2] ==  'G') {
                return 'E';
            }
            else if (codon[2] ==  'U') {
                return 'D';
            }
            else { // C
                return 'D';
            }
        }
        else if (codon[1] == 'G') {
            return 'G'; // all GG_ return G        
        }
        else if (codon[1] == 'U') {
            return 'V'; // all GU_ return V       
        }
        else { // C
            return 'A'; // all GC_ return A     
        }
    }
    else if (codon[0] == 'U') {
        if (codon[1] == 'A') {
            if (codon[2] ==  'A') {
                return 's'; // s = stop
            }
            else if (codon[2] ==  'G') {
                return 's'; // s = stop
            }
            else if (codon[2] ==  'U') {
                return 'Y';
            }
            else { // C
                return 'Y';
            }
        }
        else if (codon[1] == 'G') {
            if (codon[2] ==  'A') {
                return 's'; // s = stop
            }
            else if (codon[2] ==  'G') {
                return 'W';
            }
            else if (codon[2] ==  'U') {
                return 'C';
            }
            else { // C
                return 'C';
            }            
        }
        else if (codon[1] == 'U') {
            if (codon[2] ==  'A') {
                return 'L';
            }
            else if (codon[2] ==  'G') {
                return 'L';
            }
            else if (codon[2] ==  'U') {
                return 'F';
            }
            else { // C
                return 'F';
            }            
        }
        else { // C
            return 'S'; // all UC_ return S
        }
    }
    else { // C
        if (codon[1] == 'A') {
            if (codon[2] ==  'A') {
                return 'Q';
            }
            else if (codon[2] ==  'G') {
                return 'Q';
            }
            else if (codon[2] ==  'U') {
                return 'H';
            }
            else { // C
                return 'H';                
            }
        }
        else if (codon[1] == 'G') {
            return 'R';
        }
        else if (codon[1] == 'U') {
            return 'L'; // all CU_ return L
        }
        else { // C
            return 'P'; // all CC_ return P
        }
    }

}

int DNA_tester() {

    int cont = 1;

    int mode;
    char *template;
    char *code;
    char *mRNA;
    char *mRNA_attempt;
    int len;
    int res;
    // char *cont_str;

    while (cont) {

        mode = rand() % 2; // get either 0, 1 or 2 for 3 transcription from template, transcription from code and translation to AA's
        printf("%d\n", mode);

        if (mode == 0) { // transcription from DNA template strand

            template = DNA_template_generator(); // generate the template
            printf("Here is a DNA gene (template strand). Enter the transcription: %s\n", template);
            mRNA = mRNA_from_template_ans(template); // generate the answer
            len = strlen(mRNA);
            mRNA_attempt = (char *)malloc(len + 1); // allocate space for input

            printf("Enter the transcription of the DNA template:                   "); fgets(mRNA_attempt, len+1, stdin); printf("\n"); // get the users' attempt at mRNA transcription

            res = compare_transcription(mRNA, mRNA_attempt); // compare the transcription

            if (res) {
                printf("Correct!\n");
            }
            else {
            printf("Incorrect. The correct answer is                               %s\n", mRNA);
            }

            free(template);
            free(mRNA);
            free(mRNA_attempt);

        }
        else if (mode == 1) {  // transcription from DNA code strand

            code = DNA_code_generator(); // generate the code
            printf("Here is a DNA gene (code strand). Enter the transcription: %s\n", code);
            mRNA = mRNA_from_code_ans(code); // generate the answer
            len = strlen(mRNA);
            mRNA_attempt = (char *)malloc(len + 1); // allocate space for input

            printf("Enter the transcription of the DNA code:                   "); fgets(mRNA_attempt, len+1, stdin); printf("\n"); // get the users' attempt at mRNA transcription

            res = compare_transcription(mRNA, mRNA_attempt); // compare the transcription

            if (res) {
                printf("Correct!\n");
            }
            else {
                printf("Incorrect. The correct answer is                           %s\n", mRNA);
            }

            free(code);
            free(mRNA);
            free(mRNA_attempt);

        }
        else { // translation to AA's

        }

        // cont_str = (char *)malloc(100);

        printf("Would you like to continue (enter 1 or 0)? "); 
        scanf("%d", &cont);
        getchar();
        printf("\n"); // get the users' attempt at mRNA transcription // check if they want to continue

        // free(cont_str);

    }

    printf("Session Terminated. Please run code again to start over.");

    return 0;
}

int main() {

    srand(time(NULL)); // seed the code so rand() produces a new number each time

    DNA_tester();

    return 0;
}