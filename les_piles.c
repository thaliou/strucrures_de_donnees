#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elementpile
{
	int valeur;
	struct elementpile *suivant;
}elementpile;

typedef struct elementpile pile;

bool pile_vide(pile *s)
{
	if(s == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

pile *empiler(pile **s, int valeur)
{
	pile * nouveau;
	nouveau = (pile *)malloc(sizeof(pile));
	nouveau->valeur = valeur;

	if(pile_vide(&s))
	{
		nouveau->suivant = NULL;
		*s = nouveau;
	}
	else
	{
		nouveau->suivant = *s;
		*s = nouveau;
	}
	return *s;
}

pile *depiler(pile **s)
{
	if(pile_vide(&s))
	{
		printf(" La pile est vide .\n");
		return NULL;
	}
	else
	{
		pile *temporaire = *s;
		*s = (*temporaire)->suivant;
		free(temporaire);
	}
	return *s; 
}

int main(void)
{
	pile *sommet = NULL;
	return 0;
}