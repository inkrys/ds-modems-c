#ifndef _DS_MODEMS_H_
#define _DS_MODEMS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Type for the sample being modulated or demodulated.
 */
typedef int32_t Sample;

/**
 * @brief Output of modulating sample
 */
typedef struct ds_modems_ModState ds_modems_ModState;
struct ds_modems_ModState {
    uint32_t bitstream_chunk;
    int32_t accumulator;
    bool done;
    bool ok;
};

/**
 * @brief Modulates a sample into a series of 32-chunk bitstreams based on oversampling ratio.
 * @param sample The sample to be modulated
 * @param osamp_ratio Oversampling ratio
 * @param buffer Pointer to the buffer where 
*  @returns -1 for error, 0 for idle, 1 for busy
 */
ds_modems_ModState ds_modems_mod_sample(const int32_t sample, const unsigned int osamp_ratio, const bool reset);

/**
 * @brief Sets the oversampling ratio and must be a multiple of 32x
 * @note This is an effective limit of the maximum and minimum values that can be represented
 */
typedef int32_t OsampRatio;

/**
 * @brief Resu
 */

#ifdef __cplusplus
}
#endif

#endif