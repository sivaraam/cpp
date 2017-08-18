#include "pipe_joiner.h"

namespace pipe_joiner_solver {

  template <typename T>
  static T extract_first(set<T>& s) {
    T val = *s.begin();
    s.erase(s.begin());
    return val;
  }

  static vector<unsigned> join(set<unsigned> pipe_lengths) {
    // if there's only one pipe return cost as 0
    if(pipe_lengths.size() == 1)
      return { 0 };
    
    vector<unsigned> join_costs;

    while(pipe_lengths.size() > 1) {
      unsigned join_cost, new_pipe_length;
      join_cost = new_pipe_length =  extract_first(pipe_lengths) + extract_first(pipe_lengths);
      pipe_lengths.insert(new_pipe_length);
      join_costs.push_back(join_cost);
    }

    return join_costs;
  }

  void pipe_joiner::solve() {
    this->join_costs = join(this->pipe_lengths);
  }

  istream& operator>>(istream& is, pipe_joiner& pj_instance) {
    int num_pipe_lengths = 0;

    is>>num_pipe_lengths;

    for(int i=0; i<num_pipe_lengths; i++) {
      int curr_pipe_length=0;
      is>>curr_pipe_length;
      pj_instance.pipe_lengths.insert(curr_pipe_length);
    }

    // to convert into an asynchronous call
    pj_instance.solve();
    return is;
  }

  ostream& operator<<(ostream& os, const pipe_joiner& pj_instance) {
    for(auto join_cost : pj_instance.join_costs)
      os<<join_cost<<'\n';

    return os;
  }
}
