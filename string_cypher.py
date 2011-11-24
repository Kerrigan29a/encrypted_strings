#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright (c) 2011 Javier Escalada Gómez
# All rights reserved.

import os
import re
import string

out_file_name = "encrypted_strings.def"
in_file_name = "strings.list"
macro = "STR"
definition_pattern = re.compile('(\w+)\s*=\s*"(.*)"')

with open(out_file_name, "w") as fout:
    with open(in_file_name, "r") as fin:
        print "READING {}".format(in_file_name)
        for line in fin:
            m = definition_pattern.match(line)
            if not m:
                print 'ERROR at "{}"'.format(line)
                exit(0)
            id = m.group(1)
            charbytes = bytearray(m.group(2))
            fout.write("{}({}, {}, ".format(macro, id, len(charbytes)))
            fout.write("{")
            for c in map(lambda x: x ^ len(charbytes), charbytes):
                fout.write("'\\x{:02x}', ".format(c))
            #fout.write("0})")
            fout.write("})")
            fout.write("{}".format(os.linesep))
                
print "CREATED {}".format(out_file_name)