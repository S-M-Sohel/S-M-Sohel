#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100



typedef struct {
    char name[50];
    int age;
    char address[100];
    char occupation[100];
    int covidVaccine;
    int hepatitisBVaccine;
    int bCGVaccine;
} User;

void saveDataToFile(User users[], int numUsers) {
    FILE *file = fopen("vaccination_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Vaccination Data\n");
    fprintf(file, "----------------\n\n");

    for (int i = 0; i < numUsers; i++) {
        fprintf(file, "Name: %s\n", users[i].name);
        fprintf(file, "Age: %d\n", users[i].age);
        fprintf(file, "Address: %s\n", users[i].address);
        fprintf(file, "Occupation: %s\n", users[i].occupation);
        fprintf(file, "Covid Vaccine doses taken: %d\n", users[i].covidVaccine);
        fprintf(file, "Hepatitis B Vaccine doses taken: %d\n", users[i].hepatitisBVaccine);
        fprintf(file, "BCG Vaccine doses taken: %d\n", users[i].bCGVaccine);
        fprintf(file, "--------------------------------\n\n");
    }

    fclose(file);
    printf("Vaccination data has been saved to vaccination_data.txt.\n");
}

int main() {
    User users[MAX_USERS];
    int numUsers = 0;

    while (1) {
        printf("Vaccine Registration System\n");
        printf("1. Register user\n");
        printf("2. Display all users\n");
        printf("3. Save data to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numUsers == MAX_USERS) {
                    printf("Maximum number of users reached!\n");
                } else {
                    User newUser;
                    printf("Enter name: ");
                    scanf(" %[^\n]", newUser.name);
                    printf("Enter age: ");
                    scanf("%d", &newUser.age);
                    printf("Enter address: ");
                    getchar();
                    fgets(newUser.address, sizeof(newUser.address), stdin);
                    newUser.address[strcspn(newUser.address, "\n")] = '\0';
                    printf("Enter occupation: ");
                    fgets(newUser.occupation, sizeof(newUser.occupation), stdin);
                    newUser.occupation[strcspn(newUser.occupation, "\n")] = '\0';
                    printf("Enter number of doses of Covid Vaccine taken by %s: ", newUser.name);
                    scanf("%d", &newUser.covidVaccine);
                    printf("Enter number of doses of Hepatitis B Vaccine taken by %s: ", newUser.name);
                    scanf("%d", &newUser.hepatitisBVaccine);
                    printf("Enter number of doses of BCG Vaccine taken by %s: ", newUser.name);
                    scanf("%d", &newUser.bCGVaccine);

                    users[numUsers] = newUser;
                    numUsers++;

                    printf("User registered successfully!\n");
                }
                break;

            case 2:
                printf("Registered users:\n");
                for (int i = 0; i < numUsers; i++) {
                    printf("Name: %s\n", users[i].name);
                    printf("Age: %d\n", users[i].age);
                    printf("Address: %s\n", users[i].address);
                    printf("Occupation: %s\n", users[i].occupation);
                    printf("Covid Vaccine doses taken: %d\n", users[i].covidVaccine);
                    printf("Hepatitis B Vaccine doses taken: %d\n", users[i].hepatitisBVaccine);
                    printf("BCG Vaccine doses taken: %d\n", users[i].bCGVaccine);
                    printf("    * * *    \n");
                }
                break;

            case 3:
                saveDataToFile(users, numUsers);
                break;

            case 4:
                printf("Thanks \n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
