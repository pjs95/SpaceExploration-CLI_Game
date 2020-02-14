#include "planetRepository.hpp"

std::vector<Planet> &PlanetRepository::getModels() {
    return this->planets;
}

void PlanetRepository::add(const Planet &planet) {
    planets.push_back(planet);
}

bool PlanetRepository::remove(const Planet &planet) {
    auto countBefore = this->planets.size();
    planets.erase(std::remove(planets.begin(), planets.end(), planet), planets.end());
    return countBefore < this->planets.size();
}

PlanetRepository::~PlanetRepository() = default;
