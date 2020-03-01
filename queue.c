#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    if (!q)
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    if (q != NULL) {
        list_ele_t *tmp;
        while (q->head != NULL) {
            tmp = q->head->next;
            free(q->head->value);
            free(q->head);
            q->head = tmp;
        }
        free(q);
    }
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Arguments points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* If q is NULL, return false */
    if (!q)
        return false;
    newh = malloc(sizeof(list_ele_t));
    /* Check whether the space is enough or not */
    if (!newh)
        return false;
    size_t length = strlen(s) + 1;
    newh->value = malloc(length * sizeof(char));
    /* Check whether the space is enough or not */
    if (!newh->value) {
        free(newh);
        return false;
    }
    memcpy(newh->value, s, length);
    newh->next = q->head;
    /* If the queue is empty, let the tail pointer point to the new head */
    if (q->size == 0)
        q->head = q->tail = newh;
    else {
        q->head = newh;
    }
    q->size++;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newt;
    /* If q is NULL, return false */
    if (!q)
        return false;
    newt = malloc(sizeof(list_ele_t));
    /* Check whether the space is enough or not */
    if (!newt)
        return false;
    size_t length = strlen(s) + 1;
    newt->value = malloc(length * sizeof(char));
    /* Check whether the space is enough or not */
    if (!newt->value) {
        free(newt);
        return false;
    }
    memcpy(newt->value, s, length);
    /* If the queue is empty, let the head pointer point to the new tail */
    if (q->size == 0)
        q->head = q->tail = newt;
    else {
        q->tail->next = newt;
        q->tail = newt;
    }
    q->size++;
    return true;
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    q->head = q->head->next;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    return (q == NULL) ? 0 : q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
