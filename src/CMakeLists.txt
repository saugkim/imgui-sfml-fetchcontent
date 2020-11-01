add_executable(imgui-sfml-example
  main.cpp
)

# Yep, that's it!
target_link_libraries(imgui-sfml-example
  PUBLIC
    ImGui-SFML::ImGui-SFML
)

include(Install.cmake)

file(COPY ${CMAKE_SOURCE_DIR}/src/resources DESTINATION "${PROJECT_BINARY_DIR}/src")

#FILE(COPY resources DESTINATION "${PROJECT_BINARY_DIR}")
#add_custom_command(TARGET imgui-sfml-example PRE_BUILD
#                   	COMMAND ${CMAKE_COMMAND} -E copy_directory
#                       	${CMAKE_SOURCE_DIR}/src/resources/
#			DESTINATION "${PROJECT_BINARY_DIR}/src/resources")
		 	#$<TARGET_FILE_DIR:imgui-sfml-example/resources>)