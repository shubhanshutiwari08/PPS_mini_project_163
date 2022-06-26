/*Create a structure named date that has day, month and year as its members. Include this structure as a member
in another structure named employee which has name, id and salary as other members. Use this structure to
read and display employee’s name, id, date of birthday and salary in the .txt file */

#include <stdio.h>
#include <string.h>

//creating structure named "date".

struct date
{
    int day,month,year;
};

//creating structure named "employee".

struct employee
{
    char name[30];
    int emp_id,salary;
};

//Main Code

void main(){
    struct employee details[20];          //details as the member of structre "employee".
    struct date date_of_birth[10];        //details as the member of structre "date".
    int n,i;
    printf("\nEnter the number of employees in the organization:");  //Asking to enter  number of employees in organization.
    scanf("%d",&n);   //storing number of employees in variable n.

    for ( i = 0; i < n; i++)                // For loop to ask for the employees details.
    {
        printf("Enter Name of Employee %d : \n",i+1);  //Asking for the name of employee
        scanf("%s",&details[i].name);                  //Storing employee Name
        printf("Enter Employee Id: \n");               //Asking Employee Id
        scanf("%d",&details[i].emp_id);                //Storing Employee Id
        printf("Enter date of birth of employee(DD MM YYYY):\n");   //Asking Date of birth of employee
        scanf("%d %d %d",&date_of_birth[i].day,&date_of_birth[i].month,&date_of_birth[i].year); //Storing Date of birth
        printf("Enter employee Salary: \n");   //Asking Employee Salary
        scanf("%d",&details[i].salary);        //Storing Employee salary
    }

    printf("----------------------------------------\n");
    printf("Organization`s Employee Information\n");
    printf("----------------------------------------\n");

    for ( i = 0; i<n; i++)   //For loop for printing the employee details
    {
        printf("Employee Name %d:%s\n",i+1,details[i].name); //Printing Employee Name
        printf("Employee Id : %d\n",details[i].emp_id);      //Printing Employee Id
        printf("Date of Birth : %d / %d / %d\n",date_of_birth[i].day,date_of_birth[i].month,date_of_birth[i].year); //Printing Date of birth
        printf("Employee Salary :%d \n",details[i].salary); //Printing Employee Salary
        printf("\n");
    }

    //Storing all the records in the .txt file

    FILE *fp = fopen("record.txt", "w");   //Opening the file in the write mode.

    for ( i = 0; i < n; i++) 
    {
        fprintf(fp,"Employee Name %d:%s\n",i+1,details[i].name); //Printing Employee Name
        fprintf(fp,"Employee Id : %d\n",details[i].emp_id);      //Printing Employee Id
        fprintf(fp,"Date of Birth : %d / %d / %d\n",date_of_birth[i].day,date_of_birth[i].month,date_of_birth[i].year); //Printing Date of birth
        fprintf(fp,"Employee Salary :%d \n",details[i].salary); //Printing Employee Salary
        fprintf(fp,"\n");
    }

    fclose(fp);
}
