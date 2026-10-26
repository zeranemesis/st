#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include "semantic_candidates_round10.c"

int main(void) {
    STLinkedList list = {0};
    STLinkedNode a = {0}, b = {0}, c = {0};

    /* Empty / singleton / multi-node list cases, including return values. */
    assert(st_arm9_0202694C(&list) == NULL);
    assert(list.head == NULL && list.tail == NULL);

    list.head = &a; list.tail = &a;
    assert(st_arm9_0202694C(&list) == &a);
    assert(list.head == NULL && list.tail == NULL);

    a.next = &b; b.previous = &a;
    list.head = &a; list.tail = &b;
    assert(st_arm9_0202694C(&list) == &a);
    assert(list.head == &b && list.tail == &b && b.previous == NULL);
    assert(a.next == &b); /* original does not clear detached node */

    a.next = &b; b.next = &c; b.previous = &a; c.previous = &b;
    list.head = &a; list.tail = &c;
    assert(st_arm9_0202694C(&list) == &a);
    assert(list.head == &b && list.tail == &c && b.previous == NULL);

    STChainNode x = {0}, y = {0}, z = {0}, missing = {0};
    STChainNode *head = &x;
    x.next = &y; y.next = &z;

    assert(st_splice_chain(&head, &y) == &z); /* middle */
    assert(head == &x && x.next == &z);
    assert(st_splice_chain(&head, &missing) == &missing); /* absent */
    assert(head == &x && x.next == &z);
    assert(st_splice_chain(&head, &x) == &z); /* head */
    assert(head == &z);
    assert(st_splice_chain(&head, &z) == NULL); /* tail */
    assert(head == NULL);
    assert(st_splice_chain(&head, &missing) == &missing); /* empty */

    puts("PASS: 9 linked-list semantic cases (not original ROM byte matches)");
    return 0;
}
