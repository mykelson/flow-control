#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int testscore;
char grade;
int option;

void flow(int a);
void get_grade(int score);
void get_promotion_status (char your_grade);


int main(void)
{
    // asks users for an input to determine what they want to do
    printf("Please how may we be of service to you today?\n");
    printf("kindly press 1 to check your grade\n");
    printf("Or press 2 to check if you were promoted: \n");
    printf("Else press 3 to quit:\n");
    
    scanf("%i", &option);

    if (option == 3)
        {
            printf("Goodbye!!!");
            return 0;
        }

    flow(option);
    
}

void flow(int a)
{
    int new_option;

    //flow control to direct user to their destination
    switch (a)
    {
        case 1:
            printf("Please what is your testscore: "); 
            scanf("%i", &testscore);
            get_grade(testscore); 
        break;
        case 2: 
            printf("Please what is your grade: "); 
            scanf(" %c", &grade); 
            get_promotion_status(grade); 
        break;
        case 3:
            printf("Goodbye!!!");
            return;
            break;
        default: 
        do
        {
            printf("INVALID ENTRY, TRY AGAIN: ");
            scanf(" %i", &a);
            flow(a);
        }while ((a < 1) || (a > 2));
         break;
    }

    do
    {
        printf("kindly press 1 to check your grade\n");
        printf("Or press 2 to check if you were promoted:\n");
        printf("Else press 3 to quit:\n");
            
        scanf(" %i", &new_option);

        flow(new_option);
    }
    while((new_option < 1) && (new_option > 3));
}

//assigns a grade depending on the users testscore
void get_grade(int score)
{
    if (testscore >= 90)
    {
        grade = 'A';
    }
    else if (testscore >= 80)
    {
        grade = 'B';
    }
    else if (testscore >= 70)
    {
        grade = 'C';
    }
    else if (testscore >= 60)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }

    printf("YOUR GRADE IS \"%c\" \n", grade);
}

//Give the user his/her promotion status
void get_promotion_status (char your_grade)
{
    char new_grade;

    if (islower(your_grade))
    {
        your_grade = toupper(your_grade);
    }
    switch (your_grade)
    {
        case 'A':
        case 'B':
        case 'C': printf("CONGRATULATION YOU HAVE BEEN PROMOTED!!!\n"); 
        break;
        case 'D':
        case 'E':
        case 'F': printf("SORRY, YOU WERE NOT PROMOTED\n"); 
        break;
        default: 
            printf("Invalid entry\n"); 
            do
            {
                printf("Retry: ");
                scanf(" %c", &new_grade);
                get_promotion_status(new_grade);
            }
            while(new_grade < 'A' && new_grade > 'F');
        break;
    }
}