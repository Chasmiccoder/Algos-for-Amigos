"""
Machine Learning Task - 
Binary Classification of Bike Sharing Service Data, after appropriate Data Processing

We will be Using Multilayer Perceptron for this Binary Classification
A Multilayer Perceptron is a feedforward Artificial Neural Network
Algorithm Implemented with Libraries
"""
import time 
start_time = time.time()

from pandas import read_csv
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense

"""
Steps to Creating the Neural Network Model:
1) Define the Model
2) Compile
3) Fit
4) Evaluate
5) Make Prediction
"""

# Loading the Dataset:
path = "p2_Bike_Data.csv"
df = read_csv( path, header=None )

print(" Before Data Preprocessing ")
print( df.head() )

#Remove First Row
df = df[1:]

# Deleting the Column 'Start date' and 'End date' since the date and time are irrelevant.
# The 'Duration', however, is important.
df.drop( 1, inplace=True, axis=1 )
df.drop( 2, inplace=True, axis=1 )

# Deleting the Columns with the names of the stations, since the names are not important.
# The Station Numbers, are important.
df.drop( 4, inplace=True, axis=1 )
df.drop( 6, inplace=True, axis=1 )

# Changing column names to something more appropriate
df.columns = [ "duration", "start_station", "end_station", "bike_number", "class" ]

# Working on a smaller dataset first
df = df[:1000]


for i in range( 1, len(df) ):
    string = df['bike_number'][i]

    if string[0] == "W":
        df['bike_number'] = string[1:]

print( "After Data Preprocessing" )
print( df.head() )

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

# Defining the Sequential Model
"""
The Sequential Model Involves defining a Sequential Class and adding
layers to the model one by one in a linear manner, from input to output.
Our network will have one hidden layer, with 10 nodes.
The output layer will have 1 node, to predict the class.
The expected input is a vector (n by 1 matrix) with number of
elements equal to num_features.

To add more hidden layers, just use:
model.add( Dense(x) ) 
Where x is the number of nodes in that hidden layer.
"""
num_features = X_train.shape[1]
num_nodes_in_hidden_layer_1 = 10
num_nodes_in_hidden_layer_2 = 8
num_nodes_in_output_layer = 1

model = Sequential( )

model.add( Dense( num_nodes_in_hidden_layer_1, activation='relu', 
                  kernel_initializer='he_normal', input_shape=(num_features,) ) )

model.add( Dense( num_nodes_in_hidden_layer_2, activation='relu', 
                  kernel_initializer='he_normal', input_shape=(num_features,) ) )

model.add( Dense( num_nodes_in_output_layer, activation='sigmoid' ) )

model.compile( optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'] )

# Hyperparameter Tuning
model.fit( X_train, y_train, epochs=150, batch_size=32, verbose=0 )

# Evaluating the model
loss, acc = model.evaluate( X_test, y_test, verbose=0 )

print( "Model Accuracy: %.4f"%acc )
# Varying from 93 to 96%. Max Accuracy seen: 98.48%

end_time = time.time()
print( "Run Time: ", end_time - start_time )