#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Calculate after-tax income
double afterTax(double income, char marital) {
    double taxRate;
    if (marital == 'y' || marital == 'Y') { // married
        taxRate = (income > 32000) ? 0.25 : 0.10;
    } else { // single
        taxRate = (income > 64000) ? 0.25 : 0.10;
    }
    return income * (1 - taxRate);
}

// Administrator (A)
double Admin() {
    double salary;
    scanf("%lf", &salary);
    if (salary < 0) {
        printf("Error: Salary cannot be negative.\n");
        return -1;
    }
    return salary * 12;
}

// Staff (S)
double Staff() {
    double salary;
    int overtime;
    scanf("%lf", &salary);
    if (salary < 0) {
        printf("Error: Salary cannot be negative.\n");
        return -1;
    }
    scanf("%d", &overtime);
    if (overtime < 0) {
        printf("Error: Overtime hours cannot be negative.\n");
        return -1;
    }
    if (overtime > 10) {
        printf("Overtime hours exceed limit. Only 10 hours will be counted.\n");
        overtime = 10;
    }
    double hourly = salary / 160.0;
    double overtimePay = overtime * 1.5 * hourly;
    return (salary + overtimePay) * 12;
}

// Salesperson (E)
double SalesPerson() {
    double salary;
    int overtimePerDay, products;
    char vacation;

    scanf("%lf", &salary);
    if (salary < 0) {
        printf("Error: Salary cannot be negative.\n");
        return -1;
    }
    scanf("%d", &overtimePerDay);
    if (overtimePerDay < 0) {
        printf("Error: Overtime hours cannot be negative.\n");
        return -1;
    }
    if (overtimePerDay > 1) {
        printf("Overtime hours exceed limit. Only 1 hour per day will be counted.\n");
        overtimePerDay = 1;
    }
    scanf(" %c", &vacation);
    scanf("%d", &products);
    if (products < 0) {
        printf("Error: Product sales cannot be negative.\n");
        return -1;
    }

    int overtime = overtimePerDay * 20; // 20 working days/month
    double hourly = salary / 160.0;
    double overtimePay = overtime * 1.35 * hourly;
    double monthlyIncome = salary + overtimePay;

    if (vacation == 'y' || vacation == 'Y') {
        monthlyIncome = salary * 0.5; // one vacation month
        return (monthlyIncome + (salary + overtimePay) * 11) + (products * 600);
    }

    return (monthlyIncome * 12) + (products * 600);
}

// Part-time (P)
double PartTime() {
    double weeklySalary;
    int overtime, products;
    scanf("%lf", &weeklySalary);
    if (weeklySalary < 0) {
        printf("Error: Salary cannot be negative.\n");
        return -1;
    }
    scanf("%d", &overtime);
    if (overtime < 0) {
        printf("Error: Overtime hours cannot be negative.\n");
        return -1;
    }
    if (overtime > 10) {
        printf("Overtime hours exceed limit. Only 10 hours will be counted.\n");
        overtime = 10;
    }
    scanf("%d", &products);
    if (products < 0) {
        printf("Error: Product sales cannot be negative.\n");
        return -1;
    }

    double hourly = weeklySalary / 40.0;
    double overtimePay = overtime * hourly;
    double weeklyIncome = weeklySalary + overtimePay;
    return (weeklyIncome * 52) + (products * 600);
}

// Hourly (H)
double Hourly() {
    double hourlyWage;
    int hoursWorked;
    scanf("%lf", &hourlyWage);
    if (hourlyWage < 0) {
        printf("Error: Salary cannot be negative.\n");
        return -1;
    }
    scanf("%d", &hoursWorked);
    if (hoursWorked < 0) {
        printf("Error: Hours worked cannot be negative.\n");
        return -1;
    }

    int regularHours = (hoursWorked > 10) ? 10 : hoursWorked;
    int overtime = (hoursWorked > 10) ? hoursWorked - 10 : 0;
    if (overtime > 10) {
        printf("Overtime hours exceed limit. Only 10 hours will be counted.\n");
        overtime = 10;
    }

    double weeklyIncome = (regularHours * hourlyWage) + (overtime * 1.25 * hourlyWage);
    return weeklyIncome * 52;
}

int main() {
    char type, marital;
    double annualIncome;

    scanf(" %c", &type);

    switch (toupper(type)) {
        case 'A': annualIncome = Admin(); break;
        case 'S': annualIncome = Staff(); break;
        case 'E': annualIncome = SalesPerson(); break;
        case 'P': annualIncome = PartTime(); break;
        case 'H': annualIncome = Hourly(); break;
        default:
            return 1; // invalid type
    }

    if (annualIncome < 0) return 0; // error already printed

    scanf(" %c", &marital);
    double after = afterTax(annualIncome, marital);

    printf("This employee's annual income is $%.2f before tax and $%.2f after tax.\n",
           annualIncome, after);

    return 0;
}