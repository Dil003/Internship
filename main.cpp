#include <iostream>
#include "ConveyorBelt.h"
#include "Singulator.h"
#include "Arm.h"
#include "VisionSystem.h"
#include "LimitSwitch.h"
#include "ProximitySensor.h"
#include "SuctionSensor.h"
#include "SuctionCupSensor.h"

using namespace std;

int main() {
    // Create objects for each component
    ConveyorBelt conveyorBelt;
    Singulator singulator;
    Arm arm;
    VisionSystem vision;
    LimitSwitch limitSwitch;
    ProximitySensor proximitySensor(10.0);  // Assume threshold is 10.0
    SuctionSensor suctionSensor;
    SuctionCupSensor suctionCupSensor;

    // Conveyor belt operation
    conveyorBelt.start();
    conveyorBelt.checkStatus();
    conveyorBelt.stop();

    // Singulator operation
    singulator.activate();
    cout << "Singulator state: " << (singulator.getState() ? "Active" : "Inactive") << endl;
    singulator.deactivate();

    // Vision system capturing and processing image
    vision.captureImage();
    vision.processImage();
    vision.identifyFruit();
    vision.approveFruit();

    // Arm actions
    arm.calibrate();
    arm.moveToPosition(5.0, 3.0);
    arm.pickFruit();

    // Limit switch detecting fruit ready for pickup
    limitSwitch.setState(true);  // Simulating limit switch activation
    limitSwitch.notifyArms();
    
    // Suction cup sensor based on limit switch signal
    suctionCupSensor.setSignalFromLimitSwitch(limitSwitch.isActivated());
    suctionCupSensor.pick();
    suctionCupSensor.place();

    // Proximity sensor detection
    proximitySensor.detectDrop();
    if (proximitySensor.isTriggered()) {
        cout << "Proximity sensor triggered." << endl;
    }

    // Suction sensor operations
    suctionSensor.activate();
    suctionSensor.maintain();
    suctionSensor.deactivate();

    return 0;
}
