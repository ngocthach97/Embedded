cmd_/home/nguyen/Project/Linux/Driver/Basic/modules.order := {   echo /home/nguyen/Project/Linux/Driver/Basic/basic.ko; :; } | awk '!x[$$0]++' - > /home/nguyen/Project/Linux/Driver/Basic/modules.order
