
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>





// FUNCTION PROTOTYPES
char matrix[8][8];  /* the tic tac toe matrix */
char check(void);
void init_matrix(void);
void get_borard(void);
void get_player2_move(void);
void disp_matrix(void);
void get_computer_move(void);
void twoplayer_game(void);
void singleplayer(void);
void get_player3_move(void);
get_player4_move(void);

int m, n, z, g, l;
void print_score(void);




int main(void)

{
	int choice;

	printf("\n\npress 1. For 2 player.\n\n");
//	printf("press 2. For single player\n\n");
	printf("press 3. For exiting the game\n\n");
	do
	{
		printf("Enter your choice.\n\n");
		scanf(" %d", &choice);
		switch (choice)
		{

		case (1) : twoplayer_game();
			break;

		//case (2) : singleplayer();
			//break;

		case (3) : exit(1);
		default: printf("\n%d is not a valid choice. \n", choice);
			printf("\ntry again\n\n");
			break;

		}
	} while ((choice <1) || (choice > 5));


	return 0;
}





void twoplayer_game(void)
{
	//system("cls");
	get_borard();
	get_player3_move();



}


void singleplayer(void)
{

	char done;
	done = ' ';
	init_matrix();
	//init_matrix();


	do {

	//	printf("You are playing agaisnt the computer\n\n You are X and the computer is O.");

		printf(" player 1 your move1\n\n\n");
		disp_matrix();
		get_borard();
		done = check(); /* see if winner */
		if (done != ' ') break; /* winner!*/
		disp_matrix();



		printf(" computers move \n\n");
		get_computer_move();

		done = check(); /* see if winner */

	} while (done == ' ');

	if (done == 'Y') printf("You won!\n");
	else printf("I won!!!!\n");
	disp_matrix(); /* show final positions */

}






/* Initialize the matrix. */

void init_matrix(void)
{
	int i, j;

	for (i = 0; i<8; i++)
	for (j = 0; j<8; j++) matrix[i][j] = ' ';
}








/* Get a player1 move. */

void get_borard(void)
{
	typedef enum { empty = 0, pawn, castle, hores, king,bishop, queen, p, c, h, k, q   } chess_piece;
	int x, y;


	for (y = 0; y < 8; y++)
	{
		matrix[y][6] = 'p';

	}
	system("COLOR 3");
	matrix[0][7] = 'c';
	matrix[1][7] = 'h';
	matrix[2][7] = 'b';
	matrix[3][7] = 'k';
	matrix[4][7] = 'q';
	matrix[5][7] = 'b';
	matrix[6][7] = 'h';
	matrix[7][7] = 'c';


	for (y = 0; y < 8; y++)
	{
		matrix[y][1] = 'P';

	}
	//system("COLOR 4");
	matrix[0][0] = 'C';
	matrix[1][0] = 'H';
	matrix[2][0] = 'B';
	matrix[3][0] = 'K';
	matrix[4][0] = 'Q';
	matrix[5][0] = 'B';
	matrix[6][0] = 'H';
	matrix[7][0] = 'C';





}
//player 2 moving//

void get_player2_move(void)
{
	int x, y, m, n, z, g, l;
	disp_matrix();
	printf("Player two enter The cordinates for your move: ");
	scanf("%d%*c%d", &x, &y);

	x--; y--;

	if (matrix[x][y] == 'c')
	{
		matrix[x][y] = ' ';
		do{
			z = x + y;
			printf(" place the peace \n\n");
			scanf("%d%*c%d", &n, &m);
			l = n + m;
			g = z - l;
		} while ((g >= 0) && (g <= 1));
		n--; m--;
		matrix[n][m] = 'c';
		disp_matrix();
		//system("cls");
		get_player3_move();
		/*
		matrix[x][y] = ' ';
		printf(" place the peace\n\n ");
		scanf("%d%*c%d", &x, &y);
		matrix[x][y] = 'c';
		//disp_matrix();
		system("cls");
		get_player3_move();
		*/
	}
	else if (matrix[x][y] == 'p')
	{



			//matrix[x][y] = ' ';
			do{
				z =  x + y ;
				printf(" place the peace \n\n");
				scanf("%d%*c%d", &n, &m);
				l = n + m;
				g = z-l;
			} while ((g >= 0) && (g<=1));
			n--; m--;
			matrix[n][m] = 'p';
			disp_matrix();
		//	system("cls");
			get_player3_move();
		}


	else if (matrix[x][y] == 'h')
	{

		matrix[x][y] = ' ';
		printf(" place the peace \n\n");
		scanf("%d%*c%d", &x, &y);
		matrix[x][y] = 'h';
		system("cls");
		get_player3_move();

	}
	else if (matrix[x][y] == 'b')
	{
		matrix[x][y] = ' ';
		printf(" place the peace \n\n");
		scanf("%d%*c%d", &x, &y);
		matrix[x][y] = 'b';
	//	disp_matrix();
		system("cls");
		get_player3_move();
	}


	else if (matrix[x][y] == 'k')
	{

		matrix[x][y] = ' ';
		printf(" place the peace ");
		scanf("%d%*c%d", &x, &y);
		matrix[x][y] = 'k';
		//disp_matrix();
		system("cls");
		get_player3_move();
	}


	else if (matrix[x][y] == 'q')
	{

		matrix[x][y] = ' ';
		printf(" place the peace ");
		scanf("%d%*c%d", &x, &y);
		matrix[x][y] = 'q';
		disp_matrix();
		system("cls");
		get_player3_move();
	}

	else
	{
		printf("\n\n wrong movie, Player two try again!! \n\n");
		//system("cls");
		get_player2_move();
	}


}



/* PLAYER 1 MOVE. */

void get_player3_move(void)
{
system("cls");
	int x, y;

	disp_matrix();

  printf("Player1 enter The cordinates for your move: ");
  scanf("%d%*c%d", &x, &y);

  x--; y--;

  if (matrix[x][y] == 'C')
  {

  matrix[x][y] = ' ';
  printf(" place the peace\n\n ");
  scanf("%d%*c%d", &x, &y);
  x--; y--;
  matrix[x][y] = 'C';
  disp_matrix();
  system("cls");
  get_player2_move();

  }
  else if (matrix[x][y] == 'P')

  {
	  matrix[x][y] = ' ';

	  do{
		  z = 2*(x + y)+1;

		  printf(" place the peace \n\n");
		  scanf("%d%*c%d", &n, &m);

printf(" the posistion for player1 = %d, %d\n\n", n, m);
		  l = n + m;
		  g = l - z;
	  }
	  while (g >= 2);
		  n--; m--;
		  matrix[n][m] = 'P';

	//  disp_matrix();
	// system("cls");

	  get_player2_move();
  }


  else if (matrix[x][y] == 'H')
  {

  matrix[x][y] = ' ';
  printf(" place the peace \n\n");
  scanf("%d%*c%d", &x, &y);
  x--; y--;
  matrix[x][y] = 'H';
 // disp_matrix();
  system("cls");
  get_player2_move();

  }
  else if (matrix[x][y] == 'B')
  {
  matrix[x][y] = ' ';
  printf(" place the peace \n\n");
  scanf("%d%*c%d", &x, &y);
  x--; y--;
  matrix[x][y] = 'B';
  system("cls");
  get_player2_move();
  }


  else if (matrix[x][y] == 'K')
  {

  matrix[x][y] = ' ';
  printf(" place the peace ");
  scanf("%d%*c%d", &x, &y);
  x--; y--;
  matrix[x][y] = 'K';
  system("cls");
  get_player2_move();
  }


  else if (matrix[x][y] == 'Q')
  {

  matrix[x][y] = ' ';
  printf(" place the peace ");
  scanf("%d%*c%d", &x, &y);
  x--; y--;
  matrix[x][y] = 'Q';
  system("cls");
  get_player2_move();
  }

  else
  {
  printf("\n\n wrong movie, Player one try again!! \n\n");
  system("cls");
  get_player3_move();
  }




}









/* Get a move from the computer. */

void get_computer_move(void)
{
	int  j;

	for (j = 0; j<8; j++)
	{
		for (j = 0; j<8; j++)
		if (matrix[j][j] == ' ') break;
		if (matrix[j][j] == ' ') break;

	}

	if (j == 64)
	{
		printf("draw\n");
		exit(0);
	}
	else
		matrix[j][j] = 'O';
}




/* Display the matrix on the screen. */
void disp_matrix(void)
{
	int t;

	for (t = 0; t<8; t++)
	{
		printf("| %c | %c | %c | %c | %c | %c | %c | %c |", matrix[t][0], matrix[t][1], matrix[t][2], matrix[t][3], matrix[t][4], matrix[t][5],

			matrix[t][6], matrix[t][7]);
		 printf("\n|---|---|---|---|---|---|---|---|\n");
	}
	printf("\n");

}







/* See if there is a winner. */
// check looks after
char check(void)
{
	int i;

	for (i = 0; i<8; i++)  /* check rows */
	if (matrix[i][0] == matrix[i][1] &&
		matrix[i][0] == matrix[i][2] &&
		matrix[i][0] == matrix[i][3] &&
		matrix[i][0] == matrix[i][4] &&
		matrix[i][0] == matrix[i][5] &&
		matrix[i][0] == matrix[i][6] &&
		matrix[i][0] == matrix[i][7] &&
		matrix[i][0] == matrix[i][8])
		return matrix[i][0];


	for (i = 0; i<8; i++)  /* check columns */
	if (matrix[0][i] == matrix[1][i] &&
		matrix[0][i] == matrix[2][i] &&
		matrix[0][i] == matrix[3][i] &&
		matrix[0][i] == matrix[4][i] &&
		matrix[0][i] == matrix[5][i] &&
		matrix[0][i] == matrix[6][i] &&
		matrix[0][i] == matrix[7][i] &&
		matrix[0][i] == matrix[8][i])

		return matrix[0][i];


	/* test diagonals */
	if (matrix[0][0] == matrix[1][1] &&
		matrix[1][1] == matrix[2][2])

		return matrix[0][0];

	if (matrix[0][2] == matrix[1][1] &&
		matrix[1][1] == matrix[2][0])
		return matrix[0][2];



	return ' ';
}




