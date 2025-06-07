cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Add source to this project's executable.
# Uses cpp17 by default, which is the same as the CCC online grader so don't enable CPP20 for consistency
add_executable (DeliveryDroid "DeliveryDroid.cpp")
add_executable (ChilliPeppers "ChilliPeppers.cpp")
add_executable (SpecialEvent "SpecialEvent.cpp")

# TODO: Add tests and install targets if needed.
