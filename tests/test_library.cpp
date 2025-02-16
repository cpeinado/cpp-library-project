#include "library.h"
#include <cassert>
#include <iostream>

void testFuelSystem() {
    std::vector<double> tankCapacities = {100.0, 150.0, 200.0};
    FuelSystem fuelSystem(tankCapacities);

    assert(fuelSystem.getTotalFuelLevel() == 0.0);

    fuelSystem.refuelTank(0, 50.0);
    assert(fuelSystem.getTankFuelLevel(0) == 50.0);
    assert(fuelSystem.getTotalFuelLevel() == 50.0);

    fuelSystem.refuelTank(1, 100.0);
    assert(fuelSystem.getTankFuelLevel(1) == 100.0);
    assert(fuelSystem.getTotalFuelLevel() == 150.0);

    fuelSystem.consumeFromTank(0, 20.0);
    assert(fuelSystem.getTankFuelLevel(0) == 30.0);
    assert(fuelSystem.getTotalFuelLevel() == 130.0);

    fuelSystem.consumeFromTank(1, 90.0);
    assert(fuelSystem.getTankFuelLevel(1) == 10.0);
    assert(fuelSystem.getTotalFuelLevel() == 40.0);

    fuelSystem.refuelTank(0, 50.0);
    fuelSystem.refuelTank(1, 100.0);
    fuelSystem.refuelTank(2, 200.0);
    
    fuelSystem.consumeEqually(90.0);

    assert(fuelSystem.getTankFuelLevel(0) == 50.0);
    assert(fuelSystem.getTankFuelLevel(1) == 80.0);
    assert(fuelSystem.getTankFuelLevel(2) == 170.0);

    fuelSystem.transferFuel(2, 0, 50.0);
    assert(fuelSystem.getTankFuelLevel(0) == 100.0);
    assert(fuelSystem.getTankFuelLevel(2) == 120.0);

    fuelSystem.monitorFuelLevels();

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testFuelSystem();
    return 0;
}