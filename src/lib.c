#include "lib.h"
#include <dbg_helperz.h>
#include <stdlib.h>

DacAcc calc_acc(int32_t delta);

int generate_chunk_32(ModChState *state, const Sample sample, const OsampRatio osamp_ratio)
{
    check_mem(state);
    check(abs(sample) <= osamp_ratio, "Value of sample must be less than osamp_ratio.");
    check((osamp_ratio % 32 == 0), "osamp_ratio must be a multiple of 32.")
    check(osamp_ratio >= 32, "Oversampling ratio must be at least 32");
    int i = 0;
    Accumulator delta = 0;
    BitstreamChunk temp_chunk = 0;

    for (i = 0; i < 31; i++) {
        delta = state->acc > 0 ? (sample - osamp_ratio) : (sample + osamp_ratio);
        state->acc += delta;
        
        // Set MSB if acc is positive, otherwise leave as 0, then shift to the right
        state->chunk = (USIGN(state->acc) ? ((uint32_t)0x80000000 | state->chunk) : state->chunk);
        state->chunk = state->chunk >> 1;
    }
    return 0;
error:
    return -1;
}