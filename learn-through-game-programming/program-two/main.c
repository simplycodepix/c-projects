/*
* Improve the Word Jumble game by adding a scoring system.
* Make the point value for a word based on its length.
* Deduct points if the player asks for a hint.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 5;
    const char *WORDS[10] = { "wall", "glasses", "labored", "persistent", "jumble" };
    const char *HINTS[10] = { "Do you feel you are banging your head against something?",
                              "These might help you see the answer.", 
                              "Going slowly, is it?", 
                              "Keep at it.", 
                              "It’s what the game is all about." };

    char theWord[20], theHint[100];
    int score = 5;
    strcpy(theWord, WORDS[1]);
    strcpy(theHint, HINTS[0]);

    char jumble[20];
    strcpy(jumble, theWord);

    for(int i = 0; i < strlen(jumble); i++)
    {
        int index1 = (rand() % strlen(jumble));
        int index2 = (rand() % strlen(jumble));
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    printf("\t\tWelcome to Word Jumble\n\n");
    printf("Unscramble the letters to make a word.\n");
    printf("Enter \'hint\' for a hint.\n");
    printf("Enter \'quit\' to quit the game.\n");
    printf("Yout initial score: %d\n", score);
    printf("The jumble is: %s\n", jumble);

    char guess[20];
    printf("Your guess: ");
    fflush(stdin);
    scanf("%s", &guess);

    while(strcmp(guess, theWord) != 0 && strcmp(guess, "quit") != 0)
    {
        if( strcmp(guess, "hint") == 0 ){
            printf("%s\n", theHint);
            score--;
        } else
        {
            printf("Isn't correct. Please try again!\n");
        }

        printf("Your guess: ");
        fflush(stdin);
        scanf("%s", &guess);
    }

    if(strcmp(guess,theWord) == 0){
        printf("Congratulations! You got it\n");
        score++;
    }

    
    printf("Thanks for playing\n");
    printf("Your score: %d", score);
    return 0;

}