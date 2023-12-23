#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Error\n");
        return;
    }

    // Validation
    Person *existPerson = findPerson(list, firstName, lastName);
    if (existPerson != NULL) {
        printf("Person exist already.\n");
        return;
    }

    // Create new person
    Person *new = (Person *) malloc(sizeof(Person));
    strcpy(new->firstName, firstName);
    strcpy(new->lastName, lastName);
    new->next = NULL;
    new->father = father;
    new->mother = mother;

    // If list is empty
    if (list->first == NULL) {
        list->first = new;
    } else {
        Person *current = list->first;
        // Find last person
        while (current->next != NULL) {
            current = current->next;
        }
        // Push new person to the end of the list
        current->next = new;
    }
}

void printPerson(Person *person) {
    if (person != NULL) {
        printf("Name: %s %s\n", person->firstName, person->lastName);
    }
}

void printWithFamily(List *list, char *firstName, char *lastName) {
    Person *target = findPerson(list, firstName, lastName);

    // No one was found
    if (target == NULL) {
        printf("No one was found.\n");
        return;
    }

    printf("Person: %s %s\n", target->firstName, target->lastName);
    if (target->father != NULL) {
        printf("Father's ");
        printPerson(target->father);
    }
    if (target->mother != NULL) {
        printf("Mother's ");
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

int main() {
    List *familyList = initialList();
    if (familyList == NULL) {
        printf("Error\n");
        return -1;
    }

    int code = -1;
    do {
        char firstName[50];
        char lastName[50];
        char fatherFN[50];
        char fatherLN[50];
        char motherFN[50];
        char motherLN[50];

        printf("1: AddPerson\n");
        printf("2: PrintPerson\n");
        printf("0: Programm end \n");
        scanf("%d", &code);

        if (code < 0 || code > 2) {
            printf("Input wrong\n");
            break; // Go to the start
        }

        switch (code) {
            case 1:
                printf("Firstname: ");
                scanf("%s", firstName);
                printf("Lastname: ");
                scanf("%s", lastName);

                // Find father
                printf("Father's firstname: \n");
                scanf("%s", fatherFN);
                printf("Father's lastname: \n");
                scanf("%s", fatherLN);
                Person *father = findPerson(familyList, fatherFN, fatherLN);

                // Find mother
                printf("Mother's firstname: \n");
                scanf("%s", motherFN);
                printf("Mother's lastname: \n");
                scanf("%s", motherLN);
                Person *mother = findPerson(familyList, motherFN, motherLN);

                // Create Person
                addPerson(familyList, firstName, lastName, father, mother);
                break;

            case 2:
                printf("Firstname: \n");
                scanf("%s", firstName);
                printf("Lastname: \n");
                scanf("%s", lastName);
                printWithFamily(familyList, firstName, lastName);
                break;

            default:
                break;
        }
    } while (code != 0);
    return 0;
}