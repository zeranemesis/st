/*
 * Spirit Tracks EUR Rev 1 ARM9 — human-readable candidates.
 * These are INTERPRETATIONS of original short ARM routines, not replacements
 * for the original game's C++ symbols. Type names and signatures are proposed.
 * Matching status with Clang/CodeWarrior is NOT established for these bodies.
 * Distinct suffixes avoid accidental linkage into the production game.
 */
#include <stdint.h>

/* Overlay 0, 0x02054548, 64 ARM bytes, eight direct BL references.
 * Original instructions: conditionally link head and update list count.
 * Inferred pointer layout: head +0, count +4, tail +8.
 * This routine appears to add a node at the HEAD of a doubly linked list.
 */
typedef struct ST_ListNode_Provisional {
    struct ST_ListNode_Provisional *next;
    struct ST_ListNode_Provisional *previous;
} ST_ListNode_Provisional;

typedef struct ST_List_Provisional {
    ST_ListNode_Provisional *head;
    uint32_t count;
    ST_ListNode_Provisional *tail;
} ST_List_Provisional;

void st_semantic_ov000_02054548(ST_List_Provisional *list,
                               ST_ListNode_Provisional *new_head) {
    ST_ListNode_Provisional *old_head = list->head;
    if (old_head == 0) {
        list->head = new_head;
        list->tail = new_head;
        new_head->next = 0;
        new_head->previous = 0;
    } else {
        new_head->next = old_head;
        new_head->previous = 0;
        old_head->previous = new_head;
        list->head = new_head;
    }
    ++list->count;
}

/* Overlay 0, 0x02058FC4, 52 ARM bytes.
 * Original 0x0..0x14: copy 3 words from src+0,+4,+8 to dst+4,+8,+12.
 * Original 0x18..0x30: read link-cursor at context+128; if nonzero,
 * write dst at cursor+0, then increment cursor by 4 in context.
 * Interpreting cursor as an integer preserves the original address math.
 */
void st_semantic_ov000_02058FC4(void *context, void *dst,
                               const uint32_t *src) {
    uint32_t *target = (uint32_t *)dst;
    /* All three source words are fetched before any writes in the ROM. */
    const uint32_t first = src[0];
    const uint32_t second = src[1];
    const uint32_t third = src[2];
    target[1] = first;
    target[2] = second;
    target[3] = third;
    uintptr_t cursor = *(uintptr_t *)((uint8_t *)context + 128u);
    if (cursor != 0u) {
        *(uintptr_t *)(uintptr_t)cursor = (uintptr_t)dst;
    }
    *(uintptr_t *)((uint8_t *)context + 128u) = cursor + 4u;
}

/* Overlay 0, 0x02067BB4, 16 ARM bytes, 12 BL references.
 * cmp r1,#0; ldreq r0,[r0,#12]; ldrne r0,[r0,#16]; bx lr.
 */
uint32_t st_semantic_ov000_02067BB4(const void *object, uint32_t selector) {
    const uint32_t *data = (const uint32_t *)object;
    return selector == 0u ? data[3] : data[4];
}
