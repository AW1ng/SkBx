# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-src"
  "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-build"
  "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-subbuild/curl-populate-prefix"
  "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-subbuild/curl-populate-prefix/tmp"
  "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
  "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-subbuild/curl-populate-prefix/src"
  "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Alex_dev/Desktop/Prog/skill/HTTP/1.Users requests/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
