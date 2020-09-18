/**
 * dlistint_len - Returns the number elements
 * @h: Doubly linked lists
 *
 * Description: Returns the number of elements in a
 * linked dlistint_t list
 * Return: The number of nodes
 */
size_t dlistint_len(const *stack, *h)
{
	size_t c = 0;

	while (h)
	{
		h = h->next;
		c++;
	}
	return (c);
}
