/**
  ******************************************************************************
  * @file    font24.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-February-2014
  * @brief   This file provides text font24 for STM32xx-EVAL's LCD driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fonts.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32_EVAL
  * @{
  */

/** @addtogroup Common
  * @{
  */

/** @addtogroup FONTS
  * @brief      This file provides text font24 for STM32xx-EVAL's LCD driver.
  * @{
  */

/** @defgroup FONTS_Private_Types
  * @{
  */
/**
  * @}
  */


/** @defgroup FONTS_Private_Defines
  * @{
  */
/**
  * @}
  */


/** @defgroup FONTS_Private_Macros
  * @{
  */
/**
  * @}
  */


/** @defgroup FONTS_Private_Variables
  * @{
  */
const uint8_t NesFont8_Table [] =
{
  // @0 ' ' (8 pixels wide)
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //

  // @8 '!' (8 pixels wide)
  0x18, //    ##
  0x3C, //   ####
  0x3C, //   ####
  0x3C, //   ####
  0x18, //    ##
  0x18, //    ##
  0x00, //
  0x18, //    ##

  // @16 '"' (8 pixels wide)
  0x6C, //  ## ##
  0x6C, //  ## ##
  0x6C, //  ## ##
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //

  // @24 '#' (8 pixels wide)
  0x6C, //  ## ##
  0x6C, //  ## ##
  0xFE, // #######
  0x6C, //  ## ##
  0xFE, // #######
  0x6C, //  ## ##
  0x6C, //  ## ##
  0x00, //

  // @32 '$' (8 pixels wide)
  0x30, //   ##
  0x7C, //  #####
  0xC0, // ##
  0x78, //  ####
  0x0C, //     ##
  0xF8, // #####
  0x30, //   ##
  0x00, //

  // @40 '%' (8 pixels wide)
  0x00, //
  0xC6, // ##   ##
  0xCC, // ##  ##
  0x18, //    ##
  0x30, //   ##
  0x66, //  ##  ##
  0xC6, // ##   ##
  0x00, //

  // @48 '&' (8 pixels wide)
  0x38, //   ###
  0x6C, //  ## ##
  0x38, //   ###
  0x76, //  ### ##
  0xDC, // ## ###
  0xCC, // ##  ##
  0x76, //  ### ##
  0x00, //

  // @56 ''' (8 pixels wide)
  0x60, //  ##
  0x60, //  ##
  0xC0, // ##
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //

  // @64 '(' (8 pixels wide)
  0x18, //    ##
  0x30, //   ##
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x30, //   ##
  0x18, //    ##
  0x00, //

  // @72 ')' (8 pixels wide)
  0x60, //  ##
  0x30, //   ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x30, //   ##
  0x60, //  ##
  0x00, //

  // @80 '*' (8 pixels wide)
  0x00, //
  0x66, //  ##  ##
  0x3C, //   ####
  0xFF, // ########
  0x3C, //   ####
  0x66, //  ##  ##
  0x00, //
  0x00, //

  // @88 '+' (8 pixels wide)
  0x00, //
  0x30, //   ##
  0x30, //   ##
  0xFC, // ######
  0x30, //   ##
  0x30, //   ##
  0x00, //
  0x00, //

  // @96 ',' (8 pixels wide)
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x30, //   ##
  0x30, //   ##
  0x60, //  ##

  // @104 '-' (8 pixels wide)
  0x00, //
  0x00, //
  0x00, //
  0xFC, // ######
  0x00, //
  0x00, //
  0x00, //
  0x00, //

  // @112 '.' (8 pixels wide)
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x30, //   ##
  0x30, //   ##
  0x00, //

  // @120 '/' (8 pixels wide)
  0x06, //      ##
  0x0C, //     ##
  0x18, //    ##
  0x30, //   ##
  0x60, //  ##
  0xC0, // ##
  0x80, // #
  0x00, //

  // @128 '0' (8 pixels wide)
  0x38, //   ###
  0x4C, //  #  ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x64, //  ##  #
  0x38, //   ###
  0x00, //

  // @136 '1' (8 pixels wide)
  0x18, //    ##
  0x38, //   ###
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x7E, //  ######
  0x00, //

  // @144 '2' (8 pixels wide)
  0x7C, //  #####
  0xC6, // ##   ##
  0x0E, //     ###
  0x3C, //   ####
  0x78, //  ####
  0xE0, // ###
  0xFE, // #######
  0x00, //

  // @152 '3' (8 pixels wide)
  0x7E, //  ######
  0x0C, //     ##
  0x18, //    ##
  0x3C, //   ####
  0x06, //      ##
  0xC6, // ##   ##
  0x7C, //  #####
  0x00, //

  // @160 '4' (8 pixels wide)
  0x1C, //    ###
  0x3C, //   ####
  0x6C, //  ## ##
  0xCC, // ##  ##
  0xFE, // #######
  0x0C, //     ##
  0x0C, //     ##
  0x00, //

  // @168 '5' (8 pixels wide)
  0xFC, // ######
  0xC0, // ##
  0xFC, // ######
  0x06, //      ##
  0x06, //      ##
  0xC6, // ##   ##
  0x7C, //  #####
  0x00, //

  // @176 '6' (8 pixels wide)
  0x3C, //   ####
  0x60, //  ##
  0xC0, // ##
  0xFC, // ######
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x7C, //  #####
  0x00, //

  // @184 '7' (8 pixels wide)
  0xFE, // #######
  0xC6, // ##   ##
  0x0C, //     ##
  0x18, //    ##
  0x30, //   ##
  0x30, //   ##
  0x30, //   ##
  0x00, //

  // @192 '8' (8 pixels wide)
  0x7C, //  #####
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x7C, //  #####
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x7C, //  #####
  0x00, //

  // @200 '9' (8 pixels wide)
  0x7C, //  #####
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x7E, //  ######
  0x06, //      ##
  0x0C, //     ##
  0x78, //  ####
  0x00, //

  // @208 ':' (8 pixels wide)
  0x00, //
  0x30, //   ##
  0x30, //   ##
  0x00, //
  0x00, //
  0x30, //   ##
  0x30, //   ##
  0x00, //

  // @216 ';' (8 pixels wide)
  0x00, //
  0x30, //   ##
  0x30, //   ##
  0x00, //
  0x00, //
  0x30, //   ##
  0x30, //   ##
  0x60, //  ##

  // @224 '<' (8 pixels wide)
  0x18, //    ##
  0x30, //   ##
  0x60, //  ##
  0xC0, // ##
  0x60, //  ##
  0x30, //   ##
  0x18, //    ##
  0x00, //

  // @232 '=' (8 pixels wide)
  0x00, //
  0x00, //
  0xFC, // ######
  0x00, //
  0x00, //
  0xFC, // ######
  0x00, //
  0x00, //

  // @240 '>' (8 pixels wide)
  0x60, //  ##
  0x30, //   ##
  0x18, //    ##
  0x0C, //     ##
  0x18, //    ##
  0x30, //   ##
  0x60, //  ##
  0x00, //

  // @248 '?' (8 pixels wide)
  0x78, //  ####
  0xCC, // ##  ##
  0x0C, //     ##
  0x18, //    ##
  0x30, //   ##
  0x00, //
  0x30, //   ##
  0x00, //

  // @256 '@' (8 pixels wide)
  0x7C, //  #####
  0xC6, // ##   ##
  0xDE, // ## ####
  0xDE, // ## ####
  0xDE, // ## ####
  0xC0, // ##
  0x78, //  ####
  0x00, //

  // @264 'A' (8 pixels wide)
  0x38, //   ###
  0x6C, //  ## ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xFE, // #######
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x00, //

  // @272 'B' (8 pixels wide)
  0xFC, // ######
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xFC, // ######
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xFC, // ######
  0x00, //

  // @280 'C' (8 pixels wide)
  0x3C, //   ####
  0x66, //  ##  ##
  0xC0, // ##
  0xC0, // ##
  0xC0, // ##
  0x66, //  ##  ##
  0x3C, //   ####
  0x00, //

  // @288 'D' (8 pixels wide)
  0xF8, // #####
  0xCC, // ##  ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xCC, // ##  ##
  0xF8, // #####
  0x00, //

  // @296 'E' (8 pixels wide)
  0xFE, // #######
  0xC0, // ##
  0xC0, // ##
  0xFC, // ######
  0xC0, // ##
  0xC0, // ##
  0xFE, // #######
  0x00, //

  // @304 'F' (8 pixels wide)
  0xFE, // #######
  0xC0, // ##
  0xC0, // ##
  0xFC, // ######
  0xC0, // ##
  0xC0, // ##
  0xC0, // ##
  0x00, //

  // @312 'G' (8 pixels wide)
  0x3E, //   #####
  0x60, //  ##
  0xC0, // ##
  0xCE, // ##  ###
  0xC6, // ##   ##
  0x66, //  ##  ##
  0x3E, //   #####
  0x00, //

  // @320 'H' (8 pixels wide)
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xFE, // #######
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x00, //

  // @328 'I' (8 pixels wide)
  0x7E, //  ######
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x7E, //  ######
  0x00, //

  // @336 'J' (8 pixels wide)
  0x1E, //    ####
  0x06, //      ##
  0x06, //      ##
  0x06, //      ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x7C, //  #####
  0x00, //

  // @344 'K' (8 pixels wide)
  0xC6, // ##   ##
  0xCC, // ##  ##
  0xD8, // ## ##
  0xF0, // ####
  0xF8, // #####
  0xDC, // ## ###
  0xCE, // ##  ###
  0x00, //

  // @352 'L' (8 pixels wide)
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x7E, //  ######
  0x00, //

  // @360 'M' (8 pixels wide)
  0xC6, // ##   ##
  0xEE, // ### ###
  0xFE, // #######
  0xFE, // #######
  0xD6, // ## # ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x00, //

  // @368 'N' (8 pixels wide)
  0xC6, // ##   ##
  0xE6, // ###  ##
  0xF6, // #### ##
  0xFE, // #######
  0xDE, // ## ####
  0xCE, // ##  ###
  0xC6, // ##   ##
  0x00, //

  // @376 'O' (8 pixels wide)
  0x7C, //  #####
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x7C, //  #####
  0x00, //

  // @384 'P' (8 pixels wide)
  0xFC, // ######
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xFC, // ######
  0xC0, // ##
  0xC0, // ##
  0x00, //

  // @392 'Q' (8 pixels wide)
  0x7C, //  #####
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xDE, // ## ####
  0xCC, // ##  ##
  0x7A, //  #### #
  0x00, //

  // @400 'R' (8 pixels wide)
  0xFC, // ######
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xCE, // ##  ###
  0xF8, // #####
  0xDC, // ## ###
  0xCE, // ##  ###
  0x00, //

  // @408 'S' (8 pixels wide)
  0x78, //  ####
  0xCC, // ##  ##
  0xC0, // ##
  0x7C, //  #####
  0x06, //      ##
  0xC6, // ##   ##
  0x7C, //  #####
  0x00, //

  // @416 'T' (8 pixels wide)
  0x7E, //  ######
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x00, //

  // @424 'U' (8 pixels wide)
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0x7C, //  #####
  0x00, //

  // @432 'V' (8 pixels wide)
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xEE, // ### ###
  0x7C, //  #####
  0x38, //   ###
  0x10, //    #
  0x00, //

  // @440 'W' (8 pixels wide)
  0xC6, // ##   ##
  0xC6, // ##   ##
  0xD6, // ## # ##
  0xFE, // #######
  0xFE, // #######
  0xEE, // ### ###
  0xC6, // ##   ##
  0x00, //

  // @448 'X' (8 pixels wide)
  0xC6, // ##   ##
  0xEE, // ### ###
  0x7C, //  #####
  0x38, //   ###
  0x7C, //  #####
  0xEE, // ### ###
  0xC6, // ##   ##
  0x00, //

  // @456 'Y' (8 pixels wide)
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x3C, //   ####
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x00, //

  // @464 'Z' (8 pixels wide)
  0xFE, // #######
  0x0E, //     ###
  0x1C, //    ###
  0x38, //   ###
  0x70, //  ###
  0xE0, // ###
  0xFE, // #######
  0x00, //

  // @472 '[' (8 pixels wide)
  0x78, //  ####
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x78, //  ####
  0x00, //

  // @480 '\' (8 pixels wide)
  0xC0, // ##
  0x60, //  ##
  0x30, //   ##
  0x18, //    ##
  0x0C, //     ##
  0x06, //      ##
  0x02, //       #
  0x00, //

  // @488 ']' (8 pixels wide)
  0x78, //  ####
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x78, //  ####
  0x00, //

  // @496 '^' (8 pixels wide)
  0x10, //    #
  0x38, //   ###
  0x6C, //  ## ##
  0xC6, // ##   ##
  0x00, //
  0x00, //
  0x00, //
  0x00, //

  // @504 '_' (8 pixels wide)
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0xFF, // ########

  // @512 '`' (8 pixels wide)
  0x30, //   ##
  0x30, //   ##
  0x18, //    ##
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //

  // @520 'a' (8 pixels wide)
  0x00, //
  0x00, //
  0x3C, //   ####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x3B, //   ### ##
  0x00, //

  // @528 'b' (8 pixels wide)
  0x60, //  ##
  0x60, //  ##
  0x7C, //  #####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x7C, //  #####
  0x00, //

  // @536 'c' (8 pixels wide)
  0x00, //
  0x00, //
  0x3E, //   #####
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x3E, //   #####
  0x00, //

  // @544 'd' (8 pixels wide)
  0x06, //      ##
  0x06, //      ##
  0x3E, //   #####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x3E, //   #####
  0x00, //

  // @552 'e' (8 pixels wide)
  0x00, //
  0x00, //
  0x3C, //   ####
  0x66, //  ##  ##
  0x7E, //  ######
  0x60, //  ##
  0x3E, //   #####
  0x00, //

  // @560 'f' (8 pixels wide)
  0x0E, //     ###
  0x18, //    ##
  0x18, //    ##
  0x7E, //  ######
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x00, //

  // @568 'g' (8 pixels wide)
  0x00, //
  0x00, //
  0x3E, //   #####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x3E, //   #####
  0x06, //      ##
  0x3C, //   ####

  // @576 'h' (8 pixels wide)
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x7C, //  #####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x00, //

  // @584 'i' (8 pixels wide)
  0x00, //
  0x18, //    ##
  0x00, //
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x00, //

  // @592 'j' (8 pixels wide)
  0x00, //
  0x06, //      ##
  0x00, //
  0x06, //      ##
  0x06, //      ##
  0x06, //      ##
  0x66, //  ##  ##
  0x3C, //   ####

  // @600 'k' (8 pixels wide)
  0x60, //  ##
  0x60, //  ##
  0x62, //  ##   #
  0x64, //  ##  #
  0x68, //  ## #
  0x7C, //  #####
  0x66, //  ##  ##
  0x00, //

  // @608 'l' (8 pixels wide)
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x00, //

  // @616 'm' (8 pixels wide)
  0x00, //
  0x00, //
  0x76, //  ### ##
  0x6B, //  ## # ##
  0x6B, //  ## # ##
  0x6B, //  ## # ##
  0x6B, //  ## # ##
  0x00, //

  // @624 'n' (8 pixels wide)
  0x00, //
  0x00, //
  0x7C, //  #####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x00, //

  // @632 'o' (8 pixels wide)
  0x00, //
  0x00, //
  0x3C, //   ####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x3C, //   ####
  0x00, //

  // @640 'p' (8 pixels wide)
  0x00, //
  0x00, //
  0x7C, //  #####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x7C, //  #####
  0x60, //  ##
  0x60, //  ##

  // @648 'q' (8 pixels wide)
  0x00, //
  0x00, //
  0x3E, //   #####
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x3E, //   #####
  0x06, //      ##
  0x06, //      ##

  // @656 'r' (8 pixels wide)
  0x00, //
  0x00, //
  0x6E, //  ## ###
  0x70, //  ###
  0x60, //  ##
  0x60, //  ##
  0x60, //  ##
  0x00, //

  // @664 's' (8 pixels wide)
  0x00, //
  0x00, //
  0x3C, //   ####
  0x40, //  #
  0x3C, //   ####
  0x06, //      ##
  0x7C, //  #####
  0x00, //

  // @672 't' (8 pixels wide)
  0x30, //   ##
  0x30, //   ##
  0xFC, // ######
  0x30, //   ##
  0x30, //   ##
  0x30, //   ##
  0x1C, //    ###
  0x00, //

  // @680 'u' (8 pixels wide)
  0x00, //
  0x00, //
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x3C, //   ####
  0x00, //

  // @688 'v' (8 pixels wide)
  0x00, //
  0x00, //
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x24, //   #  #
  0x18, //    ##
  0x00, //

  // @696 'w' (8 pixels wide)
  0x00, //
  0x00, //
  0x63, //  ##   ##
  0x6B, //  ## # ##
  0x6B, //  ## # ##
  0x6B, //  ## # ##
  0x36, //   ## ##
  0x00, //

  // @704 'x' (8 pixels wide)
  0x00, //
  0x00, //
  0x63, //  ##   ##
  0x36, //   ## ##
  0x1C, //    ###
  0x36, //   ## ##
  0x63, //  ##   ##
  0x00, //

  // @712 'y' (8 pixels wide)
  0x00, //
  0x00, //
  0x66, //  ##  ##
  0x66, //  ##  ##
  0x2C, //   # ##
  0x18, //    ##
  0x30, //   ##
  0x60, //  ##

  // @720 'z' (8 pixels wide)
  0x00, //
  0x00, //
  0x7E, //  ######
  0x0C, //     ##
  0x18, //    ##
  0x30, //   ##
  0x7E, //  ######
  0x00, //

  // @728 '{' (8 pixels wide)
  0x1C, //    ###
  0x30, //   ##
  0x30, //   ##
  0xE0, // ###
  0x30, //   ##
  0x30, //   ##
  0x1C, //    ###
  0x00, //

  // @736 '|' (8 pixels wide)
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x00, //
  0x18, //    ##
  0x18, //    ##
  0x18, //    ##
  0x00, //

  // @744 '}' (8 pixels wide)
  0xE0, // ###
  0x30, //   ##
  0x30, //   ##
  0x1C, //    ###
  0x30, //   ##
  0x30, //   ##
  0xE0, // ###
  0x00, //

  // @752 '~' (8 pixels wide)
  0x76, //  ### ##
  0xDC, // ## ###
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
  0x00, //
};

sFONT NesFont8 = {
  NesFont8_Table,
  8, /* Width */
  8, /* Height */
};

/**
  * @}
  */


/** @defgroup FONTS_Private_Function_Prototypes
  * @{
  */
/**
  * @}
  */


/** @defgroup FONTS_Private_Functions
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
