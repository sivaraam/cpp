#include <set>
#include <vector>
#include <iostream>
#include <tuple>
#include <future>

using std::multiset;
using std::vector;
using std::tuple;
using std::istream;
using std::ostream;

namespace pipe_joiner_solver {

  class pipe_joiner {

      // The continers for the input and output
      multiset<unsigned> pipe_lengths;
      vector<unsigned> join_pipe_lengths;

      // future that holds the result of the
      std::future< vector<unsigned> >  join_result_handle;

      // When invoked joins the pipe in pipe_lengths and fills
      // join_pipe_lengths with the costs of each step to join them.
      // Will not mutate pipe_lengths. Executes the core function
      // asynchronously.
      void solve_async();

      public:
        // delete the unwanted defaults
        pipe_joiner(const pipe_joiner&) = delete;
        pipe_joiner(pipe_joiner&&) = delete;
        pipe_joiner& operator=(const pipe_joiner&) = delete;
        pipe_joiner& operator=(pipe_joiner&&) = delete;

        pipe_joiner() = default;

        // Returns the result of the core function
        tuple<vector<unsigned>, bool> get_pipe_lengths() noexcept;

        friend istream& operator>>(istream&, pipe_joiner&);

  };

  ostream& operator<<(ostream&, pipe_joiner&);
}
