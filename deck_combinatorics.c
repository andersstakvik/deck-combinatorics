#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CARDS_IN_DECK 52

int search_for_deck(void);
unsigned char deck_is_full(unsigned char *);

int main(int argc, char **argv)
{
    int i;
    int searches;
    int sum_of_searches;
    float avg_num_cards;

    if (argc <= 1) {
        printf("Usage: ./deck_combinatorics <number>\n");
        return 0;
    }
    
    srand(time(NULL));
    searches = atoi(argv[1]); /* strtol er bedre */
    
    for (i = 0; i < searches; i++) {
        sum_of_searches += search_for_deck();
    }

    avg_num_cards = (float) sum_of_searches / (float) searches;
    printf("The average number of cards is %f.\n", avg_num_cards);
    return 0;
}

int search_for_deck(void)
{
    unsigned char cards[CARDS_IN_DECK];
    int cards_found = 0;
    int card;

    memset(cards, 0, CARDS_IN_DECK);

    for (cards_found = 0; !deck_is_full(cards); cards_found++) {
        card = rand() % 52;
        cards[card] = 1;
    }

    return cards_found;
}

unsigned char deck_is_full(unsigned char *deck)
{
    int i;

    for (i = 0; i < CARDS_IN_DECK; i++) {
        if (!deck[i]) return 0;
    }

    return 1;
}
