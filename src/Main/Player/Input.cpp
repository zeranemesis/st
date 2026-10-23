#include "input.hpp"

// ARM9 0x02013B10, 20 bytes (Input::Init).
// Three u16 state fields at offsets +0, +2, +4.
// Independently byte-equal with standalone Clang ARMv5TE -O2 in
// research/eur1/batches/arm9_new34; CodeWarrior and DS objdiff pending.
void Input::Init() {
    // Preserve the three halfword stores in original address order.
    // Without volatile access to cur/release, Clang reorders the stores.
    *(volatile u16 *) &this->cur = 0;
    this->press = 0;
    *(volatile u16 *) &this->release = 0;
}
