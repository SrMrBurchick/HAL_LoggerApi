# Copyright (C) 2014 Google Inc.
#
# This file is part of ycmd.
#
# ycmd is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# ycmd is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with ycmd.  If not, see <http://www.gnu.org/licenses/>.

import os
import ycm_core
from glob import glob
project_dir = "common"

dir_path = os.path.dirname(os.path.realpath(__file__))
start_dir = dir_path[:dir_path.find(project_dir) + len(project_dir)]
print(start_dir)
pattern = "*.h"

# These are the compilation flags that will be used in case there's no
# compilation database set (by default, one is not set).
# CHANGE THIS LIST OF FLAGS. YES, THIS IS THE DROID YOU HAVE BEEN LOOKING FOR.
flags = [
'-Wall',
'-Wextra',
'-Werror',
'-fexceptions',
'-DNDEBUG',
# THIS IS IMPORTANT! Without a "-std=<something>" flag, clang won't know which
# language to use when compiling headers. So it will guess. Badly. So C++
# headers will be compiled as C headers. You don't want that so ALWAYS specify
# a "-std=<something>".
# For a C project, you would set this to something like 'c99' instead of
# 'c++11'.
'-std=c++11',
# ...and the same thing goes for the magic -x option which specifies the
# language that the files to be compiled are written in. This is mostly
# relevant for c++ headers.
# For a C project, you would set this to 'c' instead of 'c++'.
'-x',
'c++',
'-isystem',
'/usr/include',
'-isystem',
'/usr/local/include',
'-isystem',
'../llvm/include',
'-isystem',
'../llvm/tools/clang/include',
]

def update_flags():
    for dir,_,_ in os.walk(start_dir):
        files = glob(os.path.join(dir,pattern))
        if type(files) is list:
            for file in files:
                include_dir = '{path}'.format(path=file[:file.rfind('/')])
                if include_dir not in flags:
                    flags.append('-isystem')
                    flags.append(include_dir)
        elif type (files) is str:
            include_dir = '{path}'.format(path=files[:files.rfind('/')])
            if include_dir not in flags:
                flags.append('-isystem')
                flags.append(include_dir)

#for os_walk_entry in os.walk( root ):
#        if os.path.isdir( os_walk_entry[ 0 ] ):
#                flags += [ '-I', os_walk_entry[ 0 ] ]

def Settings( **kwargs ):
        update_flags()
        return { 'flags': flags }
update_flags()
print(flags)
