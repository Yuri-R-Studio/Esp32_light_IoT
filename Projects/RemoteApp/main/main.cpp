#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "sdkconfig.h"

#define LGFX_USE_V1
#define LGFX_AUTODETECT
#include <LovyanGFX.h>
#include <LGFX_AUTODETECT.hpp>

LGFX lcd;

extern "C"
{
  void app_main(void)
  {
    lcd.init();
    while(1) {
      vTaskDelay(1);
      lcd.print("TEST");
    }
  }
}



































// #define ESP_PLATFORM
// #include <iostream>
// #include <thread>
// #include <chrono>
// #include <memory>
// #include <string>
// #include <sstream>
// #include <cstring>
// #include <esp_attr.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>
// #include <esp_log.h>
// #include "Hardware.h"
// #include "Logger.h"
// #include "Rng.h"
// #include "CircularBuffer.h"
// #include "DebugAssert.h"
// #include "ApplicationAgent.h"
// #include "ConfigurationAgent.h"

// #define LGFX_USE_V1
// #include <LovyanGFX.hpp>

// using Applications::ApplicationAgent;
// using Configuration::ConfigurationAgent;
// using Hal::Hardware;
// using Utilities::Logger;

// extern "C" void app_main(void)
// {
// 	Hardware * hardware = Hardware::Instance();
// 	//ConfigurationAgent::Instance();
// 	ApplicationAgent::Instance();
// 	ApplicationAgent::Instance()->Initialize();
// 	ApplicationAgent::Instance()->GetRemoteReceiverService().Start();
// 	//ConfigurationAgent::Instance()->UseDefaultConfiguration();
// 	lgfx::Panel_ILI9488 _panel_instance;
//     // lgfx::Bus_Parallel16 _bus_instance;

// 	// auto cfg = _bus_instance.config();
// 	// cfg.i2s_port = I2S_NUM_0;
// 	// cfg.freq_write = 16000000;
// 	// cfg.pin_wr = 35;
// 	// cfg.pin_rd = 34;
// 	// cfg.pin_rs = 36;
// 	// cfg.pin_d0 = 33;
// 	// cfg.pin_d1 = 21;
// 	// cfg.pin_d2 = 14;
// 	// cfg.pin_d3 = 13;
// 	// cfg.pin_d4 = 12;
// 	// cfg.pin_d5 = 11;
// 	// cfg.pin_d6 = 10;
// 	// cfg.pin_d7 = 9;
// 	// cfg.pin_d8 = 3;
// 	// cfg.pin_d9 = 8;
// 	// cfg.pin_d10 = 16;
// 	// cfg.pin_d11 = 15;
// 	// cfg.pin_d12 = 7;
// 	// cfg.pin_d13 = 6;
// 	// cfg.pin_d14 = 5;
// 	// cfg.pin_d15 = 4;

// 	// _bus_instance.config(cfg);        

// 	{
// 		auto cfg = _panel_instance.config();
// 		cfg.pin_cs = -1;   
// 		cfg.pin_rst = -1;
// 		cfg.pin_busy = -1;

// 		cfg.memory_width = 320;
// 		cfg.memory_height = 480;
// 		cfg.panel_width = 320;  
// 		cfg.panel_height = 480; 
// 		cfg.offset_x = 0;       
// 		cfg.offset_y = 0;
// 		cfg.offset_rotation = 0;
// 		cfg.dummy_read_pixel = 8;
// 		cfg.dummy_read_bits = 1;
// 		cfg.readable = true;    
// 		cfg.invert = false;     
// 		cfg.rgb_order = false;  
// 		cfg.dlen_16bit = true;  
// 		cfg.bus_shared = true;  

// 		_panel_instance.config(cfg);
// 	}



// 	for (;;)
// 	{
// 		vTaskDelay(100);
// 		heap_caps_check_integrity(MALLOC_CAP_8BIT, true);
// 	}
// }
