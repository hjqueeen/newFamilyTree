#include "familyList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *initialList() {
    List *list = (List *) malloc(sizeof(List));

    // Memory allocation failure
    if (list == NULL) {
        printf("Memory allocation failure\n");
        return NULL;
    }
    // List initialization
    list->first = NULL;
    return list;
};

Person *findPerson(List *list, char *firstName, char *lastName) {
    if (list == NULL) {
        return NULL;
    }
    // Find person
    Person *current = list->first;
    while (current != NULL) {
        if (strcmp(current->firstName, firstName) == 0 && strcmp(current->lastName, lastName) == 0) {
            return current;
        }
        current = current->next;
    }
    // No one was found
    return NULL;
}

void addPerson(List *list, char *firstName, char *lastName, Person *father, Person *mother) {
    if (list == NULL) {
        printf("Error: List is NULL\n");
        return;
    }

    // Validation
    Person *existPerson = findPerson(list, firstName, lastName);
    if (existPerson != NULL) {
        printf("Person exists already.\n");
        return;
    }

    // Create new person
    Person *new = (Person *) malloc(sizeof(Person));
    strcpy(new->firstName, firstName);
    strcpy(new->lastName, lastName);
    new->father = father;
    new->mother = mother;

    // Set new Person as first
    new->next = list->first;
    list->first = new;
}

void printPerson(Person *person) {
    if (person != NULL) {
        printf("Name: %s %s\n", person->firstName, person->lastName);
    }
}

void printWithFamily(List *list, char *firstName, char *lastName) {
    if (list == NULL) {
        printf("Error: List is NULL\n");
        return;
    }

    Person *target = findPerson(list, firstName, lastName);

    // No one was found
    if (target == NULL) {
        printf("No one was found.\n");
        return;
    }

    printf("Person: %s %s\n", target->firstName, target->lastName);
    if (target->father != NULL) {
        printf("Father - ");
        printPerson(target->father);
    }
    if (target->mother != NULL) {
        printf("Mother - ");
        printPerson(target->mother);
    }
    if (target->father != NULL && target->father->father != NULL) {
        printf("Father of Father - ");
        printPerson(target->father->father);
    }
    if (target->father != NULL && target->father->mother != NULL) {
        printf("Mother of Father - ");
        printPerson(target->father->mother);
    }
    if (target->father != NULL && target->mother->father != NULL) {
        printf("Father of Mother - ");
        printPerson(target->mother->father);
    }
    if (target->father != NULL && target->mother->mother != NULL) {
        printf("Mother of Mother - ");
        printPerson(target->mother->mother);
    }
}

void deletePerson(List *list, char *firstName, char *lastName) {
    if (list == NULL) {
        printf("Error: List is NULL\n");
        return;
    }

    Person *target; // Person to delete
    Person *current = list->first;

    while (current != NULL) {
        // Find person
        if (strcmp(current->next->firstName, firstName) == 0 && strcmp(current->next->lastName, lastName) == 0) {
            // Remove people from the list and delete them
            target = current->next;
            current->next = target->next;
            free(target);
            return;
        }
        current = current->next;
    }
}