/*
 * sort_deck.c
 *
 * This file contains the implementation of a function to sort a deck of cards.
 * It sorts the deck in ascending order based on card values and kinds.
 *
 * Author: [Your Name]
 */

#include <stdlib.h>
#include <string.h>
#include "deck.h"

/*
 * Function: compare_cards
 * ------------------------
 * Compare function used by qsort to compare two card nodes.
 *
 * a: Pointer to the first card node
 * b: Pointer to the second card node
 *
 * Returns: An integer less than, equal to, or greater than zero if the first argument is
 * less than, equal to, or greater than the second argument, respectively.
 */
int compare_cards(const void *a, const void *b);

/*
 * Function: sort_deck
 * -------------------
 * Sorts a deck of cards in ascending order.
 *
 * deck: Pointer to a pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t deck_size = 52;
	size_t i;
	deck_node_t **node_array = malloc(deck_size * sizeof(deck_node_t *));
	deck_node_t *current;

	if (!deck || !*deck || !node_array)
		return;

	current = *deck;

	for (i = 0; i < deck_size; i++)
	{
		node_array[i] = current;
		current = current->next;
	}

	qsort(node_array, deck_size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < deck_size - 1; i++)
	{
		node_array[i]->next = node_array[i + 1];
		node_array[i + 1]->prev = node_array[i];
	}
	node_array[deck_size - 1]->next = NULL;

	*deck = node_array[0];
	free(node_array);
}

int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;

	int value_cmp = strcmp(node_a->card->value, node_b->card->value);
	if (value_cmp != 0)
		return value_cmp;

	return node_a->card->kind - node_b->card->kind;
}

