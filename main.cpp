#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol635;

/*
put(1, "2017:01:01:23:59:59");
put(2, "2017:01:01:22:59:59");
put(3, "2016:01:01:00:00:00");
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 2016 and 2017.
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // return [1,2], because you need to return all logs start from 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.
*/

void test1()
{
  Log log;
  log.put(1, "2017:01:01:23:59:59");
  log.put(2, "2017:01:01:22:59:59");
  log.put(3, "2016:01:01:00:00:00");

  cout << "Expect to see [1,2,3] " << endl;
  cout << Util::toString(log.retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year")) << endl;

  cout << "Expect to see [1,2] " << endl;
  cout << Util::toString(log.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour")) << endl;
}

main()
{
  test1();

  return 0;
}