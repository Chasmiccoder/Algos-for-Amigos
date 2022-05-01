import pandas as pd
import nltk
# nltk.download("stopwords")
from nltk.corpus import stopwords
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split
from sklearn import naive_bayes
import numpy as np

df = pd.read_csv("./datasets/d04_sentimentAnalysis.csv", names=['timestamp', 'regno', 'review', 'class'], encoding='latin1')
print(df.head())

# Using the TFIDF Vectorizer
stopset = set(stopwords.words('english'))
vectorizer = TfidfVectorizer(use_idf = True, lowercase = True, strip_accents = 'ascii', stop_words = stopset)

y = df['class']
X = vectorizer.fit_transform(df['review'])

print( "Shape of y: ", y.shape )
print( "Shape of X: ", X.shape )


X_train, X_test, y_train, y_test = train_test_split(X, y)

"""
Training the Naive Bayes:
"""
classifier = naive_bayes.MultinomialNB()
classifier.fit(X_train, y_train)


# ra_score = roc_auc_score(y_test, classifier.predict_proba(X_test), multi_class='ovr')
# print("Roc Auc Score: ", ra_score)

i = 0
correct = 0
for review in df['review']:
    studentReview = np.array([review])
    vector = vectorizer.transform(studentReview)
    answerFound = classifier.predict(vector)

    # print("jkabsf  ", df['class'][0] )

    if answerFound[0] == df['class'][i]:
        correct += 1

    i += 1

print("Accuracy:", correct / i)

myReview = np.array(["This was an amazing course!"])
vector = vectorizer.transform(myReview)


print("Prediction: ", classifier.predict(vector) )
# Prediction:  ['1'] => Positive Review!
# As we can see, our prediction was correct! Yay

from sklearn.metrics import ConfusionMatrixDisplay
import matplotlib.pyplot as plt



