#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("BATCH SIMULATOR RUNNING\n");
    printf("*---------------------*\n");

    int running = 1;
    int input = 0;
    char command[100];
    char currentDir[100] = "/workspace/CMPS431/batch/jobs/";

    while(running == 1) {

        printf("Working Directory: %s \n", currentDir);
        printf("Enter Your Action:\n");
        printf("1. List jobs\n2. Set jobs directory\n3. Compile and run specific job\n4. Compile and run all jobs in a specific directory.\n5. Help / Options\n6. Shutdown\n");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("Jobs in Directory...\n");
                sprintf(command, "cd %s && dir /B *.c", currentDir);
                system(command);
                break;
            
            case 2:
                printf("Enter a New Directory: (If this is giving you trouble add a / at the end)\n");
                scanf("%s", &currentDir);
                printf("Current Directory is set to: %s", currentDir);
                break;

            case 3:
                printf("Running a Specific Program...\n");
                sprintf(command, "cd %s && dir /B *.c", currentDir);
                system(command);

                printf("Which Program Would you like to Run? (Please Include Extension)\n");
                char prog[50];
                scanf("%s", &prog);
                sprintf(command, "cd %s && gcc -o prog %s", currentDir, prog);
                system(command);
                sprintf(command, "cd %s && prog.exe", currentDir);
                system(command);
                break;
            
            case 4:
                printf("Running All Programs at: %s... \n", currentDir);
                sprintf(command, "cd %s && dir /B *.c > queue.txt", currentDir);
                system(command);
                FILE *input;
                char inputPath[50];
                sprintf(inputPath, "%squeue.txt", currentDir);
                input = fopen(inputPath, "r");
                if (input != NULL) {
                    char line[25];
                    while(fgets(line, sizeof(line), input) != NULL) {
                        sprintf(command, "cd %s && gcc -o prog %s", currentDir, line);
                        system(command);
                        sprintf(command, "cd %s && prog.exe", currentDir);
                        system(command);                    
                    }
                }
                else {
                    printf("No Programs Found to Run\n");
                }
                fclose(input);
                break;

            case 5:
                printf("Need Help?\n");
                printf("Contact Thomas Floyd - thomas.floyd@selu.edu\n");
                printf("Thomas didn't add options to the programs yet, he might come back and do that, but right now he's eating pizza or watching anime, IDK ask him you have his contact now right?\n");
                break;  

            case 6:
                printf("Shutting Down & Deleting all Temp. Files...\nHave a Great Day!\n");
                sprintf(command, "cd %s && del prog.exe", currentDir);
                system(command);
                sprintf(command, "cd %s && del queue.txt", currentDir);
                system(command);
                running = 0;
                break;
            

            default:
                printf("Didn't QUITE catch that, try again...\n");
                break;
        }
        printf("\n\n");
    }
}