set(CORE_SRCS
  cores/esp32/dummySerial.cpp
  cores/esp32/Print.cpp
  cores/esp32/stdlib_noniso.c
  cores/esp32/Stream.cpp
  cores/esp32/WString.cpp
  )

set(LIBRARY_SRCS
  )

set(BLE_SRCS
  )

set(includedirs
  cores/esp32/
  )

 set(requires
    esp_timer
    driver
    )
    
set(srcs ${CORE_SRCS} ${LIBRARY_SRCS} ${BLE_SRCS})
##--##set(priv_includes cores/esp32/libb64)
##--##set(requires spi_flash mbedtls mdns esp_adc_cal wifi_provisioning nghttp wpa_supplicant)
##--##set(priv_requires fatfs nvs_flash app_update spiffs bootloader_support openssl bt esp_ipc esp_hid)

idf_component_register(INCLUDE_DIRS ${includedirs} PRIV_INCLUDE_DIRS ${priv_includes} SRCS ${srcs} REQUIRES ${requires} PRIV_REQUIRES ${priv_requires})

if(NOT CONFIG_FREERTOS_HZ EQUAL 1000 AND NOT "$ENV{ARDUINO_SKIP_TICK_CHECK}")
    # See delay() in cores/esp32/esp32-hal-misc.c.
    message(FATAL_ERROR "esp32-arduino requires CONFIG_FREERTOS_HZ=1000 "
                        "(currently ${CONFIG_FREERTOS_HZ})")
endif()
