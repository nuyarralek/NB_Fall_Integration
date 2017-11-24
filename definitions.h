#ifndef _DEFINITIONS_H
#define _DEFINITIONS_H

#define FILES_TO_READ 2
#define MAX_LENGTH 20
#define MAXSTRING 15  //The maximum number of characters for a string
#define LOCATIONS 12  //The number of cites on i26.

typedef struct city { //stores city info
    char name[MAX_LENGTH];
	char direction[MAX_LENGTH];
	int position;
    struct city *next;
    struct city *prev;
    } city;

typedef struct junction { //stores junction info
    char name[MAX_LENGTH];
    city *nextCity;
	char direction[MAX_LENGTH];
    struct junction *nextJunction;
    } junction;

typedef struct Location{ // location node
        char name[MAXSTRING];
        struct Location *east;
        struct Location *west;
        struct Location *north;
        struct Location *south;
}Location;

typedef struct STACK_ELEMENT {
    char name[40];
    struct STACK_ELEMENT *prev;
} STACK_ELEMENT;

typedef struct STACK {
    STACK_ELEMENT *head;
} STACK;

#endif
//utility
int isaLetter(char letter);
int isaSpace(char letter);
void decap(char *letter);
void capitalize(char *letter);
void sanitizeInput(char input[]);
//g3
void createMap(junction *root);
int citySearch(char name[], city *c, junction *root);
void makePath(junction *root, city *start, city *end, STACK *route);
void printCityList(junction *root);
void userInput(junction *root, city *start, city *end, Location eastWestMap[]);
void swapDirection(city *currentDirection);
void printRoute(STACK *route, city *start, city *end);
void createStack(STACK *s);
void Push(STACK *s, char cityName[]);
struct STACK_ELEMENT Pop(STACK *s);
struct STACK_ELEMENT Peek(STACK *s);
//g4
Location initializeMap(Location map[]);
int inputCheck(char input[], Location Map[]);
void searchRoute(char *From, char *To, Location cities[]);

