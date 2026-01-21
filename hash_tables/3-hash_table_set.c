#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * update_value - updates the value of an existing key
 * @node: node to update
 * @value: new value
 *
 * Return: 1 if success, 0 if failure
 */
int update_value(hash_node_t *node, const char *value)
{
	char *val_copy;

	val_copy = strdup(value);
	if (!val_copy)
		return (0);
	free(node->value);
	node->value = val_copy;
	return (1);
}

/**
 * create_node - creates a new hash node
 * @key: key string
 * @value: value string
 *
 * Return: pointer to new node or NULL
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (NULL);
	node->key = strdup(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - adds or updates a key/value in a hash table
 * @ht: pointer to hash table
 * @key: key string
 * @value: value string
 *
 * Return: 1 if success, 0 if failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current, *node;

	if (!ht || !key || strlen(key) == 0 || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (update_value(current, value));
		current = current->next;
	}

	node = create_node(key, value);
	if (!node)
		return (0);
	node->next = ht->array[index];
	ht->array[index] = node;
	return (1);
}
