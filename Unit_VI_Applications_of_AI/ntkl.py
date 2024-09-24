import nltk
from nltk.tokenize import word_tokenize
from nltk import pos_tag

# Uncomment the following lines to download necessary NLTK resources if you haven't already done so
# nltk.download('punkt')  # For tokenization
# nltk.download('averaged_perceptron_tagger')  # For part-of-speech tagging

# Sample text
text = "Hello there! How are you doing today?"

# Tokenizing the text
tokens = word_tokenize(text)
print("Tokens:", tokens)

# Part-of-speech tagging
tagged = pos_tag(tokens)
print("Tagged:", tagged)
