
#include "Wdt.h"
// #include "components/esp_system/include/esp_xt_wdt.h"
// #include "components/esp_common/include/esp_int_wdt.h"

namespace Hal
{

Wdt::Wdt()
{
}

Wdt::~Wdt()
{
}

void Wdt::Feed()
{
	esp_task_wdt_reset();
}

void Wdt::Start(uint8_t timeoutInSeconds, bool panic)
{
	// esp_int_wdt_init();
	// esp_int_wdt_cpu_init();
	// esp_task_wdt_init(timeoutInSeconds, panic);
}

void Wdt::Stop()
{
	// esp_task_wdt_deinit();
}

} // namespace Hal
