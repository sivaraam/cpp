
#include "pipe_joiner.h"

namespace pipe_joiner_solver {

  template <typename T>
  static T extract_first(multiset<T>& s) {
    T val = *s.begin();
    s.erase(s.begin());
    return val;
  }

  // The core function
  static vector<unsigned> join(multiset<unsigned> pipe_lengths) {
    const static vector<unsigned> single_pipe_join_lengths { 0 };
    // if there's only one pipe return join length as 0
    if(pipe_lengths.size() == 1)
      return single_pipe_join_lengths;
    
    vector<unsigned> join_pipe_lengths;

    while(pipe_lengths.size() > 1) {
      const unsigned new_pipe_length =  extract_first(pipe_lengths) + extract_first(pipe_lengths);
      pipe_lengths.insert(new_pipe_length);
      join_pipe_lengths.push_back(new_pipe_length);
    }

    return join_pipe_lengths;
  }

  void pipe_joiner::solve_async() {
    join_result_handle = std::async(std::launch::async, join, this->pipe_lengths);
  }

  tuple<vector<unsigned>, bool> pipe_joiner::get_pipe_lengths() noexcept {
    auto async_started = join_result_handle.valid();

    if(async_started) {
      auto result = join_result_handle.get();
      return std::make_tuple(result, async_started);
    }
    else {
      return std::make_tuple(vector<unsigned> { }, async_started);
    }
  }

  istream& operator>>(istream& is, pipe_joiner& pj_instance) {
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

    // to convert into an asynchronous call
    pj_instance.solve_async();
    return is;
  }

  ostream& operator<<(ostream& os, pipe_joiner& pj_instance) {
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
