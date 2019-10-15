# meta-mender-clearfog

This Yocto layers contains recipes which enables support of building Mender client for Clearfog boards.

**NOTE!**. To be able to support update of Linux kernel and DTB, Mender requires these to be installed in the `/boot` directory for each rootfs (normally /dev/mmcblk0p2 and /dev/mmcblk0p3). On the other hand, the Clearfog boot firmware requires that the DTB file is in the same partition as the boot firmware (/dev/mmcbl0p1) and the config.txt file. For now Mender will not use the DTB that is delivered with new artifacts and will continue to boot with the original DTB that was populated using the SDIMG file.

## Dependencies

This layer depends on:

    URI: git://github.com/SolidRun/meta-clearfog
    branch: master
    revision: HEAD

in addition to `meta-mender` dependencies.

## Build instructions

- Read [the Mender documentation on Building a Mender Yocto image](https://docs.mender.io/Artifacts/Building-Mender-Yocto-image) for Mender specific configuration.
- Set MACHINE to one of the following
    - clearfog
    - clearfog-gtr-s4
    - clearfog-gtr-s18
- Add following to your local.conf (including configuration required by meta-mender-core)

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

- Run `bitbake <image name>`