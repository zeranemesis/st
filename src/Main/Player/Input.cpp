#include "input.hpp"

// ARM9 0x02013B10, 20 bytes (Input::Init).
// Three u16 state fields at offsets +0, +2, +4.
// Independently byte-equal with standalone Clang ARMv5TE -O2 in
// research/eur1/batches/arm9_new34; CodeWarrior and DS objdiff pending.
void Input::Init() {
    this->cur = 0;
    this->press = 0;
    this->release = 0;
}
