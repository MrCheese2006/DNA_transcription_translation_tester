# DNA Transcription and Translation Tester

Welcome to my DNA Transcription and Translation Tester! This is a program that generates random DNA and mRNA sequences to you practice transcription and translation. To use, after download and run ```DNA.c```. This was made in C because I needed the practice.

## How to Use

After running the code, you will be presented with a welcome message and either a prompt to transcribe a DNA sequence or translate an mRNA sequence. DNA template sequences are given in the 3' to 5' direction, DNA code sequences in the 5' to 3' direction, and mRNA sequences in the 5' to 3' direction. Enter the transcription or translation (as appropriate) into the terminal where prompted and press enter. All inputs should be in capital letters and spaces should be placed between codons/amino acids. Please use the single-letter short-forms for amino acids (ex. use M instead of Met for the codon AUG). If your input is correct, you will be asked if you would like to continue, please enter a 1 to continue or a 0 to stop. If the input is incorrect, the correct sequence will be printed to the terminal, and the same "continue" prompt will appear. Prompts are chosen randomly.

An image of the AA codon wheel is included in the repository named ```AA_Codon_Wheel.png```.

Let me know if you find any errors!

## Example Run

1. The welcome message is printed, and the first prompt appears. In this case, you are asked to transcribe a DNA code strand.

```
Welcome to my DNA transcription and translation tester!

 - This code allows you to test your ability to transcribe DNA sequences (both template and coding strands) into mRNA sequences, as well as translate mRNA sequences to amino acid (AA) polypeptide sequences.

How the game works:
 - At random, you will be given a DNA coding or template strand or an mRNA sequence, which respectively need to be transcribed into an mRNA sequence or AA chain. Spaces should be included between codons/AA's, and all inputs should be in uppercase. For amino acids, please use the single-letter short forms only (ex. mRNA sequence: AUG --> AA chain: M)

Here is a DNA gene (code strand):        ATG GGC CCC TGA
Enter the transcription of the DNA code: 
```

2. At the prompt, enter your transcription of the DNA code in capital letters with spaces separating the codons:

```
Enter the transcription of the DNA code: AUG GGC CCC UGA

Correct!
Would you like to continue (enter 1 or 0)?
```

The response was correct (yay!) and you're asked if you wish to continue.

3. Enter 1 to continue or 0 to not continue. 1 is chosen in this example.

```
Would you like to continue (enter 1 or 0)? 1

Here is a DNA gene (code strand):        ATG GCG CCG TAG
Enter the transcription of the DNA code:
```

4. The process repeats. In this case, we are asked to transcribe a DNA code sequence again.

```
Enter the transcription of the DNA code: AUG GCG CCG UAG

Correct!
Would you like to continue (enter 1 or 0)? 1

Here is an mRNA strand:                           AUG AAA ACC GUU AAU UAA
Enter the translation of the mRNA strand to AA's:  
```

A correct response and selecting to continue is shown above.

5. We are now asked to translate an mRNA strand to an amino acid chain. Our response is entered (in all capital letters, with spaces between each amino acid, and using the one-letter short-form for each amino acid):

```
Enter the translation of the mRNA strand to AA's: M G H U G

Incorrect. The correct answer is                  M K T V N
Would you like to continue (enter 1 or 0)?  
```

Unfortunately our response is incorrect. The correct response is shown.

6. Entering 0 to stop the code from running, the code terminates.

```
Would you like to continue (enter 1 or 0)? 0

The session is now terminated. Please run the code again to start over.
```
