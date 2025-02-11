#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define USERNAME "admin"
#define PASSWORD "admin@1234"

int choice1, choice2, choice3, choice4, choice5;
int is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}
int is_valid_email(const char *email) {
    const char *at = strchr(email, '@');
    const char *dot = strrchr(email, '.');
    return at && dot && at < dot;
}
int is_valid_date(const char *date) {
    if (strlen(date) != 10 || date[2] != '/' || date[5] != '/') return 0;
    char day[3], month[3], year[5];
    strncpy(day, date, 2); day[2] = '\0';
    strncpy(month, date + 3, 2); month[2] = '\0';
    strncpy(year, date + 6, 4); year[4] = '\0';
    return is_number(day) && is_number(month) && is_number(year);
}
struct vehicle{
    char vehicle_type[20];
    char Brand[20];
    char Model[20];
    int reg_number;
    float daily_rent_price;
};
struct customer{
    char full[100];
    char email[100];
    char phone[15];
    char dob[11];
    char uname[50];
    char nic[20];
};
char user_name[20];
char password[20];
void menu();
void customer_menu();
void vehicle_information();
void add_vehicle();
void vehicle_availability();
void customer_information();
void view_customer_information();
void add_customer();
void booking();
void invalid_choise();
void enter_to_continue();
void Q_and_A();
void feedback();
void appstarting();
void thank();

int main(){
    //system("color 0A");
    appstarting();
    menu();
    return 0;
}

void vehicle_information(){

vehicle_information : while(1){
    printf("\n\t\t\t\t\t================ Vehicle Information ================\n\n");
    printf("\t\t\t\t\t1. Vehicle Registration\n");
    printf("\t\t\t\t\t2. Available Vehicles\n");
    printf("\t\t\t\t\t3. Back\n\n");
    printf("\t\t\t\t\tEnter Your Choice : ");
    scanf("%d",&choice2);
    printf(" \n\n");
    system("cls");
    //Start Vehicle Registration
    if (choice2==3){
    break;
    }
    else if(choice2>3 || choice2<1){
        invalid_choise();
    goto vehicle_information;
    }
    else if (choice2==1){
        add_vehicle();
    goto vehicle_information;
    }
    else if (choice2==2){
        vehicle_availability();
        enter_to_continue();
    }
}
}

void customer_information(){
customer_information : while(1){

    printf("\n\t\t\t\t\t================ Customer Information ================\n\n");
    printf("\t\t\t\t\t1. New Customer Registration\n");
    printf("\t\t\t\t\t2. View Customer details\n");
    printf("\t\t\t\t\t3. Back\n\n");
    printf("\t\t\t\t\tEnter Your Choice : ");
    scanf("%d",&choice2);
    printf(" \n\n");
    system("cls");

    if(choice2==3){
    break;
    }
    else if(choice2>3 || choice2<1){
        invalid_choise();
    goto customer_information;
    }

    //Start update customer Details
    else if(choice2==1){
    add_customer();
    break;
    }

    //Start View Customer details
    else if(choice2==2){
        view_customer_information();
    break;

        if(choice3==1){
        continue;
        }
        else if(choice3>1 || choice3<1){
            invalid_choise();
        continue;
        }
    }
}
}

void booking(){
vehicle_availability();

char choice6;
    printf("\n\t\t\t\t\tDo you Want to Rent a Car (y/n) : ");
    scanf(" %c", &choice6);

    switch(choice6){

    case 'Y': case 'y':
    rent();
    enter_to_continue();
    system("cls");
    break;

    case 'N': case 'n':
    system("cls");
    break;

    default:
    system("cls");
    invalid_choise();
    }
}

void rent(){
FILE *fp, *temp;
struct vehicle v;
char brand[20];
char model[20];
int days;
int found = 0;

printf("\n\t\t\t\t\tEnter the brand of the vehicle  : ");
scanf("%s", brand);
printf("\t\t\t\t\tEnter the model of the vehicle  : ");
scanf("%s", model);
printf("\t\t\t\t\tEnter the number of days        : ");
scanf("%d", &days);
system("cls");

fp = fopen("vehicle.txt", "r");
temp = fopen("temp.txt", "w");

if (fp == NULL || temp == NULL) {
    printf("\t\t\t\t\tError opening file.\n");
    return;
    }
while (fscanf(fp, "%s %s %s %d %f", v.vehicle_type, v.Brand, v.Model, &v.reg_number, &v.daily_rent_price) != EOF) {
if (strcmp(v.Brand, brand) == 0 && strcmp(v.Model, model) == 0) {
    found = 1;
    printf("\n\n\t\t\t\t\tVehicle rented successfully!\n");
    printf("\n\t\t\t\t\tTotal cost for %d days: Rs %.2f\n", days, days * v.daily_rent_price);
    } else {
    fprintf(temp, "%s %s %s %d %.2f\n", v.vehicle_type, v.Brand, v.Model, v.reg_number, v.daily_rent_price);
    }
    }
    fclose(fp);
    fclose(temp);

if (found) {
    remove("vehicle.txt");
    rename("temp.txt", "vehicle.txt");
} else {
    printf("\n\n\t\t\t\t\tVehicle not found.\n");
    remove("temp.txt");
}
}

void add_vehicle(){
printf("\n\t\t\t\t\t================ Vehicle Registration ================\n\n");
FILE*fp;
fp = fopen("vehicle.txt","a");
struct vehicle v;
printf("\t\t\t\t\tEnter the Vehicle Type (car/van): ");
scanf(" %s", &v.vehicle_type);
printf("\t\t\t\t\tEnter the Brand (Toyota)        : ");
scanf(" %s", &v.Brand);
printf("\t\t\t\t\tEnter the Model (Prius)         : ");
scanf(" %s", &v.Model);
printf("\t\t\t\t\tEnter the Registration Number    ");
printf("\n\t\t\t\t\t(Ex :- 2512)                    : ");
scanf(" %d", &v.reg_number);
printf("\t\t\t\t\tEnter daily rent Price in (LKR) : ");
scanf(" %f", &v.daily_rent_price);
fprintf(fp," %s %s %s %d %.2f\n", v.vehicle_type, v.Brand, v.Model, v.reg_number, v.daily_rent_price);
fclose(fp);
system("cls");
printf("\n\t\t\t\t\tVehicle added Successfully\n");
printf("\t\t\t\t\t---------------------------\n\n");
printf("\t\t\t\t\tVehicle Type         : %s\n", v.vehicle_type);
printf("\t\t\t\t\tVehicle Brand        : %s\n", v.Brand);
printf("\t\t\t\t\tVehicle Model        : %s\n", v.Model);
printf("\t\t\t\t\tRegistration Number  : %d\n", v.reg_number);
printf("\t\t\t\t\tDaily rent Price (Rs): %.2f\n\n",v.daily_rent_price);
enter_to_continue();
}

void vehicle_availability(){
FILE *fp;
    struct vehicle v;

    fp = fopen("vehicle.txt", "r");
    if (fp == NULL) {
        printf("\t\t\t\t\tError opening file.\n");
        return ;
    }
    printf("\n\t\t\t\t\t======================== Vehicle List ========================\n\n");
    printf("\t\t\t\t\t+----+-----------------+-----------------+------------------+\n");
    printf("\t\t\t\t\t| NO |      Brand      |      Model      |  Daily Rent (Rs) |\n");
    printf("\t\t\t\t\t+----+-----------------+-----------------+------------------+\n");
    int x = 1;
    while (fscanf(fp, "%s %s %s %d %f", v.vehicle_type, v.Brand, v.Model, &v.reg_number, &v.daily_rent_price) != EOF) {
        printf("\t\t\t\t\t|  %d | %-15s | %-15s | %-15.2f  |\n", x, v.Brand, v.Model, v.daily_rent_price);
        printf("\t\t\t\t\t+----+-----------------+-----------------+------------------+\n");
        x++;
    }
    fclose(fp);
}

void add_customer(){
struct customer c;
printf("\t\t\t\t\tCustomer Registration Form\n");
printf("\t\t\t\t========================================\n\n");

// Collecting user input
while (1) {
    printf("\t\t\t\tEnter Full Name                 : ");
    scanf(" %[^\n]", c.full);
    if (strlen(c.full) > 0) break;
    printf("\t\t\t\tName is required. Please enter a valid name.\n");
}

while (1) {
    printf("\t\t\t\tEnter Email Address             : ");
    scanf(" %[^\n]", c.email);
    if (is_valid_email(c.email)) break;
    printf("\t\t\t\tInvalid email format. Please enter a valid email address.\n");
}

while (1) {
    printf("\t\t\t\tEnter Phone Number              : ");
    scanf(" %[^\n]", c.phone);
    if (is_number(c.phone)) break;
    printf("\t\t\t\tPhone number must contain only digits. Please try again.\n");
}

while (1) {
    printf("\t\t\t\tEnter Date of Birth(DD/MM/YYYY) : ");
    scanf(" %[^\n]", c.dob);
    if (is_valid_date(c.dob)) break;
    printf("\t\t\t\tInvalid date format. Please use DD/MM/YYYY.\n");
}

while (1) {
    printf("\t\t\t\tEnter NIC Number                : ");
    scanf(" %[^\n]", c.nic);
    if (is_number(c.nic)) break;
    printf("\t\t\t\tNIC number must contain only digits. Please try again.\n");
}

while (1) {
    printf("\t\t\t\tEnter Username                  : ");
    scanf(" %[^\n]", c.uname);
    if (strlen(c.uname) > 0) break;
    printf("\t\t\t\tUsername is required. Please enter a valid username.\n");
}

// Save to file
FILE *file = fopen("customer_registration.txt", "a");
if (file == NULL) {
    printf("\t\t\t\tError opening file for writing.\n");
return 1;
}

fprintf(file, "\n%s %s %s %s %s %s", c.full, c.email, c.phone, c.dob, c.nic, c.uname);
fclose(file);
system("cls");

printf("\n\t\t\t\t\tRegistration Complete!\n");
printf("\t\t\t\t======================================\n\n");
printf("\t\t\t\t\tName     : %s\n", c.full);
printf("\t\t\t\t\tEmail    : %s\n", c.email);
printf("\t\t\t\t\tPhone    : %s\n", c.phone);
printf("\t\t\t\t\tDOB      : %s\n", c.dob);
printf("\t\t\t\t\tNIC      : %s\n", c.nic);
printf("\t\t\t\t\tUsername : %s\n\n", c.uname);
printf("\t\t\t\t%s Your registration details have been successfully Saved.\n",c.uname);
enter_to_continue();
}

void view_customer_information(){
FILE *fp;
    struct customer c;

    fp = fopen("customer_registration.txt", "r");
    if (fp == NULL) {
        printf("\t\t\t\t\tError opening file.\n");
        return;
    }

    printf("\n\t\t\t\t\t======================== Customers List ========================\n\n");
    printf("\t\t\t\t\t+----+----------------------+-----------------+----------------+\n");
    printf("\t\t\t\t\t| NO |      Full Name       |    NIC Number   |    Username    |\n");
    printf("\t\t\t\t\t+----+----------------------+-----------------+----------------+\n");

    int x = 1;
    while (fscanf(fp, "%s %s %s %s %s %s", c.full, c.email, c.phone, c.dob, c.uname, c.nic) != EOF) {
        printf("\t\t\t\t\t| %2d | %-20s | %-15s | %-15s |\n", x, c.full, c.nic, c.uname);
        printf("\t\t\t\t\t+----+----------------------+-----------------+----------------+\n");
        x++;
    }
    fclose(fp);

}

void invalid_choise(){
    printf("\n\n");
    printf("\t\t\t\t\t ----------------------------\n");
    printf("\t\t\t\t\t| You Entered Invalid Choice |\n");
    printf("\t\t\t\t\t ----------------------------\n");
    enter_to_continue();
}

void enter_to_continue(){
    printf("\n\t\t\t\t\tPress Enter to Continue : ");
    while (getchar() != '\n');
        getchar();
    system("cls");
}

void Q_and_A(){
    int num;
        printf("\t\t\t\t\t\t\t      Questions and Answers\n");
        printf("\t\t\t\t\t----------------------------------------------------------------\n\n");
        printf("\n\t\t\t\t\t1.What documents are required to register a customer? \n");
        printf("\t\t\t\t\t2.Whom can I contact if i faced issues during registration ? \n");
        printf("\t\t\t\t\t3.Go Back\n\n");
        printf("\t\t\t\t\tEnter your Choice : ");
        scanf("%d",&num);
        system("cls");
    switch(num){
    case 1:
        printf("\n\t\t\t\t\t---- Required details: ----\n");
        printf("\t\t\t\t\t*Full name\n");
        printf("\t\t\t\t\t*Email\n");
        printf("\t\t\t\t\t*date of birth\n");
        printf("\t\t\t\t\t*address\n");
        printf("\t\t\t\t\t*licenes number \n");
        printf("\t\t\t\t\t*NIC number\n");
        enter_to_continue();
    break;

    case 2:
        system("cls");
        printf("\n\t\t\t\t\tPlease contact us +94 716 162 563 / 011 933 9333\n");
        enter_to_continue();
    break;

    case 3:
    break;

    default:
        system("cls");
        invalid_choise();
    }
}

void feedback(){
struct feedback {
    char name[100];
    char email[100];
    char comments[500];
};
struct feedback fb;
    printf("\n\t\t\t\t\t\t\tUser Feedback\n");
    printf("\t\t\t\t\t---------------------------------------------\n\n");
    printf("\t\t\t\t\tEnter your name     : ");
    scanf(" %[^\n]", fb.name);

    printf("\t\t\t\t\tEnter your email    : ");
    scanf(" %[^\n]", fb.email);

    printf("\t\t\t\t\tEnter your feedback : ");
    scanf(" %[^\n]", fb.comments);

    FILE *file = fopen("feedback.txt", "a");
    if (file == NULL) {
        printf("\t\t\t\t\tError opening file.\n");
        return;
    }

    fprintf(file, "Name: %s\nEmail: %s\nComments: %s\n\n", fb.name, fb.email, fb.comments);
    fclose(file);

    printf("\n\t\t\t\t\tThank you for your feedback!\n");
    enter_to_continue();
}

void menu(){
    main_menu : while(1){
        printf("\n\t\t\t\t\t================ Are you ? ================\n\n");
        printf("\t\t\t\t\t1. Admin\n");
        printf("\t\t\t\t\t2. Customer\n");
        printf("\t\t\t\t\t3. Exit\n\n");
        printf("\t\t\t\t\tEnter your Choice : ");
        scanf("%d",&choice5);
        system("cls");

        switch(choice5){
            case 1:
                printf("\n\n\t\t\t\t\t   Enter Your Usename and Password\n");
                printf("\t\t\t\t\t-------------------------------------\n");
                printf("\n\t\t\t\t\tUser Name : ");
                scanf("%s",&user_name);
                printf("\t\t\t\t\tPassword  : ");
                scanf("%s",&password);

                if(strcmp(user_name, USERNAME) == 0 && strcmp(password, PASSWORD) == 0){

                    system("cls");
                    // Start Admin Main menu
                    Admin_menu : while(1){

                    printf("\n\t\t\t\t\t================ Admin Menu ================\n\n");
                    printf("\t\t\t\t\t1. Vehicle Information\n");
                    printf("\t\t\t\t\t2. Customer Information\n");
                    printf("\t\t\t\t\t3. Exit to Main Menu\n\n");
                    printf("\t\t\t\t\tEnter Your Choice : ");
                    scanf("%d",&choice1);
                    printf("\n");
                    system("cls");

                        //Vehicle Information Menu
                        if (choice1==3){
                        goto main_menu;
                        }
                        else if(choice1>3 || choice1<1){
                            invalid_choise();
                        continue;
                        }
                        else if (choice1==1){
                        vehicle_information();
                        }
                        //Start Customer Information
                        else if(choice1==2){
                        customer_information();
                        }
                    }
                    break;
                }
                else{
                    invalid_choise();
                goto main_menu;
                }

            case 2:
                customer_menu : while(1){
                    printf("\n\t\t\t\t\t================ Customer Menu ================\n\n");
                    printf("\t\t\t\t\t1. Customer Registration\n");
                    printf("\t\t\t\t\t2. Available Vehicles\n");
                    printf("\t\t\t\t\t3. Q&A\n");
                    printf("\t\t\t\t\t4. Feedback\n");
                    printf("\t\t\t\t\t5. Exit to Main Menu\n\n");
                    printf("\t\t\t\t\tEnter Your Choice : ");
                    scanf("%d",&choice1);
                    system("cls");
                    if(choice1==5){
                    goto main_menu;
                    }
                    else if(choice1==1){
                        add_customer();
                    }
                    else if(choice1==2){
                        booking();
                    }
                    else if(choice1==3){
                        Q_and_A();
                    }
                    else if(choice1){
                        feedback();
                    }
                }

            case 3:
                thank();
                exit(0);

            default :
                system("cls");
                printf("\t\t\t\t\t ----------------------------\n");
                printf("\t\t\t\t\t| You Entered Invalid Choice |\n");
                printf("\t\t\t\t\t ----------------------------\n\n");
                enter_to_continue();
        }
    }
}

void appstarting(){
int i;
    printf("\n\t\t\t\t\t");
    char AppStarting[100] = "*** WELCOME TO CAR RENT SYSTEM ***";
    for(i=0;i<strlen(AppStarting);i++){
        printf("%c",AppStarting[i]);
        Sleep(60);
    }
    sleep(1);
    system("cls");
}

void thank(){
    int i = 0;
    printf("\n\n\t\t\t\t\t");
    char thank[100] = "------- Thank You ! -------\n";
    char comeagain[100] = "-------  Come Again -------\n\n";
    for(i=0;i<strlen(thank);i++){
        printf("%c",thank[i]);
        Sleep(60);
    }
    printf("\t\t\t\t\t");
    for(i=0;i<strlen(comeagain);i++){
        printf("%c",comeagain[i]);
        Sleep(60);
    }
    sleep(3);
    system("cls");
}

