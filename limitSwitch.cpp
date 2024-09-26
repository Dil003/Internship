#include <iostream>
using namespace std;

class LimitSwitch {
private:
    bool state;  // Switch state

public:
    LimitSwitch() : state(false) {}

    void notifyArms() {
        if (state) {
            cout << "Fruit ready for pickup. Notifying arm." << endl;
        }
    }

    bool isActivated() const {
        return state;
    }

    void setState(bool activated) {
        state = activated;
    }
};
