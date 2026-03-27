# ds-modems-c
C library for Delta-Sigma modulators and demodulators. Objective is to be usable on embedded systems.

I'm using this project to practice using CMake, CPM, VScode, and Catch2...

## Systems
### Modulator system

The modulator generates a bitstream stored in chunks of 32 bits as this project is initially aimed to be used on an RP2350 (or RP2040) MCU, where the PIO block uses 32-bit words for the FIFOs.

As such, a single iteration of the modulator has a base upsampling rate of 32x and any oversampling ratio must be a multiple of 32.

#### generate_chunk
| Component | Description |
|-----------|-------------|
| Sample    | Sample to be modulated |
| Accumulator | Stores the accumulation value from calculation to calculation |
| BitStream | The bitstream generated from an iteration. The MSB is the last value generated |


## Side-note on Clang
Had to install libstdc++12-dev as clang was the CMake test script was unable to build.

What I tried before that:
- Setting the clang --gcc-install-dir variable to a clang installation with lstdc++

## Side-note on CMake and VScode on ubuntu:

From https://askubuntu.com/questions/1353824/bad-cmake-executable-vscode:
>The cmake version that comes with Snap is more recent on my Ubuntu 20.04.4 LTS:
>
>>$ apt show cmake
>>Package: cmake
>>Version: 3.16.3-1ubuntu1
>
>while the Snap version I installed
>
>>cmake version 3.22.2
>
>So I preferred to use /snap/cmake/current/bin/cmake as CMake Path (as recommended here: "It works when you use /snap/cmake/current/bin/cmake as CMake Path. All snap executables seem to be just symbolic links to /usr/bin/snap, and >that seems to work fine when called from a terminal but apparently not from the CMake extension in VSCode ...").
