# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a ZMK firmware configuration repository for the **cool642tb-mini** split keyboard. The keyboard uses Seeeduino XIAO BLE microcontrollers and features a PMW3610 trackball sensor on the right half.

## Build Process

Firmware is built automatically via GitHub Actions. Push to any branch or create a pull request to trigger a build. The workflow uses the official ZMK build system (`zmkfirmware/zmk/.github/workflows/build-user-config.yml`).

Build outputs (UF2 files) are generated for:
- `cool642tb-mini_R` (right half, central/master with trackball)
- `cool642tb-mini_L` (left half, peripheral)
- `settings_reset` (for clearing Bluetooth bonds)

Pre-built firmware files are available in `firmware/`.

## Key Configuration Files

- **`config/cool642tb-mini.keymap`** - Main keymap with 7 layers (DEFAULT, FUNCTION, NUM, ARROW, MOUSE, SCROLL, BLUETOOTH)
- **`config/boards/shields/Test/cool642tb-mini_R.conf`** - Right half config with PMW3610 trackball settings
- **`config/boards/shields/Test/cool642tb-mini_L.conf`** - Left half config
- **`config/boards/shields/Test/cool642tb-mini.dtsi`** - Hardware definition (key matrix, encoders, physical layout)
- **`build.yaml`** - GitHub Actions build matrix configuration
- **`config/west.yml`** - West manifest pointing to forked ZMK and PMW3610 driver

## Architecture

This repo uses a forked ZMK (`na-ka-no/zmk`, branch `for-cool642tb_mini`) and the `zmk-pmw3610-driver` for trackball support. The split keyboard communicates over BLE, with the right half as central (includes ZMK Studio support via `studio-rpc-usb-uart` snippet).

The keyboard matrix is 11 columns x 4 rows across both halves, with additional keys for trackball buttons and rotary encoder on each side.

## Flashing

1. Put the Seeeduino XIAO BLE into bootloader mode (double-tap reset)
2. Copy the appropriate `.uf2` file from `firmware/` or GitHub Actions artifacts to the mounted drive
