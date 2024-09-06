#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elementfile 
{
	int valeur;
	struct elementfile *suivant;
}elementfile;

typedef struct File
{
	elementfile *premier;
}File;

void initialiser(File *une_file)
{
	une_file->premier = NULL;
}

bool est_vide(File *une_file)
{
	return (une_file->premier == NULL);
}

void enfiler(File *une_file, int valeur)
{
	elementfile *nouveau = (elementfile *)malloc(sizeof(elementfile));

	if(nouveau == NULL)
	{
		printf("Echec de l'allocation de la memoire a nouveau . \n");
		return; 
	}

	nouveau->valeur = valeur;
	nouveau->suivant = NULL;

	if(est_vide(une_file))
	{
		une_file->premier = nouveau;
	}
	else
	{
		elementfile *p = une_file->premier;
		while(p->suivant != NULL)
		{
			p = p->suivant;
		}
		p->suivant = nouveau;
	}
}

int defiler(File *une_file)
{
	int valeur_supprimer = 0;

	if(est_vide(une_file))
	{
		printf("File vide : impossible de supprimer !! \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		elementfile *a_supprimer = une_file->premier;
		valeur_supprimer = une_file->premier->valeur;
		une_file->premier = une_file->premier->suivant;
		free(a_supprimer);
	}
	return valeur_supprimer;	
}

void afficher(File *une_file)
{
	printf("\nEtat de la file : \n");
	elementfile *p = une_file->premier;
	while(p != NULL)
	{
		printf(" %d ", p->valeur);
		p = p->suivant;
	}
}

void liberer(File *une_file)
{
	elementfile *p = une_file->premier;
	while(p != NULL)
	{
		free(p);
		p = p->suivant;
	}	
}

int main(void)
{
	printf("Creation d'une file........\n\n");
	File une_file;

	printf("initialisation de la file........\n\n");	
	initialiser(&une_file);

	printf("Enfilement........\n\n");
	enfiler(&une_file, 4);
	enfiler(&une_file, 8); 
	enfiler(&une_file, 15); 
	enfiler(&une_file, 16); 
	enfiler(&une_file, 23); 
	enfiler(&une_file, 42);

	afficher(&une_file);

	printf("\nJe defile 4 \n");
	printf("\nJe defile 8 \n");

	defiler(&une_file);
	defiler(&une_file);

	afficher(&une_file);

	printf("\nJe defile le reste......\n");

	defiler(&une_file);
	defiler(&une_file);	
	defiler(&une_file);
	defiler(&une_file);	

	afficher(&une_file);


	return 0;
}