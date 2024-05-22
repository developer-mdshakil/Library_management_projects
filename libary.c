#include <stdio.h>
#include <stdlib.h>

void password();
void heading();
void mainMenu();
void addBook();
void viewBook();
void searchBook();
void editBook();
void deleteBook();
void help();
void exitProject();

struct Book_info
{
    int id;
    char name[10];
    char author[10];
    int quantity;
    int rack;
};

struct Book_info a;

FILE *file, *file2;

int main()
{
    password();
}

// declare here Main Menu functin
void mainMenu()
{
    system("cls");
    int n;
    printf("\n\n \t\t****************Main Menu******************\n");

    printf("\n \t\t 1. Add Book\n");
    printf("\t\t 2. View Book List\n");
    printf("\t\t 3. Search Book\n");
    printf("\t\t 4. Edit Book\n");
    printf("\t\t 5. Delete Book\n");
    printf("\t\t 6. Help\n");
    printf("\t\t 7. Exit\n\n");

    printf("\t\t*********************************\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &n);

    // check user input number & show item for given user number
    if (n == 1)
    {
        addBook();
    }
    else if (n == 2)
    {
        viewBook();
    }
    else if (n == 3)
    {
        searchBook();
    }
    else if (n == 4)
    {
        editBook();
    }
    else if (n == 5)
    {
        deleteBook();
    }
    else if (n == 6)
    {
        help();
    }
    else if (n == 7)
    {
        exitProject();
    }
    else
    {
        printf("\n\n \t\tYour choice is worng!! \n \t\tPlease try agin....");

        fflush(stdin);
        getchar();
        mainMenu();
    }
}

// adding book function here for add book in library
void addBook()
{
    system("cls");
    int d, count = 0;
    printf("\n\n \t\t***************Add Book***************\n\n");

    file = fopen("books.dat", "ab+");

    printf("\t\t Please Enter ID: ");
    fflush(stdin);
    scanf("%d", &d);

    rewind(file); // used c library function

    while (fread(&a, sizeof(a), 1, file) == 1)
    {
        if (d == a.id)
        {
            printf("\n\n\t\t This Book Already Store in Library....");
            count = 1;
        }
    }
    if (count == 1)
    {
        fflush(stdin);
        getchar();
        mainMenu();
    }
    a.id = d;
    printf("\n\t\t Enter the book Name: ");
    fflush(stdin);
    scanf("%s", a.name);

    printf("\n\t\t Enter the book Author: ");
    fflush(stdin);
    scanf("%s", a.author);

    printf("\n\t\t Enter the book Quantity: ");
    fflush(stdin);
    scanf("%d", &a.quantity);

    printf("\n\t\t Enter the rack No: ");
    fflush(stdin);
    scanf("%d", &a.rack);

    fseek(file, 0, SEEK_END);       // used here c function
    fwrite(&a, sizeof(a), 1, file); // file write function

    fclose(file);
    printf("\n\n\t\t You added book Successfuly!!!\n");
    printf("\n\n\t\t Press any key.....\n");
    fflush(stdin);
    getchar();
    mainMenu();
}

// declare here view book function
void viewBook()
{
    system("cls");
    int count = 0;
    printf("\n\n\t\t***************View Book List***************\n\n");

    printf("\tID\tName\tAuthor\tQuantity\tRack\n\n");

    file = fopen("books.dat", "rb");

    while (fread(&a, sizeof(a), 1, file) == 1)
    {
        printf("\t%d", a.id);
        printf("\t%s", a.name);
        printf("\t%s", a.author);
        printf("\t%d", a.quantity);
        printf("\t\t%d\n", a.rack);

        count = count + a.quantity;
    }
    fclose(file);

    printf("\n\tTotal Book: %d\n", count);
    printf("\n\n\tPress any key....");
    fflush(stdin);
    getchar();
    mainMenu();
}

// declare here search function
void searchBook()
{
    int d, count = 0;
    system("cls");
    printf("\n\n\t\t************Search Book*************\n");
    printf("\n\t\t Searching.........\n\n");
    file = fopen("books.dat", "rb");

    printf("\n\t\tPlease Enter ID: ");
    scanf("%d", &d);

    while (fread(&a, sizeof(a), 1, file) == 1)
    {
        if (d == a.id)
        {
            printf("\n\t\tBook is Found!...\n");
            printf("\t\t Id: %d", a.id);
            printf("\n\t\tName: %s", a.name);
            printf("\n\t\tAuthor: %s", a.author);
            printf("\n\t\tQuantity: %d", a.quantity);
            printf("\n\t\tRack: %d\n", a.rack);

            count = 1;
        }
    }
    if (count == 0)
    {
        printf("\n\nBook is Not Found!!!");
    }
    printf("\n\n\t\t Press any key.....\n");
    fflush(stdin);
    getchar();
    mainMenu();
}

// declare here edit function
void editBook()
{
    system("cls");
    int d, count = 0;
    printf("\n\n\t\t **************Edit Book************\n\n");

    file = fopen("books.dat", "rb+");

    printf("\n\t\tEnter ID: ");
    scanf("%d", &d);

    while (fread(&a, sizeof(a), 1, file) == 1)
    {
        if (d == a.id)
        {
            printf("\n\t\t This book is availble!!!\n");
            printf("\n\n\t\t Enter ID: %d", a.id);
            printf("\n\t\t Please give new Name: ");
            scanf("%s", a.name);
            printf("\n\t\t Please give new Author: ");
            scanf("%s", a.author);
            printf("\n\t\t Please give new book Quantity: ");
            scanf("%d", &a.quantity);
            printf("\n\t\t Please give new Rack No: ");
            scanf("%d", &a.rack);

            fseek(file, ftell(file) - sizeof(a), 0);

            fwrite(&a, sizeof(a), 1, file);
            fclose(file);
            count = 1;
        }
    }
    if (count == 0)
    {
        printf("\n\n\t\tBook is not found.....!!");
    }
    printf("\n\n\t\t Press any key.....");
    fflush(stdin);
    getchar();

    mainMenu();
}

// declare delete function here for delete book data
void deleteBook()
{
    system("cls");
    int d, count = 0;
    printf("\n\n\t\t **************Delete Book************\n");
    printf("\n\n\t\tEnter Id for Delete Book: ");
    scanf("%d", &d);

    file = fopen("books.dat", "rb+");

    rewind(file);
    while (fread(&a, sizeof(a), 1, file) == 1)
    {
        if (d == a.id)
        {
            printf("\n\t\tBooks is Availble!!!");
            printf("\n\t\tBook Name: %s", a.name);
            printf("\n\t\tAuthor: %s", a.author);
            printf("\n\t\tRack No: %d", a.rack);
            count = 1;
        }
        if (count == 0)
        {
            printf("\n\t\tBooks is not availble!!");
        }
        else
        {
            file2 = fopen("text.dat", "wb");

            rewind(file);
            while (fread(&a, sizeof(a), 1, file) == 1)
            {
                if (d != a.id)
                {
                    fseek(file2, ftell(file2) - sizeof(a), 0);
                    fwrite(&a, sizeof(a), 1, file2);
                }
            }
            fclose(file2);
            fclose(file);

            remove("books.dat");
            rename("text.dat", "books.dat");
            file = fopen("books.dat", "rb");
            fclose(file);
        }
    }
    printf("\n\tPress any key.....");
    fflush(stdin);
    getchar();

    mainMenu();
}

// declare here help function for user take help
void help()
{
    system("cls");

    printf("\n\n\t\t**************** Help Section ****************\n\n");

    printf("\n\t\t1. This is a simple Library Management Project\n");
    printf("\n\t\t2. This project maintaince by porjects admin Shakil Miah\n");
    printf("\n\t\t3. You can add book in library\n");
    printf("\n\t\t4. See all feature under main menu\n");
    printf("\n\t\t5. You can use all of them\n");
    printf("\n\t\t6. Press any key..... to back main menu\n");

    printf("\n\t\t\tThank you for Visit!\n\n");

    printf("\n\t Press any key.....");
    fflush(stdin);
    getchar();
    mainMenu();
}

// declare here exit function for exit programm
void exitProject()
{
    system("cls");

    printf("\n\n\t\t This is simple Library Management Projects\n");

    printf("\n\n\n\t\t\t Thank you!\n\n");
    printf("\n\t\t\t\tWait....");

    fflush(stdin);
    getchar();
    mainMenu();
    exitProject(0);
}
// declare here heading function
void heading()
{
    system("cls");
    printf("\n\n \t\t**************Library Management Project************\n");

    // fflush(stdin); // clean the screen out types;
    // getchar();
}

// decleare here password function
void password()
{
    heading();

    // here create password and match password
    char password1[10] = {"admin"};
    char password2[10];

    // taking password input for user
    printf("\n \t\tPlease enter password: ");
    scanf("%s", &password2);

    // used to c library and check match password
    if (password1 == password2 == 0)
    {
        printf("\n\n \t\tMatch Password!\n");
        printf("\n \t\t Press any key...");
    }
    else
    {
        printf("\n\n \t\tWorng Password!!");
        printf("\n\n \t\t Please try agin....");

        fflush(stdin);
        getchar();
        password();
    }
    fflush(stdin);
    getchar();
    mainMenu();
}
