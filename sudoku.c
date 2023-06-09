// Importation des librairies essentielles
#include <stdlib.h>
#include <stdio.h>
typedef struct Cell { //Définition de la fonction Cell
	int x;
	int y;
	int occupe;
} Cell;

typedef struct Grid { //Définition de la fonction Board
	Cell* cell;
	int width;
	int height;
} Grid;

void initGrid(Grid* grid); //Init de initBoard
void displayGrid(Grid* grid); //Init de displayBoard
void placeNumber(Grid* grid, int x, int y, int number); //Init de la fonction pour placer un chiffre

int getCellPosition(Grid* grid, int x, int y) { //Récupère la position d'une cellule
	return x * grid->width + y;
}

Cell* getCell(Grid* grid, int x, int y) { //Récupère une cellule
	int pos = getCellPosition(grid, x, y);
	return &grid->cell[pos];
}

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

void displayGrid(Grid* grid) { //Affichage du tableau
	printf("\n");
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
	Grid grid;
	grid.height = 9; //Définition de la taille du tableau (largeur et hauteur)
	grid.width = 9;

	initGrid(&grid);	  //
	displayGrid(&grid); //Fonction pour démarrer le jeu

  return 0;
}
