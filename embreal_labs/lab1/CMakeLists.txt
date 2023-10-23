cmake_minimum_required(VERSION 3.20.0)

set(BOARD_FLASH_RUNNER "jlink")
set(BOARD "stm32f429i_disc1")
set(DTC_OVERLAY_FILE
  "MC1-Board.overlay"
)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(embreal_lab1)

target_sources(app PRIVATE src/main.c)
