cmd_/home/nguyen/Project/Linux/Driver/Memory/Share_Memory/modules.order := {   echo /home/nguyen/Project/Linux/Driver/Memory/Share_Memory/share_memory.ko; :; } | awk '!x[$$0]++' - > /home/nguyen/Project/Linux/Driver/Memory/Share_Memory/modules.order