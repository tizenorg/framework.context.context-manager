CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(context-manager)
SET(VERSION_MAJOR 1)
SET(VERSION "${VERSION_MAJOR}.0.6")
SET(PREFIX ${CMAKE_INSTALL_PREFIX})

SET(target_server "contextd")
SET(target_capi "capi-context-manager")
SET(capi_dp "dlog glib-2.0 dbus-glib-1 json capi-appfw-application")

SET(PC_NAME ${target_capi})
SET(PC_INCLUDE "/usr/include/context-manager")
SET(PC_DESCRIPTION "Tizen Platform Context-Manager Library")
SET(PC_REQUIRED ${capi_dp})
SET(PC_LDFLAGS -l${target_capi})
SET(PC_CFLAGS -I\${includedir}/context-manager)

CONFIGURE_FILE(
	${target_capi}.pc.in
	${CMAKE_CURRENT_SOURCE_DIR}/${target_capi}.pc
	@ONLY
)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${target_capi}.pc DESTINATION lib/pkgconfig)
INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include/context-manager)

IF("${ARCH}" STREQUAL "arm")
	INSTALL(FILES ${CMAKE_SOURCE_DIR}/armv7l/${target_server} DESTINATION bin)
	INSTALL(FILES ${CMAKE_SOURCE_DIR}/armv7l/lib${target_capi}.so.${VERSION} DESTINATION lib)
	INSTALL(FILES ${CMAKE_SOURCE_DIR}/armv7l/lib${target_capi}.so.${VERSION_MAJOR} DESTINATION lib)
	INSTALL(FILES ${CMAKE_SOURCE_DIR}/armv7l/lib${target_capi}.so DESTINATION lib)
ELSE("${ARCH}" STREQUAL "arm")
	INSTALL(FILES ${CMAKE_SOURCE_DIR}/i586/${target_server} DESTINATION bin)
	INSTALL(FILES ${CMAKE_SOURCE_DIR}/i586/lib${target_capi}.so.${VERSION} DESTINATION lib)
	INSTALL(FILES ${CMAKE_SOURCE_DIR}/i586/lib${target_capi}.so.${VERSION_MAJOR} DESTINATION lib)
	INSTALL(FILES ${CMAKE_SOURCE_DIR}/i586/lib${target_capi}.so DESTINATION lib)
ENDIF("${ARCH}" STREQUAL "arm")
