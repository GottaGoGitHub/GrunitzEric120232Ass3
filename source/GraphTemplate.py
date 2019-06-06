import math

class GraphTemplate(object):
    _nodes = []             #! list of NodeTemplate ONLY
    _minPriorityQueue = []  #! list of NodeTemplate ONLY

    def __init__():
        pass

    # TODO: implement additional constructors
    # TODO: implement method for adding a node
    # TODO: implement method for removing a node
    # TODO: implement method for sorting the min-priority Queue
    # TODO: implement method for extracting an element from the min-priority Queue
    # TODO: implement Djikstra (in another class)

class NodeTemplate(object):
    label               #! string
    adjacentNodes = {}  #! dict of pairs (NodeTemplate : integer) 
    parent = None       #! reference to NodeTemplate
    distance = math.inf #! number (float)

    def __init__():
        pass

    # TODO: implement additional constructors
    # TODO: implement method for adding a connection
    # TODO: implement method for removing a connection
    # TODO: implement methods for manipulating the parent and distance