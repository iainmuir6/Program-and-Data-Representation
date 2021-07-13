// Iain Muir, iam9ez
// April 22nd, 2020
// traveling.cpp

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

/**
 * @brief Forward declarations for functions, computeDistance and printRoute
 */
float computeDistance(MiddleEarth me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
 * @brief 
 * @param argc number of arguments; main method exits without six supplied arguments
 * @param argv array of arguments: 1) ./a.out
 *                                 2) world height   (20)
 *                                 3) world width    (20)
 *                                 4) num_cities     (20) out of 40 total
 *                                 5) random_seed    (14)
 *                                 6) cities_to_vist (1-num_cities)
 * @return 0 - int
 * @details Read in command line parameters and store values into int variables using the stoi() function;
 *          Create a Middle Earth object, a world, and a destinations vector using the getItinerary function;
 *          Save starting position and remove it from the vector, then sort the vector before any permutations;
 *          For all of the permuatations of the vector, compute the distance (using computeDistance()) between the 
 *          destinations and store the minimum distance and in-order vector to be printed out using printRoute()
 */
int main(int argc, char** argv) {
  /**
   * @brief Check the number of parameters; exit if not 6
   */
  if (argc != 6) {
    cout << "Usage: " << argv[0] << " <world_height> <world_width> "
	 << "<num_cities> <random_seed> <cities_to_visit>" << endl;
    exit(0);
  }
 
  /**
   * @brief Assuming the parameters are all well-formed, store their values into respective variables
   */
  int width = stoi(argv[1]);
  int height = stoi(argv[2]);
  int num_cities = stoi(argv[3]);
  int rand_seed = stoi(argv[4]);
  int cities_to_visit = stoi(argv[5]);

  /**
   * @brief Create the world, me, and select your itinerary, dests
   */ 
  MiddleEarth me(width, height, num_cities, rand_seed);
  vector<string> dests = me.getItinerary(cities_to_visit);

  /**
   * @brief Remove starting position from vector and sort
   */
  string start = dests[0];
  swap(dests[0], dests[dests.size() - 1]);
  dests.pop_back();
  sort(dests.begin(), dests.end());

  /**
   * @brief Initialize variables to be used in permutation while loop
   */
  float minDistance = 1000000000000;
  bool anotherPermutation = true;
  vector<string> sorted;

  /**
   * @brief Loop through every permutation of the vector dests, finding the miniumum distance
   * @details For a vector of length n, there are n! permutations; ex. if there are 8 cities to visit, there are
   *          40320 different permutations/paths for the travelling salesperson
   */
  while (anotherPermutation) {
    anotherPermutation = next_permutation(dests.begin(), dests.end());
    float distance = computeDistance(me, start, dests);
    if (distance < minDistance) {
      minDistance = distance;
      sorted = dests;
    }  
  }

  /**
   * @brief Print out the path with the shortest possible path
   */
  cout << "The minimum TS path has distance " << computeDistance(me, start, sorted) << ": ";
  printRoute(start, sorted);

  return 0;
}

/**
 * @brief Calculates distance of the travelling salesperson's path
 * @details This method will compute the full distance of the cycle that starts at the 'start' parameter,
 *          goes to each of the cities in the dests vector IN ORDER, and ends back at the 'start' parameter.
 */
float computeDistance(MiddleEarth me, const string& start, vector<string> dests) {
  float totalDistance = 0;

  totalDistance += me.getDistance(start, dests[0]);
  for (int i = 0; i < (dests.size() - 1); i++) {
    totalDistance += me.getDistance(dests[i], dests[i+1]);
  }
  totalDistance += me.getDistance(dests[dests.size() - 1], start);

  return totalDistance;
}

/**
 * @brief Print the travelling salesperson's path
 * @details This method will print the entire route, starting and ending at the 'start' parameter.
 *          The output should be similar to:  Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 */
void printRoute(const string& start, const vector<string>& dests) {
  cout << start << " --> ";
  for (int i = 0; i < dests.size(); i++) {
    cout << dests[i] << " --> ";
  }
  cout << start << endl;
}
