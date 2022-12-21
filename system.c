#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

#define MAX_DRIVERS 1000

struct time_and_date {
    time_t current_time;
};

struct time_entry {
    time_t current_time;
    struct tm time_info;
};

struct Driver{
    char license_number[15];
    char agency_code[4];
    char serial_number[10];

    char last_name[20];
    char first_name[20];
    char middle_name[20];
    char address[50];
    char nationality[4];
    char sex[3];

    int day_date_of_birth;
    int month_date_of_birth;
    int year_date_of_birth;
    int weight;
    int height_in_cm;
    
    char blood_type[4];
    char eyes_color[20];
    
    int restrictions;
    char conditions[20];

    time_t registration_date_and_time;

    int day_expiration;
    int month_expiration;
    int year_expiration;
};

struct DriverInfo {
    struct Driver drivers[MAX_DRIVERS];
    int numDrivers;
};

struct DriverInfo driverInfo;

void addDriver(){
    if(driverInfo.numDrivers >= MAX_DRIVERS){
        printf("Cannot add more drivers. Maximum number of drivers reached.\n");
        return;
    }

    struct Driver driver;

    int i;
    int valid_license_number = 0;
    int valid_agency_code = 0;
    int valid_serial_number = 0;
    int valid_sex = 0;
    int valid_blood_type = 0;

    printf("\e[0;33m\n\n\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("==");
    for(i=0;i<36;i++){
        printf(" ");
    }
    printf("\e[0;37mAdd Driver Menu\e[0;33m");
    for(i=0;i<35;i++){
        printf(" ");
    }
    printf("==\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n\n");

    while (!valid_license_number){
        printf("                  \e[0;37mEnter driver's new license number. Format: Hxx-xx-xxxxxx: \e[0;92m");
        scanf("%14s", driver.license_number);
        if(driver.license_number[0] == 'H' &&
            isdigit(driver.license_number[1]) && isdigit(driver.license_number[2]) &&
            driver.license_number[3] == '-' && isdigit(driver.license_number[4]) && isdigit(driver.license_number[5]) &&
            driver.license_number[6] == '-' && isdigit(driver.license_number[7]) && isdigit(driver.license_number[8]) &&
            isdigit(driver.license_number[9]) && isdigit(driver.license_number[10]) &&
            isdigit(driver.license_number[11]) && isdigit(driver.license_number[12])){
            valid_license_number = 1;
        } else {
            printf("\e[0;33m\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            for(i=0;i<36;i++){
                printf("*");
            }
            printf("\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            printf("* \e[0;91mInvalid input, please try again. \e[0;33m*\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            for(i=0;i<36;i++){
                printf("*");
            }
            printf("\n\n\e[0m");
            while (getchar() != '\n');
        }
    }

    while (!valid_agency_code){
        printf("                  \e[0;37mEnter driver's new agency code. Format: Hxx: \e[0;92m");
        scanf("%3s", driver.agency_code);
        if(driver.agency_code[0] == 'H' &&
            isdigit(driver.agency_code[1]) && isdigit(driver.agency_code[2])){
            valid_agency_code = 1;
        } else {
            printf("\e[0;33m\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            for(i=0;i<36;i++){
                printf("*");
            }
            printf("\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            printf("* \e[0;91mInvalid input, please try again. \e[0;33m*\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            for(i=0;i<36;i++){
                printf("*");
            }
            printf("\n\n\e[0m");
            while (getchar() != '\n');
        }
    }

    while (!valid_serial_number){
        printf("                  \e[0;37mEnter driver's new serial number. Format: xxxxxxxxx: \e[0;92m");
        scanf("%9s", &driver.serial_number);
        if (strlen(driver.serial_number) == 9){
            for (int i = 0; i < strlen(driver.serial_number); i++) {
                if (isdigit(driver.serial_number[i])) {
                    valid_serial_number = 1;
                }
            }
        }
        else {
            printf("\e[0;33m\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            for(i=0;i<36;i++){
                printf("*");
            }
            printf("\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            printf("* \e[0;91mInvalid input, please try again. \e[0;33m*\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            for(i=0;i<36;i++){
                printf("*");
            }
            printf("\n\n\e[0m");
            while (getchar() != '\n');
        }
    }    

    scanf("%*c");
    printf("                  \e[0;37mEnter driver's last name: \e[0;92m");
    scanf("%[^\n]", driver.last_name);
    for (int i = 0; driver.last_name[i] != '\0'; i++) {
        driver.last_name[i] = toupper(driver.last_name[i]);
    }

    scanf("%*c");
    printf("                  \e[0;37mEnter driver's first name: \e[0;92m");
    scanf("%[^\n]", driver.first_name);
    for (int j = 0; driver.first_name[j] != '\0'; j++) {
        driver.first_name[j] = toupper(driver.first_name[j]);
    }

    scanf("%*c");
    printf("                  \e[0;37mEnter driver's middle name: \e[0;92m");
    scanf("%[^\n]", driver.middle_name);
    for (int k = 0; driver.middle_name[k] != '\0'; k++) {
        driver.middle_name[k] = toupper(driver.middle_name[k]);
    }

    scanf("%*c");
    printf("                  \e[0;37mEnter driver's home address:\n                  - \e[0;92m");
    scanf("%[^\n]", driver.address);

    strcpy(driver.nationality, "PHL");

    while (!valid_sex){
        scanf("%*c");
        printf("                  \e[0;37mEnter driver's sex. Format: 'M' or 'F': \e[0;92m");
        scanf("%2s", driver.sex);
        if ((strcmp(driver.sex, "M") == 0 || strcmp(driver.sex, "F") == 0 || strcmp(driver.sex, "m") == 0 || strcmp(driver.sex, "f") == 0)){
            for (int l = 0; driver.sex[l] != '\0'; l++) {
                driver.sex[l] = toupper(driver.sex[l]);
            }
            valid_sex = 1;
        } else {
            printf("\e[0;33m\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            for(i=0;i<36;i++){
                printf("*");
            }
            printf("\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            printf("* \e[0;91mInvalid input, please try again. \e[0;33m*\n");
            for(i=0;i<18;i++){
                printf(" ");
            }
            for(i=0;i<36;i++){
                printf("*");
            }
            printf("\n\n\e[0m");
        }
    }

    printf("                  \e[0;37mEnter driver's date of birth (day). Format 'dd': \e[0;92m");
    scanf("%d", &driver.day_date_of_birth);

    printf("                  \e[0;37mEnter driver's date of birth (month). Format 'mm': \e[0;92m");
    scanf("%d", &driver.month_date_of_birth);

    printf("                  \e[0;37mEnter driver's date of birth (year). Format 'yyyy': \e[0;92m");
    scanf("%d", &driver.year_date_of_birth);

    printf("                  \e[0;37mEnter driver's weight in kg: \e[0;92m");
    scanf("%d", &driver.weight);

    printf("                  \e[0;37mEnter driver's height in cm: \e[0;92m");
    scanf("%d", &driver.height_in_cm);

    printf("                  \e[0;37mEnter driver's blood type. Format: 'A', 'O', etc.: \e[0;92m");
    scanf("%3s", driver.blood_type);

    printf("                  \e[0;37mEnter driver's eye color: \e[0;92m");
    scanf("%19s", driver.eyes_color);

    time_t current_time;
    time(&current_time);
    driver.registration_date_and_time = current_time;

    struct tm *tm = localtime(&current_time); 

    int year = tm->tm_year + 1900;
    driver.year_expiration = year + 5;
    int month = tm->tm_mon + 1;
    driver.month_expiration = month;
    int day = tm->tm_mday + 1;
    driver.day_expiration = day;

    driverInfo.drivers[driverInfo.numDrivers] = driver;
    driverInfo.numDrivers++;

    printf("\e[0;33m\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("*");
    }
    printf("\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<21;i++){
        printf(" ");
    }
    printf("\e[0;37mDriver data successfully added! Please wait.\e[0;33m");
    for(i=0;i<21;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("*");
    }
    printf("\n\n\e[0m");

    Sleep(2000);
    system("cls");

}

void updateDriver() {
    char license_number[15];
    char agency_code[4];
    int i;

    printf("\e[0;33m\n\n\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("==");
    for(i=0;i<34;i++){
        printf(" ");
    }
    printf("\e[0;37mUpdate Driver Menu\e[0;33m");
    for(i=0;i<34;i++){
        printf(" ");
    }
    printf("==\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n\n");

    printf("                  \e[0;37mEnter driver's license number to update: \e[0;92m");
    scanf("%14s", license_number);

    printf("                  \e[0;37mEnter driver's agency code to update: \e[0;92m");
    scanf("%3s", agency_code);

    printf("\e[0;33m\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n\n\e[0m");

    int found = 0;
    for (int i = 0; i < driverInfo.numDrivers; i++){
        if (strcmp(driverInfo.drivers[i].license_number, license_number) == 0 && strcmp(driverInfo.drivers[i].agency_code, agency_code) == 0){
            for (int j = i; j < driverInfo.numDrivers - 1; j++) {
                driverInfo.drivers[j] = driverInfo.drivers[j + 1];
            }
            driverInfo.numDrivers--;

            struct Driver driver;

            int i;
            int valid_license_number = 0;
            int valid_agency_code = 0;
            int valid_serial_number = 0;
            int valid_sex = 0;
            int valid_blood_type = 0;

            while (!valid_license_number){
                printf("                  \e[0;37mEnter driver's new license number. Format: Hxx-xx-xxxxxx: \e[0;92m");
                scanf("%14s", driver.license_number);
                if(driver.license_number[0] == 'H' &&
                    isdigit(driver.license_number[1]) && isdigit(driver.license_number[2]) &&
                    driver.license_number[3] == '-' && isdigit(driver.license_number[4]) && isdigit(driver.license_number[5]) &&
                    driver.license_number[6] == '-' && isdigit(driver.license_number[7]) && isdigit(driver.license_number[8]) &&
                    isdigit(driver.license_number[9]) && isdigit(driver.license_number[10]) &&
                    isdigit(driver.license_number[11]) && isdigit(driver.license_number[12])){
                    valid_license_number = 1;
                } else {
                    printf("\e[0;33m\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    for(i=0;i<36;i++){
                        printf("*");
                    }
                    printf("\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    printf("* \e[0;91mInvalid input, please try again. \e[0;33m*\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    for(i=0;i<36;i++){
                        printf("*");
                    }
                    printf("\n\n\e[0m");
                    while (getchar() != '\n');
                }
            }

            while (!valid_agency_code){
                printf("                  \e[0;37mEnter driver's new agency code. Format: Hxx: \e[0;92m");
                scanf("%3s", driver.agency_code);
                if(driver.agency_code[0] == 'H' &&
                    isdigit(driver.agency_code[1]) && isdigit(driver.agency_code[2])){
                    valid_agency_code = 1;
                } else {
                    printf("\e[0;33m\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    for(i=0;i<36;i++){
                        printf("*");
                    }
                    printf("\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    printf("* \e[0;91mInvalid input, please try again. \e[0;33m*\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    for(i=0;i<36;i++){
                        printf("*");
                    }
                    printf("\n\n\e[0m");
                    while (getchar() != '\n');
                }
            }

            while (!valid_serial_number){
                printf("                  \e[0;37mEnter driver's new serial number. Format: xxxxxxxxx: \e[0;92m");
                scanf("%9s", &driver.serial_number);
                if (strlen(driver.serial_number) == 9){
                    for (int i = 0; i < strlen(driver.serial_number); i++) {
                        if (isdigit(driver.serial_number[i])) {
                            valid_serial_number = 1;
                        }
                    }
                }
                else {
                    printf("\e[0;33m\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    for(i=0;i<36;i++){
                        printf("*");
                    }
                    printf("\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    printf("* \e[0;91mInvalid input, please try again. \e[0;33m*\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    for(i=0;i<36;i++){
                        printf("*");
                    }
                    printf("\n\n\e[0m");
                    while (getchar() != '\n');
                }
            }    

            scanf("%*c");
            printf("                  \e[0;37mEnter driver's last name: \e[0;92m");
            scanf("%[^\n]", driver.last_name);
            for (int i = 0; driver.last_name[i] != '\0'; i++) {
                driver.last_name[i] = toupper(driver.last_name[i]);
            }

            scanf("%*c");
            printf("                  \e[0;37mEnter driver's first name: \e[0;92m");
            scanf("%[^\n]", driver.first_name);
            for (int j = 0; driver.first_name[j] != '\0'; j++) {
                driver.first_name[j] = toupper(driver.first_name[j]);
            }

            scanf("%*c");
            printf("                  \e[0;37mEnter driver's middle name: \e[0;92m");
            scanf("%[^\n]", driver.middle_name);
            for (int k = 0; driver.middle_name[k] != '\0'; k++) {
                driver.middle_name[k] = toupper(driver.middle_name[k]);
            }

            scanf("%*c");
            printf("                  \e[0;37mEnter driver's home address:\n                  - \e[0;92m");
            scanf("%[^\n]", driver.address);

            strcpy(driver.nationality, "PHL");

            while (!valid_sex){
                scanf("%*c");
                printf("                  \e[0;37mEnter driver's sex. Format: 'M' or 'F': \e[0;92m");
                scanf("%2s", driver.sex);
                if ((strcmp(driver.sex, "M") == 0 || strcmp(driver.sex, "F") == 0 || strcmp(driver.sex, "m") == 0 || strcmp(driver.sex, "f") == 0)){
                    for (int l = 0; driver.sex[l] != '\0'; l++) {
                        driver.sex[l] = toupper(driver.sex[l]);
                    }
                    valid_sex = 1;
                } else {
                    printf("\e[0;33m\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    for(i=0;i<36;i++){
                        printf("*");
                    }
                    printf("\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    printf("* \e[0;91mInvalid input, please try again. \e[0;33m*\n");
                    for(i=0;i<18;i++){
                        printf(" ");
                    }
                    for(i=0;i<36;i++){
                        printf("*");
                    }
                    printf("\n\n\e[0m");
                }
            }

            printf("                  \e[0;37mEnter driver's date of birth (day). Format 'dd': \e[0;92m");
            scanf("%d", &driver.day_date_of_birth);

            printf("                  \e[0;37mEnter driver's date of birth (month). Format 'mm': \e[0;92m");
            scanf("%d", &driver.month_date_of_birth);

            printf("                  \e[0;37mEnter driver's date of birth (year). Format 'yyyy': \e[0;92m");
            scanf("%d", &driver.year_date_of_birth);

            printf("                  \e[0;37mEnter driver's weight in kg: \e[0;92m");
            scanf("%d", &driver.weight);

            printf("                  \e[0;37mEnter driver's height in cm: \e[0;92m");
            scanf("%d", &driver.height_in_cm);

            printf("                  \e[0;37mEnter driver's blood type. Format: 'A', 'O', etc.: \e[0;92m");
            scanf("%3s", driver.blood_type);

            printf("                  \e[0;37mEnter driver's eye color: \e[0;92m");
            scanf("%19s", driver.eyes_color);

            time_t current_time;
            time(&current_time);
            driver.registration_date_and_time = current_time;

            struct tm *tm = localtime(&current_time); 

            int year = tm->tm_year + 1900;
            driver.year_expiration = year + 5;
            int month = tm->tm_mon + 1;
            driver.month_expiration = month;
            int day = tm->tm_mday + 1;
            driver.day_expiration = day;

            driverInfo.drivers[driverInfo.numDrivers] = driver;
            driverInfo.numDrivers++;

            printf("\e[0;33m\n");
            for(i=0;i<15;i++){
                printf(" ");
            }
            for(i=0;i<90;i++){
                printf("=");
            }
            printf("\n\n");

            for(i=0;i<15;i++){
                printf(" ");
            }
            for(i=0;i<90;i++){
                printf("*");
            }
            printf("\n");

            for(i=0;i<15;i++){
                printf(" ");
            }
            printf("**");
            for(i=0;i<20;i++){
                printf(" ");
            }
            printf("\e[0;37mDriver data successfully updated! Please wait.\e[0;33m");
            for(i=0;i<20;i++){
                printf(" ");
            }
            printf("**\n");

            for(i=0;i<15;i++){
                printf(" ");
            }
            for(i=0;i<90;i++){
                printf("*");
            }
            printf("\n\n\e[0m");
            Sleep(2000);
            system("cls");
            found = 1;
        }
    }
    if (!found) {
        printf("                  \e[0;37mDriver with license number '\e[0;92m%s\e[0m' and agency code '\e[0;92m%s\e[0m' not found.\n", license_number, agency_code);
        Sleep(2000);
        system("cls");
    }
}

void searchDriver() {
    char license_number[15];
    char agency_code[4];
    int i;

    printf("\e[0;33m\n\n\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("==");
    for(i=0;i<34;i++){
        printf(" ");
    }
    printf("\e[0;37mSearch Driver Menu\e[0;33m");
    for(i=0;i<34;i++){
        printf(" ");
    }
    printf("==\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n\n");

    printf("                  \e[0;37mEnter driver's license number to search: \e[0;92m");
    scanf("%14s", license_number);

    printf("                  \e[0;37mEnter driver's agency code to search: \e[0;92m");
    scanf("%3s", agency_code);

    printf("\e[0;33m\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n\n\e[0m");

    int found = 0;
    for (int i = 0; i < driverInfo.numDrivers; i++) {
        if (strcmp(driverInfo.drivers[i].license_number, license_number) == 0 && strcmp(driverInfo.drivers[i].agency_code, agency_code) == 0)  {
            printf("                  \e[0;37mLicense number: \e[0;92m%s\n", driverInfo.drivers[i].license_number);
            printf("                  \e[0;37mAgency code: \e[0;92m%s\n", driverInfo.drivers[i].agency_code);
            printf("                  \e[0;37mSerial number: \e[0;92m%s\n\n", driverInfo.drivers[i].serial_number);

            printf("                  \e[0;37mLast name, first name, middle name: \e[0;92m%s, %s %s\n", driverInfo.drivers[i].last_name, driverInfo.drivers[i].first_name, driverInfo.drivers[i].middle_name);
            printf("                  \e[0;37mAddress: \e[0;92m%s\n", driverInfo.drivers[i].address);
            printf("                  \e[0;37mNationality: \e[0;92m%s\n", driverInfo.drivers[i].nationality);
            printf("                  \e[0;37mSex: \e[0;92m%s\n", driverInfo.drivers[i].sex);

            printf("                  \e[0;37mDate of birth: \e[0;92m%d/%d/%d\n", driverInfo.drivers[i].day_date_of_birth, driverInfo.drivers[i].month_date_of_birth, driverInfo.drivers[i].year_date_of_birth);
            printf("                  \e[0;37mWeight: \e[0;92m%dkg.\n", driverInfo.drivers[i].weight);

            float height_in_m = driverInfo.drivers[i].height_in_cm;
            printf("                  \e[0;37mHeight: \e[0;92m%.2fm.\n\n", height_in_m/100);

            printf("                  \e[0;37mBlood Type: \e[0;92m%s\n", driverInfo.drivers[i].blood_type);
            printf("                  \e[0;37mEyes Color: \e[0;92m%s\n\n", driverInfo.drivers[i].eyes_color);

            struct tm *saved_time = localtime(&driverInfo.drivers[i].registration_date_and_time);

            char time_string[100];
            strftime(time_string, sizeof(time_string), "%Y-%m-%d", saved_time);
            printf("                  \e[0;37mDate of registration: \e[0;92m%s\n", time_string);

            printf("                  \e[0;37mDate of expiration: \e[0;92m%d-%d-%d\n\n", driverInfo.drivers[i].year_expiration, driverInfo.drivers[i].month_expiration, driverInfo.drivers[i].day_expiration);

            printf("\e[0;33m");
            for(i=0;i<15;i++){
                printf(" ");
            }
            for(i=0;i<90;i++){
                printf("*");
            }
            printf("\n");

            for(i=0;i<15;i++){
                printf(" ");
            }
            printf("**");
            for(i=0;i<12;i++){
                printf(" ");
            }
            printf("\e[0;37mDriver data successfully searched! Press any key to continue.\e[0;33m");
            for(i=0;i<13;i++){
                printf(" ");
            }
            printf("**\n");

            for(i=0;i<15;i++){
                printf(" ");
            }
            for(i=0;i<90;i++){
                printf("*");
            }
            printf("\n\n\e[0m");

            getch();
            found = 1;
            system("cls");
            break;
        }
    }

    if (!found) {
        printf("                  \e[0;37mDriver with license number '\e[0;92m%s\e[0m' and agency code '\e[0;92m%s\e[0m' not found.\n", license_number, agency_code);
        Sleep(2000);
        system("cls");
    }
}

void deleteDriver() {
    char license_number[15];
    char agency_code[4];
    int i;

    printf("\e[0;33m\n\n\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("==");
    for(i=0;i<34;i++){
        printf(" ");
    }
    printf("\e[0;37mDelete Driver Menu\e[0;33m");
    for(i=0;i<34;i++){
        printf(" ");
    }
    printf("==\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n\n");

    printf("                  \e[0;37mEnter driver's license number to delete: \e[0;92m");
    scanf("%14s", license_number);

    printf("                  \e[0;37mEnter driver's agency code to delete: \e[0;92m");
    scanf("%3s", agency_code);

    printf("\e[0;33m\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("=");
    }
    printf("\n\n\e[0m");

    int found = 0;
    for (int i = 0; i < driverInfo.numDrivers; i++){
        if (strcmp(driverInfo.drivers[i].license_number, license_number) == 0 && strcmp(driverInfo.drivers[i].agency_code, agency_code) == 0){
            for (int j = i; j < driverInfo.numDrivers - 1; j++) {
                driverInfo.drivers[j] = driverInfo.drivers[j + 1];
            }
            driverInfo.numDrivers--;
            found = 1;

            printf("\e[0;33m");
            for(i=0;i<15;i++){
                printf(" ");
            }
            for(i=0;i<90;i++){
                printf("*");
            }
            printf("\n");

            for(i=0;i<15;i++){
                printf(" ");
            }
            printf("**");
            for(i=0;i<20;i++){
                printf(" ");
            }
            printf("\e[0;37mDriver data successfully deleted! Please wait.\e[0;33m");
            for(i=0;i<20;i++){
                printf(" ");
            }
            printf("**\n");

            for(i=0;i<15;i++){
                printf(" ");
            }
            for(i=0;i<90;i++){
                printf("*");
            }
            printf("\n\n\e[0m");

            Sleep(2000);
            system("cls");

            break;
        }
    }
    if (!found) {
        printf("                  \e[0;37mDriver with license number '\e[0;92m%s\e[0m' and agency code '\e[0;92m%s\e[0m' not found.\n", license_number, agency_code);
        Sleep(2000);
        system("cls");
    }
}

int main() {
    system("cls");
    char loading[] = "|/-\\";
    int i;
    float percent = 0;

    printf("\e[0;33m\n\n\n\n\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("*");
    }
    printf("\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<38;i++){
        printf(" ");
    }
    printf("\e[0;37mWelcome to\e[0;33m");
    for(i=0;i<38;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<19;i++){
        printf(" ");
    }
    printf("\e[0;37mPROFESSIONAL DRIVERS' LICENSE MANAGEMENT SYSTEM!\e[0;33m");
    for(i=0;i<19;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<86;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("*");
    }

    printf("\n\n");

    while (percent < 102.5) {
        printf(" Loading:  \b\e[0;92m%c\e[0m \e[0;96m%.1f%%\e[0m", loading[i % 4], percent);
        fflush(stdout);
        Sleep(100);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        fflush(stdout);
        Sleep(100);
        percent += 2.5;
        i++;
    }

    printf("\n System successfully loaded!\e[0m");

    Sleep(1500);

    printf("\n");
    int choice;
    system("cls");
    do {
        printf("\e[0;33m\n\n\n\n\n");
        for(i=0;i<15;i++){
            printf(" ");
        }
        for(i=0;i<90;i++){
            printf("*");
        }
        printf("\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<19;i++){
            printf(" ");
        }
        printf("\e[0;37mPROFESSIONAL DRIVERS' LICENSE MANAGEMENT SYSTEM \e[0;33m");
        for(i=0;i<19;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        for(i=0;i<90;i++){
            printf("*");
        }
        printf("\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<86;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<30;i++){
            printf(" ");
        }
        printf("\e[0;37mMenu:\e[0;33m");
        for(i=0;i<51;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<30;i++){
            printf(" ");
        }
        printf("\e[0;37m1. Add driver\e[0;33m");
        for(i=0;i<43;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<30;i++){
            printf(" ");
        }
        printf("\e[0;37m2. Update driver\e[0;33m");
        for(i=0;i<40;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<30;i++){
            printf(" ");
        }
        printf("\e[0;37m3. Search driver\e[0;33m");
        for(i=0;i<40;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<30;i++){
            printf(" ");
        }
        printf("\e[0;37m4. Delete driver\e[0;33m");
        for(i=0;i<40;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<30;i++){
            printf(" ");
        }
        printf("\e[0;37m5. Quit\e[0;33m");
        for(i=0;i<49;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<86;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        for(i=0;i<90;i++){
            printf("*");
        }
        printf("\n");
        
        time_t current_time = time(NULL);
        struct tm *time_info = localtime(&current_time);
        char buffer[32];
        strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", time_info);

        for(i=0;i<15;i++){
            printf(" ");
        }
        printf("**");
        for(i=0;i<27;i++){
            printf(" ");
        }
        printf("\e[0;37mCurrent time: \e[0;96m%s\e[0;33m", buffer);
        for(i=0;i<26;i++){
            printf(" ");
        }
        printf("**\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        for(i=0;i<90;i++){
            printf("*");
        }
        printf("\n\n");

        for(i=0;i<15;i++){
            printf(" ");
        }
        for(i=0;i<90;i++){
            printf("=");
        }
        printf("\n\n");

        for(i=0;i<44;i++){
            printf(" ");
        }
        printf("\e[0;37mEnter your choice: \e[0;32m");
        scanf("%d", &choice);
        printf("\e[0m");

        switch (choice) {
            case 1:
                system("cls");
                addDriver();
                break;
            case 2:
                system("cls");
                updateDriver();
                break;
            case 3:
                system("cls");
                searchDriver();
                break;
            case 4:
                system("cls");
                deleteDriver();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    system("cls");

    printf("\e[0;33m\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("*");
    }
    printf("\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    printf("**");
    for(i=0;i<26;i++){
        printf(" ");
    }
    printf("\e[0;37mTHANK YOU FOR USING MY SYSTEM! ^_^\e[0;33m");
    for(i=0;i<26;i++){
        printf(" ");
    }
    printf("**\n");

    for(i=0;i<15;i++){
        printf(" ");
    }
    for(i=0;i<90;i++){
        printf("*");
    }
    printf("\e[0m");

    Sleep(3000);

    return 0;
}
