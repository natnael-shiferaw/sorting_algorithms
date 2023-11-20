#include "deck.h"

/**
 * StrCmp - A function used to compare
 *  two strings.
 * @str1: represents the first string.
 * @str2: represents the second string.
 *
 * Return: Positive byte if str1 > str2
 *         Negative byte if str1 < str2
 *         0 if str1 == str2
 */

int StrCmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * Get_Val - A fucntion that is used for getting the
 *  numerical value of a card.
 * @card: represents the pointer that points to
 *  a card of type deck_node_t.
 *
 * Return: returns the value of the card numerically.
 */

char Get_Val(deck_node_t *card)
{
	if (StrCmp(card->card->value, "Ace") == 0)
		return (0);
	if (StrCmp(card->card->value, "1") == 0)
		return (1);
	if (StrCmp(card->card->value, "2") == 0)
		return (2);
	if (StrCmp(card->card->value, "3") == 0)
		return (3);

    if (StrCmp(card->card->value, "4") == 0)
		return (4);
	if (StrCmp(card->card->value, "5") == 0)
		return (5);
	if (StrCmp(card->card->value, "6") == 0)
		return (6);
	if (StrCmp(card->card->value, "7") == 0)
		return (7);

    if (StrCmp(card->card->value, "8") == 0)
		return (8);
	if (StrCmp(card->card->value, "9") == 0)
		return (9);
	if (StrCmp(card->card->value, "10") == 0)
		return (10);
	if (StrCmp(card->card->value, "Jack") == 0)
		return (11);
	if (StrCmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_deck_of_cards_sp_to_dia - A function that is used for sorting
 *  a deck of cards in order from Spades to diamonds.
 * @deck: represents a pointer that points to the head
 *  of a doubly-linked list that's type deck_node_t.
 * Return: It returns Nothing.
 */

void sort_deck_of_cards_sp_to_dia(deck_node_t **deck)
{
    deck_node_t *Temp;
	deck_node_t *Iter, *Ins;

	for (Iter = (*deck)->next; Iter != NULL; Iter = Temp)
	{
		Temp = Iter->next;
		Ins = Iter->prev;

        while (Ins != NULL && Ins->card->kind > Iter->card->kind)
		{
			Ins->next = Iter->next;
			if (Iter->next != NULL)
				Iter->next->prev = Ins;
			Iter->prev = Ins->prev;
			Iter->next = Ins;
			if (Ins->prev != NULL)
				Ins->prev->next = Iter;
			else
				*deck = Iter;
			Ins->prev = Iter;
			Ins = Iter->prev;
		}
	}
}

/**
 * sort_deck_of_cards_ace_to_king - A function that is used
 *  to sort a deck of cards(that are sorted from Spades
 *  to diamonds) from ace to king.
 * @deck: represents a pointer that points to the
 *  head of a doubly-linked list that's type deck_node_t.
 * Return: It returns Nothing.
 */

void sort_deck_of_cards_ace_to_king(deck_node_t **deck)
{
	deck_node_t *Iter, *Ins, *Temp;

	for (Iter = (*deck)->next; Iter != NULL; Iter = Temp)
	{
		Temp = Iter->next;
		Ins = Iter->prev;

        while (Ins != NULL &&
		       Ins->card->kind == Iter->card->kind &&
		       Get_Val(Ins) > Get_Val(Iter))
		{
			Ins->next = Iter->next;
			if (Iter->next != NULL)
				Iter->next->prev = Ins;
			Iter->prev = Ins->prev;
			Iter->next = Ins;

            if (Ins->prev != NULL)
				Ins->prev->next = Iter;
			else
				*deck = Iter;
			Ins->prev = Iter;
			Ins = Iter->prev;
		}
	}
}

/**
 * sort_deck - A function that is used for sorting a
 *  deck of cards in order from - ace to king and
 *                             - spades to diamonds.
 * @deck: represents a pointer that points to the
 *  head of a doubly-linked list that's
 *  type deck_node_t.
 * Return: It returns Nothing.
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_of_cards_sp_to_dia(deck);
	sort_deck_of_cards_ace_to_king(deck);
}
