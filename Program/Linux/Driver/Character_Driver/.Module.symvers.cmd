cmd_/home/nguyen/Embedded/Program/Linux/Driver/Character_Driver/Module.symvers := sed 's/\.ko$$/\.o/' /home/nguyen/Embedded/Program/Linux/Driver/Character_Driver/modules.order | scripts/mod/modpost -m -a  -o /home/nguyen/Embedded/Program/Linux/Driver/Character_Driver/Module.symvers -e -i Module.symvers   -T -