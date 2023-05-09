// Importation des librairies essentielles
#include <stdlib.h>
#include <stdio.h>

typedef struct Cell { //Définition de la fonction Cell
	int x;
	int y;
	int occupe;
} Cell;

typedef struct Board { //Définition de la fonction Board
	Cell* cell;
	int width;
	int height;
} Board;

void initBoard(Board* board); //Init de initBoard
void displayBoard(Board* board); //Init de displayBoard

int getCellPosition(Board* board, int x, int y) { //Récupère la position d'une cellule
	return x * board->width + y;
}

Cell* getCell(Board* board, int x, int y) { //Récupère une cellule
	int pos = getCellPosition(board, x, y);
	return &board->cell[pos];
}

void initBoard(Board* board) {
	board->cell = (Cell*)malloc(sizeof(Cell) * board->width * board->height); //Attribution d'un espace dans la mémoire au tableau
	for (int x = 0; x < board->width; x++) {
		for (int y = 0; y < board->height; y++) {
			Cell* cell = getCell(board, x, y); //Définition des valeurs des cellules par défaut
			cell->x = x;
			cell->y = y;
			cell->occupe = 0;
		}
	}
}

void displayBoard(Board* board) { //Affichage du tableau
	printf("\n");
	for (int x = 0; x < board->width; x++) {
		for (int y = 0; y < board->height; y++) {
			Cell* cell = getCell(board, x, y); //Récupération des cellules
			char display = '.'; //Mettre un . si occupe vaut 0
			if (cell->occupe == 1) {
				display = 'O'; //Mettre un O si occupe vaut 1
			}
			printf("%c", display); //Affichage sur le tableau des valeurs occupe
		}
		printf("\n");
	}
}

int main() {
	Board board;
	board.height = 9; //Définition de la taille du tableau (largeur et hauteur)
	board.width = 9;


	initBoard(&board);	  //
	displayBoard(&board); //Fonction pour démarrer le jeu

  return 0;
}
