#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>

class FuelTank {
public:
    FuelTank(double capacity);
    void refuel(double amount);
    void consume(double amount);
    void transferTo(FuelTank& otherTank, double amount);
    double getFuelLevel() const;
    double getCapacity() const;
    bool isLowFuel() const;

private:
    double capacity;
    double currentLevel;
    static constexpr double LOW_FUEL_THRESHOLD = 10.0; // Example threshold for low fuel
};

class FuelSystem {
public:
    FuelSystem(const std::vector<double>& tankCapacities);
    void refuelTank(int tankIndex, double amount);
    void consumeFromTank(int tankIndex, double amount);
    void consumeEqually(double amount);
    void transferFuel(int fromTankIndex, int toTankIndex, double amount);
    void monitorFuelLevels() const;
    double getTotalFuelLevel() const;
    double getTankFuelLevel(int tankIndex) const;
    double getTankCapacity(int tankIndex) const;

private:
    std::vector<FuelTank> tanks;
};

#endif // LIBRARY_H