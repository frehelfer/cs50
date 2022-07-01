#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
// Get Text
  string text = get_string("Text: ");


// Get data from text
  float letters = count_letters(text) * 1.0;
  float words = count_words(text) * 1.0;
  float sentences = count_sentences(text) * 1.0;

// Coleman-Liau Formula
  float index = 0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8;
  int grade = round(index);

// Print Result
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



// Function count letters
int count_letters(string text)
{
  int letters = 0;

  for (int i = 0, len = strlen(text); i < len; i++)
  {
    if (isalpha(text[i]))
    {
      letters++;
    }
  }
  return letters;
}



// Function Count Words
int count_words(string text)
{
  int words = 1;

  for (int i = 0, len = strlen(text); i < len; i++)
  {
    if (isspace(text[i]))
    {
      words++;
    }
  }

  return words;
}



// Funtion count Sentences
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
      if (text[i] == '.' || text[i] == '!' || text[i] == '?')
      {
        sentences++;
       }
    }

    return sentences;
}