cmd_/home/nguyen/Embedded/Driver/Device/Module.symvers := sed 's/ko$$/o/' /home/nguyen/Embedded/Driver/Device/modules.order | scripts/mod/modpost -m -a   -o /home/nguyen/Embedded/Driver/Device/Module.symvers -e -i Module.symvers   -T -
