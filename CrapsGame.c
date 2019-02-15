#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//prupose: to produce 2 pseudo random rolls[1,6], calculate the sum, and use sum as roll value
int rollDice(void)
{
    int roll1 = 0, roll2 = 0, sum = 0;
    
    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;
    
    sum = roll1 + roll2;
    
    return sum;
}

//purpose: to have the user roll the dice until they win or lose pointGame
//win (rolling same value as point) = true
//lose (rolling a 7) = false
bool pointGame(int roll)
{
    int point = roll;
    
    printf("Your point is: %d\n", point);
    
    do {
        roll = rollDice();
        printf("You rolled: %d\n", roll);
    } while (roll != point && roll != 7);
    
    if(roll == point) {
        printf("You win!\n");
        return(true);
    } 
    
    printf("You lose!\n");
    return(false);
}

//purpose: to play a round of craps
//win (rolling 7, 11, or winning pointGame) = true
//lose (rolling 2, 3, 12, or losing pointGame = false
bool playGame(void)
{
    int roll = 0;
    bool pointResult; 
    roll = rollDice();
    
    printf("You rolled: %d\n", roll);
    
    if(roll == 7 || roll == 11) {
        printf("You win!\n");
        return(true);
    } else if(roll == 2 || roll == 3 || roll == 12) {
        printf("You lose!\n");
        return(false);
    } else {
        pointResult = pointGame(roll);
        return(pointResult);
    }
}

    
//purpose: to carry out the game until user presses any key other than 'y' / 'Y'
//purpose: to count number of wins/losses
void winLoss(void)
{
    int wins = 0, losses = 0;
    char playAgain = 0;
    do {
        bool gamePlayed = playGame();
    
        if (gamePlayed == true) {
            wins++;
        } else {
            losses++;
        }
        
        printf("Play again? ");
        scanf(" %c", &playAgain);
        
    } while(playAgain == 'y' || playAgain == 'Y');
     
    printf("\nWins: %d\nLosses: %d\n", wins, losses);
}

