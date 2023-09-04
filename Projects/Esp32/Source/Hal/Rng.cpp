
#include "Rng.h"

namespace Hal
{

Rng::Rng()
{
}

Rng::~Rng()
{
}

uint32_t Rng::GetNumber()
{
    return (uint32_t)rand();
}

} // namespace Hal
