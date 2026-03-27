#include <plotgen.h>
#include <iostream>

// extern "C" {
#include "lib.h"
// }

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Generate a chunk for a sample") {
    ModChState mod_state = {.acc = 0, .chunk = 0};
    REQUIRE((generate_chunk_32(&mod_state, 0, 32)) == 0);
    REQUIRE ((mod_state.chunk == 0x55555555 | mod_state.chunk == 0xAAAAAAAA));
}