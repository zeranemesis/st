#include "input.hpp"

// ARM9 0x02013B88, 16 bytes.
// Clear pressed/released edges without changing the held key mask.
// The unmangled symbol is taken from config/eur1/arm9/symbols.txt.
// Standalone Clang ARMv5TE byte equality was previously verified;
// CodeWarrior and full DS game-build matching have not been measured.
extern "C" void func_02013b88(Input *input) {
    input->press = 0;
    input->release = 0;
}
