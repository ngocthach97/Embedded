#include <stdio.h>
#include <stdlib.h>
#include "Subject.h"
#include "Octal.h"
#include "Hexa.h"
#include "Binary.h"

int main(int argc, const char *argv[])
{
    struct subject *subject = (struct subject *)malloc(sizeof(struct subject));
    init_subject(subject);

    struct octal *octal = (struct octal *)malloc(sizeof(struct octal));
    init_octal(octal);

    struct hexa *hexa = (struct hexa *)malloc(sizeof(struct hexa));
    init_hexa(hexa);

    struct binary *binary = (struct binary *)malloc(sizeof(struct binary));
    init_binary(binary);

    add_list(subject, &octal->observer);
    add_list(subject, &hexa->observer);
    add_list(subject, &binary->observer);
    set_state(subject, 10);

    printf("%d \n",get_state(subject));
    return 0;
}