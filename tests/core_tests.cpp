#include "streamforge/core/stream_target.hpp"
#include <cstdlib>
int main() {
  streamforge::StreamTarget target;
  if (!target.can_connect()) return EXIT_FAILURE;
  target.state = streamforge::TargetState::Connecting;
  if (target.can_connect()) return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
