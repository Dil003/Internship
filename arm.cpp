#include <iostream>
using namespace std;

class Arm {
private:
    float positionX, positionY;  // Arm's position coordinates
    bool suctionCupActive;       // Status of the suction cup
    bool calibrated;             // Calibration status

public:
    Arm() : positionX(0), positionY(0), suctionCupActive(false), calibrated(false) {}

    void moveToPosition(float x, float y) {
        positionX = x;
        positionY = y;
        cout << "Arm moved to position (" << positionX << ", " << positionY << ")." << endl;
    }

    void pickFruit() {
        suctionCupActive = true;
        cout << "Suction cup activated. Picking up fruit." << endl;
    }

    void placeFruit() {
        suctionCupActive = false;
        cout << "Fruit placed into the tray. Suction cup deactivated." << endl;
    }

    void calibrate() {
        positionX = 0;
        positionY = 0;
        calibrated = true;
        cout << "Arm calibrated to home position (0, 0)." << endl;
    }

    void checkPosition() const {
        cout << "Current arm position: (" << positionX << ", " << positionY << ")." << endl;
    }
};
