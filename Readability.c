#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// declaring functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void) 
{
    // get user input
    string text = get_string("Text: ");
    
    // all three variables required for Coleman-liau index
    int letters = count_letters(text);
    int words = count_words(text) + 1;
    int sentences = count_sentences(text);

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    
}

int count_letters(string text)
{
    char text_len[strlen(text)];
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        text_len[i] = text[i];
        if (isalpha(text_len[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    char text_len[strlen(text)];
    int word_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        text_len[i] = text[i];
        if (text_len[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    char text_len[strlen(text)];
    int sentence_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        text_len[i] = text[i];
        if (text_len[i] == '.' | text_len[i] == '?' | text_len[i] == '!')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
