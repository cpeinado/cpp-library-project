#include "library.h"
#include <iostream>

// Implementation of FuelTank class
FuelTank::FuelTank(double capacity) : capacity(capacity), currentLevel(0) {}

void FuelTank::refuel(double amount) {
    if (currentLevel + amount <= capacity) {
        currentLevel += amount;
    } else {
        currentLevel = capacity;
    }
}

void FuelTank::consume(double amount) {
    if (currentLevel - amount >= 0) {
        currentLevel -= amount;
    } else {
        currentLevel = 0;
    }
}

void FuelTank::transferTo(FuelTank& otherTank, double amount) {
    if (currentLevel >= amount) {
        currentLevel -= amount;
        otherTank.refuel(amount);
    } else {
        double transferableAmount = currentLevel;
        currentLevel = 0;
        otherTank.refuel(transferableAmount);
    }
}

double FuelTank::getFuelLevel() const {
    return currentLevel;
}

double FuelTank::getCapacity() const {
    return capacity;
}

bool FuelTank::isLowFuel() const {
    return currentLevel <= LOW_FUEL_THRESHOLD;
}

// Implementation of FuelSystem class
FuelSystem::FuelSystem(const std::vector<double>& tankCapacities) {
    for (double capacity : tankCapacities) {
        tanks.emplace_back(capacity);
    }
}

void FuelSystem::refuelTank(int tankIndex, double amount) {
    if (tankIndex >= 0 && tankIndex < tanks.size()) {
        tanks[tankIndex].refuel(amount);
    }
}

void FuelSystem::consumeFromTank(int tankIndex, double amount) {
    if (tankIndex >= 0 && tankIndex < tanks.size()) {
        tanks[tankIndex].consume(amount);
    }
}

void FuelSystem::consumeEqually(double amount) {
    double totalFuel = getTotalFuelLevel();
    if (amount > totalFuel) {
        amount = totalFuel;
    }

    while (amount > 0) {
        double amountPerTank = amount / tanks.size();
        for (auto& tank : tanks) {
            double fuelLevel = tank.getFuelLevel();
            if (fuelLevel >= amountPerTank) {
                tank.consume(amountPerTank);
                amount -= amountPerTank;
            } else {
                tank.consume(fuelLevel);
                amount -= fuelLevel;
            }
        }
    }
}

void FuelSystem::transferFuel(int fromTankIndex, int toTankIndex, double amount) {
    if (fromTankIndex >= 0 && fromTankIndex < tanks.size() && toTankIndex >= 0 && toTankIndex < tanks.size()) {
        tanks[fromTankIndex].transferTo(tanks[toTankIndex], amount);
    }
}

void FuelSystem::monitorFuelLevels() const {
    for (size_t i = 0; i < tanks.size(); ++i) {
        if (tanks[i].isLowFuel()) {
            std::cout << "Warning: Tank " << i << " is low on fuel." << std::endl;
        }
    }
}

double FuelSystem::getTotalFuelLevel() const {
    double total = 0;
    for (const auto& tank : tanks) {
        total += tank.getFuelLevel();
    }
    return total;
}

double FuelSystem::getTankFuelLevel(int tankIndex) const {
    if (tankIndex >= 0 && tankIndex < tanks.size()) {
        return tanks[tankIndex].getFuelLevel();
    }
    return 0;
}

double FuelSystem::getTankCapacity(int tankIndex) const {
    if (tankIndex >= 0 && tankIndex < tanks.size()) {
        return tanks[tankIndex].getCapacity();
    }
    return 0;
}