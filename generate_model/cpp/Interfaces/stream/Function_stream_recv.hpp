#pragma once

#include <istream>

namespace CompoMe {
class Function_stream_recv {
public:
  virtual ~Function_stream_recv() {};
  virtual std::istream &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
  // Spaces between the tokens of a call are skipped: f("a", "b" ) is read as
  // f("a","b"). Those inside a string argument are kept, std::ws only runs
  // before a separator or an argument.
  char get() { return (this->get_si() >> std::ws).get(); }
};

template <typename T>
CompoMe::Function_stream_recv &operator>>(CompoMe::Function_stream_recv &s,
                                          T &e) {
  s.get_si() >> std::ws >> e;
  return s;
}

} // namespace CompoMe
