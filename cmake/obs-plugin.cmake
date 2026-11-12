option(STREAMFORGE_BUILD_OBS_PLUGIN
       "Build the native OBS Studio plugin (requires OBS 30.0.2 SDK and matching Qt6)" OFF)

if(STREAMFORGE_BUILD_OBS_PLUGIN)
  find_package(libobs CONFIG REQUIRED)
  find_package(obs-frontend-api CONFIG REQUIRED)
  find_package(Qt6 CONFIG REQUIRED COMPONENTS Core Widgets)

  add_library(streamforge_plugin MODULE src/obs/plugin_main.cpp)
  target_compile_features(streamforge_plugin PRIVATE cxx_std_20)
  target_link_libraries(streamforge_plugin PRIVATE
    OBS::libobs OBS::obs-frontend-api Qt6::Core Qt6::Widgets
  )
  set_target_properties(streamforge_plugin PROPERTIES
    AUTOMOC ON PREFIX "" OUTPUT_NAME "streamforge"
  )
  if(WIN32)
    set_target_properties(streamforge_plugin PROPERTIES SUFFIX ".dll")
  endif()
endif()
