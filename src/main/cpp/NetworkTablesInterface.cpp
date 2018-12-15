
#include "NetworkTablesInterface.h"
#include "NetworkTables/NetworkTableInstance.h"

bool NetworkTablesInterface::crossFound() {
	return nt::NetworkTableInstance::GetDefault().GetTable("cv")->GetEntry("crossFound").GetBoolean(false);
}
double NetworkTablesInterface::crossAzi() {
	return nt::NetworkTableInstance::GetDefault().GetTable("cv")->GetEntry("crossAzi").GetDouble(-1);
}
bool NetworkTablesInterface::rectFound() {
	return nt::NetworkTableInstance::GetDefault().GetTable("cv")->GetEntry("rectFound").GetBoolean(false);
}
double NetworkTablesInterface::rectAzi() {
	return nt::NetworkTableInstance::GetDefault().GetTable("cv")->GetEntry("rectAzi").GetDouble(-1);
}

