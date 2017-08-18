#include <set>
#include <vector>
#include <iostream>

using std::multiset;
using std::vector;
using std::istream;
using std::ostream;

namespace pipe_joiner_solver {

  class pipe_joiner {

      // The continers for the input and output
      multiset<unsigned> pipe_lengths;
      vector<unsigned> join_costs;

      // When invoked joins the pipe in pipe_lengths and
      // fills join_costs with the costs of each step to join them.
      // Will not mutate pipe_lengths.
      void solve();

      public:
        pipe_joiner() = default;

        // delete the unwanted defaults
        pipe_joiner(const pipe_joiner&) = delete;
        pipe_joiner(pipe_joiner&&) = delete;
        pipe_joiner& operator=(const pipe_joiner&) = delete;
        pipe_joiner& operator=(pipe_joiner&&) = delete;


        friend istream& operator>>(istream&, pipe_joiner&);
        friend ostream& operator<<(ostream&, const pipe_joiner&);

  };

}
