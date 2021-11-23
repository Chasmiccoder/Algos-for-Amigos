import time 
start_time = time.time()

from pandas import read_csv
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.neighbors import KNeighborsClassifier


# Loading the Dataset:
df = read_csv( "./datasets/d01_iris.data", header=None )

# Splitting the DataFrame into input and output columns
X, y = df.values[:, :-1], df.values[:, -1]

# To make sure that all data is of floating point values (conversion from str to float)
X = X.astype('float32')

# Encode Strings to integers
y = LabelEncoder().fit_transform(y)
# Member gets encoded as 1, and Casual gets encoded as 0.

# Splitting the dataframe into train and test datasets
# One third of the data is for testing, and two thirds of the data is for training the network
X_train, X_test, y_train, y_test = train_test_split( X, y, test_size=0.33 )

# Verifying the dimensions of the Training and Testing Data:
print( "X_train Shape: ", X_train.shape )
print( "X_test Shape: ", X_test.shape )
print( "y_train Shape: ", y_train.shape )
print( "y_test Shape: ", y_test.shape )

# Taking k as 5
model = KNeighborsClassifier(n_neighbors=5)

model.fit( X_train, y_train )

# Evaluating the model
accuracy = model.score(X_test, y_test)

print( "Model Accuracy: %.4f" % accuracy )

end_time = time.time()
print( "Run Time: %.3f" % (end_time - start_time) )
