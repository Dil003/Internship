#include <iostream>
using namespace std;

class SuctionSensor {
private:
    bool active;  // Activation status of the vacuum generator

public:
    SuctionSensor() : active(false) {}

    void activate() {
        active = true;
        cout << "Vacuum generator activated." << endl;
    }

    void maintain() {
        if (active) {
            cout << "Maintaining vacuum suction..." << endl;
        }
    }

    void deactivate() {
        active = false;
        cout << "Vacuum generator deactivated." << endl;
    }

    bool isActive() const {
        return active;
    }
};
