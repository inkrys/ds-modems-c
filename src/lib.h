#ifndef _LIB_H_
#define _LIB_H_

#include <stdint.h>
#include <ds_modems.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DAC_CHANNELS 6

typedef struct DacAcc DacAcc;
struct DacAcc {
    uint32_t val[DAC_CHANNELS];
};

/**
 * @brief Stores a chunk of bits.
 * @note MSB is the last chunk generated, i.e. needs to be pushed to the serialiser in little-endian format.
 */
typedef uint32_t BitstreamChunk;

/**
 * @brief Stores the running accumulator value of the delta-sigma modulation algorithm.
 */
typedef int32_t Accumulator;

/**
 * @brief Stores the state of a modulator channel
 */
typedef struct ModChState ModChState;
struct ModChState {
    Accumulator acc;
    BitstreamChunk chunk;
};

/**
 * @brief Sign function that returns -1 or 1, i.e. not a "full" signum.
 * @note Brackets are necessary.
 */
#define SIGN(A) (A>0 ? 1 : -1)

/**
 * @brief Sign function that returns 0 or 1, i.e. an unsigned sign?
 * @note Brackets are necessary.
 */
#define USIGN(A) (A>0 ? 1 : 0)

/**
 * @brief Generates a 32-bit chunk of a bitstream.
 * @param state Reference to state of modulator. Modified by function.
 * @param sample Sample to be modulated
 * @param osamp_ratio Oversampling ratio. Must be larger than the absolute value of sample.
 * @returns 0 if parameters are OK, -1 if error.
 */
int generate_chunk_32(ModChState *state, const Sample sample, const OsampRatio osamp_ratio);

#ifdef __cplusplus
}
#endif

#endif

