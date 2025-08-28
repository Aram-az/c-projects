#include <stdio.h>
#include <string.h>

struct Contact {
        char name[50];
        char phone[15];
        char email[50];
    };

void savefile(int count, struct Contact Contacts[]) {
    FILE*fp;
    fp = fopen("Contacts.txt", "w");
    if (fp != NULL) {
        for (int i = 0; i < count; i++) {
            fprintf(fp, "%s|%s|%s\n", Contacts[i].name, Contacts[i].phone, Contacts[i].email);
        }
    }
    else {
        printf("File Could Not Be Opened.\n");
        return;
    }
    fclose(fp);
}

int openfile(struct Contact Contacts[]) {
    int count = 0;
    char line[120];
    FILE*fp;
    fp = fopen("Contacts.txt", "r");
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp) != NULL && count < 100) {
            line[strcspn(line, "\n")] = '\0';
            strcpy(Contacts[count].name, strtok(line, "|"));
            strcpy(Contacts[count].phone, strtok(NULL, "|"));
            strcpy(Contacts[count].email, strtok(NULL, ""));
            printf("Name: %s, Phone: %s, Email: %s\n", Contacts[count].name, Contacts[count].phone, Contacts[count].email);
            count++;
        }
        printf("File Content is Loaded!\n");
    }
    else {
        printf("File Could Not Be Opened.\n");
        return 0;
    }
    fclose(fp);
    return count;
}


int main() {
    struct Contact Contacts[100];
    int count = 0;
while(1) {
    int choice;
    printf("Please select one of the menu options:\n");
    printf("1: Add New Contact\n");
    printf("2: View All Contacts\n");
    printf("3: Search for a Contact by Name\n");
    printf("4: Delete a contact by name\n");
    printf("5: Save contacts to file\n");
    printf("6: Load contacts from file\n");
    printf("0: Exit the program\n");

    scanf("%d", &choice);
    while(getchar() != '\n');

    if (choice == 0)
        break;

    if (choice == 1) {
        if (count < 100) {
            int duplicate;
            do {
                duplicate = 0;
                printf("Please enter the name: ");
                fgets(Contacts[count].name, sizeof(Contacts[count].name), stdin);
                Contacts[count].name[strcspn(Contacts[count].name, "\n")] = '\0';

                for (int i = 0; i < count; i++) {
                    if (strcasecmp(Contacts[count].name, Contacts[i].name) == 0) {
                        printf("This Contact as already been added, please enter a new one.\n");
                        duplicate = 1;
                        break;
                    }
                }
            } while(duplicate);

            printf("\nPlease enter the number: ");
            fgets(Contacts[count].phone, sizeof(Contacts[count].phone), stdin);
            Contacts[count].phone[strcspn(Contacts[count].phone, "\n")] = '\0';

            printf("\nPlease enter the email: ");
            fgets(Contacts[count].email, sizeof(Contacts[count].email), stdin);
            Contacts[count].email[strcspn(Contacts[count].email, "\n")] = '\0';


            count++;
        }
        else
            printf("More than 100 Contacts have been added. Please remove 1 to add more.\n");
    }

    if (choice == 2) {
        if (count > 0) {
        for (int i = 0; i < count; i++) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", Contacts[i].name, Contacts[i].phone, Contacts[i].email);
        }
    }
    else
        printf("No Contacts to Display.\n");
    }

    if (choice == 3) {
        if (count > 0) {
            char searchname[50];
            int done = 0;
            printf("Please enter the name of the contact you are searching for: ");
            fgets(searchname, sizeof(searchname), stdin);
            searchname[strcspn(searchname, "\n")] = '\0';
            for (int i = 0; i < count; i++) {
                int x = strcasecmp(searchname, Contacts[i].name);
                if (x == 0) {
                    printf("Contact Found!\nName: %s\nPhone: %s\nEmail: %s\n", searchname, Contacts[i].phone, Contacts[i].email);
                    done = 1;
                }
            }
            if (done == 0)
                printf("Contact Not Found.\n");
            }
        else
            printf("No Contacts Available.\n");
    }

    if (choice == 4) {
        if (count > 0) {
            char delete[50];
            int found = 0;
            printf("Please enter the name of the contact you wish to delete: ");
            fgets(delete, sizeof(delete), stdin);
            delete[strcspn(delete, "\n")] = '\0';

            for (int i = 0; i < count; i++) {
                if (strcasecmp(delete, Contacts[i].name) == 0) {
                    for (int j = i; j < count - 1; j++) {
                        strcpy(Contacts[j].name, Contacts[j+1].name);
                        strcpy(Contacts[j].phone, Contacts[j+1].phone);
                        strcpy(Contacts[j].email, Contacts[j+1].email);
                    }
                    printf("Deleted Contact: %s\n", delete);
                    count --;
                    found = 1;
                    break;
                }
            }
            if (found != 1)
                printf("Contact Not Found.\n");
        }
        else
            printf("No Contacts Available.\n");
}

if (choice == 5) {
        savefile(count, Contacts);
}

if (choice == 6) {
    count = openfile(Contacts);
}

}

    return 0;
}