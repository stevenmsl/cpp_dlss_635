#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol635;
using namespace std;

/*takeaways
  - we don't know if we need to favor the retrieve
    or the put method in our design. So this solution
    is in favor of put
  - a typical log system will have a lot of entries
    created but fewer queries required
  - you also need to consider the cost of maintaining
    an ordered set of log entries all time

*/

void Log::put(int id, string timestamp)
{
  entries.push_back({id, timestamp});
}
vector<int> Log::retrieve(string start, string end, string granularity)
{
  auto result = vector<int>();
  auto endPos = granEndPos[granularity];
  /* only need to compare up to the endPos */
  start = start.substr(0, endPos);
  end = end.substr(0, endPos);

  for (auto &[id, ts] : entries)
    if (ts.substr(0, endPos) >= start && ts.substr(0, endPos) <= end)
      result.push_back(id);

  return result;
}