#include <plotgen.h>
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

// extern "C" {
#include "lib.h"
// }

#include <catch2/catch_test_macros.hpp>

int mod_n_meas_sample(const int steps, const Sample sample, const ModChState initial_state);

TEST_CASE("Generate chunk for sample = 0.") {
    ModChState mod_state = {.acc = 0, .chunk = 0};
    REQUIRE(generate_chunk_32(&mod_state, 0, 32) == 0);
    REQUIRE ((mod_state.chunk == 0x55555555 | mod_state.chunk == 0xAAAAAAAA));
}

SCENARIO("Generate a stream of chunks") {
    ModChState mod_state = {.acc = 0, .chunk = 0};
    Sample test_sample;
    Sample bit_count_total = 0;
    uint32_t chunk_mean = 0;

    GIVEN("A sample is to be generated over several steps") {
        int sim_steps = 4;

        WHEN("Sample is 0") {
            test_sample = 0;

            THEN("The result is half the number of bits") {
                REQUIRE(mod_n_meas_sample(sim_steps, test_sample, mod_state) == test_sample);
            }
        }

        WHEN("Sample is positive") {
            test_sample = 37;
            
            THEN("The number of high bits is equal to the test sample +/- 1.") {
                REQUIRE(std::abs(mod_n_meas_sample(sim_steps, test_sample, mod_state) - test_sample) < 2);
            }
        }

        WHEN("Sample is negative") {
            test_sample = -66;
            
            THEN("The number of high bits is equal to the test sample +/- 1.") {
                REQUIRE(std::abs(mod_n_meas_sample(sim_steps, test_sample, mod_state) - test_sample) < 2);
            }
        }
    }
}

int mod_n_meas_sample(const int steps, const Sample sample, const ModChState initial_state)
{
    ModChState mod_state = initial_state;
    int bit_count_total = 0;
    int chunk_mean = 0;
    for (int i = 0; i <= steps - 1; i++) {
        REQUIRE(generate_chunk_32(&mod_state, sample, steps * 32) == 0);
        chunk_mean = __builtin_popcount(mod_state.chunk);
        std::cout << "chunk mean at step " << i << ": " << chunk_mean << std::endl;
        bit_count_total += chunk_mean;
        std::cout << "Bit count at step" << i << ": " << bit_count_total << std::endl;
    }

    int mean = 32 * steps / 2;
    int rec_sample = (bit_count_total - mean) * 2;

    return rec_sample;
}