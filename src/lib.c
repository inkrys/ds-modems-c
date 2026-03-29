#include "lib.h"
#include <dbg_helperz.h>
#include <stdlib.h>

DacAcc calc_acc(int32_t delta);

int generate_chunk_32(ModChState *state, const Sample sample, const OsampRatio osamp_ratio)
{
    check_mem(state);
    check(abs(sample) <= osamp_ratio, "Value of sample must be less than osamp_ratio.");

    int i = 0;
    Accumulator delta = 0;
    BitstreamChunk temp_chunk = 0;

    for (i = 0; i < 32; i++) {
        delta = state->acc > 0 ? (sample - osamp_ratio) : (sample + osamp_ratio);
        state->acc += delta;
        state->chunk = state->chunk >> 1;
        
        // Set MSB if acc is positive, otherwise leave as 0, then shift to the right
        state->chunk = ((state->acc > 0) ? ((uint32_t)0x80000000 | state->chunk) : state->chunk);
        // debug("Chunk %d is %x.", i, state->chunk);
    }
    return 0;
error:
    return -1;
}