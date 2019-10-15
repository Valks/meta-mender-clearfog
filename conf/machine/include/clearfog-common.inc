# Have to manually specify the DTB file to use with Mender
# 
#    armada-388-clearfog.dtb        - Clearfog
#    armada-388-clearfog-base.dtb   - Clearfog Base
#    armada-388-clearfog-pro.dtb    - Clearfog Pro
#    armada-388-clearfog-gtr-s4.dtb - Clearfog GTR S4
#    armada-388-clearfog-gtr-l8.dtb - Clearfog GTR L8
#
MENDER_DTB_NAME_FORCE ?= "armada-388-clearfog.dtb"

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