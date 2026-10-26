/* Spirit Tracks EUR Rev 1: two readable list operations from BL50C's
 * formerly unrefactored C register-state hypotheses.
 * These are semantic candidates, NOT byte-exact original CodeWarrior sources.
 * Layout contracts below hold on Nintendo DS ARM9 (32-bit pointers).
 */
#include <stddef.h>
#include <stdint.h>

typedef struct STLinkedNode STLinkedNode;
struct STLinkedNode {
    uint8_t unknown_00[16];
    STLinkedNode *next;       /* +0x10 on ARM9 */
    STLinkedNode *previous;   /* +0x14 on ARM9 */
};

typedef struct STLinkedList {
    STLinkedNode *head;       /* +0x00 */
    STLinkedNode *tail;       /* +0x04 on ARM9 */
} STLinkedList;

#if UINTPTR_MAX == UINT32_MAX
_Static_assert(offsetof(STLinkedNode, next) == 16, "unexpected ARM9 next offset");
_Static_assert(offsetof(STLinkedNode, previous) == 20, "unexpected ARM9 prev offset");
_Static_assert(offsetof(STLinkedList, tail) == 4, "unexpected ARM9 tail offset");
#endif

/* arm9:0x0202694C -- pop the first item of a doubly linked list.
 * Returns the detached node. The detached node's own links are unchanged,
 * which follows the original low-level register trace.
 */
STLinkedNode *st_arm9_0202694C(STLinkedList *list) {
    STLinkedNode *head = list->head;
    if (head == NULL) return NULL;
    STLinkedNode *next = head->next;
    list->head = next;
    if (next != NULL) {
        next->previous = NULL;
    } else {
        list->tail = NULL;
    }
    return head;
}

typedef struct STChainNode STChainNode;
struct STChainNode {
    uint8_t unknown_00[660];
    STChainNode *next;        /* +0x294 on ARM9 */
};

#if UINTPTR_MAX == UINT32_MAX
_Static_assert(offsetof(STChainNode, next) == 660, "unexpected ARM9 chain link offset");
#endif

/* Pure test seam: traverse a chain of pointers and splice out a matching
 * pointer. If found, return the successor; if not found, return the requested
 * target unchanged, matching the old register-state trace.
 * PRECONDITION: target != NULL. No cycle detection in the original routine.
 */
static inline STChainNode *st_splice_chain(STChainNode *volatile *slot, STChainNode *target) {
    for (;;) {
        STChainNode *value = *slot;
        if (value == target) {
            STChainNode *successor = target->next;
            *slot = successor;
            return successor;
        }
        if (value == NULL) return target;
        slot = &value->next;
    }
}

/* overlay_038:0x0211988C -- the original global head-slot address is
 * 0x021215C4 in EUR1. The test seam above avoids touching this address
 * when exercising list semantics in a 64-bit host process.
 */
STChainNode *st_ov038_0211988C(STChainNode *target) {
    STChainNode *volatile *slot = (STChainNode *volatile *)(uintptr_t)0x021215C4u;
    return st_splice_chain(slot, target);
}
