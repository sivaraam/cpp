#include "pipe_joiner.h"

namespace pipe_joiner_solver {

  // declared 'noexcept' because the usage is known to
  // avoid such invocations
  template <typename T>
  inline static T extract_first(multiset<T>& s) {
    T val = *s.begin();
    s.erase(s.begin());
    return val;
  }

  // The core function (invoked asynchronously)
  static vector<unsigned> join(multiset<unsigned> pipe_lengths) noexcept {
    const static vector<unsigned> single_pipe_join_lengths { 0 };

    // if there's only one pipe return join length as 0
    if(pipe_lengths.size() == 1)
      return single_pipe_join_lengths;
    
    vector<unsigned> joined_pipe_lengths;

    while(pipe_lengths.size() > 1) {
      const unsigned new_pipe_length =  extract_first(pipe_lengths) + extract_first(pipe_lengths);
      pipe_lengths.insert(new_pipe_length);
      joined_pipe_lengths.push_back(new_pipe_length);
    }

    return joined_pipe_lengths;
  }

  // starts the async invocation of the core function of computing result
  void pipe_joiner::solve_async() {
    join_result_handle = std::async(std::launch::async, &join, this->pipe_lengths);
  }

  tuple<vector<unsigned>, bool> pipe_joiner::get_pipe_lengths() noexcept {
    auto async_started = join_result_handle.valid();

    if(async_started) {
      auto result = join_result_handle.get();
      return std::make_tuple(result, async_started);
    }
    else {
      const static vector<unsigned> empty_vector { };
      return std::make_tuple(empty_vector, async_started);
    }
  }

  istream& operator>>(istream& is, pipe_joiner& pj_instance) noexcept {
    int num_pipe_lengths = 0;

    is>>num_pipe_lengths;

    for(int i=0; i<num_pipe_lengths; i++) {
      int curr_pipe_length=0;

      is>>curr_pipe_length;

      if(curr_pipe_length <= 0) {
        is.setstate(std::ios::failbit);
        pj_instance.pipe_lengths.clear(); // cleanup
        return is;
      }

      pj_instance.pipe_lengths.insert(curr_pipe_length);
    }

    pj_instance.solve_async();
    return is;
  }

  ostream& operator<<(ostream& os, pipe_joiner& pj_instance) noexcept {
    auto [pipe_lengths, solved] = pj_instance.get_pipe_lengths();

    if(!solved) {
      os<<"Warning: Problem not yet solved\n";
      return os;
    }

    for(auto pipe_length : pipe_lengths)
      os<<pipe_length<<'\n';

    return os;
  }
}
