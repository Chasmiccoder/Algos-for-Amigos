# Generate all subsets of a set
K = []
def generateSubsets(A):
    P = []
    K.append([])
    f(A,0,P)

def f(A,i,P):
    if i >= len(A):
        return
    K.append(P)
    f(A,i+1,list(P))
    
    P.append(A[i])
    f(A,i+1,list(P))


A = [1,2,3]
generateSubsets(A)
print(K)
