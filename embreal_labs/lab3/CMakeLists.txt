cmake_minimum_required(VERSION 3.20.0)

set(BOARD_FLASH_RUNNER "jlink")
set(BOARD "stm32f429i_disc1")

# set default overlay file
set(DTC_OVERLAY_FILE
  "MC1-Board.overlay"
)

set(DTC_OVERLAY_FILE
  "stm32f429i_disc1.overlay"
  "display_parameters_blue_board.overlay"
  "MC1-Board.overlay"
)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr_lab)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
