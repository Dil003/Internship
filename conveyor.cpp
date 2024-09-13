#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class InletConveyor {
private:
    bool sensor1_detected;  // Fruit detected at the start (Sensor 1)
    bool sensor2_detected;  // Fruit detected at the end (Sensor 2)
    bool singulator_occupied;  // Is singulator occupied (Yes/No)
    bool motor1_status;     // Motor1 status (ON/OFF)

public:
    // Constructor to initialize the state of sensors and motor
    InletConveyor() : sensor1_detected(false), sensor2_detected(false), singulator_occupied(false), motor1_status(false) {}

    // Function to set sensor 1, sensor 2 and singulator status, and make a single decision
    void gather_input_and_decide(bool sensor1, bool sensor2, bool singulator) {
        sensor1_detected = sensor1;
        sensor2_detected = sensor2;
        singulator_occupied = singulator;

        // Display the gathered input
        cout << "\nSensor 1: " << (sensor1_detected ? "Fruit detected at the start." : "No fruit detected at the start.") << endl;
        cout << "Sensor 2: " << (sensor2_detected ? "Fruit detected at the end." : "No fruit detected at the end.") << endl;
        cout << "Singulator: " << (singulator_occupied ? "Occupied." : "Unoccupied.") << endl;

        // Make a decision based on the gathered input
        update_motor_status();
    }

    // Updates the motor status based on the current sensor inputs
    void update_motor_status() {
        if (sensor2_detected && singulator_occupied) {
            // If fruit is detected at the end AND singulator is occupied, pause the belt
            motor1_status = false;
            cout << "Motor 1: OFF - Conveyor belt is paused." << endl;
        } else if (sensor1_detected || sensor2_detected) {
            // If fruit is detected at the start or the end (and no blockage), run the motor
            motor1_status = true;
            cout << "Motor 1: ON - Conveyor belt is running." << endl;
        } else {
            // If no fruit at start or end and singulator is not occupied, turn the motor off
            motor1_status = false;
            cout << "Motor 1: OFF - Conveyor belt is stopped." << endl;
        }
    }

    // The main loop to gather user inputs and process them at once
    void run() {
        string user_input;
        bool detected_at_start;
        bool detected_at_end;
        bool is_singulator_occupied;

        try {
            while (true) {
                // Gather inputs all at once
                cout << "\nIs fruit detected at the start? (yes/no): ";
                cin >> user_input;
                detected_at_start = (user_input == "yes");

                cout << "Is fruit detected at the end? (yes/no): ";
                cin >> user_input;
                detected_at_end = (user_input == "yes");

                cout << "Is the singulator occupied? (yes/no): ";
                cin >> user_input;
                is_singulator_occupied = (user_input == "yes");

                // After gathering all inputs, make a decision
                gather_input_and_decide(detected_at_start, detected_at_end, is_singulator_occupied);

                // Simulate time passing (pause for 1 second)
                this_thread::sleep_for(chrono::seconds(1));
            }
        } catch (exception& e) {
            cout << "Conveyor system stopped due to an error: " << e.what() << endl;
        }
    }
};

int main() {
    InletConveyor conveyor;
    conveyor.run();  // Start the conveyor system simulation
    return 0;
}
