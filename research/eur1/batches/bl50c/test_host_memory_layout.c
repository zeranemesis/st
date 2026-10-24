/* Host-only semantic guard for three corrected C routines.
 * Not evidence of original Nintendo CodeWarrior or DS gameplay matching.
 * Example (Linux/macOS): clang -std=c11 -O2 -w reconstructed_50.c test_host_memory_layout.c -o test_memory && ./test_memory
 */
#include <assert.h>
#include <stdint.h>

void st_ov000_0205B1CC(uint32_t *dst, uint32_t first, uint32_t second);
void st_ov023_020EF9A4(uint32_t *dst, uint32_t a, uint32_t b, uint32_t c);
void st_ov032_0211DA50(uint32_t *dst);

int main(void) {
    uint32_t a[] = {7, 8, 9, 10, 11};
    st_ov000_0205B1CC(a, 100, 200);
    assert(a[0]==100 && a[1]==100 && a[2]==200 && a[3]==10 && a[4]==11);

    uint32_t b[] = {7, 8, 9, 10, 11};
    st_ov023_020EF9A4(b, 100, 200, 300);
    assert(b[0]==7 && b[1]==100 && b[2]==200 && b[3]==300 && b[4]==11);

    uint32_t c[] = {7, 8, 9, 10, 11};
    st_ov032_0211DA50(c);
    assert(c[0]==7 && c[1]==9 && c[2]==8 && c[3]==10 && c[4]==11);
}
