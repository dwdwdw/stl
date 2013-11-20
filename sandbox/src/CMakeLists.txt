file(GLOB src_list "*.cpp")
foreach(src ${src_list})
    get_filename_component(exe ${src} NAME_WE)
    add_executable(${exe} ${src})
    install(TARGETS ${exe} RUNTIME DESTINATION bin)
endforeach(src)

#target_link_libraries(sigma m)

