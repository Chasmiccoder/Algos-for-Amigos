"""
Machine Learning Task - 
Binary Classification of Bike Sharing Service Data, after appropriate Data Processing

Using KNN With no libraries to solve the Problem
"""

import time    # To calculate run time
import csv     # To import the dataset
import random  # To shuffle the dataset

start_time = time.time()


def check( ):
    print( ".", end='' )


def print_progress_bar( size ):
    print( " " * size, end='' )
    print( "<-Needs to Reach Here" )


def data_prepocessing( dataset ):
    """
    This function conducts data preprocessing.
    The unique values of start stations, end stations and bike numbers are found and returned.
    Also, the entire dataset, in the form of a dictionary named 'dataframe' is also returned.
    The keys of dataframe involve the classes and the values involve the respective features of those points.

    We also prune the dataset by removing the unnecessary columns like the names of the start stations and
    the names of the end stations.

    Handling Start Date and End Date:
    The exact date they started and ended the bike sharing service does not matter, but the duration
    they used it does matter, so we will extract only the duration, and add it to new_dataset.
    """
    start_station = [ ]
    end_station   = [ ]
    bike_numbers  = [ ]
    new_dataset = [ ]
    classes     = [ ]

    for row in dataset:
        if row[ 7 ][0] == "W":
            row[ 7 ] = row[ 7 ][ 1: ]

        if row[ 3 ] not in start_station:
            start_station.append( row[ 3 ] )
            
        if row[ 5 ] not in end_station:
            end_station.append( row[ 5 ] )

        if row[ 7 ] not in bike_numbers:
            bike_numbers.append( row[ 7 ] )

        new_dataset.append( [ row[0], row[3], row[5], row[7] ] )
          
        if row[ 8 ] == "Member":
            classes.append( 1 )
        else:
            classes.append( 2 )

    return new_dataset, classes, bike_numbers, start_station, end_station


def one_hot_encoding( dataset, feature, feature_index ):
    """
    Will help in accuracy, but needs more computation power.
    """
    new_dataset = [ ]
    for row in dataset:
        for value in feature:
            #print( "TYPE: ", type(row[ feature_index ]), type(value))
            if row[ feature_index ] == value: 
                row.append( 1 )
            else:
                row.append( 0 )
    
        new_dataset.append( row[ : feature_index ] + row[ feature_index+1: ] )
        
    check( )
    return new_dataset


def euclidean_distance( point1, point2 ):
    distance = 0
    for i in range( len(point1) ):
        distance += ( point1[ i ] - point2[ i ] ) ** 2
    
    distance = distance ** 0.5
    return distance


def special_sort( d ):
    """
    Sorts the array d according to the first value of each pair.
    """
    n = len( d )
    
    for i in range( n-1 ):
        for j in range( 0, n-i-1 ):
            if d[ j ][ 0 ] > d[ j+1 ][ 0 ]:
                d[ j ][ 0 ], d[ j+1 ][ 0 ] = d[ j+1 ][ 0 ], d[ j ][ 0 ]
                d[ j ][ 1 ], d[ j+1 ][ 1 ] = d[ j+1 ][ 1 ], d[ j ][ 1 ]


def shuffle_dataset( dataset, datapoints ):
    new_dataset = [ ]

    progress = datapoints / 20   # Simple meter to see how much data has been shuffled
    i = 1

    print_progress_bar( progress )
    check( )
    while( datapoints > len(new_dataset)  ):
        r = random.randint( 0, len(dataset) )
        new_dataset.append( dataset[ r ] )
        dataset = dataset[ : r ] + dataset[ r+1 : ]

        if len(new_dataset) == progress * i:
            check( )
            i += 1

    return new_dataset


"""---MAIN---""" 
csv_file   = open( "Bike_Data.csv" )
csv_reader = csv.reader( csv_file, delimiter = ',' )

line_count = 0
dataset  = [ ]
features = [ ]

for row in csv_reader:
    if line_count == 0:
        features.append( row )
        line_count += 1

    else:
        dataset.append( row )
        line_count += 1 

print( "Dataset successfully incorporated!" )

dataset, classes, bike_numbers, start_station, end_station = data_prepocessing ( dataset )
print( "Data Preprocessing completed successfully!" )

print( "Start Stations: ", len(start_station) )
print( "End Stations: ", len(end_station) )
print( "Bike Numbers: \n", len(bike_numbers) )

print( "Before str to int: " )
for i in range( 0, 3 ):
    print( "Datapoint: ", dataset[ i ] )
    print( "Class: ", classes[ i ] )

# Miracle change, reduced runtime significantly
dataset = [ [ int(i) for i in intermediate ] for intermediate in dataset ]

print( "After str to int: " )
for i in range( 0, 3 ):
    print( "Datapoint: ", dataset[ i ] )
    print( "Class: ", classes[ i ] )

# Implement some sort of shuffle here (on dataset):
print( "Shuffling Dataset: " )

# Change this variable to alter how many datapoints to use.
shuffle_datapoints = 10000
dataset = shuffle_dataset( dataset, shuffle_datapoints )
print( "Dataset has been Shuffled successfully" )

# Trying to predict the class of the last 100 datapoints using the first 100,000 datapoints:
print( "Testing our Algorithm!" )

#Change these 2 variables to play around with the number of datapoints used to train and to test.
train_size = 9000
test_size  = 100
if train_size + test_size > shuffle_datapoints:
    print( "Error!\nDataset not large enough. Increase Shuffle Threshold!" )

K = int( train_size ** 0.5 )
#K = 5

X_test = dataset [ len(dataset) - test_size :  ]
Y_test = classes [ len(classes) - test_size :  ]

X_train = dataset[ : train_size ]
Y_train = classes[ : train_size ]

predicted_classes = [ ]

# One Hot Encoding:
print( )
print( "One Hot Encoding Testing Data: " )
X_test = one_hot_encoding( X_test, start_station, 1 )
print( "Done encoding Start Station!\n" )
X_test = one_hot_encoding( X_test, end_station, 2 )
print( "Done encoding End Station!\n" )
X_test = one_hot_encoding( X_test, bike_numbers, 3 )
print( "Done encoding Bike Numbers!\n" )

print( )
print( "One Hot Encoding Training Data: " )
X_train = one_hot_encoding( X_train, start_station, 1 )
print( "Done encoding Start Station!\n" )
X_train = one_hot_encoding( X_train, end_station, 2 )
print( "Done encoding End Station!\n" )
X_train = one_hot_encoding( X_train, bike_numbers, 3 )
print( "Done encoding Bike Numbers!\n" )

list_of_distances = [ ]
list_of_classes   = [ ]

print_progress_bar( test_size )

for i in range( test_size ):
    for j in range( train_size ):
        distance = euclidean_distance( X_test[ i ], X_train[ j ] )
        voting_class = Y_train[ j ]
        list_of_distances.append( distance )
        list_of_classes.append( voting_class )
    
    #special_sort( list_of_distances )
    # Sorting the list of clases according to the list of distances
    list_of_classes = [ x for _,x in sorted( zip( list_of_distances, list_of_classes) ) ]

    #K_least_distances = list_of_distances[ : K ]
    K_least_classes = list_of_classes[ : K ]

    member = 0
    casual = 0

    for vote in K_least_classes:
        if vote == 1:
            member += 1
        else:
            casual += 1
    
    check( )
    # After implementing One Hot Encoding, the run time for each loop iteration became about 20 seconds.
    # Therfore, time taken to test this (after encoding) = test_size * 20 seconds (appx)
    if casual > member: 
        predicted_classes.append( 2 )

    else:
        predicted_classes.append( 1 )

print( )
correct_predictions = 0
total_predictions = len( Y_test )

for i in range( total_predictions ):
    if Y_test[ i ] == predicted_classes[ i ]:
        correct_predictions += 1


accuracy = correct_predictions / total_predictions
print( "Accuracy of Model: ", accuracy )


"""
We need to implement one hot Encoding to convert categorical integer data into Numeric Data:

Since these are arbitrary numbers, to prevent the model from getting confused, we need to
employ One Hot Encoding. 
For example: If the datapoint's start station is not equal to 31020, then the value under 
start_station_31020 column will be 0. Else it will be 1. 

"""

end_time = time.time()
print( "Run Time: ", end_time - start_time )