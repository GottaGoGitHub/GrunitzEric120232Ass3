#include <vector>
#include <string>
#include <map>

class GraphTemplate {
private:
    std::vector<NodeTemplate> nodes;
    std::vector<NodeTemplate> minPriorityQueue;

public:
    GraphTemplate(/* args */);
    ~GraphTemplate();

    GraphTemplate(NodeTemplate node):
    nodes{node}, minPriorityQueue{node}{}

    void addNode(NodeTemplate node){
        nodes.push_back(node);
        minPriorityQueue.push_back(node);
        for(int i = 0; i < minPriorityQueue.size; i++){
            if(minPriorityQueue.data[i] > minPriorityQueue.data[i+1]){
                NodeTemplate temp = minPriorityQueue[i];
                minPriorityQueue[i] = minPriorityQueue[i+1];
                minPriorityQueue[i] = temp;
            }
        }
    }
    void removeNode(NodeTemplate node){
        //could not quite figure out, how that is supposed to work
    }
    void insertionSort(int arr[], int n)  
    {  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
            }  
        arr[j + 1] = key;  
        }  
    }
    void extractFromQueue(){
        
        minPriorityQueue.pop_back();

    }
    // TODO: implement Djikstra (in another class)
};

class NodeTemplate {
private:
    int data_;
    std::string label;
    std::map<NodeTemplate, int> adjacentNodes;
    NodeTemplate *parent_;
    int distance;

public:
    NodeTemplate(/* args */);
    ~NodeTemplate();
    
    NodeTemplate(int data):
        data_{data}, label{"first node"} {} 
    NodeTemplate(int data, std::string name):
        data_{data}, label{name}{}
    NodeTemplate(int data, std::string name, std::map<NodeTemplate, int> adjNodes):
        data_{data}, label{name}, adjacentNodes{adjNodes}{}
        
    void addConnection(NodeTemplate one, NodeTemplate two, int weight){
        one.adjacentNodes.insert_or_assign(two, weight);
        two.adjacentNodes.insert_or_assign(one, weight);
    }
    void removeConnection(NodeTemplate one, NodeTemplate two){
        one.adjacentNodes.erase(two);
        two.adjacentNodes.erase(one);
    }
    void changeParent(NodeTemplate one, NodeTemplate *newparent){
        one.parent_ = newparent;
    }
    void changeDistance(NodeTemplate one, int newdistance){
        one.distance  = newdistance;
    }
};

//I got confused by the Graph and Node Layout and i couldnt figure out how to implement djikstra with is, so i decided to use my own on in main.hpp
