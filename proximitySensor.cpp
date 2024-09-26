#include <iostream>
using namespace std;

class ProximitySensor {
private:
    bool activated;        // Activation status
    float triggerThreshold; // Threshold for triggering

public:
    ProximitySensor(float threshold) : activated(false), triggerThreshold(threshold) {}

    void detectDrop() {
        cout << "Drop detected by proximity sensor." << endl;
        activated = true;
    }

    bool isTriggered() const {
        return activated;
    }
};
