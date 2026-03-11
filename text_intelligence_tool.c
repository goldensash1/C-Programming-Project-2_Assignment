#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char word[40];
    int count;
} WordStat;

typedef struct {
    int (*count_words)(char*, char**);
    void (*longest_word)(char*, int);
    void (*most_frequent)(WordStat*, int);
    void (*vowel_density)(char*);
} Analysis;

// Count words
int count_words(char *text, char **words_ptr) {
    int count = 0;
    char *copy = malloc(strlen(text) + 1);
    strcpy(copy, text);
    
    char *token = strtok(copy, " ");
    while (token) {
        count++;
        token = strtok(NULL, " ");
    }
    free(copy);
    return count;
}

// Find longest word
void longest_word(char *text, int word_count) {
    char *copy = malloc(strlen(text) + 1);
    strcpy(copy, text);
    
    char longest[40] = "";
    char *token = strtok(copy, " ");
    while (token) {
        if (strlen(token) > strlen(longest)) {
            strcpy(longest, token);
        }
        token = strtok(NULL, " ");
    }
    printf("Longest Word: %s (Length: %lu)\n", longest, strlen(longest));
    free(copy);
}

// Find most frequent (simple version)
void most_frequent(WordStat *words, int count) {
    int max_count = 0;
    char most_freq[40] = "";
    
    for (int i = 0; i < count; i++) {
        if (words[i].count > max_count) {
            max_count = words[i].count;
            strcpy(most_freq, words[i].word);
        }
    }
    printf("Most Frequent Word: %s (Count: %d)\n", most_freq, max_count);
}

// Custom analysis: Vowel density
void vowel_density(char *text) {
    int vowels = 0, total = 0;
    for (int i = 0; text[i]; i++) {
        char c = tolower(text[i]);
        if (isalpha(c)) {
            total++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            }
        }
    }
    printf("Vowel Density: %.2f%%\n", (total > 0) ? (vowels * 100.0 / total) : 0);
}

void show_menu() {
    printf("\n=== Text Analysis Tool ===\n");
    printf("1. Count Words\n");
    printf("2. Find Longest Word\n");
    printf("3. Most Frequent Word\n");
    printf("4. Vowel Density Analysis\n");
    printf("5. Exit\n");
    printf("Choose: ");
}

int main() {
    char text[500];
    WordStat words[100];
    int choice;
    
    printf("Enter a paragraph: ");
    fgets(text, sizeof(text), stdin);
    
    printf("\nText stored at memory address: %p\n", (void*)text);
    printf("WordStat array at memory address: %p\n\n", (void*)words);
    
    Analysis ops = {count_words, longest_word, most_frequent, vowel_density};
    
    while (1) {
        show_menu();
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1: {
                int count = ops.count_words(text, NULL);
                printf("Total Words: %d\n\n", count);
                break;
            }
            case 2:
                ops.longest_word(text, 0);
                printf("\n");
                break;
            case 3: {
                // Simple frequency count
                char *copy = malloc(strlen(text) + 1);
                strcpy(copy, text);
                int count = 0;
                char *token = strtok(copy, " ");
                while (token && count < 100) {
                    strcpy(words[count].word, token);
                    words[count].count = 1;
                    count++;
                    token = strtok(NULL, " ");
                }
                ops.most_frequent(words, count);
                free(copy);
                printf("\n");
                break;
            }
            case 4:
                ops.vowel_density(text);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

