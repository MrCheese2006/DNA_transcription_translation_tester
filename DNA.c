# include "stdio.h"
# include "stdlib.h"
# include "string.h"

char ** DNA_code_generator() {
    // a function that generates a random gene from the DNA code strand
}

char ** DNA_template_generator() {
    // a function that generates a random gene from the DNA template strand
}

char ** mRNA_from_code_ans() {
    // generates the mRNA strand given a DNA code strand
}

char ** mRNA_from_template_ans() {
    // generates the mRNA strand given a DNA template strand
}

int compare_transcription() {
    // compares the generated mRNA strand answer with the user-inputted mRNA strand
}

int DNA_tester() {

    int start = 1;
    int cont;

    while (start == 1 || cont == 1){

        start = 0;

        int mode = rand() % 3; // get either 0, 1 or 2 for 3 transcription from template, transcription from code and translation to AA's

        if (mode == 0) { // transcription from template


            char * template = * DNA_template_generator(); // generate the template

            char *mRNA_attempt;
            printf("Enter the transcription of the DNA template: "); scanf("%s", mRNA_attempt); // get the users' attempt at mRNA transcription

            compare_transcription(); // compare the transcription

        }
        else if (mode == 1) {  // transcription from code
            char * code = * DNA_code_generator(); // generate the code

            char *mRNA_attempt;
            printf("Enter the transcription of the DNA code: "); scanf("%s", mRNA_attempt); // get the users' attempt at mRNA transcription

            compare_transcription(); // compare the transcrpition

        }
        else { // translation to AA's

        }

        printf("Would you like to contnue (1/0)?: "); scanf("%d", cont); // check if they want to continue

    }



    return 0;
}

int main() {

    

}