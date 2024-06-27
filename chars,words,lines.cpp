
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    int characters = 0, words = 0, lines = 0;
    printf("Enter text :\n");

    // Loop to read input until EOF (Ctrl+D in Unix/Linux, Ctrl+Z in Windows)
    while (fgets(input, sizeof(input), stdin) != NULL) {
        lines++; // Increment line count for each line read

        // Loop through each character in the input
        for (int i = 0; input[i] != '\0'; i++) {
            characters++; // Increment character count for each character read

            // Check for word boundary (space, tab, newline, or punctuation)
            if (isspace(input[i]) || ispunct(input[i])) {
                // Increment word count if previous character was part of a word
                if (i > 0 && !isspace(input[i - 1]) && !ispunct(input[i - 1])) {
                    words++;
                }
            }
        }
    }

    // Check if there is a word at the end of the input
    if (characters > 0 && !isspace(input[characters - 1]) && !ispunct(input[characters - 1])) {
        words++;
    }

    // Output the counts
    printf("Number of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);

    return 0;
}

