function(set_all_warnings)
  set(COMPILE_OPTIONS_GNU
      -Werror
      -Wall
      -Wextra
      -Wconversion
      -Wsign-conversion
      -Wpedantic
      -Wshadow
      -Wlogical-op
      -Wdeprecated
      -Wswitch-enum
      -Wduplicated-cond
      -Wnull-dereference
      -Wmisleading-indentation
      -Wduplicated-branches
      -Wuseless-cast
      PARENT_SCOPE)
  return()
endfunction()

function(set_project_warnings options)

  set_all_warnings()

  set(${options}
      "$<$<CXX_COMPILER_ID:GNU>:${COMPILE_OPTIONS_GNU}>"
      PARENT_SCOPE)
  return()

endfunction()
