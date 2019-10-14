# Depending on which boot medium is selected the U-boot binary will change name
#
#    u-boot-spl-mmc.kwb
#    u-boot-spl-nand.kwb"
#    u-boot-spl-sata.kwb"
#    u-boot-spl-sdhc.kwb"
#    u-boot-spl-spi.kwb
#
# Update this variable to change boot location, it will update
# MVEBU_SPL_BOOT_DEVICE_XXX
UBOOT_BINARY ?= "u-boot-spl-sdhc.kwb"

WKS_FILE = "clearfog.wks"
WKS_FILE_DEPENDS = "virtual/bootloader clearfog-u-boot-scr"