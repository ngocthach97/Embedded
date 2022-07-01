cmd_/home/nguyen/Embedded/Driver/Device/modules.order := {   echo /home/nguyen/Embedded/Driver/Device/device.ko; :; } | awk '!x[$$0]++' - > /home/nguyen/Embedded/Driver/Device/modules.order
