install(
    TARGETS cpp-template_exe
    RUNTIME COMPONENT cpp-template_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
