cmd_/home/nguyen/Embedded/Programing/Driver/PCI/Module.symvers := sed 's/ko$$/o/' /home/nguyen/Embedded/Programing/Driver/PCI/modules.order | scripts/mod/modpost -m -a   -o /home/nguyen/Embedded/Programing/Driver/PCI/Module.symvers -e -i Module.symvers   -T -
