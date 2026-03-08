# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

int start() {

    srand(time(NULL)); // seed the code so rand() produces a new number each time

    printf("\nWelcome to my DNA transcription and translation tester!\n\n");
    printf("   - This code allows you to test your ability to transcribe DNA sequences (both template and coding strands) into mRNA sequences, as well as translate mRNA sequences to amino acid (AA) polypeptide sequences.\n\n");

    printf("How the game works:\n");
    printf("   - At random, you will be given a DNA coding or template strand or an mRNA sequence, which respectively need to be transcribed into an mRNA sequence or AA chain. Spaces should be included between codons/AA's, and all inputs should be in uppercase. For amino acids, please use the single-letter short forms only (ex. AUG --> M, not Met).\n");
    printf("   - DNA template sequences are given in the 3' to 5' direction, DNA code sequences in the 5' to 3' direction, and mRNA sequences in the 5' to 3' direction.\n\n");
}

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

char *DNA_template_generator() {
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

char *mRNA_generator() {
    // generate and mRNA strand for AA translation

    int multiplier = (rand() % 6) + 3; // have 3-8 codons in the string
    int size = 4 * multiplier - 1; // (3 bases + space) * number _of_codons - no_space_at_end = size of string
    char *mRNA = (char *)malloc(size+1);
    *(mRNA + size) = '\0';

    // start codon
    *(mRNA + 0) = 'A';
    *(mRNA + 1) = 'U';
    *(mRNA + 2) = 'G';
    

    int len = strlen(mRNA);

    int mode;
    int i = 3;

    for (i; i <= len - 3; i++) {
        
        if ((i+1) % 4 ==  0 & i != 0) { // break the sequence into codons
            *(mRNA + i) = ' ';
            continue;
        }

        mode = rand() % 4; // get random numbers from 0 to 3

        if (mode == 0) { // select base from random number
            *(mRNA + i) = 'A';
        }
        else if (mode == 1) {
            *(mRNA + i) = 'U';
        } 
        else if (mode == 2) {
            *(mRNA + i) = 'G';
        }    
        else {
            *(mRNA + i) = 'C';
        }
    }

    // stop codon in DNA mRNA
    int stop_mode = rand() % 3; // random numer to choose stop codon
    if (stop_mode == 0) {
        *(mRNA + len-3) = 'U';
        *(mRNA + len-2) = 'A';
        *(mRNA + len-1) = 'A';
    }
    else if (stop_mode == 1) {
        *(mRNA + len-3) = 'U';
        *(mRNA + len-2) = 'A';
        *(mRNA + len-1) = 'G';
    }
    else {
        *(mRNA + len-3) = 'U';
        *(mRNA + len-2) = 'G'; 
        *(mRNA + len-1) = 'A'; 
    }

    return mRNA;
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

char get_AA(char *codon) {

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
                return 's' ; // There is no corresponding AA for the stop codon, just use 's' to represent stop
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

char *get_codon(char *mRNA, int index) {
    char * codon = (char *)malloc(3+1);
    codon[3] = '\0';

    codon[0] = mRNA[index];
    codon[1] = mRNA[index+1];
    codon[2] = mRNA[index+2];

    return codon;
}

char *AA_strand_ans(char *mRNA) {
    // returns the amino acid sequence for a given mRNA strand

    int len = strlen(mRNA);

    char *codon;
    char AA;
    char *AA_strand = (char *)malloc(2*((len+1) / 4 + 1)); // the AA strand needs to be len / 4 because a codon+space takes 4 characters. Add 1 for the null character
    AA_strand[(len+1) / 4] = '\0'; // NULL
    int AA_i = 0;    

    for(int i = 0; i < len; i=i+4) { // increment by codon+space characters each time
        codon = get_codon(mRNA, i); // extract the current codon from the mRNA strand
        AA = get_AA(codon); // get the right AA from the current codon
        if (AA == 's'){
            AA_strand[AA_i-1] = '\0'; // Set NULL
            break; // the AA_strand is done when the stop codon is reached, and there is no AA to be added to the strand for the stop codon
        }
        AA_strand[AA_i] = AA; // Add the AA to the strand
        AA_i++; // increment the AA index
        AA_strand[AA_i] = ' '; // Add a space between AA's
        AA_i++; // increment the AA index
    }

    return AA_strand;
}

int compare_translation(char *AA_strand, char *AA_strand_attempt, int len) {
    // M E G s len = 7 i < len-2

    for (int i = 0; i < len-2; i++) {
        if (AA_strand[i] != AA_strand_attempt[i]){
            return 0;
        }
    }

    return 1;
}

int DNA_tester() {

    start();

    int cont = 1;

    int mode;
    char *template;
    char *code;
    char *mRNA;
    char *mRNA_attempt;
    char *AA_strand;
    char *AA_strand_attempt;
    int len;
    int res;
    // char *cont_str;

    while (cont) {

        printf("---------------------------------------------------------------------------------------------------------------------\n\n");

        mode = rand() % 3; // get either 0, 1 or 2 for 3 transcription from template, transcription from code and translation to AA's

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
            printf("Here is a DNA gene (code strand):        %s\n", code);
            mRNA = mRNA_from_code_ans(code); // generate the answer
            len = strlen(mRNA);
            mRNA_attempt = (char *)malloc(len + 1); // allocate space for input

            printf("Enter the transcription of the DNA code: "); fgets(mRNA_attempt, len+1, stdin); printf("\n"); // get the users' attempt at mRNA transcription

            res = compare_transcription(mRNA, mRNA_attempt); // compare the transcription

            if (res) {
                printf("Correct!\n");
            }
            else {
                printf("Incorrect. The correct answer is     %s\n", mRNA);
            }

            free(code);
            free(mRNA);
            free(mRNA_attempt);

        }
        else { // translation to AA's
            mRNA = mRNA_generator();

            printf("Here is an mRNA strand:                           %s\n", mRNA);
            AA_strand = AA_strand_ans(mRNA); // generate the answer
            len = strlen(AA_strand);
            AA_strand_attempt = (char *)malloc(len + 1); // allocate space for input

            printf("Enter the translation of the mRNA strand to AA's: "); fgets(AA_strand_attempt, len+1, stdin); printf("\n"); // get the users' attempt at mRNA transcription

            res = compare_translation(AA_strand, AA_strand_attempt, len);

            if (res) {
                printf("Correct!\n");
            }
            else {
                printf("Incorrect. The correct answer is                  %s\n", AA_strand);
            }
            
            free(mRNA);
            free(AA_strand);
            free(AA_strand_attempt);
        }

        printf("Would you like to continue (enter 1 or 0)? "); 
        scanf("%d", &cont);
        getchar();
        printf("\n");// check if they want to continue

        // free(cont_str);

    }

    printf("\nThe session is not terminated. Please run the code again to start over.");

    return 0;
}

int main() {

    DNA_tester();

    return 0;
}