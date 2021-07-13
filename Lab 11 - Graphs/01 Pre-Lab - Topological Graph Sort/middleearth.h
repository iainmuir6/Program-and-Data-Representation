// Iain Muir, iam9ez
// April 21st, 2020
// middleearth.h

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
  /**
   * @class middleearth.h 
   * @author Iain Muir, iam9ez
   * @date April 21st, 2020
   * @brief World in which we will explore the Travelling Salesperson Problem
   * @details This class creates a world and populates it with cities at random distances apart, and then given a number of
   *          cities to stop in, calculates the minimum path distance for the travelling salesman to go to every city and
   *          return to home.
   */
public:
  /**
   * @brief Creates a world, xsize x ysize, with a total of num_cities cities.
   * @param xsize the x length of the world
   * @param ysize the y length of the world
   * @param num_cities specified number of cities in the World
   * @param seed random number generator
   * @return a World for the Travelling Salesperson
   */
  MiddleEarth(int xsize, int ysize, int num_cities, int seed);
  /**
   * @brief Prints out information of the created World
   * @return Prints out the number of cities, as well as each city name and its position in the World
   */
  void print();
  /**
   * @brief Prints a tab-separated table of the distances (which can be loaded into Excel or similar)
   * @return Table with the city, it's x and y position, and it's distances to every other city
   */
  void printTable();
  /**
   * @brief Calculates the distance between two cities the travelling salesperson passes through
   * @details If we assume that the hash table (i.e. the map) is O(1), then this method call is also O(1)
   * @param city1 first passed city
   * @param city2 second passed city
   * @return Distance between the two passed cities
   */
  float getDistance(const string& city1, const string& city2);
  /**
   * @brief Records the details of the travelling salesperson's movements, effectively creating an itinerary
   * @details The first city is the original start point as well as the end point, and therefore the number of 
              cities passed in does not include this start/end point. There will be length+1 entries in the returned vector.
   * @param length the number of cities passed, exlcuding the starting point city
   * @return a vector that represents the list of cities to travel to
   */
  vector<string> getItinerary(unsigned int length);

private:
  /**
   * @brief Number of cities in the World/ x length of the World/ y length of the World
   * @private
   */
  int num_city_names, xsize, ysize;
  /**
   * @brief Location of a city in the World
   * @private
   */
  unordered_map<string, float> xpos, ypos;
  /**
   * @brief Mutable vector that is created from a shuffled copy of all of the cities in the World
   * @private
   */
  vector<string> cities;
  /**
   * @brief Map that contains each city, and a Map that contains every other other and the distance between the two
   * @details city1 : (city2 : 50.0) , (city3 : 63.4), etc.
   * @private
   */
  unordered_map<string, unordered_map<string, float>> distances;
  /**
   * @brief Mersenne-Twister random number engine
   * @private
   */
  mt19937 gen; 
};

#endif
