from cs50 import get_string

# Get_string
text = get_string("Text: ")

# Iniciate values
n_letters = 0 * 1.0
n_words = 0 * 1.0 + 1.0
n_sentences = 0 * 1.0

# Loop trought the text and count the values
for i in range(len(text)):
    if text[i].isalpha():
        n_letters += 1

for i in range(len(text)):
    if text[i].isspace():
        n_words += 1

for i in range(len(text)):
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        n_sentences += 1

L = n_letters / n_words * 100
S = n_sentences / n_words * 100

# Coleman-Liau formula
N = 0.0588 * L - 0.296 * S - 15.8
grade = round(N)

# Print the result
if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")