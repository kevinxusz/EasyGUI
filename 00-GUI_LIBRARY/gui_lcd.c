/**	
 * \file            gui_lcd.c
 * \brief           LCD specific functions
 */
 
/*
 * Copyright (c) 2017 Tilen Majerle
 *  
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Author:          Tilen Majerle <tilen@majerle.eu>
 */
#define GUI_INTERNAL
#include "gui_lcd.h"

/******************************************************************************/
/******************************************************************************/
/***                           Private structures                            **/
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/***                           Private definitions                           **/
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/***                            Private variables                            **/
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/***                            Private functions                            **/
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/***                              Protothreads                               **/
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/***                                Public API                               **/
/******************************************************************************/
/******************************************************************************/

/**
 * \brief           Get LCD width in units of pixels
 * \return          LCD width in units of pixels
 */
GUI_Dim_t
gui_lcd_getwidth(void) {
    return GUI.LCD.Width;
}

/**
 * \brief           Get LCD height in units of pixels
 * \return          LCD height in units of pixels
 */
GUI_Dim_t
gui_lcd_getheight(void) {
    return GUI.LCD.Height;
}

/**
 * \brief           Notify GUI stack from low-level layer which layer is currently used as display layer
 * \param[in]       layer_num: Layer number used as display layer
 */
void
gui_lcd_confirmactivelayer(uint8_t layer_num) {
    if ((GUI.LCD.Flags & GUI_FLAG_LCD_WAIT_LAYER_CONFIRM)) {/* If we have anything pending */
        GUI.LCD.Layers[layer_num].Pending = 0;
        GUI.LCD.Flags &= ~GUI_FLAG_LCD_WAIT_LAYER_CONFIRM;  /* Clear flag */
    }
}
