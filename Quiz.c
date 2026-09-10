#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TOTAL_QUESTIONS 6
#define TOTAL_CATEGORIES 3
#define TOTAL_DIFFICULTIES 3


/* =========================================================
   STRUCTURE
   ========================================================= */

struct Question
{
    char *question;
    char *options[4];
    int correctAnswer;
};


/* =========================================================
   FUNCTION PROTOTYPES
   ========================================================= */

int getInteger();

void loadEasyQuestions(int category, struct Question questions[]);
void loadMediumQuestions(int category, struct Question questions[]);
void loadHardQuestions(int category, struct Question questions[]);

int runQuiz(struct Question questions[], int totalQuestions);

void showScore(int score, int totalQuestions);
float calculatePercentage(int score, int totalQuestions);
void showGrade(float percentage);

void showAnswerReview(
    struct Question questions[],
    int userAnswers[],
    int totalQuestions
);

void loadHighScores(
    int highScores[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES],
    int highScoreQuestions[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES]
);

void saveHighScores(
    int highScores[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES],
    int highScoreQuestions[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES]
);

void showHighScore(
    int highScores[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES],
    int highScoreQuestions[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES],
    int category,
    int difficulty
);


/* =========================================================
   GET INTEGER
   ========================================================= */

int getInteger()
{
    int value;
    int result;

    while (1)
    {
        result = scanf("%d", &value);

        if (result == 1)
        {
            while (getchar() != '\n')
            {
            }

            return value;
        }

        printf("Invalid input! Please enter a number: ");

        while (getchar() != '\n')
        {
        }
    }
}


/* =========================================================
   LOAD EASY QUESTIONS
   ========================================================= */

void loadEasyQuestions(int category, struct Question questions[])
{
    if (category == 1)
    {
        /* C Basics */

        questions[0] = (struct Question)
        {
            "Which language are we learning?",
            {"Python", "Java", "C", "HTML"},
            3
        };

        questions[1] = (struct Question)
        {
            "What is the extension of a C source file?",
            {".py", ".java", ".c", ".html"},
            3
        };

        questions[2] = (struct Question)
        {
            "Which function is used to display output in C?",
            {"scanf()", "printf()", "print()", "display()"},
            2
        };

        questions[3] = (struct Question)
        {
            "Which data type is used to store whole numbers?",
            {"float", "char", "int", "double"},
            3
        };

        questions[4] = (struct Question)
        {
            "Which symbol is used to access the address of a variable?",
            {"&", "*", "%", "#"},
            1
        };

        questions[5] = (struct Question)
        {
            "Which symbol is used to end a statement in C?",
            {".", ":", ";", ","},
            3
        };
    }
    else if (category == 2)
    {
        /* Operators */

        questions[0] = (struct Question)
        {
            "Which operator is used for addition?",
            {"+", "-", "*", "/"},
            1
        };

        questions[1] = (struct Question)
        {
            "Which operator is used for subtraction?",
            {"+", "-", "*", "%"},
            2
        };

        questions[2] = (struct Question)
        {
            "Which operator is used for multiplication?",
            {"+", "-", "*", "/"},
            3
        };

        questions[3] = (struct Question)
        {
            "Which operator is used for division?",
            {"+", "-", "*", "/"},
            4
        };

        questions[4] = (struct Question)
        {
            "Which operator gives the remainder?",
            {"/", "%", "*", "+"},
            2
        };

        questions[5] = (struct Question)
        {
            "Which operator is used to compare two values for equality?",
            {"=", "==", "!=", ">="},
            2
        };
    }
    else if (category == 3)
    {
        /* Loops */

        questions[0] = (struct Question)
        {
            "Which keyword is commonly used to create a loop?",
            {"for", "loop", "repeat", "cycle"},
            1
        };

        questions[1] = (struct Question)
        {
            "Which loop checks its condition before execution?",
            {"do-while", "while", "both", "none"},
            2
        };

        questions[2] = (struct Question)
        {
            "Which loop executes its body at least once?",
            {"for", "while", "do-while", "if"},
            3
        };

        questions[3] = (struct Question)
        {
            "Which keyword exits a loop immediately?",
            {"continue", "skip", "break", "exit"},
            3
        };

        questions[4] = (struct Question)
        {
            "Which keyword skips the current iteration?",
            {"break", "continue", "stop", "skip"},
            2
        };

        questions[5] = (struct Question)
        {
            "Which loop is commonly used when the number of iterations is known?",
            {"for", "while", "do-while", "if"},
            1
        };
    }
}


/* =========================================================
   LOAD MEDIUM QUESTIONS
   ========================================================= */

void loadMediumQuestions(int category, struct Question questions[])
{
    if (category == 1)
    {
        /* C Basics */

        questions[0] = (struct Question)
        {
            "What is the purpose of a pointer in C?",
            {
                "Store an address",
                "Store only characters",
                "Create loops",
                "Print output"
            },
            1
        };

        questions[1] = (struct Question)
        {
            "Which symbol is used to dereference a pointer?",
            {"&", "*", "%", "#"},
            2
        };

        questions[2] = (struct Question)
        {
            "Which keyword is used to define a constant variable?",
            {"constant", "const", "fixed", "define"},
            2
        };

        questions[3] = (struct Question)
        {
            "Which function is used to read formatted input?",
            {"printf()", "scanf()", "input()", "read()"},
            2
        };

        questions[4] = (struct Question)
        {
            "Which header file is commonly used for printf() and scanf()?",
            {"stdlib.h", "string.h", "stdio.h", "math.h"},
            3
        };

        questions[5] = (struct Question)
        {
            "What does sizeof return?",
            {
                "The size of a type or object",
                "The value of a variable",
                "The address of a variable",
                "The number of functions"
            },
            1
        };
    }
    else if (category == 2)
    {
        /* Operators */

        questions[0] = (struct Question)
        {
            "What is the result of 10 % 3?",
            {"0", "1", "2", "3"},
            2
        };

        questions[1] = (struct Question)
        {
            "Which operator represents logical AND?",
            {"||", "&&", "!", "&"},
            2
        };

        questions[2] = (struct Question)
        {
            "Which operator represents logical OR?",
            {"&&", "||", "!", "|"},
            2
        };

        questions[3] = (struct Question)
        {
            "Which operator is used for logical NOT?",
            {"!", "&&", "||", "~"},
            1
        };

        questions[4] = (struct Question)
        {
            "What is the result of 5 > 3?",
            {"0", "1", "5", "3"},
            2
        };

        questions[5] = (struct Question)
        {
            "Which operator has higher precedence in C?",
            {"+", "*", "=", "=="},
            2
        };
    }
    else if (category == 3)
    {
        /* Loops */

        questions[0] = (struct Question)
        {
            "What happens when continue is used inside a loop?",
            {
                "The loop ends",
                "The current iteration is skipped",
                "The program ends",
                "The loop becomes infinite"
            },
            2
        };

        questions[1] = (struct Question)
        {
            "What happens when break is used inside a loop?",
            {
                "The current iteration is skipped",
                "The loop terminates",
                "The program restarts",
                "Nothing happens"
            },
            2
        };

        questions[2] = (struct Question)
        {
            "Which statement can create an infinite loop?",
            {"while(1)", "if(1)", "for()", "switch(1)"},
            1
        };

        questions[3] = (struct Question)
        {
            "Which loop checks the condition after executing its body?",
            {"for", "while", "do-while", "if"},
            3
        };

        questions[4] = (struct Question)
        {
            "How many times does for(i = 0; i < 5; i++) execute?",
            {"4", "5", "6", "Infinite"},
            2
        };

        questions[5] = (struct Question)
        {
            "Which part of a for loop changes the loop variable?",
            {"Initialization", "Condition", "Update", "Body"},
            3
        };
    }
}


/* =========================================================
   LOAD HARD QUESTIONS
   ========================================================= */

void loadHardQuestions(int category, struct Question questions[])
{
    if (category == 1)
    {
        /* C Basics */

        questions[0] = (struct Question)
        {
            "What is the main advantage of using functions in C?",
            {
                "Code reuse",
                "Slower execution",
                "More variables",
                "More errors"
            },
            1
        };

        questions[1] = (struct Question)
        {
            "What is recursion?",
            {
                "A function calling itself",
                "A loop without a condition",
                "A variable changing type",
                "A pointer storing a value"
            },
            1
        };

        questions[2] = (struct Question)
        {
            "Which storage class keeps a local variable's value between function calls?",
            {"auto", "static", "register", "extern"},
            2
        };

        questions[3] = (struct Question)
        {
            "What does a function return type of void mean?",
            {
                "Returns an integer",
                "Returns a character",
                "Returns no value",
                "Returns a pointer"
            },
            3
        };

        questions[4] = (struct Question)
        {
            "Which keyword is used to return a value from a function?",
            {"send", "return", "give", "output"},
            2
        };

        questions[5] = (struct Question)
        {
            "What does a pointer variable store?",
            {
                "A value only",
                "An address",
                "A function name only",
                "A data type"
            },
            2
        };
    }
    else if (category == 2)
    {
        /* Operators */

        questions[0] = (struct Question)
        {
            "What is the result of 10 / 3 when both operands are integers?",
            {"3", "3.33", "4", "1"},
            1
        };

        questions[1] = (struct Question)
        {
            "What is the result of 10 % 4?",
            {"1", "2", "3", "4"},
            2
        };

        questions[2] = (struct Question)
        {
            "Which operator is the conditional operator?",
            {"::", "?:", "??", "=>"},
            2
        };

        questions[3] = (struct Question)
        {
            "What does ++i do?",
            {
                "Uses i then increments",
                "Increments i before using its value",
                "Decrements i",
                "Does nothing"
            },
            2
        };

        questions[4] = (struct Question)
        {
            "What does i++ do?",
            {
                "Increments i after its current value is used",
                "Decrements i",
                "Increments i twice",
                "Does nothing"
            },
            1
        };

        questions[5] = (struct Question)
        {
            "Which operator is used for bitwise AND?",
            {"&&", "&", "||", "|"},
            2
        };
    }
    else if (category == 3)
    {
        /* Loops */

        questions[0] = (struct Question)
        {
            "What is the purpose of a nested loop?",
            {
                "A loop inside another loop",
                "A loop without a condition",
                "A function inside a loop",
                "A pointer inside a loop"
            },
            1
        };

        questions[1] = (struct Question)
        {
            "If both an outer loop and inner loop execute 3 times, how many times does the inner loop body execute in total?",
            {"3", "6", "9", "12"},
            3
        };

        questions[2] = (struct Question)
        {
            "Which loop is commonly used to traverse an array?",
            {"for", "switch", "if", "goto"},
            1
        };

        questions[3] = (struct Question)
        {
            "What happens if a loop condition always remains true?",
            {
                "The loop may run indefinitely",
                "The loop runs once",
                "The compiler stops it",
                "The loop automatically becomes false"
            },
            1
        };

        questions[4] = (struct Question)
        {
            "Which statement immediately skips to the next iteration?",
            {"break", "continue", "return", "goto"},
            2
        };

        questions[5] = (struct Question)
        {
            "Which statement immediately terminates the current loop?",
            {"continue", "break", "skip", "next"},
            2
        };
    }
}


/* =========================================================
   RUN QUIZ
   ========================================================= */

int runQuiz(struct Question questions[], int totalQuestions)
{
    int answer;
    int score = 0;

    bool isInvalid;

    /*
       Stores the user's answers.
       This allows us to show a review at the end.
    */
    int userAnswers[TOTAL_QUESTIONS] = {0};


    for (int i = 0; i < totalQuestions; i++)
    {
        printf("\n---------------------------------\n");
        printf("Question %d of %d\n", i + 1, totalQuestions);
        printf("---------------------------------\n");

        printf("Q%d. %s\n\n", i+1, questions[i].question);


        for (int j = 0; j < 4; j++)
        {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }


        do
        {
            isInvalid = false;

            printf("\nEnter your answer (1-4): ");
            answer = getInteger();

            if (answer < 1 || answer > 4)
            {
                printf("Invalid answer! Please enter 1-4.\n");
                isInvalid = true;
            }

        } while (isInvalid);


        userAnswers[i] = answer;


        if (answer == questions[i].correctAnswer)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect!\n");
            printf("Correct answer: %s\n",
                   questions[i].options[questions[i].correctAnswer - 1]);
        }
    }


    /*
       Store answers temporarily for review.
       The review is handled separately below.
    */

    printf("\n");


    /* Show final review */
    showAnswerReview(questions, userAnswers, totalQuestions);


    return score;
}


/* =========================================================
   ANSWER REVIEW
   ========================================================= */

void showAnswerReview(
    struct Question questions[],
    int userAnswers[],
    int totalQuestions
)
{
    printf("\n=================================\n");
    printf("         ANSWER REVIEW\n");
    printf("=================================\n");


    for (int i = 0; i < totalQuestions; i++)
    {
        printf("\nQuestion %d: %s\n",
               i + 1,
               questions[i].question);

        printf("Your answer: %s\n",
               questions[i].options[userAnswers[i] - 1]);

        printf("Correct answer: %s\n",
               questions[i].options[questions[i].correctAnswer - 1]);

        if (userAnswers[i] == questions[i].correctAnswer)
        {
            printf("Result: Correct\n");
        }
        else
        {
            printf("Result: Incorrect\n");
        }
    }
}


/* =========================================================
   SHOW SCORE
   ========================================================= */

void showScore(int score, int totalQuestions)
{
    printf("\nYour score is %d out of %d.\n",
           score,
           totalQuestions);
}


/* =========================================================
   CALCULATE PERCENTAGE
   ========================================================= */

float calculatePercentage(int score, int totalQuestions)
{
    float percentage;

    percentage =
        (score / (float)totalQuestions) * 100;

    printf("Percentage obtained = %.2f%%\n",
           percentage);

    return percentage;
}


/* =========================================================
   SHOW GRADE
   ========================================================= */

void showGrade(float percentage)
{
    if (percentage >= 95)
    {
        printf("Grade: A++\n");
    }
    else if (percentage >= 90)
    {
        printf("Grade: A\n");
    }
    else if (percentage >= 80)
    {
        printf("Grade: B\n");
    }
    else if (percentage >= 70)
    {
        printf("Grade: C\n");
    }
    else if (percentage >= 60)
    {
        printf("Grade: D\n");
    }
    else
    {
        printf("Grade: F\n");
    }
}


/* =========================================================
   LOAD HIGH SCORES
   ========================================================= */

void loadHighScores(
    int highScores[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES],
    int highScoreQuestions[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES]
)
{
    FILE *file;


    file = fopen("highscore.txt", "r");


    if (file == NULL)
    {
        printf("No high score file found.\n");
        printf("Creating a new high score file...\n");


        file = fopen("highscore.txt", "w");


        if (file != NULL)
        {
            for (int i = 0; i < TOTAL_DIFFICULTIES; i++)
            {
                for (int j = 0; j < TOTAL_CATEGORIES; j++)
                {
                    highScores[i][j] = 0;
                    highScoreQuestions[i][j] = 0;

                    fprintf(file, "0 0\n");
                }
            }

            fclose(file);
        }
    }
    else
    {
        for (int i = 0; i < TOTAL_DIFFICULTIES; i++)
        {
            for (int j = 0; j < TOTAL_CATEGORIES; j++)
            {
                fscanf(
                    file,
                    "%d %d",
                    &highScores[i][j],
                    &highScoreQuestions[i][j]
                );
            }
        }

        fclose(file);
    }
}


/* =========================================================
   SAVE HIGH SCORES
   ========================================================= */

void saveHighScores(
    int highScores[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES],
    int highScoreQuestions[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES]
)
{
    FILE *file;


    file = fopen("highscore.txt", "w");


    if (file == NULL)
    {
        printf("Error: Could not save high score.\n");
        return;
    }


    for (int i = 0; i < TOTAL_DIFFICULTIES; i++)
    {
        for (int j = 0; j < TOTAL_CATEGORIES; j++)
        {
            fprintf(
                file,
                "%d %d\n",
                highScores[i][j],
                highScoreQuestions[i][j]
            );
        }
    }


    fclose(file);
}


/* =========================================================
   SHOW HIGH SCORE
   ========================================================= */

void showHighScore(
    int highScores[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES],
    int highScoreQuestions[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES],
    int category,
    int difficulty
)
{
    int highScore =
        highScores[difficulty - 1][category - 1];

    int highScoreQuestionCount =
        highScoreQuestions[difficulty - 1][category - 1];


    if (highScoreQuestionCount == 0)
    {
        printf("High Score: No score yet\n");
    }
    else
    {
        printf(
            "High Score: %d out of %d\n",
            highScore,
            highScoreQuestionCount
        );
    }
}


/* =========================================================
   MAIN
   ========================================================= */

int main()
{
    struct Question questions[TOTAL_QUESTIONS];


    int highScores[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES] = {0};

    int highScoreQuestions[TOTAL_DIFFICULTIES][TOTAL_CATEGORIES] = {0};


    int category;
    int difficulty;
    int totalQuestions;

    int score;

    int playAgain = 1;

    float percentage;
    float oldPercentage;


    bool isInvalid;


    /* =====================================================
       LOAD SAVED HIGH SCORES
       ===================================================== */

    loadHighScores(
        highScores,
        highScoreQuestions
    );


    /* =====================================================
       MAIN GAME LOOP
       ===================================================== */

    do
    {
        printf("\n\n");
        printf("========================================\n");
        printf("       QUIZ MANAGEMENT SYSTEM\n");
        printf("========================================\n");


        /* =================================================
           NUMBER OF QUESTIONS
           ================================================= */

        do
        {
            isInvalid = false;

            printf("\nHow many questions do you want to attempt? (1-6): ");

            totalQuestions = getInteger();


            if (totalQuestions < 1 ||
                totalQuestions > TOTAL_QUESTIONS)
            {
                printf(
                    "Invalid number! Please enter a number from 1 to 6.\n"
                );

                isInvalid = true;
            }

        } while (isInvalid);


        /* =================================================
           CATEGORY
           ================================================= */

        do
        {
            isInvalid = false;


            printf("\n===== SELECT CATEGORY =====\n");
            printf("1. C Basics\n");
            printf("2. Operators\n");
            printf("3. Loops\n");


            printf("Enter category (1-3): ");

            category = getInteger();


            if (category < 1 ||
                category > TOTAL_CATEGORIES)
            {
                printf(
                    "Invalid category! Please enter 1-3.\n"
                );

                isInvalid = true;
            }

        } while (isInvalid);


        /* =================================================
           DIFFICULTY
           ================================================= */

        do
        {
            isInvalid = false;


            printf("\n===== SELECT DIFFICULTY =====\n");
            printf("1. Easy\n");
            printf("2. Medium\n");
            printf("3. Hard\n");


            printf("Enter difficulty (1-3): ");

            difficulty = getInteger();


            if (difficulty < 1 ||
                difficulty > TOTAL_DIFFICULTIES)
            {
                printf(
                    "Invalid difficulty! Please enter 1-3.\n"
                );

                isInvalid = true;
            }

        } while (isInvalid);


        /* =================================================
           LOAD QUESTIONS
           ================================================= */

        printf("\n========================================\n");


        if (difficulty == 1)
        {
            printf("             EASY QUIZ\n");

            loadEasyQuestions(
                category,
                questions
            );
        }
        else if (difficulty == 2)
        {
            printf("            MEDIUM QUIZ\n");

            loadMediumQuestions(
                category,
                questions
            );
        }
        else
        {
            printf("             HARD QUIZ\n");

            loadHardQuestions(
                category,
                questions
            );
        }


        printf("========================================\n");


        /* =================================================
           RUN QUIZ
           ================================================= */

        score = runQuiz(
            questions,
            totalQuestions
        );


        /* =================================================
           RESULT
           ================================================= */

        printf("\n\n");
        printf("========================================\n");
        printf("             QUIZ RESULT\n");
        printf("========================================\n");


        showScore(
            score,
            totalQuestions
        );


        percentage =
            calculatePercentage(
                score,
                totalQuestions
            );


        showGrade(percentage);


        /* =================================================
           HIGH SCORE CALCULATION
           ================================================= */

        oldPercentage = 0;


        if (highScoreQuestions[difficulty - 1][category - 1] > 0)
        {
            oldPercentage =
                (
                    highScores[difficulty - 1][category - 1]
                    /
                    (float)
                    highScoreQuestions[difficulty - 1][category - 1]
                ) * 100;
        }


        /*
           New high score if:

           1. Percentage is higher

           OR

           2. Percentage is equal but more questions
              were completed.
        */

        if (
            percentage > oldPercentage
            ||
            (
                percentage == oldPercentage
                &&
                totalQuestions >
                highScoreQuestions[difficulty - 1][category - 1]
            )
        )
        {
            highScores[difficulty - 1][category - 1] =
                score;


            highScoreQuestions[difficulty - 1][category - 1] =
                totalQuestions;


            saveHighScores(
                highScores,
                highScoreQuestions
            );


            printf("\n*** NEW HIGH SCORE! ***\n");
        }


        /* =================================================
           SHOW HIGH SCORE
           ================================================= */

        showHighScore(
            highScores,
            highScoreQuestions,
            category,
            difficulty
        );


        /* =================================================
           PLAY AGAIN
           ================================================= */

        printf("\n========================================\n");
        printf("Do you want to play again?\n");
        printf("1. Yes\n");
        printf("2. No\n");


        do
        {
            isInvalid = false;


            printf("Enter your choice (1-2): ");

            playAgain = getInteger();


            if (playAgain < 1 ||
                playAgain > 2)
            {
                printf(
                    "Invalid choice! Please enter 1 or 2.\n"
                );

                isInvalid = true;
            }

        } while (isInvalid);


    } while (playAgain == 1);


    /* =====================================================
       EXIT
       ===================================================== */

    printf("\n========================================\n");
    printf("Thank you for playing!\n");
    printf("========================================\n");


    return 0;
}