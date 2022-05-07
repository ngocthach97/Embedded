cmd_/home/nguyen/Project/Linux/Basic/modules.order := {   echo /home/nguyen/Project/Linux/Basic/basic.ko; :; } | awk '!x[$$0]++' - > /home/nguyen/Project/Linux/Basic/modules.order
