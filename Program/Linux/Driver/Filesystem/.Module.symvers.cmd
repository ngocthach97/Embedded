cmd_/home/nguyen/Embedded/Programing/Driver/Filesystem/Module.symvers := sed 's/ko$$/o/' /home/nguyen/Embedded/Programing/Driver/Filesystem/modules.order | scripts/mod/modpost -m -a   -o /home/nguyen/Embedded/Programing/Driver/Filesystem/Module.symvers -e -i Module.symvers   -T -