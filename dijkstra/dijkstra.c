//Samuel Lewright

#include<stdio.h>
#include <stdlib.h>

int cost[20];
int parent[20];
int table[20][20];
int distance[20];
int beenVisited[20];

//finds the minimum distance to a node
int getMinDistance(int nodes){
    int i; 
    int costAtIndex; 
    int currentMin = 1000;
    for (i=0 ; i<nodes; i++)
    {
        if (distance[i] <= currentMin && beenVisited[i] == 0 ){
            currentMin = distance[i]; 
        	costAtIndex = i ;
        }
    }
    cost[costAtIndex] = 0 ;
    return costAtIndex;
}

//finds sum from node to node
int findSum(int nodes){
	int sum=0;
	int i;
    for(i=0; i<nodes; i++){
        sum+=cost[i];
    }
    return sum;
}

//prints final answer, will be looped later based on how many nodes
void printAns(int nodes){
	int i;
	//for each node, print the node number, the parent of that node, and the shortest distance
    for (i=0; i<nodes; i++){
        printf("nodes: %d Parent: %d shortest distance: %d \n", i + 1 , parent[i] , distance[i]);
    }
}

void dijkstra(int S, int nodes){
	int i;
	int traverse = findSum(nodes);
	int minDist;

	//loop as long as there are nodes
	while(traverse > 0){
		minDist = getMinDistance(nodes);

		beenVisited[minDist] = 1;
		cost[minDist] = 0;
		for(i=0; i<nodes; i++){
			if( table[minDist][i] >0){
				if( distance[minDist] + table[minDist][i] < distance[i]){
					distance[i] = distance[minDist] + table[minDist][i];
					parent[i] = minDist + 1;
				}
			}
			//find sum of next node
		}traverse = findSum(nodes);
	}printAns(nodes);
}

int main(){
	int nodes; 
	int i;
	int j;
	int S; //source node

	//ask user to input number of nodes
	printf("Enter number of nodes: ");
    scanf("%d", &nodes) ;

    //ask user to fill the array with values one by one
    for(i=0; i<nodes; i++) {
      for(j=0;j<nodes;j++) {
         printf("Enter value for index[%d][%d]:", i, j);
         scanf("%d", &table[i][j]);
      }
    }

    //reset all values before performing dijkstra
    for(i=0; i<nodes; i++){
	    distance[i] = 1000;
	    beenVisited[i] = 0;
	    cost[i] = 1;
	    parent[i] = -1;
	}

	printf ("Enter the source node: ");
	scanf("%d", &S);
	distance[S - 1] = 0;
	//perform dijkstra with source S and number of nodes entered
	dijkstra(S, nodes);
	return 0;
}
