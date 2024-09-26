#include <iostream>
using namespace std;

class SuctionCupSensor {
private:
    bool suctionCupActive;       // Suction cup status
    bool signalFromLimitSwitch;  // Signal from the limit switch

public:
    SuctionCupSensor() : suctionCupActive(false), signalFromLimitSwitch(false) {}

    void pick() {
        if (signalFromLimitSwitch) {
            suctionCupActive = true;
            cout << "Suction cup activated to pick up the fruit." << endl;
        } else {
            cout << "No signal from limit switch. Can't pick fruit." << endl;
        }
    }

    void place() {
        suctionCupActive = false;
        cout << "Fruit placed. Suction cup deactivated." << endl;
    }

    bool checkStatus() const {
        return suctionCupActive;
    }

    void setSignalFromLimitSwitch(bool signal) {
        signalFromLimitSwitch = signal;
    }
};
