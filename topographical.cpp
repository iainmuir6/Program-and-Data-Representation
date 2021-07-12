// Iain Muir, iam9ez
// April 21st, 2020
// topographical.cpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <fstream>
#include <cstdlib>

using namespace std;

/**
 * @brief main method for topographical sort
 * @details using command line parameter, this main method reads in an input file, parses the data into two separate maps; 
 *          one map stores the indegree of every course in the file, while the other map stores which classes are prerequisites to other classes.
 * @param argc is the number of command line parameters (2)
 * @param argv is the array of the parameters: 1) a.out 2) text file (pre-lab-small.txt or pre-lab-full.txt)
 */
int main(int argc, char** argv) {
  /**
   * @brief Verify the correct number of parameters
   */
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  /**
   * @brief Attempt to open the supplied file; Reports any problems opening the file and then exit
   */
  ifstream file(argv[1], ifstream::binary);
  if (!file.is_open()) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  /**
   * @brief unordered maps to store course indegree and prerequisites
   */
  unordered_map<string, vector<string>> courseMap;
  unordered_map<string, int> indegreeMap;
    
  /**
   * @brief string variables to store courses read in from the file; boolean value for while loop
   */
  string s1, s2;
  bool end = false;

  /**
   * @brief Generates courseMap and indegreeMap through reading input file
   * @details Reads in the input file and stores the values into s1 and s2, until the last line "0 0" is reached.
   *          For each iteration, courses and their respective indegrees are iterated and then inserted into indegreeMap and
   *          courses and a vector of their prerequisites are inserted into courseMap
   */
  while (!end) {
    file >> s1;
    file >> s2;
    //cout << s1 << endl;
    //cout << s2 << endl;
    if (s1 == "0" && s2 == "0") {
      end = true;
      break;
    }
    if (indegreeMap.find(s1) == indegreeMap.end()) {
      indegreeMap[s1] = 0;
    }
    if (indegreeMap.find(s2) == indegreeMap.end()) {
      indegreeMap[s2] = 1;
    }
    else {
      indegreeMap[s2]++;
    }

    if (courseMap.size() == 0) {
      vector<string> new_vec;
      new_vec.push_back(s2);
      courseMap[s1] = new_vec;
    }
    else {
      courseMap[s1].push_back(s2);
    }  
  }
  
  /**
   * @brief Closes inputed file, no longer needed.
   */
  file.close();

  /**
   * @brief Queue of strings; Loop through indegreeMap to insert courses with an indegree of zero into the queue
   */
  queue<string> q;
  for ( auto it = indegreeMap.begin(); it != indegreeMap.end(); ++it ) {
      if (it->second == 0) {
	q.push(it->first);
      }
  }

  /**
   * @brief counter variable to check for cyclical nature of a graph
   * @details this counter is later compared to the number of vertices in the graph to ensure that there is not a cycle
   *          If there is a cycle, there would be no valid topographical sort and the code exit with an error
   */
  int counter = 0;

  /**
   * @brief Prints out a valid topographical sort
   * @details While the queue is not empty, this loop pops off the front value, prints it, and then decrements
   *          the indegrees of any adjacent vertices. This is done by way of using both the courseMap to find the 
   *          course prerequisites and then the indegreeMap to decrement each prerequisites' indegree
   */
  while (!q.empty()) {
    string v = q.front();
    //cout << "Course: " << v << endl;
    q.pop();
    counter++;
    cout << v << " ";
    for (int i = 0; i < courseMap[v].size(); i++) {
      //cout << "Points to: " << courseMap[v][i] << endl;
      indegreeMap[courseMap[v][i]]--;
      if (indegreeMap[courseMap[v][i]] == 0) {
	q.push(courseMap[v][i]);
      }
    }  
  }
  if (counter != indegreeMap.size()) {
    cout << "Cycle found :(" << endl;
    exit(1);
  }  
  cout << "" << endl; 

  return 0;
}
  
