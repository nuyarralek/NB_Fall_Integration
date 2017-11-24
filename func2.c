#include <stdio.h>
#include <string.h>
#include "definitions.h"

//functions from Group 4
Location initializeMap(Location map[])
{
        char *eastToWestList[] = {"Sandy","Boring","Gresham","East Portland","i5","West Portland","Sylvan","Beaverton","Tanasbourne","Hillsboro","North Plains","Mountaindale"};
	//Initializing nodes
        for (int i = 0; i< LOCATIONS; i++){
                strcpy(map[i].name,eastToWestList[i]);
                if(i == 0){
                        map[i].east = NULL;
                        map[i].west = &map[1];
                        map[i].south = NULL;
                        map[i].north = NULL;
                }else if(i == 11){
                        map[i].east = &map[10];
                        map[i].west = NULL;
                        map[i].south = NULL;
                        map[i].north = NULL;
                }else{
                        map[i].east = &map[i-1];
                        map[i].west = &map[i+1];;
                        map[i].south = NULL;
                        map[i].north = NULL;
                }
        }

}

// Function which checks user input to make sure it is valid
int inputCheck(char input[], Location Map[])//lookup struct name
{
	for(int i = 0; i < LOCATIONS; ++i)
	{
		if(strcmp(input, Map[i].name) == 0) return 1;
	}

	return 0;
}

// Function which executes the search for route between two cities
void searchRoute(char *From, char *To, Location cities[]){
	int east = 0, e = 0; //  0 implies that eastern side hasn't been traversed yet, 1 implies the opposite
  	int west = 0, w = 0; //  0 implies that western side hasn't been traversed yet, 1 implies the opposite
  	char route[LOCATIONS][MAXSTRING];  // This stores all the cities between origin and destination
	int totalCities = 0;
	int destinationFound = 0; // 0 implies that destination hasn't been found yet, 1 implies the opposite 
  	Location *origin; // Origin

 	for (int i = 0; i < LOCATIONS; i++)
	{
		if (strcmp(From, cities[i].name) == 0)
		{
        		origin = &cities[i];
        		break;
    		}
 	 }

   	while(destinationFound == 0)
	{
     		Location *currentNode;
     		currentNode = origin;

    		while(east == 0)
			{
      			strcpy(route[e], currentNode->name);
				totalCities += 1;

				if (strcmp(currentNode->name, To) == 0)
				{
        			destinationFound = 1;
        			break;
      			}
      			if(currentNode->east == NULL)
				{
        			east = 1;
				//Given destinationFound is 0, if it's an end node, this resets the route list
        			if(destinationFound == 0)
					{
          				for(int a = 0; a < LOCATIONS; a++)
						{
            				for (int b = 0; b < MAXSTRING; b++)
							{
								route[a][b] = '\0';
							}
          				}
        			}

					currentNode = origin;
					totalCities = 0;
        			break;
      			}

      			currentNode = currentNode->east;
      			e += 1;
    		}

    		while(west == 0 && destinationFound == 0)
			{
      			strcpy(route[w], currentNode->name);
				totalCities += 1;

				if (strcmp(currentNode->name, To) == 0)
				{
        			destinationFound = 1;
        			break;
      			}

				if(currentNode->west == NULL)
				{
        			west = 1;
      			}

      			currentNode = currentNode->west;
      			w += 1;
    		}
   	}
	printf("\n");
	printf("Here is the route from %s to %s\n", From, To);
	for(int z = 0; z <totalCities; z++)
	{
		printf("%s    ",route[z]);
	}
	printf("\n");
}
