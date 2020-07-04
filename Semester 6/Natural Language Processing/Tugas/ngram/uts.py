import nltk
from nltk import *
from nltk.util import ngrams

# Unigram

berkas = open("uts.txt", "r")
kalimat = sent_tokenize(berkas.read())
token = []
for klm in kalimat :
    token.append(word_tokenize(klm))

listunigram = []
for tk in token :
    unigram = ngrams(tk, 1, 
                pad_right = True, 
                pad_left = True, 
                left_pad_symbol = '<s>', 
                right_pad_symbol = '</s>')
    for gram in unigram :
        listunigram.append(gram)

unigram_fd = FreqDist(listunigram)
print("===== Unigram =====")
for key, value in unigram_fd.items() :
    print(key, value)

# Peluang Unigram

kal = "Buah berwarna hijau dan merah"
token = word_tokenize(kal)

p = 1
print("\n===== Peluang Unigram =====")
for kata in token: 
    pkata = unigram_fd.freq((kata,))
    print("p('%s') = %f" %(kata, pkata))
    p = p * pkata

print("Total Peluang = ", p)

# Bigram

berkas = open("uts.txt", "r")
kalimat = sent_tokenize(berkas.read())
token = []
for klm in kalimat :
    token.append(word_tokenize(klm))

listbigram = []
for tk in token :
    bigram = ngrams(tk, 2, 
                pad_right = True, 
                pad_left = True, 
                left_pad_symbol = '<s>', 
                right_pad_symbol = '</s>')
    for gram in bigram :
        listbigram.append(gram)

bigram_fd = FreqDist(listbigram)
print("\n===== Bigram =====")
for key, value in bigram_fd.items() :
    print(key, value)

# Peluang Bigram

# kal = "Buah berwarna hijau dan merah"
# kalimat = sent_tokenize(kal)
# token = []
# for klm in kalimat :
#     token.append(word_tokenize(klm))
# # token = word_tokenize(kal)

# p = 1
# print("\n===== Peluang Bigram =====")
# for kata in token: 
#     bigram = ngrams(kata, 2, 
#                 pad_right = True, 
#                 pad_left = True, 
#                 left_pad_symbol = '<s>', 
#                 right_pad_symbol = '</s>')
#     for gram in bigram :
#         pkata = bigram_fd.freq((gram,))
#         print("P('%s') = %f" %(gram, pkata))
#         p = p * pkata

# print("Total Peluang = ", p)
