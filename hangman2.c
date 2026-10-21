#include <stdio.h>
#include <string.h>
int main( ) {
    char secword[20], temp_sec[20];
    printf("Secret Word: ");
    scanf("%s", secword);
    int seclength = strlen(secword), counter= 0;
    char g_ltr[20] = "", g_word[21], gl;
    int win = 0, choice;
    // Initialize temp_sec with underscores and null-terminate
    for (int i = 0; i < seclength; i++) {
        temp_sec[i] = '_';
    }
    temp_sec[seclength] = '\0';
    do {
        printf("Guess letter: 1 or word: 2,  ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (strlen(g_ltr) < seclength) {
                    scanf(" %c", &gl);
                    strncat(g_ltr, &gl,1);
                    for (int i = 0; i < seclength; i++) {
                        if (gl == secword[i]) {
                            temp_sec[i] = gl;
                            counter++;
                        }
                    }
                    if (counter == seclength) {
                        printf("WINNER!\n");
                        printf("%s\n", temp_sec);
                        win=1;
                    } else  {
                        printf("%s\n", temp_sec);
                    }
                } else {
                    printf("LOST...\n");
                    win=2;
                }
                break;
            case 2:
                printf("GUESS WORD (ONE CHANCE!!) :");
                scanf("%s", g_word);
                if ( strcmp( g_word, secword) == 0 ) {
                    printf("WINNER. (%s)", secword);
                    win=1;
                }
                break;
        }
    } while (win == 0);
    return 0;
}