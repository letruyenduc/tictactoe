#include <stdio.h>

void display_grid(char grid[3][3])
{
    printf("    +   +   \n");
    for (int i = 0; i < 3; i++)
    {
        printf("  %c | %c | %c \n", grid[i][0], grid[i][1], grid[i][2]);
        if (i < 2)
        {
            printf("+---+---+---+\n");
        }
    }
    printf("    +   +   \n");
    printf("\n");
}
int win_cond_horizontal(char grid[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        while (count < 3 && grid[i][count] == player)
        {
            count++;
        }
        if (count == 3)
        {
            return 1;
        }
    }
    return 0;
}
int win_cond_vertical(char grid[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        while (count < 3 && grid[count][i] == player)
        {
            count++;
        }
        if (count == 3)
        {
            return 1;
        }
    }
    return 0;
}
int win_cond_diagonale(char grid[3][3], char player)
{

    int count = 0;
    while (count < 3 && grid[count][count] == player)
    {
        count++;
    }
    if (count == 3)
    {
        return 1;
    }
    count = 0;
    while (count < 3 && grid[count][3 - count - 1] == player)
    {
        count++;
    }
    if (count == 3)
    {
        return 1;
    }

    return 0;
}
int win_cond_global(char grid[3][3], char player)
{
    return win_cond_horizontal(grid, player) || win_cond_vertical(grid, player) || win_cond_diagonale(grid, player);
}

void play(char grid[3][3], char player)
{
    int swi = 1;
    while (swi)
    {
        int tile;
        printf("Joueur %c choisir une case : ", player);

        // Ici
        if (scanf("%d", &tile) != 1)
        {
            while (getchar() != '\n');
            printf("Erreur : entrez un chiffre uniquement.\n");
            continue;
        }
        // ici
        if (tile > 0 && tile <= 9)
        {
            int row = (tile - 1) / 3;
            int col = (tile - 1) % 3;
            if (grid[row][col] != 'x' && grid[row][col] != 'o')
            {
                grid[row][col] = player;
                swi = 0;
            }
            else{
                printf("La case est occupee, ressayez.\n");
            }
        }
        else{
            printf("Le chiffre doit etre entre 1-9\n");
        }
    }
}
void nextPlayer(char players[2])
{
    int tmp = players[0];
    players[0] = players[1];
    players[1] = tmp;
}
int main()
{
    char grid[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};
    char players[2] = {'o', 'x'};
    int rounds = 0;
    while (1)
    {
        display_grid(grid);
        play(grid, players[0]);
        nextPlayer(players);
        rounds++;
        if (win_cond_global(grid, players[1]))
        {
            display_grid(grid);
            printf("\nLe joueur %c a gagne!\n", players[1]);
            break;
        }
        if (rounds == 9)
        {
            printf("Egalite");
            break;
        }
    }
    return 0;
}