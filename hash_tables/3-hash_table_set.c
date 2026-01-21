#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - adds or updates a key/value in a hash table
 * @ht: pointer to hash table
 * @key: key string (cannot be empty)
 * @value: value string (will be duplicated)
 *
 * Return: 1 if success, 0 if failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node;
    unsigned long int index;

    if (!ht || !key || strlen(key) == 0 || !value)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    new_node = malloc(sizeof(hash_node_t));
    if (!new_node)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
