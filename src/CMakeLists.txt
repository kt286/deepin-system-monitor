set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(APP_NAME ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall ")
set(CMAKE_CXX_FLAGS "-Wl,--as-need -fPIE")
set(CMAKE_EXE_LINKER_FLAGS "-pie")
if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "sw_64")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mieee")
endif ()
if (CMAKE_BUILD_TYPE STREQUAL "Release")
  add_definitions("-DQT_NO_DEBUG_OUTPUT")
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/environments.h.in ${CMAKE_CURRENT_BINARY_DIR}/environments.h @ONLY)

include(CheckIncludeFiles)
check_include_files ("sys/random.h" HAVE_SYS_RANDOM_H)
include(CheckSymbolExists)
check_symbol_exists(syscall "unistd.h" HAVE_SYS_CALL)
check_symbol_exists(SYS_getrandom "sys/syscall.h" HAVE_SYS_GETRANDOM)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include(FindPkgConfig)

find_package(DtkCore REQUIRED)
find_package(DtkGui REQUIRED)
find_package(DtkWidget REQUIRED)
find_library(LIB_PCAP NAMES pcap REQUIRED)
find_library(LIB_PROCPS NAMES procps REQUIRED)
find_library(LIB_XCB NAMES xcb REQUIRED)
find_library(LIB_XEXT NAMES Xext REQUIRED)
find_library(LIB_ICCCM NAMES xcb-icccm REQUIRED)
find_package(ICU COMPONENTS i18n uc REQUIRED)

pkg_search_module(LIB_NL3 REQUIRED libnl-3.0)
pkg_search_module(LIB_NL3_ROUTE REQUIRED libnl-route-3.0)
pkg_search_module(LIB_UDEV REQUIRED libudev)
include_directories(${LIB_NL3_INCLUDE_DIRS})
include_directories(${LIB_NL3_ROUTE_INCLUDE_DIRS})
include_directories(${LIB_UDEV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gui/base)

set(HPP_GLOBAL
    config.h
    environments.h
    accessible.h
    accessibledefine.h
    application.h
    stack_trace.h
    cpu_monitor.h
    memory_monitor.h
    network_monitor.h
    compact_cpu_monitor.h
    compact_memory_monitor.h
    compact_network_monitor.h
    compact_disk_monitor.h
    smooth_curve_generator.h
    settings.h
)
set(CPP_GLOBAL
    main.cpp
    application.cpp
    cpu_monitor.cpp
    memory_monitor.cpp
    network_monitor.cpp
    compact_cpu_monitor.cpp
    compact_memory_monitor.cpp
    compact_network_monitor.cpp
    compact_disk_monitor.cpp
    smooth_curve_generator.cpp
    settings.cpp
)

set(HPP_COMMON
    common/common.h
    common/error_context.h
    common/hash.h
    common/han_latin.h
    common/perf.h
    common/base_thread.h
    common/thread_manager.h
    common/time_period.h
    common/sample.h
)
set(CPP_COMMON
    common/common.cpp
    common/error_context.cpp
    common/hash.cpp
    common/han_latin.cpp
    common/perf.cpp
    common/thread_manager.cpp
    common/time_period.cpp
)

set(HPP_DBUS
    dbus/systemd1_manager_interface.h
    dbus/systemd1_service_interface.h
    dbus/systemd1_unit_interface.h
    dbus/dbus_properties_interface.h
    dbus/dbus_common.h
    dbus/environment_file.h
    dbus/unit_file_info.h
    dbus/unit_info.h
)
set(CPP_DBUS
    dbus/environment_file.cpp
    dbus/unit_file_info.cpp
    dbus/unit_info.cpp
    dbus/systemd1_manager_interface.cpp
    dbus/systemd1_service_interface.cpp
    dbus/systemd1_unit_interface.cpp
    dbus/dbus_properties_interface.cpp
)

set(HPP_MODEL
    model/process_table_model.h
    model/process_sort_filter_proxy_model.h
    model/system_service_table_model.h
    model/system_service_sort_filter_proxy_model.h
    model/cpu_info_model.h
    model/cpu_stat_model.h
    model/cpu_list_model.h
    model/cpu_list_sort_filter_proxy_model.h
    model/netif_info_model.h
    model/netif_stat_model.h
    model/netif_addr_model.h
    model/netif_info_sort_filter_proxy_model.h
    model/block_dev_stat_model.h
    model/block_dev_info_model.h
    model/block_dev_info_sort_filter_proxy_model.h
    model/model_manager.h
)
set(CPP_MODEL
    model/system_service_table_model.cpp
    model/system_service_sort_filter_proxy_model.cpp
    model/process_table_model.cpp
    model/process_sort_filter_proxy_model.cpp
    model/cpu_info_model.cpp
    model/cpu_stat_model.cpp
    model/cpu_list_model.cpp
    model/cpu_list_sort_filter_proxy_model.cpp
    model/netif_info_model.cpp
    model/netif_stat_model.cpp
    model/netif_addr_model.cpp
    model/netif_info_sort_filter_proxy_model.cpp
    model/block_dev_info_model.cpp
    model/block_dev_stat_model.cpp
    model/block_dev_info_sort_filter_proxy_model.cpp
    model/model_manager.cpp
)

set(HPP_GUI
    gui/base/base_detail_item_delegate.h
    gui/base/base_table_view.h
    gui/base/base_item_delegate.h
    gui/base/base_header_view.h
    gui/base/base_detail_view_widget.h
    gui/base/base_commandlink_button.h
    gui/ui_common.h
    gui/toolbar.h
    gui/main_window.h
    gui/process_table_view.h
    gui/process_page_widget.h
    gui/service_name_sub_input_dialog.h
    gui/system_service_table_view.h
    gui/system_service_page_widget.h
    gui/monitor_expand_view.h
    gui/monitor_compact_view.h
    gui/priority_slider.h
    gui/kill_process_confirm_dialog.h
    gui/process_attribute_dialog.h
    gui/dialog/error_dialog.h
    gui/xwin_kill_preview_widget.h
    gui/xwin_kill_preview_background_widget.h
    gui/mem_detail_view_widget.h
    gui/mem_summary_view_widget.h
    gui/mem_stat_view_widget.h
    gui/block_dev_detail_view_widget.h
    gui/block_dev_summary_view_widget.h
    gui/netif_detail_view_widget.h
    gui/netif_stat_view_widget.h
    gui/netif_item_view_widget.h
    gui/netif_summary_view_widget.h
    gui/detail_view_stacked_widget.h
    gui/chart_view_widget.h
    gui/block_dev_stat_view_widget.h
    gui/animation_stackedwidget.h
    gui/cpu_detail_widget.h
    gui/cpu_summary_view_widget.h
    gui/block_dev_item_widget.h
)
set(CPP_GUI
    gui/base/base_detail_item_delegate.cpp
    gui/base/base_table_view.cpp
    gui/base/base_item_delegate.cpp
    gui/base/base_header_view.cpp
    gui/base/base_detail_view_widget.cpp
    gui/base/base_commandlink_button.cpp
    gui/toolbar.cpp
    gui/system_service_table_view.cpp
    gui/main_window.cpp
    gui/system_service_page_widget.cpp
    gui/process_page_widget.cpp
    gui/service_name_sub_input_dialog.cpp
    gui/process_table_view.cpp
    gui/dialog/error_dialog.cpp
    gui/monitor_expand_view.cpp
    gui/monitor_compact_view.cpp
    gui/kill_process_confirm_dialog.cpp
    gui/process_attribute_dialog.cpp
    gui/priority_slider.cpp
    gui/ui_common.cpp
    gui/xwin_kill_preview_widget.cpp
    gui/xwin_kill_preview_background_widget.cpp
    gui/mem_detail_view_widget.cpp
    gui/mem_summary_view_widget.cpp
    gui/mem_stat_view_widget.cpp
    gui/block_dev_detail_view_widget.cpp
    gui/block_dev_summary_view_widget.cpp
    gui/netif_detail_view_widget.cpp
    gui/netif_summary_view_widget.cpp
    gui/netif_stat_view_widget.cpp
    gui/netif_item_view_widget.cpp
    gui/detail_view_stacked_widget.cpp
    gui/chart_view_widget.cpp
    gui/animation_stackedwidget.cpp
    gui/cpu_detail_widget.cpp
    gui/cpu_summary_view_widget.cpp
    gui/block_dev_item_widget.cpp
    gui/block_dev_stat_view_widget.cpp
)

set(HPP_PROCESS
    process/private/process_p.h
    process/process.h
    process/process_set.h
    process/process_icon.h
    process/process_icon_cache.h
    process/process_name.h
    process/process_name_cache.h
    process/priority_controller.h
    process/process_controller.h
    process/desktop_entry_cache.h
    process/desktop_entry_cache_updater.h
    process/process_db.h
)
set(CPP_PROCESS
    process/process.cpp
    process/process_set.cpp
    process/process_icon.cpp
    process/process_icon_cache.cpp
    process/process_name.cpp
    process/process_name_cache.cpp
    process/priority_controller.cpp
    process/process_controller.cpp
    process/desktop_entry_cache.cpp
    process/desktop_entry_cache_updater.cpp
    process/process_db.cpp
)

set(HPP_SERVICE
    service/service_manager_worker.h
    service/service_manager.h
    service/system_service_entry_data.h
    service/system_service_entry.h
)
set(CPP_SERVICE
    service/service_manager_worker.cpp
    service/service_manager.cpp
    service/system_service_entry_data.cpp
    service/system_service_entry.cpp
)

set(HPP_SYSTEM
    system/private/mem_p.h
    system/private/cpu_p.h
    system/private/cpu_set_p.h
    system/private/block_device_p.h
    system/private/netif_p.h
    system/private/sys_info_p.h
    system/system_monitor.h
    system/system_monitor_thread.h
    system/device_id_cache.h
    system/packet.h
    system/netif.h
    system/netif_info_db.h
    system/netif_monitor.h
    system/netif_monitor_thread.h
    system/netif_packet_capture.h
    system/netif_packet_parser.h
    system/mem.h
    system/cpu.h
    system/cpu_set.h
    system/block_device.h
    system/block_device_info_db.h
    system/device_db.h
    system/sys_info.h
    system/udev.h
    system/udev_device.h
    system/netlink.h
    system/nl_addr.h
    system/nl_hwaddr.h
    system/nl_link.h
    system/wireless.h
    system/diskio_info.h
    system/net_info.h
)
set(CPP_SYSTEM
    system/system_monitor.cpp
    system/system_monitor_thread.cpp
    system/device_id_cache.cpp
    system/netif_monitor.cpp
    system/netif_monitor_thread.cpp
    system/netif_packet_capture.cpp
    system/netif_packet_parser.cpp
    system/device_db.cpp
    system/netif.cpp
    system/netif_info_db.cpp
    system/mem.cpp
    system/cpu.cpp
    system/cpu_set.cpp
    system/block_device.cpp
    system/block_device_info_db.cpp
    system/sys_info.cpp
    system/udev.cpp
    system/udev_device.cpp
    system/netlink.cpp
    system/nl_addr.cpp
    system/nl_hwaddr.cpp
    system/nl_link.cpp
    system/wireless.cpp
    system/diskio_info.cpp
    system/net_info.cpp
)

set(HPP_WM
    wm/wm_atom.h
    wm/wm_connection.h
    wm/wm_info.h
    wm/wm_window_list.h
    wm/wm_window_tree.h
)
set(CPP_WM
    wm/wm_atom.cpp
    wm/wm_connection.cpp
    wm/wm_info.cpp
    wm/wm_window_list.cpp
    wm/wm_window_tree.cpp
)

set(APP_HPP
    ${HPP_GLOBAL}
    ${HPP_COMMON}
    ${HPP_DBUS}
    ${HPP_MODEL}
    ${HPP_GUI}
    ${HPP_PROCESS}
    ${HPP_SERVICE}
    ${HPP_SYSTEM}
    ${HPP_WM}
)
set(APP_CPP
    ${CPP_GLOBAL}
    ${CPP_COMMON}
    ${CPP_DBUS}
    ${CPP_MODEL}
    ${CPP_GUI}
    ${CPP_PROCESS}
    ${CPP_SERVICE}
    ${CPP_SYSTEM}
    ${CPP_WM}
)

add_executable(${APP_NAME}
    ${APP_HPP}
    ${APP_CPP}
    ${CMAKE_SOURCE_DIR}/${APP_RESOURCES}
)

target_link_libraries(${APP_NAME}
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    Qt5::DBus
    Qt5::Concurrent
    Qt5::X11Extras
    dtkcore
    dtkwidget
    dtkgui
    ${LIB_PCAP}
    ${LIB_PROCPS}
    ICU::i18n
    ICU::uc
    ${LIB_XCB}
    ${LIB_XEXT}
    ${LIB_ICCCM}
    ${LIB_NL3_LIBRARIES}
    ${LIB_NL3_ROUTE_LIBRARIES}
    ${LIB_UDEV_LIBRARIES}
)

install(TARGETS ${APP_NAME} DESTINATION bin)
