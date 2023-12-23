#include "familyList.h"
#include <stdio.h>

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

        printf("1: Add Person\n");
        printf("2: Print Person\n");
        printf("3: Delete Person\n");
        printf("===================\n");
        printf("0: Program end \n");
        scanf("%d", &code);

        if (code < 0 || code > 3) {
            printf("Input wrong\n");
            break; // Go to the start
        }

        if (code) {
            printf("Firstname:");
            scanf("%s", firstName);
            printf("Lastname:");
            scanf("%s", lastName);
        }

        switch (code) {
            case 1:
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
                printWithFamily(familyList, firstName, lastName);
                break;

            case 3:
                deletePerson(familyList, firstName, lastName);
                break;

            default:
                break;
        }
    } while (code != 0);
    return 0;
}