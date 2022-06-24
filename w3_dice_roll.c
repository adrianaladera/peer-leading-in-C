/* Author:          Arcade Buddies
   Program:         Dice Roll
   Description:     Create a program that simulates rolling
                    three dice in a row, and give Greenbae an award
                    if they get three of the same number in a row. */

 #include <stdio.h>
 #include <stdlib.h> //use this for rand() function
 #include <time.h> //call the time() function

 int main()
 {
    int choice = 1, flag = 0; //allows options for game play
    srand(time(NULL));

    printf("\n********************* Welcome to the Dice Roller 420 **************************\n"
            "\nDo you want to play? \nEnter 1 for yes, or 0 for no.\n");

    scanf("%d", &choice);

    //allows user to play multiple times
    while(choice == 1)
    {
        int i; //increment
        int roll[3]; //int array - stores the values of each dice roll
        //array indices: n - 1
        printf("\n\nYour Rick Rolls:\n");

        for(i = 0; i < 3; i++) //replicate our three in a row dice rolls
        {
            int num = (rand() % (6 + 1 - 1) + 1); //range of dice faces from 1 - 6 inclusive
            roll[i] = num; //0 - 2, 1 - 2, 2 - 2
            switch(num)
            {
                case 1: printf("face 1\n");
                break;
                case 2: printf("face 2\n");
                break;
                case 3: printf("face 3\n");
                break; 
                case 4: printf("face 4\n");
                break;      
                case 5: printf("face 5\n");
                break;     
                case 6: printf("face 6\n");
                break;                                                   
            }//switch

        }//for loop

        //if all three results are the same, then the user wins da $hmoneyyyyy
        if(roll[0] == roll[1] && roll[0] == roll[2]) //check if all three dice rolls are the same
        {
            printf("\nCongrats bestie! You won 1,000 Goofy Goober Dollars!\n");
            flag = 1;
        }

        if(flag == 0)
            printf("\nSorry, you didn't win :(((\n");

        printf("\nWould you like to play again?\nPress 1 to continue, 0 to quit: \n");
        scanf("%d", &choice);

        if(choice == 0)
        {
            printf("\nThank you for playing!\n Copyright 2022 Notta Reele Company\n\n");
        }

    }//while loop

    return 0;
 }                   