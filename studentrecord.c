#include "stdio.h"
#include "conio.h"

struct student
{
    char first_name[100];
    char last_name[100];
    int roll_no;
    char Class[100];
    char Address[100];
    float per;
};
// Main function
void main()
{

    int choice;
    while (choice != 5)
    {
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\n\t\t\t        = WELCOME TO SRMIST STUDENT DATABASE MANAGEMENT SYSTEM =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        printf("\n\n\n\t\t\t\t     1. Add Student\n");
        printf("\t\t\t\t     2. Students Records\n");
        printf("\t\t\t\t     3. Search Student\n");
        printf("\t\t\t\t     4. Delete Student\n");
        printf("\t\t\t\t     5. Exit\n");
        printf("\t\t\t\t    -------------------------------------------\n");
        printf("\t\t\t\t         RA2111050010046 HARSH SRIVASTAVA\n");
        printf("\t\t\t\t    -------------------------------------------\n\n\n\n");
        printf("\t\t\t\t     Enter the provided choice: \n\n\n\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addstudent();
            break;
        case 2:
            studentrecord();
            printf("\t\t\t\tpress any key to exit..... \n");
            getch();
            break;
        case 3:
            searchstudent();
            printf("\n\t\t\t\tPress any key to exit.......\n");
            getch();
            break;
        case 4:
            delete ();
            printf("\n\t\t\t\tPress any key to exit.......\n");
            getch();
            break;
        case 5:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
            break;
        default:
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
            break;
        }
    }
    getch();
}
// Function to create a new student
void addstudent()
{
    char another;
    FILE *fp;
    int n, i;
    struct student info;
    do
    {
        printf("\t\t\t\t                =======Add Students Info=======\n\n\n");
        fp = fopen("srmist_students_record.txt", "a");
        printf("\n\t\t\tEnter First Name     : ");
        scanf("%s", &info.first_name);
        printf("\n\t\t\tEnter Last Name     : ");
        scanf("%s", &info.last_name);
        printf("\n\t\t\tEnter Roll-No (Integer Only)      : ");
        scanf("%d", &info.roll_no);
        printf("\n\t\t\tEnter Class(course) : ");
        scanf("%s", &info.Class);
        printf("\n\t\t\tEnter Address       : ");
        scanf("%s", &info.Address);
        printf("\n\t\t\tEnter Percentage    : ");
        scanf("%f", &info.per);
        printf("\n\t\t\t______________________________\n");
        if (fp == NULL)
        {
            fprintf(stderr, "can't open file");
        }
        else
        {
            printf("\t\t\tRecord stored successfuly\n\n");
        }
        fwrite(&info, sizeof(struct student), 1, fp);
        fclose(fp);
        printf("\t\t\tYou want to add another record?(y/n) : ");
        scanf("%s", &another);
    } while (another == 'y' || another == 'Y');
}
// Function to list out the pre stored records
void studentrecord()
{

    FILE *fp;
    struct student info;
    fp = fopen("srmist_students_record.txt", "r");
    printf("\t\t\t\t=======SRMIST STUDENTS RECORD=======\n\n\n");
    if (fp == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    }
    else
    {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }
    while (fread(&info, sizeof(struct student), 1, fp))
    {
        printf("\n\t\t\t\t Student Name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t Roll NO       : %d", info.roll_no);
        printf("\n\t\t\t\t Class         : %s", info.Class);
        printf("\n\t\t\t\t Address  : %s", info.Address);
        printf("\n\t\t\t\t Percentage    : %f%", info.per);
        printf("\n\t\t\t\t ________________________________\n");
    }
    fclose(fp);
    getch();
}
// Function to search any student
void searchstudent()
{
    struct student info;
    FILE *fp;
    int roll_no, found = 0;
    fp = fopen("srmist_students_record.txt", "r");
    printf("\t\t\t\t=======SEARCH SRMIST STUDENTS RECORD=======\n\n\n");
    printf("\t\t\tEnter the roll no : ");
    scanf("%d", &roll_no);
    while (fread(&info, sizeof(struct student), 1, fp) > 0)
    {
        if (info.roll_no == roll_no)
        {
            found = 1;
            printf("\n\n\t\t\tStudent Name : %s %s", info.first_name, info.last_name);
            printf("\n\t\t\tRoll NO        : %d", info.roll_no);
            printf("\n\t\t\tClass          : %s", info.Class);
            printf("\n\t\t\tAddress        : %s", info.Address);
            printf("\n\t\t\tPercentage     : %f%", info.per);
            printf("\n\t\t\t______________________________________\n");
        }
    }
    if (!found)
    {
        printf("\n\t\t\tRecord not found\n");
    }
    fclose(fp);
    getch();
}
// Function to delete a record/student
void delete ()
{
    struct student info;
    FILE *fp, *fp1;
    int roll_no, found = 0;
    printf("\t\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
    fp = fopen("srmist_students_record.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("\t\t\t\tEnter the roll no : ");
    scanf("%d", &roll_no);
    if (fp == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    }

    while (fread(&info, sizeof(struct student), 1, fp))
    {
        if (info.roll_no == roll_no)
        {
            found = 1;
        }
        else
        {
            fwrite(&info, sizeof(struct student), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    if (!found)
    {
        printf("\n\t\t\t\tRecord not found\n");
    }
    if (found)
    {
        remove("srmist_students_record.txt");
        rename("temp.txt", "srmist_students_record.txt");
        printf("\n\t\t\t\tRecord deleted succesfully\n");
    }
    getch();
}