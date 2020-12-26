#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define PATTERN_SIZE 32

int menu(int highScore)
{
    system("CLS");
    printf("\n\nWelcome to Simon Says\nHigh score = %d\n\n", highScore);
    printf("1) Play again\n2) Exit\nchoose: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

int main()
{
    system("CLS");
    printf("\n\nSimon Says is a children's game for three or more players. \nOne player takes the role of 'Simon' and issues instructions \nto the other players,which should be followed only when prefaced \nwith the phrase 'Simon says'\n\npress any key to continue");
    getchar();

    srand(time(NULL));
    int score=0, highScore=0;
    while (menu(highScore) != 2)
    {
        char simonPatter[PATTERN_SIZE] = {0}, userPattern[PATTERN_SIZE] = {0};
        int gameover = 0;
        while (gameover != 1)
        {
            int lenght = 0; //lenght of new pattern
            //generate next color
            for (int i = 0; i < PATTERN_SIZE; i++)
            {
                lenght++;
                if (simonPatter[i] != 0)
                {
                    continue;
                }
                else
                {
                    //generate a randome number presenting a color between
                    //red, blue, yellow, green
                    int randColor = rand() % 4 + 1;
                    /*
                     * or use rand() / (RAND_MAX + 1)
                     * RAND_MAX = 4
                     */
                    //red = 1, blue = 2, yellow = 3, green = 4
                    switch (randColor)
                    {
                    case 1:
                        simonPatter[i] = 'R';
                        break;
                    case 2:
                        simonPatter[i] = 'B';
                        break;
                    case 3:
                        simonPatter[i] = 'Y';
                        break;
                    case 4:
                        simonPatter[i] = 'G';
                        break;
                    }
                    //break the loop
                    break;
                }
            }
            
            //print Simon's pattern
            printf("\n\nSimons Pattern : ");
            for (int i = 0; i < PATTERN_SIZE; i++)
            {
                if (simonPatter[i] == 0)
                {
                    printf("\n");
                    break;
                }
                
                printf("%c", simonPatter[i]);
            }
            //flush buffer
            fflush(stdin);

            //get User's pattern
            printf("User pattern : ");
            for (int i = 0; i < lenght; i++)
            {
                char c;
                scanf("%c", &c);
                userPattern[i] = c;
            }

            //compare patterns
            for (int i = 0; i < lenght; i++)
            {
                if (userPattern[i] == simonPatter[i])
                {
                    score++;
                }
            }
            
            //update highscore
            printf("score: %d\n", score);
            highScore = score >= highScore ? score : highScore;

            //round gameover
            if (score != lenght)
            {
                printf("GAMEOVER!\nPress any button");
                gameover = 1;

                //flush buffer
                fflush(stdin);
                //getchar to continue
                getchar();
            }

            //reset score
            score = 0;
        }
    }
}