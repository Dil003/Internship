#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Singulator {
private:
    bool sensor3_detected;  // Laser sensor detecting fruit
    bool limit_switch_active;  // Limit switch status (ON/OFF)
    bool motor2_status;  // Motor2 status (ON/OFF)

public:
    // Constructor to initialize the singulator state
    Singulator() : sensor3_detected(false), limit_switch_active(false), motor2_status(false) {}

    // Function to set sensor 3 and limit switch status, and make a decision
    void gather_input_and_decide(bool sensor3, bool limit_switch) {
        sensor3_detected = sensor3;
        limit_switch_active = limit_switch;

        // Display the gathered input
        cout << "\nSensor 3 (Laser): " << (sensor3_detected ? "Fruit detected at singulator." : "No fruit detected.") << endl;
        cout << "Limit Switch: " << (limit_switch_active ? "Active." : "Inactive.") << endl;

        // Make a decision based on the input
        update_motor_status();
    }

    // Updates the motor status based on sensor and limit switch
    void update_motor_status() {
        if (sensor3_detected && !limit_switch_active) {
            // If fruit is detected and limit switch is not active, run the motor
            motor2_status = true;
            cout << "Motor 2: ON - Singulator is running." << endl;
        } else if (limit_switch_active) {
            // If limit switch is active, stop the motor
            motor2_status = false;
            cout << "Motor 2: OFF - Singulator is stopped." << endl;
        } else {
            // Default to motor off
            motor2_status = false;
            cout << "Motor 2: OFF - Singulator is idle." << endl;
        }
    }

    // The main loop to gather user inputs and process them at once
    void run() {
        string user_input;
        bool detected_at_singulator;
        bool limit_switch_active;

        try {
            while (true) {
                // Gather inputs all at once
                cout << "\nIs fruit detected at the singulator (Laser sensor)? (yes/no): ";
                cin >> user_input;
                detected_at_singulator = (user_input == "yes");

                cout << "Is the limit switch active? (yes/no): ";
                cin >> user_input;
                limit_switch_active = (user_input == "yes");

                // After gathering all inputs, make a decision
                gather_input_and_decide(detected_at_singulator, limit_switch_active);

                // Simulate time passing (pause for 1 second)
                this_thread::sleep_for(chrono::seconds(1));
            }
        } catch (exception& e) {
            cout << "Singulator system stopped due to an error: " << e.what() << endl;
        }
    }
};

int main() {
    Singulator singulator;
    singulator.run();  // Start the singulator system simulation
    return 0;
}
