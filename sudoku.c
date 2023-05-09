// Importation des librairies essentielles
#include <stdlib.h>
#include <stdio.h>
typedef struct Cell { //Définition de la fonction Cell
	int x;
	int y;
	int occupe;
} Cell;

typedef struct Board { //Définition de la fonction Board
typedef struct Grid { //Définition de la fonction Board
	Cell* cell;
	int width;
	int height;
} Board;
} Grid;

void initBoard(Board* board); //Init de initBoard
void displayBoard(Board* board); //Init de displayBoard
void initGrid(Grid* grid); //Init de initBoard
void displayGrid(Grid* grid); //Init de displayBoard
void placeNumber(Grid* grid, int x, int y, int number); //Init de la fonction pour placer un chiffre

int getCellPosition(Board* board, int x, int y) { //Récupère la position d'une cellule
	return x * board->width + y;
int getCellPosition(Grid* grid, int x, int y) { //Récupère la position d'une cellule
	return x * grid->width + y;
}

Cell* getCell(Board* board, int x, int y) { //Récupère une cellule
	int pos = getCellPosition(board, x, y);
	return &board->cell[pos];
Cell* getCell(Grid* grid, int x, int y) { //Récupère une cellule
	int pos = getCellPosition(grid, x, y);
	return &grid->cell[pos];
}

void initBoard(Board* board) {
	board->cell = (Cell*)malloc(sizeof(Cell) * board->width * board->height); //Attribution d'un espace dans la mémoire au tableau
	for (int x = 0; x < board->width; x++) {
		for (int y = 0; y < board->height; y++) {
			Cell* cell = getCell(board, x, y); //Définition des valeurs des cellules par défaut
void initGrid(Grid* grid) {
	grid->cell = (Cell*)malloc(sizeof(Cell) * grid->width * grid->height); //Attribution d'un espace dans la mémoire au tableau
	for (int x = 0; x < grid->width; x++) {
		for (int y = 0; y < grid->height; y++) {
			Cell* cell = getCell(grid, x, y); //Définition des valeurs des cellules par défaut
			cell->x = x;
			cell->y = y;
			cell->occupe = 0;
		}
	}
}

void displayBoard(Board* board) { //Affichage du tableau
void displayGrid(Grid* grid) { //Affichage du tableau
	printf("\n");
	for (int x = 0; x < board->width; x++) {
		for (int y = 0; y < board->height; y++) {
			Cell* cell = getCell(board, x, y); //Récupération des cellules
			char display = '.'; //Mettre un . si occupe vaut 0
			if (cell->occupe == 1) {
				display = 'O'; //Mettre un O si occupe vaut 1
			}
	for (int x = 0; x < grid->width; x++) {
		for (int y = 0; y < grid->height; y++) {
			Cell* cell = getCell(grid, x, y); //Récupération des cellules
			char display = '.'; //Mettre un . pour afficher le tableau
			printf("%c", display); //Affichage sur le tableau des valeurs occupe
		}
		printf("\n");
	}
}

void placeNumber(Grid* grid, int x, int y, int number) {
	grid->cell[getCellPosition(grid, x, y)].occupe = number; //Permet de placer un chiffre dans la grille
}

int main() {
	Board board;
	board.height = 9; //Définition de la taille du tableau (largeur et hauteur)
	board.width = 9;
	Grid grid;
	grid.height = 9; //Définition de la taille du tableau (largeur et hauteur)
	grid.width = 9;


	initBoard(&board);	  //
	displayBoard(&board); //Fonction pour démarrer le jeu
	initGrid(&grid);	  //
	displayGrid(&grid); //Fonction pour démarrer le jeu

  return 0;
}
