#include "LaserControlService.h"
#include "ApplicationAgent.h"
#include "StatusAgent.h"
#include "ConfigurationAgent.h"
#include "Logger.h"

namespace Applications
{
using Utilities::Logger;

LaserControlService::LaserControlService() : cpp_freertos::Thread("LSRVC", configLASERSVC_STACK_DEPTH, 3)
{

}

LaserControlService::~LaserControlService()
{

}

void LaserControlService::Run()
{
    Logger::LogInfo(Logger::LogSource::LaserController, "Laser Controller Service Started");

}

void LaserControlService::randomPosition()
{
	uint16_t laserDelay = Status::StatusAgent::Instance()->GetInputStatusList().
					GetInput(Configuration::InputIndex::PotLaserDelay).GetAnalogLevel();
    
	_motorX->SetPositon(_rng->GetNumber()%100);
	_motorY->SetPositon(_rng->GetNumber()%100);

	if (laserDelay < 300)
		laserDelay = 300;

	vTaskDelay(laserDelay + _rng->GetNumber()%(laserDelay / 2));
}

void LaserControlService::roundEffect()
{
	switch(_roundEffectState)
	{
		case LaserRoundEffectStateMachine::RasingXDroppingY:
			_remoteX++;
			_remoteY--;
			if (_remoteX == 100)
				_roundEffectState = LaserRoundEffectStateMachine::DroppingXDroppingY;
			break;
		case LaserRoundEffectStateMachine::DroppingXDroppingY:
			_remoteX--;
			_remoteY--;
			if (_remoteX == 50)
				_roundEffectState = LaserRoundEffectStateMachine::DroppingXRasingY;
			break;
		case LaserRoundEffectStateMachine::DroppingXRasingY:
			_remoteX--;
			_remoteY++;
			if (_remoteX == 0)
				_roundEffectState = LaserRoundEffectStateMachine::RasingXRasingY;
			break;
		case LaserRoundEffectStateMachine::RasingXRasingY:
			_remoteX++;
			_remoteY++;
			if (_remoteX == 50)
				_roundEffectState = LaserRoundEffectStateMachine::None;
			break;
		
		default:
			_roundEffectState = LaserRoundEffectStateMachine::RasingXDroppingY;
			_remoteX = 50;
			_remoteY = 100;
	}
	_motorX->SetPositon(_remoteX);
	_motorY->SetPositon(_remoteY);
	uint16_t laserDelay = Status::StatusAgent::Instance()->GetInputStatusList().
				GetInput(Configuration::InputIndex::PotLaserDelay).GetAnalogLevel();

	vTaskDelay(10 + (laserDelay / 100));
}

} // namespace Applications
