import time
import csv
import random
import matplotlib.pyplot as plt

start_time = time.time()

csv_file = open( "./datasets/d01_iris.data" )
csv_reader = csv.reader( csv_file, delimiter = ',' )

dataset  = [ ]
classes = { 'Iris-setosa' : 1, 'Iris-versicolor' : 2, 'Iris-virginica' : 3 }

for row in csv_reader:
    datapoint = row

    if datapoint != []:
        # Encoding the classes as numbers
        datapoint[-1] = classes[datapoint[-1]]
        dataset.append( row )

print( "\nDataset Successfully Incorporated!" )

# Perform datapreprocessing
print( "\nPerforming Datapreprocessing\n" + "=" * 28 + "\n" )
 

# Converting all datapoints to integer
print( "Converting datapoints to numerical values" )
dataset = [ [float(i) for i in datapoint] for datapoint in dataset ]


print( "Shuffling the Dataset" )
random.shuffle( dataset )

print( "Extracting Features and Labels" )
new_dataset = []
classes = []

for i in range(len(dataset)):
    datapoint = dataset[i]
    new_dataset += [datapoint[:-1]]
    classes += [datapoint[-1]]

dataset = list(new_dataset)

print( "Preparing the model" )
train_size = 100
test_size = len(dataset) - train_size

X_test = dataset[ len(dataset) - test_size : ]
y_test = classes[ len(dataset) - test_size : ]

X_train = dataset[ : train_size ]
y_train = classes[ : train_size ]


predicted_classes = []

print( "\nTesting the model!" )

def distance( point1, point2 ):
    """
    Euclidean Distance
    """
    distance = 0
    for i in range( len(point1) ):
        distance += ( point1[i] - point2[i] ) ** 2
    return distance ** 0.5


def predict(point, X_train, y_train, K):
    train_size = len(X_train)

    list_of_classes   = []
    list_of_distances = []
    for j in range( train_size ):
        d = distance( point, X_train[j] )
        
        voting_class = y_train[j]
        list_of_distances.append( d )
        list_of_classes.append( voting_class )

    list_of_classes = [ x for _,x in sorted(zip(list_of_distances, list_of_classes)) ]

    K_least_classes = list_of_classes[ : K ]

    iris_setosa = 0
    iris_versicolour = 0
    iris_virginica = 0

    for vote in K_least_classes:
        if vote == 1:
            iris_setosa += 1
        elif vote == 2:
            iris_versicolour += 1
        else:
            iris_virginica += 1

    if iris_setosa > iris_versicolour and iris_setosa > iris_virginica:
        return 1
    elif iris_versicolour > iris_setosa and iris_versicolour > iris_virginica:
        return 2
    else:
        return 3


def test_model(X_test,y_test, X_train, y_train, K):
    test_size = len(y_test)
    predicted_classes = []

    for i in range( test_size ):
        prediction = predict(X_test[i], X_train, y_train, K)
        predicted_classes.append( prediction )
        
    correct_predictions = 0
    total_predictions = len( y_test )

    for i in range( total_predictions ):
        if y_test[i] == predicted_classes[i]:
            correct_predictions += 1

    accuracy = correct_predictions / total_predictions
    return accuracy

# Testing the model's performance with various values of K
K_vals = [x for x in range(3,50)]

model_accuracies = []
max_acc = 0
best_K = 1

for k in K_vals:
    acc = test_model( X_test, y_test, X_train, y_train, k )
    model_accuracies += [acc]

    if acc > max_acc:
        max_acc = acc
        best_K = k

print( "Best k value: %d which gave an accuracy of: %.3f" % (best_K, max_acc) )

plt.plot(K_vals, model_accuracies)
plt.title("Homemade KNN Accuracy vs. K")
plt.xlim(0,60)
plt.ylim(0.6,1)
plt.show()

end_time = time.time()
print( "Run Time: %.3f seconds" % (end_time - start_time) )