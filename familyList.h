#ifndef FAMILYTREE_FAMILYLIST_H
#define FAMILYTREE_FAMILYLIST_H

typedef struct Person {
    char firstName[50];
    char lastName[50];
    struct Person *father;
    struct Person *mother;
    struct Person *next;
} Person;

typedef struct List {
    Person *first;
} List;

List *initialList();

Person *findPerson(List *list, char *firstName, char *lastName);

void addPerson(List *list, char *firstName, char *lastName, Person *father, Person *mother);

void printPerson(Person *person);

void printWithFamily(List *list, char *firstName, char *lastName);

void deletePerson(List *list, char *firstName, char *lastName);


#endif //FAMILYTREE_FAMILYLIST_H