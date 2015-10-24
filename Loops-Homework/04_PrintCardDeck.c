/* 
 * Write a program that generates and prints all possible cards from
 * a standard deck of 52 cards (without the jokers). The cards should be
 * printed using the classical notation (like 5S (♠), AH (♥), 9C (♣) and KD (♦)).
 * The card faces should start from 2 to A.
 * Print each card face in its four possible suits: clubs, diamonds, hearts and spades.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int row = 2; row < 15; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (row < 11)
            {
                printf("%d", row);
            }
            else
            {
                switch (row)
                {
                    case 11:
                        printf("J");
                        break;
                    case 12:
                        printf("Q");
                        break;
                    case 13:
                        printf("K");
                        break;
                    case 14:
                        printf("A");
                        break;
                }
            }
            
            switch (col)
            {
                case 0:
                    printf("C ");
                    break;
                case 1:
                    printf("D ");
                    break;
                case 2:
                    printf("H ");
                    break;
                case 3:
                    printf("S ");
                    break;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}

