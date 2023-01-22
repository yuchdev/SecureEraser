install(
    TARGETS winapi_helpers eraser eraser_cli
    RUNTIME COMPONENT secure_eraser_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
