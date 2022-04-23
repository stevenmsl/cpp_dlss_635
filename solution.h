
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
namespace sol635
{
  class Log
  {
  private:
    unordered_map<string, int> granEndPos = {
        {"Year", 4},
        {"Month", 7},
        {"Day", 10},
        {"Hour", 13},
        {"Minute", 16},
        {"Second", 19}};
    vector<pair<int, string>> entries;

  public:
    void
    put(int id, string timestamp);
    vector<int> retrieve(string start, string end, string granularity);
  };
}
#endif