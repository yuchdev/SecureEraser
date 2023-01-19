install(
    TARGETS winapi_helpers eraser appcli
    RUNTIME COMPONENT cpp-template_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
