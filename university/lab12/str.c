#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int isLetters(char* word);

int main()
{
    char words[200];
    char word[40];
    int countLetters = 0, start = 0;
    int i;
 
    gets(words);

    for (i = 0; i < strlen(words); i++) {
        
        if (isspace(words[i]) || i == strlen(words) - 1) {
            if (i != strlen(words) - 1)
                words[i] = '\0';

            strcpy(word, words + start);
            
            if (isLetters(word))
                printf("Word: %15s Adress: %p\n", word, &word);
            
            words[i] = ' ';
            word[0] = '\0';
            start = i + 1;
            countLetters = 0;
        }
    }
}

int isLetters(char* word)
{
    int wordLength = strlen(word);
    for(int i = 0; i < wordLength; i++)
        if (word[i] == 'A' || word[i] == 'a')
            for(int j = 0; j < wordLength; j++)
                if (word[j] == 'B' || word[j] == 'b')
                    return 1;
    return 0;
}