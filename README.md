# LVGL_DEMOS_STM32
 LVGL DEMOS STM32


How to import the demo project?

Step 1: Clone or copy and paste the desired example into your STM32CUBEIDE workspace folder.

Step 2: Open STM32CUBEIDE, click FILE -> IMPORT -> General -> Existing Projects into Workspace.

Step 3: A windown named "Import" will open, select the root directory by clicking the button named 
        "Browse ..", locate the example folder you cloned or copy&paste into your workspace in the Step 1, 
        select it and click the button named "Select folder".
        
Step 4: The example will be launched into Container named "Projects", be sure the project example is 
        visible and selected, then click finish. 


Do you want to change screen orientation?

I have implemented the orientation using the display controller hardware, so do not worry about performance.

Step 1: Go to LVGL-> hal_stm_lvgl -> tft -> tft.c

Step 2: Go "static void disp_init(void)" and set the orientation into "ILI9341_Init()" function.

It can be set to: DISP_ROT_Portrait, DISP_ROT_Landscape, DISP_ROT_Inv_Portrait or DISP_ROT_Inv_Landscape
