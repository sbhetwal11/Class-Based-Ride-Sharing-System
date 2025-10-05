#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iomanip>


class Ride {
protected:
std::string rideID;
std::string pickupLocation;
std::string dropoffLocation;
double distance; // miles


public:
Ride(std::string id, std::string pickup, std::string dropoff, double dist)
: rideID(std::move(id)), pickupLocation(std::move(pickup)), dropoffLocation(std::move(dropoff)), distance(dist) {}
virtual ~Ride() = default;


virtual double fare() const = 0; // polymorphic


virtual std::string rideDetails() const {
return "Ride#" + rideID + " from " + pickupLocation + " to " + dropoffLocation +
" (" + std::to_string(distance) + " mi)";
}
};


class StandardRide : public Ride {
public:
using Ride::Ride; // inherit constructor
double fare() const override {
return distance * 1.0; // minimal fare rule
}
};


class PremiumRide : public Ride {
public:
using Ride::Ride;
double fare() const override {
return distance * 1.5; // premium multiplier
}
};


class Driver {
private:
std::string driverID;
std::string name;
double rating{};
std::vector<std::shared_ptr<Ride>> assignedRides; // encapsulated


public:
Driver(std::string id, std::string nm, double rt)
: driverID(std::move(id)), name(std::move(nm)), rating(rt) {}


void addRide(const std::shared_ptr<Ride>& r) {
assignedRides.push_back(r);
}


std::string getDriverInfo() const {
return "Driver#" + driverID + " — " + name + " (rating " + std::to_string(rating) + ")";
}


void listAssignedRides() const {
std::cout << getDriverInfo() << "\nAssigned Rides (" << assignedRides.size() << "):\n";
std::cout << std::fixed << std::setprecision(2);
for (const auto& r : assignedRides) {
std::cout << " - " << r->rideDetails() << ", fare $" << r->fare() << "\n";
}
}
};


class Rider {
private:
std::string riderID;
std::string name;
std::vector<std::shared_ptr<Ride>> requestedRides; // encapsulated


public:
Rider(std::string id, std::string nm) : riderID(std::move(id)), name(std::move(nm)) {}


void requestRide(const std::shared_ptr<Ride>& r) {
requestedRides.push_back(r);
}


void viewRides() const {
std::cout << "Rider#" << riderID << " — " << name << "\nRide History (" << requestedRides.size() << "):\n";
std::cout << std::fixed << std::setprecision(2);
for (const auto& r : requestedRides) {
std::cout << " * " << r->rideDetails() << ", fare $" << r->fare() << "\n";
}
}
};


int main() {
// Hard-coded sample data
auto r1 = std::make_shared<StandardRide>("S-001", "Downtown", "Airport", 12.0);
auto r2 = std::make_shared<PremiumRide>("P-101", "Stadium", "Hotel", 5.5);
auto r3 = std::make_shared<StandardRide>("S-002", "Museum", "University", 7.25);


// Polymorphic collection
std::vector<std::shared_ptr<Ride>> rides = { r1, r2, r3 };


// Demonstrate polymorphism
std::cout << "All Rides (polymorphic fare/rideDetails)\n";
std::cout << std::fixed << std::setprecision(2);
for (const auto& r : rides) {
std::cout << "- " << r->rideDetails() << ": $" << r->fare() << "\n";
}
std::cout << "\n";


// Driver & Rider usage (encapsulation via methods)
Driver d{"D-77", "Alex Johnson", 4.9};
d.addRide(r1);
d.addRide(r3);


Rider u{"U-42", "Sam Patel"};
u.requestRide(r2);
u.requestRide(r3);


d.listAssignedRides();
std::cout << "\n";
u.viewRides();


return 0;
}