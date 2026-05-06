//Group 1
//SDC255 Project 
//2May2026


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Addition(); 		// Declares Add function
int Subtraction(); 		// Declares sub function
int Multiplication(); 	// Declares mul function
int Division(); 	// Declares div function

int main() {
    int totalQuestions = 0;
    int correctAnswers = 0;
    char choice;
    char playAgain;


 time_t current_time;
    
    time(&current_time); 


    printf("The current local time is: %s\n", ctime(&current_time)); 
    srand(time(NULL)); // Seed random number generator

    do {
        printf("SDC 255 Math Program\n");
        printf("A for Addition\nS for Subtraction\nM for Multiplication\nD for Division\n");
        printf("Choose a type of question ('A', 'S', 'M', 'D'): ");
        scanf_s(" %c", &choice, 1);
        choice=toupper(choice);
        

        int result = 0;
        switch(choice) {
        	case 'a':
            case 'A': result = Addition(); break;
            case 's':
            case 'S': result = Subtraction(); break;
            case 'm':
            case 'M': result = Multiplication(); break;
            case 'd':
            case 'D': result = Division(); break;
            default: 
                printf("Invalid Letter.\n");
                continue; // wrong input Stop counting
        }

        totalQuestions++; 		//printing if correct or incorrect
        if(result) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect.\n");
        }

        printf("Statistics: %d correct out of %d questions (%.2f%%)\n", correctAnswers, totalQuestions, (correctAnswers * 100.0) / totalQuestions);

        printf("Do you want to continue? (y/n): ");
        scanf_s(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    printf("Final Statistics: %d correct out of %d questions (%.2f%%)\n", correctAnswers, totalQuestions, (correctAnswers * 100.0) / totalQuestions);

    return 0;
}

// Function add
int Addition() {
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int answer;
    printf("What is %d + %d? ", a, b);
    scanf_s("%d", &answer);
    return answer == (a + b);
}

int Subtraction() { 	// Function sub
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int answer;
    printf("What is %d - %d? ", a, b);
    scanf_s("%d", &answer);
    return answer == (a - b);
}

int Multiplication() { 	//mul function
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int answer;
    printf("What is %d * %d? ", a, b);
    scanf_s("%d", &answer);
    return answer == (a * b);
}

int Division() { 		//div function
    int b = rand() % 99 + 1; // so the divisor can't be 0
    int a = b * (rand() % 100 + 1); // make sure its divisible
    int answer;
    printf("What is %d / %d? ", a, b);
    scanf_s("%d", &answer);
    return answer == (a / b);
}
